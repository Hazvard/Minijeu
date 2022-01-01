#include <iostream>
#include <string>
#include "Score.hpp"


int main(int argc, char ** argv) {
	Score zebi;
	zebi.setScore(3);
	zebi.incrementScore(21);
	int zbeul = zebi.getScore();
	zbeul++;
	zebi.setScore(zbeul);
	zebi.printScoreToFile("bangbang.txt");
}