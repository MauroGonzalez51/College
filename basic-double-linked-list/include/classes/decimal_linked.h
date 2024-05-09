#ifndef DECIMAL_LINKED_H
#define DECIMAL_LINKED_H
#include <iostream>
#include "classes/double_linked_list.h"

class DecimalLinked {
    private:
        DoubleLinkedList *list;

    public:
        DecimalLinked(long = 0);
        DecimalLinked operator+(const DecimalLinked &) const;
        friend std::ostream &operator<<(std::ostream &, const DecimalLinked &);
};

#endif