#ifndef ENTREE_H
#define ENTREE_H
 
#include <SFML/Graphics.hpp>
 
 
class Entree{
 
    //Structures
    struct Touche { 
        bool gauche; 
        bool droite; 
        bool haut;
        bool bas;
        bool entrer; 
        bool P;
    };
    
    public:
    
    //Constructeur
    Entree();
    
    //Getteurs
    Touche getTouche(void) const;
    
    //Setteurs
    void setTouche(int touches, bool appuyee);
    
    //Fonctions
    void gestionEntrees(sf::RenderWindow &renderwindow);
    void getEntree(sf::RenderWindow &renderwindow);
    
    
    private:
    
    //Variables de la classe en accès privé
    sf::Event event;
    Touche touche;
 
    //Enum pour les boutons
    enum{ haut, bas, droite, gauche, entrer, P };

 
};
#endif 