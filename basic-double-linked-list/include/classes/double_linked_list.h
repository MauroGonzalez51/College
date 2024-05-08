#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include <iostream>
#include "../node.h"

class DoubleLinkedList {
    private:
        Node *head, *tail;
        int currentSize;

    public:
        DoubleLinkedList(): head(nullptr), tail(nullptr), currentSize(0) {}
        DoubleLinkedList(const DoubleLinkedList *);
        int push(short);
        Node *getHead() const;
        Node *getTail() const;
};

#endif