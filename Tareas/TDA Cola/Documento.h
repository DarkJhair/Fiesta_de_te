#ifndef TDA_COLA_DOCUMENTO_H
#define TDA_COLA_DOCUMENTO_H

#include <iostream>

struct Documento {
    int numeroPaginas;
    bool blancoYnegro;
    int pageSize;
    Documento *next;

    Documento(int, bool, int);
    ~Documento();
};



#endif //TDA_COLA_DOCUMENTO_H
