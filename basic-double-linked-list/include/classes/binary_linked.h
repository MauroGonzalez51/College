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
        BinaryLinked(long = 0);
        BinaryLinked *operator+(const BinaryLinked &) const;
        friend std::ostream &operator<<(std::ostream &, const BinaryLinked &);
        DoubleLinkedList *getList();
};

#endif 