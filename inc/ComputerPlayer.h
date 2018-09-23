#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <string>
#include "Player.h"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(std::string Name = "Valak");
	virtual int getGuess();
	void changeMin(int min);
	void changeMax(int max);
	virtual void checkFeedback(int fb, int guess);
	virtual int getScore() {}
private:
	static int min_value;
	static int max_value;
};
#endif