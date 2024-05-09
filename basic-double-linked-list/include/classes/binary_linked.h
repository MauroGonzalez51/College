#ifndef BINARY_LINKED_H
#define BINARY_LINKED_H
#include <iostream>
#include "classes/double_linked_list.h" 

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