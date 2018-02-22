#include "Mage.h"

using namespace std;
using namespace sf;

Mage::Mage() {
    m.loadFromFile("images/black_mage4.png");
    mageSprite.setTexture(m);
    mageSprite.setPosition(900, 530);
    dinero = 0;
}

void Mage::sellMangos() {
    int mass, price;
    while(!stock.empty()) {
        mass = stock.top()->peso;
        cout << "masa es: " << mass << endl;
        price = mass*3;
        cout << "el precio es: " << price << endl;
        dinero += price;
        cout << "dinero es: " << dinero << endl;
        stock.pop();
    }
}
