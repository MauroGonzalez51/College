#ifndef LISTADECIMAL_H
#define LISTADECIMAL_H

#include <iostream>
using namespace std;

class listadecimal
{
public:
    friend ostream &operator<<(ostream &, const listadecimal &);
public:
    listadecimal(long = 0);
    listadecimal operator+(const listadecimal &) const;
private:
    struct Nodo {
        short digito;
        Nodo *siguiente;
        Nodo *anterior;
        Nodo(short digito = 0, Nodo *siguiente = nullptr, Nodo *anterior = nullptr)
            : digito(digito), siguiente(siguiente), anterior(anterior) {}
    };
    Nodo *ultimo;
    Nodo *primero;
};

#endif // LISTADECIMAL_H
