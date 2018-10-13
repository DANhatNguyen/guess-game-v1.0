#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() {}

/* Constructer */
HumanPlayer::HumanPlayer(const std::string name): Player(name) 
{
	_score = 0;
}

/* Invoke this if Player is HumanPlayer */
int HumanPlayer::getGuess()
{
    std::string guess;
	std::cout << "Enter your guess (a number from 0 to 100): ";

   _guess = getValidNumber();

   while(!isInRange(_guess, 0, 100)) {
        std::cout << "Invalid guess. Please enter a guess from 0 to 100: ";
        _guess = getValidNumber();
   }
   
    /* Update score based on number of guessing */
    _score++;
    
    return _guess;

}

int HumanPlayer::getScore()
{
	return _score;
}

void HumanPlayer::setScore(const int score)
{
	_score = score;
}

/* no checking feedback for HumanPlayer */
void HumanPlayer::checkFeedback(int fb, int guess)
{
    ;
}