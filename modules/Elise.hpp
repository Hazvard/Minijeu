#ifndef ELISE_H
#define ELISE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

 
using namespace sf; // Permet de ne pas écrire sf::
using namespace std;
 
class Elise{

public:
 
//Constructeur ---------------------------------------
Elise();
 
//Fonctions ------------------------------------------
void drawElise(sf::RenderWindow &window, int numTexture, int pose );
 
 
private:
//Variables de la classe en accès privé
 
//Background
Texture eliseMarcheTexture[8] ;
Texture eliseNeutreTexture[8] ;
Sprite eliseSprite ;
 };
#endif