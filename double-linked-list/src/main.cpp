#include <iostream>
#include "../include/double_linked_list.h"

int main(int argc, char **argv) {
    DoubleLinkedList<int> *list = new DoubleLinkedList<int>();

    for (int i = 0; i < 10; i++)
        list -> push(i);

    DoubleLinkedList<int> *squared = list -> map<int>([](int value) {
        return value * value;
    });

    // squared -> forEach([](int value) {
    //     std::cout << "Squared: " << value << std::endl;
    // });

    // bool allPositive = squared -> every([](int value) {
    //     return value >= 0;
    // });

    // std::cout << squared -> reduce([](int acc, int current) {
    //     return acc + current;
    // }, 0) << std::endl;

    
    DoubleLinkedList<int> *result = (*list) + (*squared);

    result -> print();

    return EXIT_SUCCESS;
}