#include "classes/binary_linked.h"

// TODO: Docstring this (the methods that are neccesary)

DoubleLinkedList *BinaryLinked::getList() {
    return this -> list;
}

BinaryLinked::BinaryLinked(long value) {
    this -> list = new DoubleLinkedList();

    if (value == 0) {
        return;
    }

    /**
     * Since the this -> list remains the same (in size)
     * The space complexity sticks at O(1)
     * 
     * But ...
     * The nodes are being added, so the object of list will be
     * growing in size.
     * 
     * This growth is independent of the class constructor itself.
     * 
     * Note: list -> unshift() // Time: O(1)
     *  
    */
    while (value != 0) {
        this -> list -> unshift(value % 2);
        value /= 2;
    }
}

BinaryLinked *BinaryLinked::operator+(const BinaryLinked &other) const {
    BinaryLinked *result =  new BinaryLinked();
    Node *currentThis = this -> list -> getTail();
    Node *currentOther = other.list -> getTail();
    int carry = 0;

    while (currentThis != nullptr || currentOther != nullptr) {
        int sum = carry;

        if (currentThis != nullptr) {
            sum += currentThis -> value;
            currentThis = currentThis -> previousElement;
        }
        
        if (currentOther != nullptr) {
            sum += currentOther -> value;
            currentOther = currentOther -> previousElement;
        }

        result -> list -> unshift(sum % 2);
        carry = sum / 2;
    }

    if (carry == 1)
        result -> list -> unshift(carry);

    return result;
}

std::ostream &operator<<(std::ostream &output, const BinaryLinked &binaryLinked) {
    return binaryLinked.list -> print(output);
}