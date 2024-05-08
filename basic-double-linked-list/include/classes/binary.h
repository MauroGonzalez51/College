#ifndef BINARY_H
#define BINARY_H
#include <iostream>
#define MAX_SIZE_BINARY 40

class Binary {
    private:
        short binary[MAX_SIZE_BINARY];

    public:
        Binary(long = 0);
        Binary operator+(const Binary &) const;
        friend std::ostream &operator<<(std::ostream &, const Binary &);
};

#endif