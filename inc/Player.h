#ifndef PLAYER_H
#define PLAYER_H

#include <string>

/* Abstract class */
class Player
{
public:
	/* Default constructer */
	Player();

	/* Constructer */
	Player(const std::string name);

	/* virtual destructer */
	virtual ~Player();
	
	/* Getter and setter */
	std::string getName();
	void setName(const std::string name);

	/* pure virtual behaviours */
	virtual int getGuess() = 0;
	virtual void checkFeedback(int fb, int guess) = 0;
	virtual int getScore() = 0;

private:
	std::string _name;
};

#endif