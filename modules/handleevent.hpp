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

void walk(sf::Sprite elise, float pas);
 
 
private:
};
#endif