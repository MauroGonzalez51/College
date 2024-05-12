#ifndef NODE_H
#define NODE_H

/**
 * Node structure.
 * 
 * @size 
 *  - {Node *}: 8 Bytes
 *  - {Node}: 24 Bytes
 * 
 * @param {short} value - Value of the node 
*/
typedef struct Node {
    short value;
    struct Node *nextElement, *previousElement;

    Node(short value): value(value), nextElement(nullptr), previousElement(nullptr) {}
} Node;

#endif