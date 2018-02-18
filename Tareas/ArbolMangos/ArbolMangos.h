#ifndef ARBOLMANGOS_H_INCLUDED
#define ARBOLMANGOS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Mango.h"

class ArbolMangos {
private:
    sf::Texture t1, t3;
    sf::Sprite tree;
    Mango *first;
    int cantidadMangos;
    int growth; //este atributo tendra el numero 1 o 2, el arbol podra crecer solo si este atributo contiene el numero 1
public:
    ArbolMangos();
    ArbolMangos(int);
    ~ArbolMangos();
    void addMango(int, int, int);
    void addMango(Mango*);
    void insertMango(int, int, int, int);
    void deleteMango(int);
    void printMass();
    int getSize();
    Mango *get(int);
    sf::Sprite getSprite();
    void grow();
    int getGrowth();
};

#endif // ARBOLMANGOS_H_INCLUDED
