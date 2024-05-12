#include <iostream>
#include "classes/decimal.h"
#include "classes/binary.h"
#include "classes/binary_linked.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cerr << "Using argv[1], argv[2]" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << sizeof(int) << std::endl;

    BinaryLinked *b1 = new BinaryLinked(std::stoi(argv[1]));
    BinaryLinked *b2 = new BinaryLinked(std::stoi(argv[2]));

    BinaryLinked *result = (*b1) + (*b2);  
    
    std::cout << *result << std::endl;

    return EXIT_SUCCESS;
}