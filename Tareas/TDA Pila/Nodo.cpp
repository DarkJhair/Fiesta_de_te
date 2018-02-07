#include "Nodo.h"

Nodo::Nodo(double numero) {
    this->numero = numero;
    this->operador = NULL;
    next = NULL;
}

Nodo::Nodo(char operador) {
    this->operador = operador;
    this->numero = NULL;
    next = NULL;
}

Nodo::~Nodo() {

}
