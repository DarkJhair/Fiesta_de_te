#ifndef LISTAARBOLES_H_INCLUDED
#define LISTAARBOLES_H_INCLUDED

#include "Nodo.h"
#include "ArbolMangos.h"

class ListaArboles {
private:
    Nodo *first;
    int cantidadArboles;
public:
    ListaArboles();
    void addArbol(ArbolMangos*);
    void insertArbol(ArbolMangos*, int);
    void deleteArbol(int);
    int getSize();
    ArbolMangos *get(int);
};

#endif // LISTAARBOLES_H_INCLUDED
