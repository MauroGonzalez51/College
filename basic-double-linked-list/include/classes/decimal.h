#ifndef DECIMAL_H
#define DECIMAL_H
#include <iostream>
#define MAX_SIZE_DECIMAL 30

class Decimal {
    private:
        short decimal[MAX_SIZE_DECIMAL];

    public:
        Decimal(long = 0);
        Decimal operator+(const Decimal &) const;
        friend std::ostream &operator<<(std::ostream &, const Decimal &);
};

#endif