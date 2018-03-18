//
// Created by jhair on 03-08-18.
//

#ifndef ARBOLBUSQUEDA_NODO_H
#define ARBOLBUSQUEDA_NODO_H


class Nodo {
public:
    int dato;
    Nodo *derecho;
    Nodo *izquierdo;

    int get_Altura();
    Nodo(int);
    bool get_izquierdo();
    bool get_derecho();


};


#endif //ARBOLBUSQUEDA_NODO_H
