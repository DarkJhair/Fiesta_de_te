#ifndef MANGO_H_INCLUDED
#define MANGO_H_INCLUDED

#include <iostream>

struct Mango {
    Mango *anterior;
    Mango *siguiente;
    int peso;
    Mango(int);
    ~Mango();
};



#endif // MANGO_H_INCLUDED
