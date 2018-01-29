#include <iostream>

using namespace std;

int main()
{
    //variable de tipo int normal
    int a = 10;
    //guardar la direccion de memoria de la variable de arriba en un apuntador
    int *b = &a;
    //guardando el numero 6 en un apuntador
    int *intPtr = new int(6);
    //guardando la direccion de memoria del apuntador de arriba en un doble apuntador
    int **doublePointer = &intPtr;

    cout << "imprimiendo direccion en memoria de a: "<< &a << endl;
    cout << "imprimiendo b: " << b << endl;
    cout << "imprimiendo b desreferenciado: " << *b << endl;
    cout << "imprimiendo intPtr: " << intPtr << endl;
    cout << "imprimiendo intPtr desreferenciado: " << *intPtr << endl;
    cout << "imprimiendo direccion en memoria del apuntador: " <<&intPtr << endl;
    cout << "imprimiendo doublePointer: " << doublePointer << endl;
    cout << "imprimiendo doublePointer desreferenciado: " << *doublePointer << endl;
    cout << "imprimiendo doublePointer doblemente desreferenciado: " << **doublePointer << endl;

    return 0;
}
