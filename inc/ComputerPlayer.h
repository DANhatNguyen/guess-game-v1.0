#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Player.h"

#include <iostream>
#include <string>

#include <cstdlib>

class ComputerPlayer: public Player
{
public:
	/* Constructer */
	ComputerPlayer(std::string name = "Valak");

	/* Setter functions for min and max values */
	void changeMin(int min);
	void changeMax(int max);

	int getGuess();
	void checkFeedback(int fb, int guess);
	int getScore() {}

private:
	static int min_value;
	static int max_value;
};

#endif