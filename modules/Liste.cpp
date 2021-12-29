#include "Liste.hpp"
#include <cstddef>


using namespace std;

Liste::Liste(){
	laListe->numCarte = 0;
}


//getters
int Liste::getTete(){
	return laListe->numCarte;
}

int Liste::getTaille(){
	int i = 0;
	while(laListe -> suivant != NULL){
		i++;
	}
	return i;
}

//setters
void Liste::setTete(int zebi){
	laListe -> numCarte = zebi;
}

void Liste::setSuivant(maillon* l){ //si c'est pété, parsemer de pointeurs
	laListe -> suivant = l;
}

/*
void Liste::goSuivant(){
	(this) = laListe -> suivant;
}


//autres
void Liste::shuffle(){
	//ipod
}

void Liste::ajouter(int i){ //fonction qui ajoute un élément À LA FIN de la liste
	Liste *l;
	l.setTete(i);
	(*this).suivant = l;
}

*/