#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H
#define MAX_SIZE_HEXADECIMAL 100
#include <iostream>

class Hexadecimal {
    private:
        char hexadecimal[MAX_SIZE_HEXADECIMAL];

    public:
        Hexadecimal(long = 0);
        Hexadecimal *operator+(const Hexadecimal &) const;
        friend std::ostream &operator<<(std::ostream &, const Hexadecimal &);
};

#endif