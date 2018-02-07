#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>

struct Nodo {
    double numero;
    char operador;
    Nodo *next;

    Nodo(double);
    Nodo(char);
    ~Nodo();
};

#endif // NODO_H_INCLUDED
