#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include <iostream>
#include <stdexcept>
#include "node.h"

class DoubleLinkedList {
    private:
        Node *head, *tail;
        int currentSize;

    public:
        /**
         * Default constructor for DoubleLinkedList.
         * Initializes an empty list.
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(1)
         * 
         * @public 
        */
        DoubleLinkedList(): head(nullptr), tail(nullptr), currentSize(0) {}

        /**
         * Copy constructor for DoubleLinkedList.
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(n)
         *      n being the number of elements of the {other} list
         * 
         * @param {DoubleLinkedList *} other - source list
         * @public 
        */
        DoubleLinkedList(const DoubleLinkedList *);

        /**
         * Returns the HEAD of the list (firstElement)
         * 
         * @complexity 
         *  - Space: O(1)
         *  - Time: O(1)
         * 
         * @public
         * @returns {Node *} - Head of the list 
        */
        Node *getHead() const;

        /**
         * Returns the TAIL of the list (lastElement)
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(1)
         * 
         * @public
         * @returns {Node *} - Tail of the list 
        */
        Node *getTail() const;

        /**
        * Adds a new element to the end of the double linked list.
        *   
        * @complexity
        *   - Space: O(1)
        *   - Time: O(1)
        *       In any case
        * 
        * @public
        * @param {short} newValue - The value to be added to the list.
        * @returns {int} The new size of the list after adding the element.
        */
        int push(short);
        
        /**
         * Adds a new element at the beggining of the double linked list.
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(1)
         *      In any case
         * 
         * @public
         * @param {short} newValue - The value to be added to the list.
         * @returns {int} The new size of the list after adding the element. 
        */
        int unshift(short);

        /**
         * Removes the last node of the list, and returns it's
         * value
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(1)
         *      In any case
         * 
         * @public
         * @throws {std::out_of_range} - In case the list is empty
         * @returns {short} - Value of the last element
        */
       short pop();

       /**
        * Removes the first element of the list, and returns it's
        * value
        * 
        * @complexity
        *   - Space: O(1)
        *   - Time: O(1)
        *       In any case
        * 
        * @public
        * @throws {std::out_of_range} - In case the list is empty
        * @returns {number} - Value of the first element
       */
        short shift();
        
        /**
         * Prints the whole list (values)
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(n)
         *      n being the number of elements of the list     
         * 
         * @public 
        */
        void print();

        /**
         * Prints the whole list (values)
         * Meant to be used for operator overloading.
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(n)
         *      n being the number of elements of the list
         * 
         * @public
         * @returns {std::ostream} - OutputObject 
        */
        std::ostream &print(std::ostream &);

        /**
         * Checks if the list is empty or not
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(1)
         *      In any case
         * 
         * @public
         * @returns {boolean} - Will evaluate to true if the list is empty
        */
        int isEmpty() const;
};

#endif