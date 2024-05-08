#ifndef NODE_H
#define NODE_H

typedef struct Node {
    short value;
    struct Node *nextElement, *previousElement;

    Node(short value): value(value), nextElement(nullptr), previousElement(nullptr) {}
} Node;

#endif