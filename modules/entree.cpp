#include "entree.hpp"
#include <cstdlib>
 
using namespace std;
using namespace sf;
 
//Constructeur
Entree::Entree(){
    touche.gauche = touche.droite = touche.haut = touche.bas = touche.entrer = touche.P = touche.C = touche.E = menu = switchSkin = recommencer = false;
    elise = true ;
}
 

void Entree::initialisation(){
    touche.gauche = touche.droite = touche.haut = touche.bas = touche.entrer = touche.P = touche.C = touche.E = menu = switchSkin = recommencer = false;
    elise = true ;
}
 
//Getteurs
Entree::Touche Entree::getTouche(void) const {
     return touche ;
}

bool Entree::getMenu(){
    return menu ;
}

bool Entree::getswitchSkin(){
    return switchSkin ;
}

bool Entree::getElise(){
    return elise ;
}

void Entree::setMort(bool b){
    mort = b ;
}

bool Entree::getMort(){
    return mort ;
}
 
 bool Entree::getRecommencer(){
     return recommencer ;
 }


 
//Setteurs
void Entree::setTouche(int touches, bool appuyee){
    switch (touches){
        case haut:
            touche.haut = appuyee ;
            break;
 
        case bas:
            touche.bas = appuyee ;
            break;
 
        case droite:
            touche.droite = appuyee ;
            break;
 
        case gauche:
            touche.gauche = appuyee ;
            break;

        case entrer:
            touche.entrer = appuyee ;
            break;

        case P:
            touche.P = appuyee ;
            break;
        case C:
            touche.C = appuyee ;
            break;
        case E:
            touche.E = appuyee ;
            break;
    }
}

void Entree::setRecommencer(bool b){
    recommencer = b ;
}
 
 
//Fonctions
void Entree::gestionEntrees(RenderWindow &renderwindow){
    
    //Pour l'instant, cette fonction n'est donc pas utile sauf si on rajoute une mannette.
    getEntree(renderwindow);
}
 
 
void Entree::getEntree(RenderWindow &renderwindow){


    if( sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        positionSouris = sf::Mouse::getPosition(renderwindow) ;
        
        if(menu){

            if(positionSouris.x > 486 && positionSouris.x < 723 && positionSouris.y > 75 && positionSouris.y < 147) // Case jouer
                menu = false ;

            if(positionSouris.x > 486 && positionSouris.x < 723 && positionSouris.y > 178 && positionSouris.y < 251) // Case recomencer
                recommencer = true ;

            if(positionSouris.x > 486 && positionSouris.x < 723 && positionSouris.y > 284 && positionSouris.y < 361) // Case quitter
                renderwindow.close();

        }else if(mort){
            if(positionSouris.x > 486 && positionSouris.x < 723 && positionSouris.y > 178 && positionSouris.y < 251) // Case recomencer
                recommencer = true ;

            if(positionSouris.x > 486 && positionSouris.x < 723 && positionSouris.y > 284 && positionSouris.y < 361) // Case quitter
                renderwindow.close();
        }
    }
 
    // Continue jusqu'?? avoir tout trait??
    while (renderwindow.pollEvent(event)){

        switch (event.type){

            // On appuie sur la croix de la fenetre
            case Event::Closed:
                renderwindow.close();
                break;
 
            // On appuie sur la touche
            case Event::KeyPressed:
                switch (event.key.code){

                    case Keyboard::Escape:
                        renderwindow.close();
                        break;
 
                    case Keyboard::Left:
                        touche.gauche = true;
                        break;
 
                    case Keyboard::Right:
                        touche.droite = true;
                        break;
 
                    case Keyboard::Down:
                        touche.bas= true;
                        break;
 
                    case Keyboard::Up:
                        touche.haut = true;
                        break;
 
 
                    case Keyboard::Return:
                        touche.entrer = true;
                        break;

                    case Keyboard::C:
                        touche.C = true;
                        switchSkin = true ;
                        elise = false ;
                        break;

                    case Keyboard::E:
                        touche.E = true;
                        switchSkin = true ;
                        elise = true ;
                        break;
                    
                    case Keyboard::P:
                        touche.P = true ;
                        if(!menu)
                            menu = true ;
                        else
                            menu = false ;

                        break;
 
                    default:
                        break;
                }
                break;
 
            // On relache la touche
            case Event::KeyReleased:
                switch (event.key.code){
 
                    case Keyboard::Left:
                        touche.gauche = false;
                        break;
                        
                    case Keyboard::Right:
                        touche.droite = false;
                        break;
                        
                    case Keyboard::Down:
                        touche.bas = false;
                        break;
                    
                    case Keyboard::Up:
                        touche.haut = false;
                        break;
                                
                    case Keyboard::Return:
                        touche.entrer = false;
                        break;
                    
                    case Keyboard::P:
                        touche.P = false ;
                        break;
                    
                    case Keyboard::C:
                        touche.C = false ;
                        switchSkin = false ;
                        break;
                    
                    case Keyboard::E:
                        touche.E = false ;
                        switchSkin = false ;
                        break;

                    default:
                        break;
                }
                break;
 
                // on ne traite pas les autres types d'??v??nements
            default:
                break;
        }
    }
}