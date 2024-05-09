#include "classes/decimal.h"

Decimal::Decimal(long value) {
    for (int i = 0; i < MAX_SIZE_DECIMAL; i++) 
        this -> decimal[i] = 0;

    for (int i = MAX_SIZE_DECIMAL - 1; i >= 0; i--) {
        this -> decimal[i] = value % 10;
        value /= 10;
    }
}

Decimal Decimal::operator+(const Decimal &other) const {
    Decimal result;
    int extra = 0;

    for (int i = MAX_SIZE_DECIMAL - 1; i >= 0; i++) {
        result.decimal[i] = this -> decimal[i] + other.decimal[i] + extra;

        if (result.decimal[i] > 9) {
            result.decimal[i] %= 10;
            extra = 1;
            continue;
        }

        extra = 0;
    }

    return result;
}

std::ostream &operator<<(std::ostream &output, const Decimal &decimal) {
    int i;
    for (i = 0; (decimal.decimal[i] == 0 && i < MAX_SIZE_DECIMAL); i++);

    if (i == MAX_SIZE_DECIMAL) {
        output << 0;
        return output;
    }

    for (; i < MAX_SIZE_DECIMAL; i++)
        output << decimal.decimal[i];

    return output;
}