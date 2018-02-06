#include "Documento.h"

Documento::Documento(int numeroPaginas, bool blancoYnegro, int pageSize) {
    this->numeroPaginas = numeroPaginas;
    this->blancoYnegro = blancoYnegro;
    this->pageSize = pageSize;
    next = NULL;
}

Documento::~Documento() {
}

