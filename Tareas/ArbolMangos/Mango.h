#ifndef MANGO_H_INCLUDED
#define MANGO_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

struct Mango {
    sf::Texture t1;
    sf::Sprite mango;
    Mango *anterior;
    Mango *siguiente;
    int peso;
    Mango(int, int, int);
    sf::Sprite getSprite();
    ~Mango();
};

#endif // MANGO_H_INCLUDED
