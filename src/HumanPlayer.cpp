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
	int guess;
	cout << "Enter your guess: ";
    cin >> guess;
    while (cin.fail() || guess < 0 || guess > 100)
    {
        cin.clear();
        cin.ignore();
        cout << "Not a valid number. Please reenter: ";
        cin >> guess;
    }
    score++;
    return guess;
}

int HumanPlayer::getScore()
{
	return score;
}

void HumanPlayer::changeScore(int new_score)
{
	score = new_score;
}