#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <string>
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer();
	HumanPlayer(std::string Name);
	virtual int getGuess();
	virtual void checkFeedback(int fb, int guess) {}
    virtual int getScore();
    void changeScore(int new_score);
private:
	int score;
};
#endif