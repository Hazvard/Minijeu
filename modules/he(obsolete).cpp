#include "handleevent.hpp"
 
using namespace std;
using namespace sf;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float HAUTEUR_PIECE = 200;  //fonctionne que si toutes les pieces ont la meme hauteur

HandleEvent::HandleEvent(){ //constructeur
	
}

int HandleEvent::walk(sf::Sprite elise, float pas){  //0: OK; -1: bouger vers la gauche; 1: vers la droite
    float posx;
    float posy;
    sf::Vector2f position;
    float sizex = elise.getTexture()->getSize().x * elise.getScale().x;
    float sizey = elise.getTexture()->getSize().y * elise.getScale().y; 



    //Correction de potentielles erreurs de placement:
    position = elise.getPosition();
    posy = position.y;
    posx = position.x;

    if(posx < HAUTEUR_PIECE){ //Elise trop haut
        elise.setPosition(posx, HAUTEUR_PIECE); //rectification de position au cas où elise soit encastrée dans le mur
    }

    if((posy + sizey) > SCREEN_HEIGHT){ //Elise trop bas
        elise.setPosition(posx, SCREEN_HEIGHT - sizey);
    }

    if(posx < 100){ //Elise trop à gauche
        elise.setPosition(100, posy);
    }



	//Tentative de mouvement d'élise:
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ //fleche gauche
        position = elise.getPosition();
        posy = position.y;
        posx = position.x;

        if((posx-pas) > 100){
            elise.move(sf::Vector2f((-1)*pas, 0.f));
        }
        else{
            return -1;
        }

        if(posx < 100){
            elise.setPosition(100, posy);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){ //fleche droite
        position = elise.getPosition();
        posy = position.y;
        posx = position.x;

        if((posx+pas) < (SCREEN_WIDTH - 100)){
            elise.move(sf::Vector2f(pas, 0.f));  //vector2f(abscisse float, ordonnée float)
        }
        else{
            return 1;
        }

        if(posx > (SCREEN_WIDTH - 100)){
            elise.setPosition(SCREEN_WIDTH - 100, posy);
        }
        
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //fleche haut
        position = elise.getPosition();
        posy = position.y;
        posx = position.x;

        if((posy - pas) > HAUTEUR_PIECE){  // (0,0) est en haut à gauche de la fenetre, pos du sprite fixée par son point en haut à gauche
            elise.move(sf::Vector2f(0.f, (-1)*pas));
        }

        if(posx < HAUTEUR_PIECE){
            elise.setPosition(posx, HAUTEUR_PIECE);
        }

        return 0; 
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ //fleche bas
        position = elise.getPosition();
        posy = position.y;
        posx = position.x;

        if((posy + pas + sizey) < SCREEN_HEIGHT){
            elise.move(sf::Vector2f(0.f, pas));  
        }

        if((posy + sizey) > SCREEN_HEIGHT){
            elise.setPosition(posx, SCREEN_HEIGHT - sizey);
        }

        return 0;     	
    }

    return 0; //Rien n'a été fait, donc rien ne bouge
}

