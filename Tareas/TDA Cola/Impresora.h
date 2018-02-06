#ifndef TDA_COLA_IMPRESORA_H
#define TDA_COLA_IMPRESORA_H

#include "Documento.h"

class Impresora {
private:
    Documento *front;
    Documento *back;
    bool empty;

public:
    Impresora();
    void pushDocument(int, bool, int);
    Documento* getBack();
    Documento* printFront();
    void pop();
    bool isEmpty();
};

#endif //TDA_COLA_IMPRESORA_H
