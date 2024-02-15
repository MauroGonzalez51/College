#include <iostream>
#include <vector>
#include "../include/execution_time.h"

int not_recursive_binary_search(std::vector <int> &, int);
int actually_recursive_binary_search(std::vector <int> &, int, int, int);

int main(int argc, char **argv) {
    if (argv[1] == NULL) {
        std::cout << "Using argv[1]" << std::endl;
        exit(1);
    }

    ExecutionTime *execution_time = new ExecutionTime();

    std::vector <int> vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int random_value_to_search = *argv[1] - '0';

    execution_time -> start();
    std::cout << "[ INDEX ] Normal: " << not_recursive_binary_search(vector, random_value_to_search) << std::endl;
    execution_time -> end();
    std::cout << "[ EXECUTION (s) ]: " << execution_time -> getTimeInSeconds() << std::endl;

    std::cout << std::endl;

    execution_time -> start();
    std::cout << "[ INDEX ] Recursive: " << actually_recursive_binary_search(vector, random_value_to_search, 0, int(vector.size() - 1)) << std::endl;
    execution_time -> end();
    std::cout << "[ EXECUTION (s) ]: " << execution_time -> getTimeInSeconds() <<  std::endl;

    return EXIT_SUCCESS;
}

/**
 * ! Normal BinarySearch
 * 
 * Complexity: O(log n)
 * 
 * 
 * 
*/

int not_recursive_binary_search(std::vector <int> &vector, int element) {
    int left = 0, right = int(vector.size() - 1);

    if (left > right) return -1;

    while (left <= right) {
        int mid = left + (right -  left) / 2;

        if (vector.at(mid) == element)
            return mid;

        if (element < vector.at(mid)) 
            right = mid - 1;
        
        if (element > vector.at(mid))
            left = mid + 1;
    }

    return -1;
}

/**
 * ! Recursive BinarySearch
 * 
 * Complexity: Seems to be also O(log n)
 * 
 * Because, in each iteration is slicing the array in half, then
 * it takes one or another path (like what's happening when inserting a new Node in ABB)
 * 
 * But, even tho both have the same the same time complexity
 * the recursive version seems to be like 10 times as fast as the other.
 * 
 * 
 * 
 * 
*/

int actually_recursive_binary_search(std::vector <int> &vector, int element_to_search, int left, int right) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (vector.at(mid) == element_to_search) return mid;

    if (element_to_search < vector.at(mid)) 
        return actually_recursive_binary_search(vector, element_to_search, left, mid - 1);
    
    if (element_to_search > vector.at(mid))
        return actually_recursive_binary_search(vector, element_to_search, mid + 1, right);

    return -1;
}