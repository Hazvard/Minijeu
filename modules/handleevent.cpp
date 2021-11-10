#include "handleevent.hpp"
 
using namespace std;
using namespace sf;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int ELISE_SIZE = 100;

HandleEvent::HandleEvent(){ //constructeur
	
}

void HandleEvent::walk(sf::Sprite elise, float pas){
    float posx;
    float posy;
    sf::Vector2f newpos;
	//Tentative de mouvement d'élise
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ //fleche gauche
        elise.move(sf::Vector2f((-1)*pas, 0.f));  //déplacement relatif à la position absolue
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){ //fleche droite
        elise.move(sf::Vector2f(pas, 0.f));  //vector (abscisse float ordonnée float)
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //fleche haut
        //si la position d'elise est trop basse
        sf::Vector2f position = elise.getPosition();
        posy = position.y;
        if((posy + ELISE_SIZE) > SCREEN_HEIGHT){

        }
        elise.move(sf::Vector2f(0.f, (-1)*pas));  //ATTENTION Ordonnée orientée vers le bas
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ //fleche bas
     	elise.move(sf::Vector2f(0.f, pas));  
    }
}

