#include <iostream>
#include "ArbolMangos.h"

using namespace std;

int main()
{
    ArbolMangos arbol;
    arbol.addMango(4);
    arbol.addMango(5);
    arbol.addMango(2);
    arbol.addMango(8);
    arbol.addMango(10);
    arbol.insertMango(6, 0);
    arbol.deleteMango(1);
    for(int i = 0; i < arbol.getSize(); i++) {
        cout << arbol.get(i)->peso << endl;
    }
    return 0;
}
