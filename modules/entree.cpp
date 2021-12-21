#include "entree.hpp"
 
using namespace std;
using namespace sf;
 
//Constructeur
Entree::Entree(){
    touche.gauche = touche.droite = touche.haut = touche.bas = touche.entrer = touche.P = false;
}
 
 
//Getteurs
Entree::Touche Entree::getTouche(void) const {
     return touche ;
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
    }
}
 
 
//Fonctions
void Entree::gestionEntrees(RenderWindow &renderwindow){
    
    //Pour l'instant, cette fonction n'est donc pas utile sauf si on rajoute une mannette.
    getEntree(renderwindow);
}
 
 
void Entree::getEntree(RenderWindow &renderwindow){
 
    // Continue jusqu'à avoir tout traité
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
                    
                    case Keyboard::P:
                        touche.P = true ;
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
                        touche.P = true ;
                        break;
 
                    default:
                        break;
                }
                break;
 
                // on ne traite pas les autres types d'évènements
            default:
                break;
        }
    }
}