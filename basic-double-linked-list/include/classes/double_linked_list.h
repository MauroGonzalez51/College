#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include <iostream>
#include <stdexcept>
#include "../node.h"

class DoubleLinkedList {
    private:
        Node *head, *tail;
        int currentSize;

    public:
        DoubleLinkedList(): head(nullptr), tail(nullptr), currentSize(0) {}
        DoubleLinkedList(const DoubleLinkedList *);

        Node *getHead() const;
        Node *getTail() const;

        /**
        * Adds a new element to the end of the double linked list.
        *
        * @param {number} value - The value to be added to the list.
        * @returns {number} The new size of the list after adding the element.
        */
        int push(short);
        
        /**
         * Adds a new element at the beggining of the double linked list.
         * 
         * @param {number} value - The value to be added to the list.
         * @returns {number} The new size of the list after adding the element. 
        */
        int unshift(short);

        /**
         * Removes the last node of the list, and returns it's
         * value
         * 
         * @returns {number} - Value of the last element
        */
       short pop();

       /**
        * Removes the first element of the list, and returns it's
        * value
        * 
        * @returns {number} - Value of the first element
       */
        short shift();
        
        /**
         * Prints the whole list (values)
         *  
        */
        void print();

        /**
         * Checks if the list is empty or not
         * 
         * @returns {boolean} - Will evaluate to true if the list is empty
        */
        int isEmpty();
};

#endif