#include "classes/octal.h"

Octal::Octal(long valor) {
    for(int i = 0; i < 12; i++)
        oct[i] = 0;

    // Convierte el valor decimal a octal y lo almacena en el arreglo oct[]
    for(int j = 11; valor != 0 && j >= 0; j--) {
        oct[j] = valor % 8;
        valor /= 8;
    }
}

Octal Octal::operator+(const Octal &op2) const {
    Octal temp;
    int acarreo = 0;

    // Realiza la suma bit a bit, teniendo en cuenta el acarreo
    for(int i = 11; i >= 0; i--) {
        temp.oct[i] = oct[i] + op2.oct[i] + acarreo;
        if(temp.oct[i] > 7) {
            temp.oct[i] %= 8; // Reduce a 0 - 7
            acarreo = 1;
        } else {
            acarreo = 0;
        }
    }
    return temp;
}

std::ostream& operator<<(std::ostream &salida, const Octal &num) {
    int i;
    for(i = 0; (num.oct[i] == 0) && (i < 12); i++);
    // Ignora ceros a la izquierda
    if(i == 12)
        salida << 0;
    else
        for(; i < 12; i++)
            salida << num.oct[i];
    return salida;
}
