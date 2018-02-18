#include "Mango.h"

using namespace sf;

Mango::Mango(int peso, int x, int y) {
    t1.loadFromFile("images/mango.png");
    mango.setTexture(t1);
    mango.setPosition(x, y);
    this->peso = peso;
    anterior = NULL;
    siguiente = NULL;
}

Sprite Mango::getSprite() {
    return mango;
}

Mango::~Mango() {
}
