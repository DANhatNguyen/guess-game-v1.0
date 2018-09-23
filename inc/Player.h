#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
private:
	std::string name;
public:
	Player();
	Player(std::string Name);
	std::string getName();
	void changeName(std::string new_name);
	virtual int getGuess() = 0;
	virtual void checkFeedback(int fb, int guess) = 0;
	virtual int getScore() = 0;
};
#endif