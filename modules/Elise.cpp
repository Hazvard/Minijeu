#include "Elise.hpp"
 
using namespace std;
using namespace sf;
 
//Constructeur ------------------------------------------------------------------------------
Elise::Elise(){

	eliseSprite.setScale(sf::Vector2f(0.5, 0.5));
	eliseSprite.setPosition(sf::Vector2f(10.f, 50.f));

    //Chargement des ressources graphiques

    for(int i = 0 ; i < 8 ; i++){
	    if (!eliseMarcheTexture[i].loadFromFile("ressources/Elise_marche.png", sf::IntRect(320 * i, 0 , 320, 320))){
		    std::cout <<"Erreur de load de la texture" << std::endl;
	    }
    }
    
    for(int i = 0 ; i < 8 ; i++){
	    if (!eliseNeutreTexture[i].loadFromFile("ressources/Elise_neutre.png", sf::IntRect(320 * i, 0 , 320, 320))){
		    std::cout <<"Erreur de load de la texture" << std::endl;
	    }
    }

}
 
//Fonctions ---------------------------------------------------------------------------------

void Elise::drawElise(sf::RenderWindow &window, int numTexture, int pose ){

    if(pose == 2) // Marche gauche
        eliseSprite.setTexture( eliseMarcheTexture[numTexture] ) ;

    if(pose == 1) // Marche droite
        eliseSprite.setTexture( eliseMarcheTexture[numTexture] ) ;

    if(pose == 0) // Neutre
        eliseSprite.setTexture( eliseNeutreTexture[numTexture] ) ;

    window.draw(eliseSprite) ;
}