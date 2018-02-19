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
    double dinero;
    void printMass();

    Mage();
};

Mage::Mage() {
    m.loadFromFile("images/black_mage4.png");
    mageSprite.setTexture(m);
    mageSprite.setPosition(900, 530);
    dinero = 0;
}

void Mage::printMass() {
    for(int i = 0; i < stock.size(); i++)
        cout << stock[i]->peso << endl;
}

void sellMangos(vector<Mango*> mangos, Mage mage) {
    int mass, price;
    mass = mangos[mangos.size()-1]->peso;
    price = 3*price;
    mage.dinero += price;
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
    Texture t, b1, b2, bm; //textures a usar
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

    //objeto que contiene al mago que planta los arboles
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
            //click izquierdo para agregar mangos a un arbol, click derecho para quitar los mangos de un arbol
            if(event.type == Event::MouseButtonPressed) {
                for(int i = 0; i < arboles.getSize(); i++) {
                    ArbolMangos *temp = arboles.get(i);
                    if(temp->getSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        if(event.key.code == Mouse::Left) {
                            window.draw(text);
                            window.display();
                            if(temp->getGrowth() == 1)
                                cout << "No puedes agregar mangos ahi, el arbol aun es muy peque�o" << endl << endl;
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
                                    cout << "Se ha quitado el mango del arbol y se ha agregado a tu stock" << endl << endl;
                                }
                            }
                        }
                    }
                }
            }
            if(event.type == Event::KeyPressed) {
                if(event.key.code == Keyboard::Left)
                    mage.mageSprite.move(-5, 0);
                if(event.key.code == Keyboard::Right)
                    mage.mageSprite.move(5, 0);
                if(event.key.code == Keyboard::V) {
                    if(mage.stock.size() == 0)
                        cout << "No puedes vender mangos, ya que no has bajado ninguno" << endl << endl;
                    else {
                        int option;
                        cout << "Deseas vender todos tus mangos?" << endl;
                        cout << "1. Si\n2.No" << endl;
                        cin >> option;
                        if(option == 1) {
                            cout << "coming soon" << endl << endl;
                        }
                    }
                }
                if(event.key.code == Keyboard::Z) {
                    ArbolMangos* arbol = new ArbolMangos(mage.mageSprite.getPosition().x);
                    arboles.addArbol(arbol);
                }
                if(event.key.code == Keyboard::Space) {
                    cout << "A continuacion se mostrara cuantos mangos has recogido de tus arboles" << endl;
                    cout << "Tienes en tu inventario " << mage.stock.size() << " mangos" << endl;
                    cout << "Tu dinero es: " << mage.dinero << endl << endl;
                }
                for(int i = 0; i < arboles.getSize(); i++) {
                    arbolTemp = arboles.get(i);
                    if(event.key.code == Keyboard::X) {
                        if(mage.mageSprite.getGlobalBounds().contains(arbolTemp->getSprite().getPosition().x, arbolTemp->getSprite().getPosition().y))
                            arbolTemp->grow();
                    }
                    if(event.key.code == Keyboard::C) {
                        if(mage.mageSprite.getGlobalBounds().contains(arbolTemp->getSprite().getPosition().x, arbolTemp->getSprite().getPosition().y)) {
                            if(arbolTemp->getSize() == 0) {
                                arboles.deleteArbol(i);
                            }
                            else {
                                cout << "No puedes quitar el arbol sin antes haber bajado los mangos de ahi" << endl << endl;
                            }
                        }
                        if(arbolTemp->getSprite().getGlobalBounds().contains(mage.mageSprite.getPosition().x, mage.mageSprite.getPosition().y)) {
                            if(arbolTemp->getSize() == 0) {
                                arboles.deleteArbol(i);
                            }
                            else {
                                cout << "No puedes quitar el arbol sin antes haber bajado los mangos de ahi" << endl << endl;
                            }
                        }
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
