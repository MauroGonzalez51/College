#include "classes/binary_linked.h"

DoubleLinkedList *BinaryLinked::getList() {
    return this -> list;
}

BinaryLinked::BinaryLinked(long value) {
    this -> list = new DoubleLinkedList();

    if (value == 0) {
        return;
    }

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