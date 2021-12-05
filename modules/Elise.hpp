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
int getOrdonnee();
int getStamina();
int getHeight();
int getWidth();
int getDirX();
int getDirY();


// Setteurs
void setAbscisse(int valeur);
void setOrdonnee(int valeur);
void setWidth(int valeur);
void setHeight(int valeur);
void setStamina(int valeur);
void setDirX(int val);
void setDirY(int val);

//Fonctions
void initialize(Map &map);
void update(Entree &entree, Map &map);
void centerScrolling(Map &map);
void collisionObjets(Map &map);
void drawElise(sf::RenderWindow &window, Map &map);

 
private:
//Variables de la classe en accès privé

// Variable des stats du personnage d'Elise
    int stamina ;

    // Position du sprite d'Elise
    int abscisse, ordonnee ;

    // Dimmension du sprite d'Elise
    int w, h ;

    // Variable utile pour l'affichage
    int etat;
    int enDeplacement ;
    int sensSprite;

    // Variables utiles pour l'animation :
    // Numéro de la frame (= image) en cours + timer
    int frameNumber, frameTimer, frameMax;

    int dirX, dirY; //direction du mouvement

    int mort; //si c'est 0 elle est vivante, si c'est 1 c'est la fin

    int reflexion; // test pour le moment qui permet de flip le sprite


// Animation
const int TEMPS_ENTRE_DEUX_FRAMES = 3;
const int MAXIFRAME = 2;

//Valeurs attribuée aux poses du personnages
const int NEUTRE = 0; //cf etat
const int MARCHE = 1;

const int GAUCHE = 0 ;  //cf sensSprite
const int DROITE = 1 ;
const int HAUT = 2;
const int BAS = 3;

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
const int LIMITE_ORDONNEE = 220;
const int LIMITE_WIDTH = 100;
const int LIMITE_HEIGHT = 80;


const int TILE_SIZE = 32 ;
//Constante pour la vitesse du centerscrolling
const int SCROLL_DISTANCE = 3;

//Constante qui code pour les cases collisionnées
const int DUR = 1;

//Enum pour les entrées
enum{ haut, bas, droite, gauche, entrer };
 
//Background
Texture eliseMarcheTexture ;
Texture eliseNeutreTexture ;
Sprite eliseSprite ;
 };
#endif