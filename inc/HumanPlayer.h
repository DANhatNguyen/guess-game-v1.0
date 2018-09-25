#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"

#include <iostream>
#include <string>
#include <limits>
/* 
* HumanPlayer inherits from Player
*/
class HumanPlayer: public Player
{
public:
	/* Default constructer */
	HumanPlayer();

	/* Constructer */
	HumanPlayer(const std::string name);
	
	int getGuess();
	void checkFeedback(int fb, int guess);
    int getScore();

    /* Setter */
	void setScore(const int score);

private:
	int _score;
	int _guess;
};

#endif