#include "Menu.hpp"

using namespace sf; 
using namespace std;

Menu::Menu(){
    if(!menuTexture.loadFromFile("ressources/Menu.png")){
        cout << "Erreur durant le chargement de l'image"<< endl;
    }else{
        menu.setTexture(menuTexture);
    }

    if(!finTexture.loadFromFile("ressources/fin.png")){
        cout << "Erreur durant le chargement de l'image"<< endl;
    }else{
        fin.setTexture(finTexture);
    }

    menuActif = gameover = false ;
}


void Menu::drawMenu( sf:: RenderWindow &window){
    if(menuActif){
        window.draw(menu) ;
    }

}
void Menu::gestionMenu( Entree &entree){
    menuActif = entree.getMenu() ;
    
}

bool Menu::getMenuActif(){
    return menuActif ;
}

void Menu::setMenuActif( bool b){
    menuActif = b ;
}



void Menu::drawFin( sf:: RenderWindow &window){
    if(gameover){
        window.draw(fin) ;
    }

}

bool Menu::getFinActif(){
    return gameover ;
}

void Menu::setFinActif( bool b){
    gameover = b ;
}