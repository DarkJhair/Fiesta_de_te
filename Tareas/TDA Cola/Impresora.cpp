#include "Impresora.h"

Impresora::Impresora() {
    front = NULL;
    back = NULL;
    empty = true;
}

void Impresora::pushDocument(int numeroPaginas, bool blancoYnegro, int pageSize) {
    Documento *nuevo = new Documento(numeroPaginas, blancoYnegro, pageSize);
    if(empty) {
        front = nuevo;
        back = nuevo;
        empty = false;
    }
    else {
        nuevo->next = back;
        back = nuevo;
    }
}

Documento* Impresora::getBack() {
    return back;
}

Documento* Impresora::printFront() {
    return front;
}

void Impresora::pop() {
    if (!empty) {
        Documento *iterador = back;
        if (front == back) {
            delete iterador;
            front = NULL;
            back = NULL;
            empty = true;
        } else {
            while (iterador->next != front)
                iterador = iterador->next;
            Documento *borrar = iterador->next;
            front = iterador;
            front->next = NULL;
            delete borrar;
        }
    }
}

bool Impresora::isEmpty() {
    return empty;
}

