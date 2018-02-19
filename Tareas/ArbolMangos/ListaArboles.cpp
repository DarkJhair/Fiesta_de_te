#include "ListaArboles.h"
#include <iostream>

ListaArboles::ListaArboles() {
    first = NULL;
    cantidadArboles = 0;
}

void ListaArboles::addArbol(ArbolMangos *arbol) {
    insertArbol(arbol, cantidadArboles);
}

void ListaArboles::insertArbol(ArbolMangos *arbol, int posicion) {
    if(posicion < 0 || posicion > cantidadArboles)
        return;
    Nodo *nuevo = new Nodo(arbol);
    if(posicion == 0 && first == NULL) {
        first = nuevo;
        cantidadArboles++;
    }
    else if(posicion == 0 && first != NULL) {
        nuevo->siguiente = first;
        first = nuevo;
        cantidadArboles++;
    }
    else {
        Nodo *iterador = first;
        if(posicion == cantidadArboles) {
            for(int i = 0; i < cantidadArboles -1; i++)
                iterador = iterador->siguiente;
            iterador->siguiente = nuevo;
            nuevo->anterior = iterador;
            cantidadArboles++;
        }

        else if(posicion <= cantidadArboles) {
            for(int i = 0; i < posicion-1; i++)
                iterador = iterador->siguiente;
            iterador->siguiente->anterior = nuevo;
            nuevo->anterior = iterador;
            nuevo->siguiente = iterador->siguiente;
            iterador->siguiente = nuevo;
            cantidadArboles++;
        }
    }
}

void ListaArboles::deleteArbol(int posicion) {
    if(posicion < 0 || posicion > cantidadArboles || cantidadArboles == 0)
        return;
    Nodo *borrar;
    if(cantidadArboles == 1) {
        borrar = first;
        first = NULL;
    }
    else if(posicion == 0) {
        borrar = first;
        first = first->siguiente;
    }
    else if(posicion == cantidadArboles - 1) {
        Nodo *iterador = first;
        for(int i = 0; i < posicion - 1; i++)
            iterador = iterador->siguiente;
        borrar = iterador->siguiente;
        delete borrar;
        iterador->siguiente = NULL;
    }
    else {
        Nodo *iterador = first;
        for(int i = 0; i < posicion - 1; i++)
            iterador = iterador->siguiente;
        borrar = iterador->siguiente;
        iterador->siguiente = borrar->siguiente;
        borrar->siguiente->anterior = iterador;
    }
    delete borrar;
    cantidadArboles--;
}

int ListaArboles::getSize() {
    return cantidadArboles;
}

ArbolMangos* ListaArboles::get(int posicion) {
    Nodo *iterador = first;
    for(int i = 0; i < posicion; i++)
        iterador = iterador->siguiente;
    return iterador->arbol;
}
