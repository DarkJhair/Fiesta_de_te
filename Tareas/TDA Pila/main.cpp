#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack *numbers = new Stack();
    int option;
    do {
        cout << "1. Insertar numero" << endl;
        cout << "2. Insertar operador" << endl;
        cout << "3. Imprimir pila" << endl;
        cout << "-1 para salir" << endl;
        cout << "Escriba la opcion aqui: ";
        cin >> option;
        cout << "" << endl;
        switch(option) {
            case 1: {
                double number;
                cout << "Insertar numero: ";
                cin >> number;
                numbers->push(number);
                cout << "Se ha insertado el numero a la pila" << endl;
                break;
            }
            case 2: {
                char operador;
                cout << "Insertar operador: ";
                cin >> operador;
                if(operador == '+' || operador == '-' || operador == '*' || operador == '/') {
                    numbers->push(operador);
                    numbers->operate();
                    cout << "Se ha hecho la operacion correspondiente" << endl;
                }
                else
                    cout << "operador invalido" << endl;
                break;
            }
            case 3: {
                cout << "Imprimiendo pila" << endl;
                while(!numbers->isEmpty()) {
                    cout << numbers->getTop()->numero << endl;
                    numbers->pop();
                }
                cout << "La pila se ha vaciado" << endl;
                break;
            }
        }
        cout << "" << endl;
    } while(option != -1);
    return 0;
}
