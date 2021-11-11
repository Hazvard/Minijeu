#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

 
#ifndef HANDLEEVENT_H
#define HANDLEEVENT_H
 
using namespace sf;

class HandleEvent{
    
public:
 
//Constructeur
HandleEvent();
 
//Fonctions

int walk(sf::Sprite elise, float pas);  //renvoie 0 si OK, -1 si on doit scroller vers la gauche et 1 vers la droite
 
 
private:
};
#endif