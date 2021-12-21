#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "entree.hpp"

class Menu
{
private:
    bool menuActif ;
    sf::Texture menuTexture;
    sf::Sprite menu;

public:
    Menu();
    void drawMenu( sf:: RenderWindow &window) ;
    void gestionMenu( Entree &entree) ;
    bool getMenuActif() ;
    void setMenuActif( bool b) ;
};



#endif