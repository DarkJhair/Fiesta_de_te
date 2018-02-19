#include "Mango.h"
#include "ArbolMangos.h"

using namespace sf;

ArbolMangos::ArbolMangos() {
}

ArbolMangos::ArbolMangos(int x) {
    t1.loadFromFile("images/arbol.png");
    t3.loadFromFile("images/arbol3.png");
    tree.setTexture(t1);
    tree.setPosition(x, 600);
    first = NULL;
    cantidadMangos = 0;
    growth = 1;
}

ArbolMangos::~ArbolMangos() {
}

void ArbolMangos::addMango(int peso, int x, int y) {
    if(growth == 2)
        insertMango(peso, cantidadMangos, x, y);
}

void ArbolMangos::addMango(Mango *mango) {
    if(first == NULL)
        first = mango;
    else {
        Mango *iterador = first;
        for(int i = 0; i < cantidadMangos-1; i++)
            iterador = iterador->siguiente;
        iterador->siguiente = mango;
    }
    cantidadMangos++;
}

void ArbolMangos::insertMango(int peso, int posicion, int x, int y) {
    if(posicion < 0 || posicion > cantidadMangos)
        return;
    Mango *nuevo = new Mango(peso, x, y);
    if(posicion == 0 && first == NULL) {
        first = nuevo;
        cantidadMangos++;
    }
    else if(posicion == 0 && first != NULL) {
        nuevo->siguiente = first;
        first = nuevo;
        cantidadMangos++;
    }
    else {
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
            iterador->siguiente->anterior = nuevo;
            nuevo->anterior = iterador;
            nuevo->siguiente = iterador->siguiente;
            iterador->siguiente = nuevo;
            cantidadMangos++;
        }
    }
}

void ArbolMangos::deleteMango(int posicion) {
    if(posicion < 0 || posicion > cantidadMangos || cantidadMangos == 0)
        return;
    Mango *borrar;
    if(cantidadMangos == 1) {
        borrar = first;
        first = NULL;
    }
    else if(posicion == 0) {
        borrar = first;
        first = first->siguiente;
    }
    else if(posicion == cantidadMangos - 1) {
        Mango *iterador = first;
        for(int i = 0; i < posicion - 1; i++)
            iterador = iterador->siguiente;
        borrar = iterador->siguiente;
        delete borrar;
        iterador->siguiente = NULL;
    }
    else {
        Mango *iterador = first;
        for(int i = 0; i < posicion - 1; i++)
            iterador = iterador->siguiente;
        borrar = iterador->siguiente;
        iterador->siguiente = borrar->siguiente;
        borrar->siguiente->anterior = iterador;
    }
    delete borrar;
    cantidadMangos--;
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

Sprite ArbolMangos::getSprite() {
    return tree;
}

void ArbolMangos::grow() {
    if(growth == 1) {
        tree.setTexture(t3);
        tree.setPosition(tree.getPosition().x, 300);
        tree.setTextureRect(IntRect(0, 0, 180, 350));
        growth++;
    }
}

int ArbolMangos::getGrowth() {
    return growth;
}
