#include <iostream>
#include "classes/decimal.h"
#include "classes/binary.h"
#include "classes/binary_linked.h"
#include "classes/hexadecimal.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cerr << "Using argv[1], argv[2]" << std::endl;
        return EXIT_FAILURE;
    }

    Hexadecimal *h1 = new Hexadecimal(std::stoi(argv[2]));
    Hexadecimal *h2 = new Hexadecimal(std::stoi(argv[3]));

    std::cout << *h1 + *h2 << std::endl;

    return EXIT_SUCCESS;
}