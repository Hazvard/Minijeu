 #include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

 
#ifndef CARTE_H
#define CARTE_H
 
 using namespace sf; // Permet de ne pas écrire sf::
 
class Carte{
    
public:
 
//Constructeur
Carte();
 
//Fonctions
void drawBackground(sf::RenderWindow &window);
 
 
private:
//Variables de la classe en accès privé
 
//Background
Texture backgroundTexture;
Sprite background;
 
};
#endif