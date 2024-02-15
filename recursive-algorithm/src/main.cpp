#include <iostream>
#include <vector>
#include <chrono>

int not_recursive_binary_search(std::vector <int> &, int);
int actually_recursive_binary_search(std::vector <int> &, int, int, int);

int main(int argc, char **arv) {
    std::vector <int> vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int random_value_to_search = 19;

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "[ INDEX ] Normal: " << not_recursive_binary_search(vector, random_value_to_search) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double> diff = end - start;
    std::cout << "[ EXECUTION (s) ]: " << diff.count() << std::endl;

    std::cout << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << "[ INDEX ] Recursive: " << actually_recursive_binary_search(vector, random_value_to_search, 0, int(vector.size() - 1)) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "[ EXECUTION (s) ]: " << diff.count() << std::endl;

    return EXIT_SUCCESS;
}

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