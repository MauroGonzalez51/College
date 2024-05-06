#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {   
    T value;
    Node *nextElement, *previousElement;

    Node(T value): value(value), nextElement(nullptr), previousElement(nullptr) {}
};

#endif