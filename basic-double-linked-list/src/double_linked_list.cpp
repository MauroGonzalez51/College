#include "classes/double_linked_list.h"

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

    Node *node = this -> tail;
    short value = node -> value;
    this -> currentSize--;

    if (!node -> previousElement) {
        this -> head = this -> tail = nullptr;
        
        delete node;

        return value;
    }

    node -> previousElement -> nextElement = nullptr;
    this -> tail = node -> previousElement;

    delete node;

    return value;
}

short DoubleLinkedList::shift() {
    if (!this -> head)
        throw std::out_of_range("Cannot shift from an empty list");

    Node *node = this -> head;
    short value = node -> value;
    this -> currentSize--;

    if (!node -> nextElement) {
        this -> head = this -> tail = nullptr;

        delete node;

        return value;
    }

    node -> nextElement -> previousElement = nullptr;
    this -> head = node -> nextElement;

    delete node;

    return value;
}

int DoubleLinkedList::isEmpty() {
    return this -> head == nullptr;
}

void DoubleLinkedList::print() {
    Node *current = this -> head;
    while (current) {
        std::cout << current -> value;
        current = current -> nextElement;
    }

    std::cout << std::endl;
}

std::ostream &DoubleLinkedList::print(std::ostream &output) {
    Node *current = this -> head;
    while (current) {
        output << current -> value;
        current = current -> nextElement;
    }

    return output;
}