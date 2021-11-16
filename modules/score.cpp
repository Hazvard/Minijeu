#include "score.hpp"
#include <iostream>
#include <string>
#include <fstream> 
 
using namespace std;

//Constructeurs
Score::Score(){
	val = 0;
}

Score::Score(int a){
	val = a;
}

//Getter
int Score::getScore(){
	return val;
}

//Setter
void Score::setScore(int a){
	val = a;
}

void Score::incrementScore(int a){
	val = val+a;
}

//Autres
void Score::printScoreToFile(const std::string &str){ //str est le nom du fichier, voire l'arborescence si ca passe avec ofstram
	ofstream scoreFile(str);
	scoreFile << "Score final: " << val <<endl;
	scoreFile.close();
}