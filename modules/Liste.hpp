#ifndef LISTE_H
#define LISTE_H

struct maillon{
	int numCarte;
	maillon* suivant;
};

class Liste{

public:
	Liste(); //auparavant constructeur par un int
	int getTete();
	int getTaille();
	void setTete(int zebi);
	void setSuivant(maillon* l); //probablement pété
	void goSuivant();
	void shuffle(); //fonction de mélange des éléments
	void ajouter(int i);


private:
	maillon* laListe;
	maillon* creerSuivant; //pas sur de mon coup
	int rang;

};
#endif