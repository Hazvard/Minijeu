#include <iostream>
#include <string>

#ifndef SCORE_H
#define SCORE_H
 
class Score{
    int val;

	public: 
		Score();
		Score(int a);
		int getScore();
		void setScore(int a);
		void incrementScore(int a);
		void printScoreToFile(const std::string &str);

	private:
};
#endif 