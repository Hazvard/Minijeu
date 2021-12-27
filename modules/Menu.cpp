#include "Menu.hpp"

using namespace sf; 
using namespace std;

Menu::Menu(){
    if(!menuTexture.loadFromFile("ressources/Menu.png")){
        cout << "Erreur durant le chargement de l'image"<< endl;
    }else{
        menu.setTexture(menuTexture);
    }

    menuActif = false ;
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