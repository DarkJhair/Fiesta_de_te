//
// Created by jhair on 03-08-18.
//

#ifndef ARBOLBUSQUEDA_ARBOLLISTA_H
#define ARBOLBUSQUEDA_ARBOLLISTA_H

#include "Nodo.h"
#include <iostream>

class Arbollista {
private:
    Nodo * raiz=NULL;

public:
    void add_Nodo(int);
    void add_Nodo(Nodo*,Nodo**);

    void eliminar_Nodo();
    void preorden(Nodo*);
    void preorden();
    void posorden(Nodo*);
    void postorden();
    void inorden(Nodo *);
    void inorden();



    Arbollista();



};


#endif //ARBOLBUSQUEDA_ARBOLLISTA_H
