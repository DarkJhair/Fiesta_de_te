#ifndef MAGE_H_INCLUDED
#define MAGE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <stack>
#include "Mango.h"

struct Mage {
    sf::Texture m;
    sf::Sprite mageSprite;
    std::stack<Mango*> stock;
    int dinero;
    void printMass();
    void sellMangos();
    Mage();
};



#endif // MAGE_H_INCLUDED
