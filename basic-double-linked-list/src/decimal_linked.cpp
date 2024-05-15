#include "classes/decimal_linked.h"

listadecimal::listadecimal(long valor) : ultimo(nullptr), primero(nullptr)
{
    // Insertar los dígitos del valor en la lista doblemente enlazada
    while (valor > 0) {
        short digito = valor % 10;
        Nodo *nuevoNodo = new Nodo(digito);
        if (!primero) {
            primero = nuevoNodo;
            ultimo = nuevoNodo;
        } else {
            nuevoNodo->siguiente = primero;
            primero->anterior = nuevoNodo;
            primero = nuevoNodo;
        }
        valor /= 10;
    }
}

listadecimal listadecimal::operator+(const listadecimal &op2) const
{
    listadecimal temp;
    Nodo *iterador1 = primero;
    Nodo *iterador2 = op2.primero;
    Nodo *acarreo = nullptr;

    while (iterador1 || iterador2 || acarreo) {
        short suma = (iterador1 ? iterador1->digito : 0) + (iterador2 ? iterador2->digito : 0) + (acarreo ? acarreo->digito : 0);
        temp.primero = new Nodo(suma % 10, temp.primero);
        if (suma >= 10) {
            if (!temp.primero->siguiente) {
                temp.primero->siguiente = new Nodo(1);
                acarreo = nullptr;
            } else {
                acarreo = new Nodo(1);
            }
        } else {
            acarreo = nullptr;
        }
        if (iterador1) iterador1 = iterador1->siguiente;
        if (iterador2) iterador2 = iterador2->siguiente;
    }

    return temp;
}

ostream& operator<<(ostream &salida, const listadecimal &num)
{
    listadecimal::Nodo *iterador = num.primero;
    while (iterador) {
        salida << iterador->digito;
        iterador = iterador->siguiente;
    }
    return salida;
}
