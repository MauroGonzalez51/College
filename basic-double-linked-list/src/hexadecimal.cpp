#include "classes/hexadecimal.h"

Hexadecimal::Hexadecimal(long value) {
    int i = 0, temp = 0;

    for (i = 0; i < MAX_SIZE_HEXADECIMAL; i++) 
        this->hexadecimal[i] = '0';

    i = MAX_SIZE_HEXADECIMAL - 1;

    while(value > 0) {
        temp = value % 16;
        if (temp < 10) {
            this -> hexadecimal[i] = temp + 48;
            value = value / 16;
            i--;
            continue;
        }
        
        this -> hexadecimal[i] = temp + 55;
        i--;
        
        value = value / 16;
    }
}

Hexadecimal *Hexadecimal::operator+(const Hexadecimal &other) const {
    Hexadecimal *result = new Hexadecimal();
    int carry = 0;
    int sum;

    for (int i = MAX_SIZE_HEXADECIMAL - 1; i >= 0; i--) {
        sum = (this -> hexadecimal[i] - '0') + (other.hexadecimal[i] - '0') + carry;

        result -> hexadecimal[i] = sum % 16;

        if (result -> hexadecimal[i] < 10) {
            result -> hexadecimal[i] += '0';
            carry = sum / 16;
            continue;
        } 
        
        result -> hexadecimal[i] += 'A' - 10;
        carry = sum / 16;
    }

    return result;
}

std::ostream &operator<<(std::ostream &output, const Hexadecimal &hexadecimal) {
    int i;

    for(i = 0; (hexadecimal.hexadecimal[i] == '0') && (i < MAX_SIZE_HEXADECIMAL); i++);
    
    if (i == MAX_SIZE_HEXADECIMAL - 1) {
        output << 0;
        return output;
    }

    for (; i < MAX_SIZE_HEXADECIMAL; i++)
        output << hexadecimal.hexadecimal[i];

    return output;
}
