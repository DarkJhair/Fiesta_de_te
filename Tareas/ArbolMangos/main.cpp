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
    cout << "\t\tInstrucciones:" << endl;
    cout << "Mueve a black mage con las arrow keys" << endl;
    cout << "Presiona Z para plantar un arbol" << endl;
    cout << "Presiona X para hacer que un arbol crezca" << endl;
    cout << "Click izquierdo en un arbol para agregarle un mango, siempre y cuando el arbol este grande" << endl;
    cout << "Click derecho en un mango para quitarlo de ahi y agregarlo a tu stock" << endl << endl;
    RenderWindow window(sf::VideoMode(1200, 720), "Arboles de mango");
    Texture t, b1, b2, bm;
    t.loadFromFile("images/fondo.png");
    Font font;
    font.loadFromFile("fonts/orange_juice.ttf");
    Text text;
    text.setFont(font);
    text.setColor(Color::Red);
    text.setCharacterSize(100);
    text.setString("Ver la consola");
    text.setPosition(50, 50);
    text.setCharacterSize(20);
    Sprite fondo(t);

    Mage mage;
    ListaArboles arboles;
    ArbolMangos *arbolTemp;
    Mango *mangoTemp;
    while (window.isOpen())
    {
        Event event;
        Vector2i mousePosition = Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(event.type == Event::MouseButtonPressed) {
                for(int i = 0; i < arboles.getSize(); i++) {
                    ArbolMangos *temp = arboles.get(i);
                    if(temp->getSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        if(event.key.code == Mouse::Left) {
                            window.draw(text);
                            window.display();
                            if(temp->getGrowth() == 1)
                                cout << "No puedes agregar mangos ahi, el arbol aun es muy pequeño" << endl << endl;
                            else {
                                int peso;
                                cout << "Escribe el peso del mango que deseas agregar: " << endl;
                                cin >> peso;
                                temp->addMango(peso, mousePosition.x, mousePosition.y);
                                cout << "Se ha agregado el mango exitosamente al arbol" << endl << endl;
                            }
                        }
                        for(int j = 0; j < temp->getSize(); j++) {
                            mangoTemp = temp->get(j);
                            if(mangoTemp->getSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                                if(event.key.code == Mouse::Right) {
                                    mage.stock.push_back(mangoTemp);
                                    arbolTemp->deleteMango(j);
                                    cout << "Se ha quitado el mango del arbol y se ha agregado a tu stock" << endl;
                                }
                            }
                        }
                    }
                }
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
                if(event.key.code == Keyboard::Space) {
                    cout << mage.stock.size() << endl;
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
        for(int i = 0; i < arboles.getSize(); i++) {
            arbolTemp = arboles.get(i);
            window.draw(arbolTemp->getSprite());
            for(int j = 0; j < arbolTemp->getSize(); j++) {
                window.draw(arbolTemp->get(j)->mango);
            }
        }
        window.draw(mage.mageSprite);
        window.display();
    }
    return 0;
}
