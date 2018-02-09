#include "Stack.h"

double sum(double num1, double num2);
double rest(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);

Stack::Stack() {
    top = NULL;
    empty = true;
}

Nodo *Stack::getTop() {
    return top;
}

void Stack::push(double numero) {
    Nodo *nuevo = new Nodo(numero);
    if(top == NULL) {
        top = nuevo;
        empty = false;
    }
    else {
        nuevo->next = top;
        top = nuevo;
    }
}

void Stack::push(char operador) {
    if(empty || top->next == NULL)
        return;
    else {
        if(operador == '+' || operador == '-' || operador == '*' || operador == '/') {
            Nodo *nuevo = new Nodo(operador);
            nuevo->next = top;
            top = nuevo;
        }
    }
}

/*si el numero del nodo que esta encima de la pila es nulo, significa
 * que el nodo contiene un operador, asi que procedera a hacer la
 * operacion aritmetica correspondiente */
void Stack::operate() {
    if(top->numero == NULL) {
        char operador = top->operador;
        pop();
        double num1, num2;
        num1 = top->numero;
        num2 = top->next->numero;
        pop();
        pop();
        switch (operador) {
            case '+' : {
                push(sum(num1, num2));
                break;
            }
            case '-' : {
                push(rest(num1, num2));
                break;
            }
            case '*' : {
                push(multiply(num1, num2));
                break;
            }
            case '/' : {
                if(num2 != 0)
                    push(divide(num1, num2));
                else {
                    push(num2);
                    push(num1);
                }
                break;
            }
        }
    }
}

void Stack::pop() {
    if(!empty) {
        if(top->next == NULL) {
            delete top;
            top = NULL;
            empty = true;
        }
        else {
            Nodo *borrar = top;
            top = borrar->next;
            delete borrar;
        }
    }
}

bool Stack::isEmpty() {
    return empty;
}

double sum(double num1, double num2) {
    return num1 + num2;
}
double rest(double num1, double num2) {
    return num1 - num2;
}
double multiply(double num1, double num2) {
    return num1 * num2;
}
double divide(double num1, double num2) {
    return num1 / num2;
}
