#ifndef LISTE_H
#define LISTE_H
 
#include <iostream>
#include <cassert>
 
using namespace std;
 
// Définition du noeud en tant que struct
struct Noeud
{
    int donnees;
    Noeud * suivant;
};
 
// Définition de la classe Liste
class Liste{
    private:
        Noeud * entete;
        int compteur;
        Noeud * CreerNoeud (int valeur);
     
    public:
        Liste ();
        ~Liste ();
        void inserer (int pos, int valeur);
        void supprimer (int pos);
        int getNoeud (int pos) const;
        void afficher () const;
        int taille () const;
};
#endif