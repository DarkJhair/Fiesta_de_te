#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "ArbolMangos.h"
#include "Mango.h"

struct Nodo {
    ArbolMangos *arbol;
    Nodo *siguiente;
    Nodo *anterior;
    Nodo(ArbolMangos*);
    ~Nodo();
};

#endif // NODO_H_INCLUDED
