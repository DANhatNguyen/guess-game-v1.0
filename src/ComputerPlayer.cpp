#include "ComputerPlayer.h"

int ComputerPlayer::_min = -1;
int ComputerPlayer::_max = 100;

/* Default constructer with Player named "Valak" */
ComputerPlayer::ComputerPlayer(): Player("Valak") {}

ComputerPlayer::ComputerPlayer(const std::string name): Player(name) {}

/* Invoke this if Player is ComputerPlayer */
int ComputerPlayer::getGuess()
{
	int temp;

	/* Using bisection for increasing computer's winning probability */
	temp = ceil((_min + _max)/2.0);
	return temp;
}


/* Upper bound */
void ComputerPlayer::setMax(const int max)
{
	_max = max;
}

/* lower bound */
void ComputerPlayer::setMin(const int min)
{
	_min = min;
}	

/* Update upper bound and lower bound for computer player */
void ComputerPlayer::checkFeedback(int fb, int guess)
{
	if ((fb == 1) && (guess < _max))
		setMax(guess);
	if ((fb == 2) && (guess > _min))
		setMin(guess);
}

/* If ComputerPlayer wins, score does not count, so this func does nothing */
int ComputerPlayer::getScore()
{
	return -1;
}