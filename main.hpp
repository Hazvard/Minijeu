#ifndef MAIN_H
#define MAIN_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SFML/Graphics.hpp"
#include "modules/Elise.hpp"
//#include "modules/map.hpp"
#include "modules/entree.hpp"
#include "modules/Carte.hpp"
#include "modules/Menu.hpp"

using namespace sf; // Permet de ne pas écrire sf::
using namespace std;

//Fonctions
void maj(Entree &entree, Carte &map, Elise &elise, Menu &menu);
void draw(sf::RenderWindow &window, Carte &map, Elise &elise, Menu &menu);

// Taille de la fenêtre : 800x600 pixels
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;

#endif