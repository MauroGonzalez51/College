#ifndef BINARY_H
#define BINARY_H
#include <iostream>
#define MAX_SIZE_BINARY 40

/**
 * Class to implement some binary operations.
 * Implemented using unidimensional arrays
 * 
 * @size
 *  - {Binary *}: 8 Bytes
 *  - {Binary}: 80 Bytes
 *      2 * MAX_SIZE_BINARY 
 *          2 => sizeof(short) 
 * 
*/
class Binary {
    private:
        short binary[MAX_SIZE_BINARY];

    public:
        /**
         * Default constructor for Binary class.
         * Initializes the binary representation with the given {long} value.
         *
         * @complexity
         *  - Space: O(1)
         *  - Time: O(k)
         *      k being the number of bits required to represent the {long} value
         *      k = static_cast<int>(log2(value)) + 1
         * 
         * @public
         * @param {long} value - The value to be converted to binary
         */
        Binary(long = 0);

        /**
         * Overloaded operator+ for Binary class 
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time: O(MAX_SIZE_BINARY)
         *      In any case
         *      which is a constant time complexity, but not optimal
         * 
         * @public
         * @param {const Binary &} other - The Binary object to add
         * @returns {Binary} - The result of the binary addition
        */
        Binary operator+(const Binary &) const;

        /**
         * Overloaded operator<< for Binary class.
         * Prints the binary representation of the object
         * 
         * @complexity
         *  - Space: O(1)
         *  - Time:
         *      - Best case: O(1)
         *          Binary representation of 0
         *      
         *      - Worst case: O(MAX_SIZE_BINARY)
         *          When there's a value stored that's different of 0
         * 
         * @public
         * @param {std::ostream &} output - The output stream
         * @param {const Binary &} binary - The binary object to be printed
         * @returns {std::ostream &} - The output stream
        */
        friend std::ostream &operator<<(std::ostream &, const Binary &);
};

#endif