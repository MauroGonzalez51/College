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
        return ++this -> currentSize;
    }

    this -> tail -> nextElement = node;
    node -> previousElement = this -> tail;
    this -> tail = node;
    this -> currentSize++;
    return ++this -> currentSize;
}

int DoubleLinkedList::unshift(short newValue) {
    Node *node = new Node(newValue);

    if (!node) return 0;

    if (!this -> head) {
        delete node;
        return this -> push(newValue);
    }

    this -> head -> previousElement = node;
    node -> nextElement = this -> head;
    this -> head = node;
    return ++this -> currentSize;
}

short DoubleLinkedList::pop() {
    if (!this -> tail)
        throw std::out_of_range("Cannot pop from an empty list");

    Node *node = this -> head;
    short value = node -> value;

    this -> tail -> previousElement -> nextElement = nullptr;
    
    delete node;
}

short DoubleLinkedList::shift() {
    if (!this -> head)
        throw std::out_of_range("Cannot shift from an empty list");

    short value = this -> head -> value;



}