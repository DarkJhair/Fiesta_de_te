#include "Mage.h"

using namespace std;
using namespace sf;

Mage::Mage() {
    m.loadFromFile("images/black_mage4.png");
    mageSprite.setTexture(m);
    mageSprite.setPosition(900, 530);
    dinero = 0;
}

/*
void Mage::printMass() {
    for(int i = 0; i < stock.size(); i++)
        cout << stock[i]->peso << endl;
}
*/
void Mage::sellMangos() {
    int mass, price;
    while(!stock.empty()) {
        mass = stock.top()->peso;
        price = 3*price;
        dinero += price;
        stock.pop();
    }
}
