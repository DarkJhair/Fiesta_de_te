#ifndef ARBOLMANGOS_H_INCLUDED
#define ARBOLMANGOS_H_INCLUDED
#include "Mango.h"

class ArbolMangos {
private:
    Mango *first;
    int cantidadMangos;
public:
    ArbolMangos();
    void addMango(int);
    void insertMango(int, int);
    void deleteMango(int);
    void printMass();
    int getSize();
    Mango *get(int);
};



#endif // ARBOLMANGOS_H_INCLUDED
