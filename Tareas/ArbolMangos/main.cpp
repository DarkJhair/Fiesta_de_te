#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Mango.h"
#include "ListaArboles.h"
#include "ArbolMangos.h"

using namespace std;
using namespace sf;


struct Mage {
    Texture m;
    Sprite mageSprite;
    vector<Mango*> stock;

    Mage();
};

Mage::Mage() {
    m.loadFromFile("images/black_mage4.png");
    mageSprite.setTexture(m);
    mageSprite.setPosition(900, 530);
}

int main()
{
    cout << "\tInstrucciones:" << endl;
    cout << "Click derecho en un arbol para hacer que crezca" << endl;
    cout << "Click izquierdo en un arbol para agregar un mango en el" << endl << endl;
    RenderWindow window(sf::VideoMode(1200, 720), "Arboles de mango");
    Texture t, b1, b2, bm;
    t.loadFromFile("images/fondo.png");
    b1.loadFromFile("images/plant.png");
    b2.loadFromFile("images/cut.png");
    Sprite fondo(t);
    Sprite button1(b1);
    button1.setPosition(20, 20);
    Sprite button2(b2);
    button2.setPosition(900, 20);

    Mage mage;
    ListaArboles arboles;

    while (window.isOpen())
    {
        Event event;
        Vector2i mousePosition = Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(event.type == Event::MouseButtonPressed) {
                //if(event.key.code == Mouse::Right)

                //if(event.key.code == Mouse::Left)

            }
            if(event.type == Event::KeyPressed) {
                if(event.key.code == Keyboard::Left)
                    mage.mageSprite.move(-5, 0);
                if(event.key.code == Keyboard::Right)
                    mage.mageSprite.move(5, 0);
                if(event.key.code == Keyboard::Z) {
                    ArbolMangos* arbol = new ArbolMangos(mage.mageSprite.getPosition().x);
                    arboles.addArbol(arbol);
                }
                for(int i = 0; i < arboles.getSize(); i++) {
                    ArbolMangos *temp = arboles.get(i);
                    if(mage.mageSprite.getGlobalBounds().contains(temp->getSprite().getPosition().x, temp->getSprite().getPosition().y)) {
                        if(event.key.code == Keyboard::X)
                            temp->grow();
                    }
                }
            }
        }
        window.clear();
        window.draw(fondo);
        window.draw(button1);
        window.draw(button2);
        for(int i = 0; i < arboles.getSize(); i++) {
            window.draw(arboles.get(i)->getSprite());
        }
        window.draw(mage.mageSprite);
        window.display();
    }
    return 0;
}
