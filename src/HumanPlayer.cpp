#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(): Player() {};

/* Constructer */
HumanPlayer::HumanPlayer(string name): Player(name) 
{
	_score = 0;
}

int 
HumanPlayer::getGuess()
{
	int guess;
	cout << "Enter your guess: ";
    cin >> guess;

    /* Check input condition */
    while (cin.fail() || guess < 0 || guess > 100)
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid number. Please re-enter: ";
        cin >> guess;
    }
    
    /* Update score based on number of guessing */
    _score++;
    
    return guess;
}

int 
HumanPlayer::getScore()
{
	return _score;
}

void 
HumanPlayer::changeScore(int new_score)
{
	_score = new_score;
}