#include "carte.hpp"
 
using namespace std;
using namespace sf;
 
//Constructeur ------------------------------------------------------------------------------
Carte::Carte(){
    //Chargement des ressources graphiques
    //Chargement du background
    if ( !backgroundTexture.loadFromFile( "ressources/fond1.png" ) ) {
        cout << "Erreur durant le chargement de l'image de background." << endl; // Erreur
    } else {
        background.setTexture( backgroundTexture ) ;
    }
}
 
//Fonctions ---------------------------------------------------------------------------------
 
void Carte::drawBackground(RenderWindow &window){
    window.draw(background);
}