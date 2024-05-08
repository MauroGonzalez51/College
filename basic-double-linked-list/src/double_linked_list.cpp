#include "../include/classes/double_linked_list.h"

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList *other) {
    if (!other) return;

    if (!other -> currentSize) return;

    Node *current = this -> head;
    while (current) {
        this -> push(current -> value);
        current = current -> nextElement;
    }
}

Node *DoubleLinkedList::getHead() const {
    return this -> head;
}

Node *DoubleLinkedList::getTail() const {
    return this -> tail;
}

int DoubleLinkedList::push(short newValue) {
    Node *node = new Node(newValue);

    if (!node) return 0;

    if (!this -> head) {
        this -> head = node;
        this -> tail = node;
        this -> currentSize++;
        return this -> currentSize;
    }

    this -> tail -> nextElement = node;
    node -> previousElement = this -> tail;
    this -> tail = node;
    this -> currentSize++;
    return this -> currentSize;
}