#ifndef CARTE_H
#define CARTE_H
 
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "Liste.hpp"
 
 
class Carte
{
 
public:

struct WARPSPE { int value; };

//Constructeur
Carte();

void initialisation() ;


int getBeginX() const;
int getBeginY() const;
int getDebutAbscisse() const;
int getDebutOrdonne() const;
int getMaxX() const;
int getMaxY() const;
int getTile(int y, int x) const;
int getLevel() const;
float getTimer() ;
bool getMenu() ;
/*
int getWarpUp(void) const;
int getWarpDown(void) const;
int getWarpLeft(void) const;
int getWarpRight(void) const;
int getWarpSP(int number) const;
int getWarpDirection(void) const;
int getWarp_coming_from_x(void) const;
int getWarp_coming_from_y(void) const;
*/
 
//Mutateurs
void setLevel(int valeur);
void setDebutAbscisse(int valeur);
void setDebutOrdonne(int valeur);
void setTile(int y, int x, int valeur);
void setBegin(int x, int y);
void setMenu(bool b) ;
/*
void setWarpDirection(int valeur);
void setWarp_coming_from_x(int valeur);
void setWarp_coming_from_y(int valeur);
*/

 
//Fonctions
void loadMap(std::string filename);
void draw(sf::RenderWindow &window);
void drawTimer(sf::RenderWindow &window);
void changeLevel(void);
void testDefilement(void); //fait déffiler la carte toute seule.
void TimerAZero();
std::string decompte();
void creerListeDeCartes();
void nextLevel();
void addTime();
int decompteInt();
bool tempsDepasse();

 
private:

/* Coordonnées de départ du héros, lorsqu'il commence le niveau */
int beginx, beginy;
 
/* Coordonnées de début, lorsqu'on doit draw la map */
int debutAbscisse, debutOrdonne;
 
/* Coordonnées max de fin de la map */
int maxX, maxY;
 
/* Tableau à double dimension représentant la map de tiles */
int tile[160][160];  //maxi 80 par 80 tiles pour le moment
 
//Numéro du niveau en cours
int level;

bool menu ;

//timer
sf::Time timer ;
sf::Time timeMenu ;
int tempsdonne ;
 
//Variable pour testDefilement()
int testdefil;
 
//Nouvelles variabbles
int warpUp, warpDown, warpLeft, warpRight;
WARPSPE warpSP[10];
 
//Pour gérer les warps
int warpDirection;
int warp_coming_from_x;
int warp_coming_from_y;

//gestion de l'animation de la map
sf::Clock frameTimer;
sf::Clock TimerMenu;
 
//Tilesets
sf::Texture tileSetTexture1;  //j'ai bricolé ici alors si c'est cassé c'est normal
sf::Texture tileSetTexture2;  //j'ai bricolé ici alors si c'est cassé c'est normal

//Sprite 
sf::Sprite tileSet1;
sf::Sprite tileSet2;

//Police de caractères
sf::Font font;
 
//au cas ou on aurait besoin d'un hud
sf::Texture HUDTexture;
sf::Sprite HUD;
float HUDtimer;
int HUDDirection;

//liste dynamique chainée de cartes
Liste <int> listeDeCartes;
 
 
/*******************/
/* Constantes */
/******************/
 
// Taille de la fenêtre : 800x480 pixels
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;
 
/* Taille maxi de la map */
const int MAX_MAP_X = 80;
const int MAX_MAP_Y = 80;
 
/* Taille d'une tile (32 x 32 pixels) */
const int TILE_SIZE = 32; 

//temps qu'on donne généreusement à la fin de la complétion d'une map
const int TEMPSSUPPLEMENTAIRE = 15;
 
};
#endif