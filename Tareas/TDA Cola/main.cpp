#include <iostream>
#include "Documento.h"
#include "Impresora.h"

using namespace std;

int main() {
    Impresora *impresora = new Impresora;
    impresora->pushDocument(5, false, 1);
    impresora->pushDocument(7, true, 1);
    impresora->pushDocument(2, false, 1);
    impresora->pushDocument(1, false, 1);
    while(!impresora->isEmpty()) {
        cout << impresora->printFront()->numeroPaginas << endl;
        impresora->pop();
    }
    return 0;
}