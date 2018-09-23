#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"

#include <iostream>
#include <string>

/* 
* HumanPlayer inherits from PLayer
*/
class HumanPlayer: public Player
{
public:
	/* Default constructer */
	HumanPlayer();

	/* Constructer */
	HumanPlayer(std::string name);

	/* Setter */
	void changeScore(int new_score);
	
	int getGuess();

	/* 
	* Narrow down the range computer has to guess in order to increase 
	* the winning probability 
	*/
	void checkFeedback(int fb, int guess) {}
    int getScore();

private:
	int _score;
};

#endif