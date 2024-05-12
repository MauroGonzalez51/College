#ifndef BINARY_LINKED_H
#define BINARY_LINKED_H
#include <iostream>
#include "classes/double_linked_list.h" 

/**
 * Class to implement some binary operations.
 * Implemented using DoubleLinkedLists data structure
 * 
 * @size
 *  - {BinaryLinked *}: 8 Bytes
 *  - {Binary}: 8 Bytes
 *      since the class itself works with pointers
 *      the size of the object is minimum
*/
class BinaryLinked {
    private:
        DoubleLinkedList *list;

    public:
        /**
         * Default constructor for the BinaryLinked class.
         * Initializes the binary representation with the given {long} value.
         * 
         * @complexity
         *  - Space: O(1) 
         *  - Time: O(k)
         *      k being the number of bits required to represent the {long} value
         *      k = static_cast<int>(log2(value)) + 1
         * 
         * @public
         * @param {long} value - The value to be converted to binary
        */
        BinaryLinked(long = 0);

        /**
         * Overloaded operator+ for BinaryLinked class
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(k)
         *      k being the greater value of
         *          (this -> number of digits) && (other.number of digits)
         *      k = std::max(static_cast<int>(log2(this -> value)) + 1, static_cast<int>(log2(other.value)) + 1)
         * 
         * @public
         * @param {const BinaryLinked &} other - The BinaryLinked object to add
         * @returns {BinaryLinked *} - The result of the binary addition
        */
        BinaryLinked *operator+(const BinaryLinked &) const;

        /**
         * Overloaded operator<< for BinaryLinked class.
         * Prints the binary representation of the object
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(k)
         *      since the method used is DoubleLinkedList::print(std::ostream),
         *      which has a complexity of O(n), n being the number of elements of the
         *      list, here this param will be k
         *      
         *      k = static_cast<int>(log2(number)) + 1
         * 
         * @public
         * @param {std::ostream &} output - The output stream
         * @param {const BinaryLinked &} binaryLinked - The BinaryLinked object to be printed
         * @returns {std::ostream &} - The output stream
        */
        friend std::ostream &operator<<(std::ostream &, const BinaryLinked &);

        /**
         * Returns the list, in which is represente the number.
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(1)
         *      In any case
         * 
         * @public
         * @returns {DoubleLinkedList *} Pointer to the list
        */
        DoubleLinkedList *getList();
};

#endif 