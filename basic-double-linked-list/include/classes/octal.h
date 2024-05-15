#ifndef OCTAL_H
#define OCTAL_H

#include <iostream>

class Octal {
    private:
        int oct[12]; 

    public:
        Octal(long valor = 0);
        Octal operator+(const Octal &op2) const; 
        friend std::ostream& operator<<(std::ostream &salida, const Octal &num); 
};

#endif
