#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include <stdint.h>
#include <functional>
#include <iostream>
#include "node.h"
#define u32 uint32_t

template <typename T>
class DoubleLinkedList {
    public:
        Node<T> *head, *tail;
        u32 currentSize;
        
        DoubleLinkedList(): head(nullptr), tail(nullptr), currentSize(0) {}

        DoubleLinkedList(size_t alloc): DoubleLinkedList() {
            for (size_t i = 0; i < alloc; i++)
                this -> push(nullptr);
        }

        DoubleLinkedList(const DoubleLinkedList<T> &other): DoubleLinkedList() {
            Node<T> *current = other.head;
            while (current) {
                this -> push(current -> value);
                current = current -> nextElement;
            }
        }

        ~DoubleLinkedList() {
            Node<T> *current = this -> head;
            while (current != nullptr) {
                Node<T> *next = current -> nextElement;
                delete current;
                current = next;
            }
        }

        void print() {
            Node<T> *current = this -> head;
            while (current) {
                std::cout << current -> value << std::endl;
                current = current -> nextElement;
            }
        }

        int push(T newValue) {
            Node<T> *newNode = new Node<T>(newValue);

            if (!newNode) return 0;

            if (!this -> head) {
                this -> head = newNode;
                this -> tail = newNode;
                this -> currentSize++;
                return 1;
            }     

            this -> tail -> nextElement = newNode;
            newNode -> previousElement = this -> tail;
            this -> tail = newNode;
            this -> currentSize++;
            return 1;
        }

        Node<T> *pop() {
            if (!this -> tail)
                return nullptr;

            Node<T> *element = this -> tail;
            this -> tail = element -> previousElement;
            this -> tail -> nextElement = nullptr; 
            return element;
        }

        Node<T> *shift() {
            if (!this -> head) 
                return nullptr;

            Node<T> *element = this -> head;
            this -> head = element -> nextElement;
            this -> head -> previousElement = nullptr;
            return element;
        }

        template <typename U, typename Func>
        DoubleLinkedList<U> *map(Func function) {
            DoubleLinkedList<U> *result = new DoubleLinkedList<U>();
            Node<T> *current = this -> head;
            while (current) {
                result -> push(function(current -> value));
                current = current -> nextElement;   
            }

            return result;
        }

        template <typename Func>
        void forEach(Func function) {
            Node<T> *current = this -> head;
            while (current) {
                function(current -> value);
                current = current -> nextElement;
            }
        }

        template <typename Func>
        DoubleLinkedList<T> *filter(Func function) {
            DoubleLinkedList<T> *list = new DoubleLinkedList<T>();
            Node<T> *current = this -> head;
            while (current) {
                if (function(current -> value)) 
                    list -> push(current -> value);
                current = current -> nextElement;
            }

            return list;
        }

        template <typename Func>
        bool some(Func function) {
            Node<T> *current = this -> head;

            while (current) {
                if (function(current -> value))
                    return true;
                current = current -> nextElement;
            }

            return false;
        }

        template <typename Func>
        bool every(Func function) {
            Node<T> *current = this -> head;

            while (current) {
                if (!function(current -> value))
                    return false;
                current = current -> nextElement;
            }

            return true;
        }

        template <typename U, typename Func>
        U reduce (Func function, U initialValue) {
            U accumulator = initialValue;
            Node<T> *current = this -> head;
            
            while (current) {
                accumulator = function(accumulator, current -> value);
                current = current -> nextElement;
            }

            return accumulator;
        }

        DoubleLinkedList<T> *toReversed() {
            DoubleLinkedList<T> *list = new DoubleLinkedList<T>();

            Node<T> *current = this -> tail;
            while (current) {
                list -> push(current -> value);
                current = current -> previousElement;
            }

            return list;
        }

        DoubleLinkedList<T> *operator+(const DoubleLinkedList<T> &other) const {
            DoubleLinkedList<T> *list =  new DoubleLinkedList<T>();

            this -> forEach([list](T value) {
                list -> push(value);
            });

            other.forEach([list](T value) {
                list -> push(value);
            });

            return list; 
        }
};

#endif