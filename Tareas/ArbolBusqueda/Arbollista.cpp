//
// Created by jhair on 03-08-18.
//

#include "Arbollista.h"
#include <iostream>

using namespace std;

Arbollista::Arbollista() {

    this->raiz= NULL;

}

void Arbollista::add_Nodo(int numero) {
    Nodo *nuevo = new Nodo(numero);
    add_Nodo(nuevo,&raiz);

}

void Arbollista::add_Nodo(Nodo * nuevo, Nodo **subraiz) {
    if(*subraiz==NULL){
        *subraiz=nuevo;
    }
    else if((*subraiz)->dato > nuevo->dato){
        add_Nodo(nuevo,&(*subraiz)->izquierdo);

    }else if((*subraiz)->dato < nuevo->dato){
        add_Nodo(nuevo,&(*subraiz)->derecho);

    }
}

//Funcion para imprimir la lista en modo preorden
void Arbollista::preorden() {
    preorden(raiz);
}

void Arbollista::preorden(Nodo *nuevo) {

    cout <<nuevo->dato<<" , ";
    if(nuevo->get_izquierdo()){
        preorden(nuevo->izquierdo);
    }
    if(nuevo->derecho){
        preorden(nuevo->derecho);
}

}

//Imprimir la lista de manera posorden
void Arbollista::postorden() {
    posorden(raiz);
}

void Arbollista::posorden(Nodo *nuevo) {
    if(nuevo->get_izquierdo()){
        posorden(nuevo->izquierdo);
    }
    if (nuevo->get_derecho()){
        posorden(nuevo->derecho);
    }
    cout<<nuevo->dato<<" , ";
}

//Imprimir reocorrido en Inorden
void Arbollista::inorden() {
    inorden(raiz);
}

void Arbollista::inorden(Nodo *nuevo) {
    if(nuevo->get_izquierdo()){
        inorden(nuevo->izquierdo);
    }
    cout<<nuevo->dato<<" , ";
    if (nuevo->get_derecho()){
        inorden(nuevo->derecho);
    }

}

































