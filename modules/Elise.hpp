#ifndef ELISE_H
#define ELISE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "map.hpp"
#include "entree.hpp"


 
using namespace sf; // Permet de ne pas écrire sf::
using namespace std;

class Map;
class Input;
class Elise{

public:

    struct coordonnee{
        int x, y ;
    } ;





 
//Constructeur ---------------------------------------
Elise();
 
//Fonctions ------------------------------------------

// Getteurs
int getAbscisse();
int getOrdonne();
int getStamina();
int getHeight();
int getWidth();


// Setteurs
void setAbscisse(int valeur);
void setOrdonne(int valeur);
void setWidth(int valeur);
void setHeight(int valeur);
void setStamina(int valeur);

//Fonctions
void initialize(Map &map);
void draw(Map &map, sf::RenderWindow &window);
void update(Entree &entree, Map &map);






void drawElise(sf::RenderWindow &window, Map &map);


void centerScrolling(Map &map);
void collisionObjets(Map &map);
 
private:
//Variables de la classe en accès privé

// Variable des stats du personnage d'Elise
    int stamina ;

    // Position du sprite d'Elise
    int abscisse, ordonne ;

    // Dimmension du sprite d'Elise
    int w, h ;

    // Variable utile pour l'affichage
    int etat, direction ;
    int enDeplacement ;
    // Variables utiles pour l'animation :
    // Numéro de la frame (= image) en cours + timer
    int frameNumber, frameTimer, frameMax;





// Animation
const int TEMPS_ENTRE_DEUX_FRAMES = 3;

//Valeurs attribuée aux poses du personnages
const int NEUTRE = 0;
const int MARCHE = 1;

const int RIGHT = 0 ;
const int LEFT = 0 ;

// Taille du sprite de notre héros (largeur = width et hauteur = heigth)
const int ELISE_WIDTH = 40;
const int ELISE_HEIGTH = 48;

//Vitesse de déplacement en pixels du sprite
const int ELISE_SPEED = 3 ;

// Les limites de jeux 
// Taille de la fenêtre :
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;
 
//Constantes pour les limites de la caméra avant scrolling
const int LIMITE_ABSCISSE = 400;
const int LIMITE_ORDONNE = 220;
const int LIMITE_WIDTH = 100;
const int LIMITE_HEIGHT = 80;

//Enum pour les entrées
enum{ haut, bas, droite, gauche, entrer };
 
//Background
Texture eliseMarcheTexture[8] ;
Texture eliseNeutreTexture[8] ;
Sprite eliseSprite ;
 };
#endif