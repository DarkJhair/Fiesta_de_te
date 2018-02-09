#include <iostream>
#include "ArbolMangos.h"

using namespace std;

int main()
{
    ArbolMangos arbol;
    arbol.addMango(4);
    cout << "size" << arbol.getSize() << endl;
    arbol.addMango(5);
    cout << "size" << arbol.getSize() << endl;
    arbol.addMango(2);
    cout << "size" << arbol.getSize() << endl;
    arbol.addMango(8);
    cout << "size" << arbol.getSize() << endl;
    arbol.addMango(10);
    cout << "size" << arbol.getSize() << endl;
    arbol.insertMango(6, 0);
    cout << "size" << arbol.getSize() << endl;
    //arbol.deleteMango(3);
    for(int i = 0; i < arbol.getSize(); i++) {
        cout << arbol.get(i)->peso << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
