#include <iostream>
#include "Arbollista.h"
#include "Nodo.h"
using namespace std;

int main() {
    Arbollista  arbol;

    arbol.add_Nodo(8);
    arbol.add_Nodo(3);
    arbol.add_Nodo(10);
    arbol.add_Nodo(1);
    arbol.add_Nodo(6);
    arbol.add_Nodo(14);
    arbol.add_Nodo(4);
    arbol.add_Nodo(7);
    arbol.add_Nodo(13);
    cout<<"Recorrido en Preorden: ";
    arbol.preorden();
    cout<<""<<endl;
    cout<<"Recorrido en Postorden: ";
    arbol.postorden();
    cout<<""<<endl;
    cout<<"Recorrido en Inorden:  ";
    arbol.inorden();

    return 0;
}