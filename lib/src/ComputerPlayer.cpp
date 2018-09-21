#include "Player.h"
#include "ComputerPlayer.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int ComputerPlayer::min_value = -1;
int ComputerPlayer::max_value = 100;

ComputerPlayer::ComputerPlayer(string Name) :Player(Name) {}

int ComputerPlayer::getGuess()
{
	int temp;
	temp = rand() % 100;
	while(temp <= min_value || temp >= max_value)
		temp = rand() % 100;
	return temp;
}

void ComputerPlayer::changeMax(int max)
{
	max_value = max;
}

void ComputerPlayer::changeMin(int min)
{
	min_value = min;
}	

void ComputerPlayer::checkFeedback(int fb, int guess)
{
	if((fb == 1) && (guess < max_value))
		changeMax(guess);
	if((fb == 2) && (guess > min_value))
		changeMin(guess);
}