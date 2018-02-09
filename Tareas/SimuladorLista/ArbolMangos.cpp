#include "Mango.h"
#include "ArbolMangos.h"

ArbolMangos::ArbolMangos() {
    first = NULL;
    cantidadMangos = 0;
}

void ArbolMangos::addMango(int peso) {
    insertMango(peso, cantidadMangos);
}

void ArbolMangos::insertMango(int peso, int posicion) {
    if(posicion < 0 || posicion > cantidadMangos)
        return;
    Mango *nuevo = new Mango(peso);
    if(cantidadMangos == 0) {
        first = nuevo;
        cantidadMangos++;
    }
    else {
        if(posicion == 0) {
            nuevo->siguiente = first;
            first = nuevo;
            cantidadMangos++;
            return;
        }
        Mango *iterador = first;
        if(posicion == cantidadMangos) {
            for(int i = 0; i < cantidadMangos -1; i++)
                iterador = iterador->siguiente;
            iterador->siguiente = nuevo;
            nuevo->anterior = iterador;
            cantidadMangos++;
        }

        else if(posicion <= cantidadMangos) {
            for(int i = 0; i < posicion-1; i++)
                iterador = iterador->siguiente;
            nuevo->anterior = iterador;
            nuevo->siguiente = iterador->siguiente;
            iterador->siguiente = nuevo;
            nuevo->siguiente->anterior = nuevo;
            cantidadMangos++;
        }
    }
}

void ArbolMangos::deleteMango(int posicion) {
    if(posicion < 0 || posicion > cantidadMangos || cantidadMangos == 0)
        return;
    Mango *borrar;
    if(posicion == 0) {
        borrar = first;
        first = first->siguiente;
        delete borrar;
        cantidadMangos--;
    }
    else {
        Mango *iterador = first;
        for(int i = 0; i < posicion; i++)
            iterador = iterador->siguiente;
        borrar = iterador;
        borrar->anterior = iterador->anterior;
        borrar->siguiente = iterador->anterior;
        iterador->anterior->siguiente = borrar;
        iterador->siguiente->anterior = borrar;
        delete borrar;
        cantidadMangos--;
    }
}

void ArbolMangos::printMass() {
    Mango *iterador = first;
    for(int i = 0; i < cantidadMangos; i++) {
        std::cout << iterador->peso << std::endl;
        iterador = iterador->siguiente;
    }
}

int ArbolMangos::getSize() {
    return cantidadMangos;
}

Mango* ArbolMangos::get(int posicion) {
    Mango *iterador = first;
    for(int i = 0; i < posicion; i++)
        iterador = iterador->siguiente;
    return iterador;
}
