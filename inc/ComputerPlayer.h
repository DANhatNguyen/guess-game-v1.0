#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Player.h"

#include <iostream>
#include <string>

#include <cstdlib>
#include <cmath>

class ComputerPlayer: public Player
{
public:
	/* Default constructer */
	ComputerPlayer();

	/* Constructer */
	ComputerPlayer(const std::string name);
	
	/* Setter functions for min and max values */
	/* Used for update upper bound and lower bound for ComputerPlayer */
	void setMin(const int min);
	void setMax(const int max);

	int getGuess();

	/* 
	* increase the winning probability based on the updated range 
	*/
	void checkFeedback(int fb, int guess);

	int getScore();

private:
	static int _min;
	static int _max;
};

#endif