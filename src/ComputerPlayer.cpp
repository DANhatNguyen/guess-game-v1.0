#include "ComputerPlayer.h"

using namespace std;

int ComputerPlayer::min_value = -1;
int ComputerPlayer::max_value = 100;

ComputerPlayer::ComputerPlayer(string name): Player(name) {}

int 
ComputerPlayer::getGuess()
{
	int temp;
	temp = rand() % 100;

	while (temp <= min_value || temp >= max_value)
		temp = rand() % 100;
	
	return temp;
}
/* Upper bound */
void 
ComputerPlayer::changeMax(int max)
{
	max_value = max;
}

/* lower bound */
void 
ComputerPlayer::changeMin(int min)
{
	min_value = min;
}	

/* Update upper bound and lower bound for computer player */
void 
ComputerPlayer::checkFeedback(int fb, int guess)
{
	if ((fb == 1) && (guess < max_value))
		changeMax(guess);
	if ((fb == 2) && (guess > min_value))
		changeMin(guess);
}