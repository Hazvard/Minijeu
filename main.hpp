#ifndef MAIN_H
#define MAIN_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SFML/Graphics.hpp"
#include "modules/carte.hpp"
#include "modules/Elise.hpp"
#include "modules/map.hpp"
#include "modules/entree.hpp"

using namespace sf; // Permet de ne pas écrire sf::
using namespace std;

//Fonctions
void maj(Entree &entree,Map &map, Elise &elise);
void draw(sf::RenderWindow &window, Map &map, Elise &elise);

// Taille de la fenêtre : 800x600 pixels
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;

#endif