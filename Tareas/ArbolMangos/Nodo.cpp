#include "Nodo.h"
#include <iostream>

Nodo::Nodo(ArbolMangos *arbol) {
    this->arbol = arbol;
    siguiente = NULL;
    anterior = NULL;
}

Nodo::~Nodo() {
}
