#ifndef ENTREE_H
#define ENTREE_H
 
#include <SFML/Graphics.hpp>
#include <iostream>
 
 
class Entree{
 
    //Structures
    struct Touche { 
        bool gauche; 
        bool droite; 
        bool haut;
        bool bas;
        bool entrer; 
        bool P;
        bool C;
        bool E;
    };
    
    public:
    
    //Constructeur
    Entree();
    
    //Getteurs
    Touche getTouche(void) const;
    bool getMenu();
    bool getMort();
    bool getswitchSkin();
    bool getElise() ;
    
    //Setteurs
    void setTouche(int touches, bool appuyee);
    void setMort(bool b);
    
    //Fonctions
    void gestionEntrees(sf::RenderWindow &renderwindow);
    void getEntree(sf::RenderWindow &renderwindow);
    
    
    private:
    
    //Variables de la classe en accès privé
    sf::Event event;
    Touche touche;
    sf::Vector2i positionSouris ;

    bool menu ;
    bool mort ;
    bool switchSkin ;
    bool elise ;
 
    //Enum pour les boutons
    enum{ haut, bas, droite, gauche, entrer, P, C, E };

 
};
#endif 