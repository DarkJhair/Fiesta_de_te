#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Nodo.h"

class Stack {
private:
    Nodo *top;
    bool empty;

public:
    Stack();
    Nodo *getTop();
    void push(double);
    void push(char);
    void operate();
    void pop();
    bool isEmpty();
};



#endif // STACK_H_INCLUDED
