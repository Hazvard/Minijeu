#include "Liste.hpp"
 
// Constructeur

Liste::Liste ():entete (NULL), compteur (0) {}
 
// Destructeur

Liste:: ~Liste ()
{
    Noeud * del = entete;
    while (entete){
        entete = entete -> suivant;
        delete del;
        del = entete;
    }
}
 

Noeud * Liste  :: CreerNoeud (int &valeur){
    Noeud * temp = new Noeud ;
    temp -> donnees = valeur;
    temp -> suivant = NULL;
    return temp;
}
 

void Liste  :: inserer (int pos, int &valeur)
{
    if (pos < 0 || pos > compteur){
        cout << "Erreur! La position est invalide." << endl;
        return;
    }
    Noeud * nouveau = CreerNoeud (valeur);
 
    //Insertion au début
    if (pos == 0){
        nouveau -> suivant = entete;
        entete = nouveau;
    }
    // Insertion au milieu 
    else{
        Noeud * courant = entete;
        for (int i = 1; i < pos; i++){
            courant = courant -> suivant;
        }
        nouveau -> suivant = courant -> suivant;
        courant -> suivant = nouveau;
    }
    compteur++;
}
 

void Liste  :: supprimer (int pos){
    if (pos < 0 || pos > compteur-1){
        cout << "Erreur! La position est invalide." << endl;
        return;
    }
    if (pos == 0){
        Noeud * del = entete;
        entete = entete -> suivant;
        delete del;
    }
    else{
        Noeud * courant = entete;
        for (int i = 0; i < pos-1; i++){
            courant = courant -> suivant;
        }
        Noeud * del = courant -> suivant;
        courant -> suivant = courant -> suivant -> suivant;
        delete del;
    }
    compteur--;
}
 

int Liste  :: getNoeud (int pos) const {
    if (pos < 0 || pos > compteur-1){
        cout << "Erreur! La position est invalide";
        assert (false);
    }
    else if (pos == 0){
        return entete -> donnees;
    }
    else{
        Noeud * courant = entete;
        for (int i = 0 ; i < pos ; i++){
            courant = courant -> suivant;
        }
        return courant -> donnees;
    }
}
 

void Liste  :: afficher () const {
    if (compteur == 0){
        cout << "La liste est vide!" << endl;
        return;
    }
    Noeud * courant = entete;
    while (courant != 0){
        cout << courant -> donnees << endl;
        courant = courant -> suivant;
    }
}
 

int Liste  :: taille () const{
    return compteur;
}