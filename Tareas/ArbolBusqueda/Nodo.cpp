//
// Created by jhair on 03-08-18.
//

#include "Nodo.h"
#include <iostream>


Nodo::Nodo(int dato) {
    this->dato=dato;
    this->izquierdo=NULL;
    this->derecho=NULL;
}

int Nodo::get_Altura() {

}

bool Nodo::get_izquierdo() {

    if(izquierdo==NULL){
        return false;
    }
    return (izquierdo!=NULL);

}
bool Nodo::get_derecho()  {

    if( derecho==NULL){
        return false;
    }
    return (derecho!=NULL);

}
