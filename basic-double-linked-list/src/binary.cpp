#include "../include/classes/binary.h"

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
    for (i = 0; (binary.binary[i] == 0 && i < MAX_SIZE_BINARY); i++);

    if (i == MAX_SIZE_BINARY) {
        output << 0;
        return output;
    }

    for (; i < MAX_SIZE_BINARY; i++)
        output << binary.binary[i];

    return output;
}