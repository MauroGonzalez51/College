#include "classes/binary.h"

Binary::Binary(long value) {
    for (int i = 0; i < MAX_SIZE_BINARY; i++)
        this -> binary[i] = 0;

    for (int i = MAX_SIZE_BINARY - 1; i >= 0; i--) {
        this -> binary[i] = value % 2;
        value /= 2;
    }
}

Binary Binary::operator+(const Binary &other) const {
    Binary result;
    int extra = 0;

    for (int i = MAX_SIZE_BINARY - 1; i >= 0; i++) {
        result.binary[i] = this -> binary[i] + other.binary[i] + extra;

        if (result.binary[i] > 1) {
            result.binary[i] %= 2;
            extra = 1;
            continue;
        }

        extra = 0;
    }

    return result;
}

std::ostream &operator<<(std::ostream &output, const Binary &binary) {
    int i;

    /**
     * The amount of iterations of this will be
     * 
     * MAX_SIZE_BINARY - (static_cast<int>(log2(__number (decimal))) + 1)
     * MAX_SIZE_BINARY - (static_cast<int>(log10(Ob)) + 1) 
     * 
     * => MAX_SIZE_BINARY - the number of digits in binary
    */
    for (i = 0; (binary.binary[i] == 0 && i < MAX_SIZE_BINARY); i++);

    if (i == MAX_SIZE_BINARY) {
        output << 0;
        return output;
    }

    /**
     * When dealing with an actual binary value (!= 0)
     * 
     * The iterations of the loop above will still be performed,
     * so, this loop will have to execute again a number of
     * 
     * static_cast<int>(log2(__number (decimal)) + 1)
     * static_cast<int>(log10(Ob) + 1) 
     * 
     * Resulting in a total time complexity of
     * 
     * (MAX_SIZE_BINARY - (static_cast<int>(...) + 1)) + static_cast<int>(...) + 1
     * 
     * => MAX_SIZE_BINARY - the number of digits in binary + the number of digits in binary
     * => MAX_SIZE_BINARY
    */
    for (; i < MAX_SIZE_BINARY; i++)
        output << binary.binary[i];

    return output;
}