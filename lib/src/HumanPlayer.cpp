#include "Player.h"
#include "HumanPlayer.h"
#include <string>
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer() :Player() {};

HumanPlayer::HumanPlayer(string Name) :Player(Name) 
{
	score = 0;
}

int HumanPlayer::getGuess()
{
	int temp;
	cout << "Enter your guess: ";
	cin >> temp;
	while(temp < 0 || temp > 100)
	{
		cout << "Invalid guess!" << endl;
		cout << "Enter your guess: ";
	    cin >> temp;
	}
	score++;
	return temp;
}

int HumanPlayer::getScore()
{
	return score;
}

void HumanPlayer::changeScore(int new_score)
{
	score = new_score;
}