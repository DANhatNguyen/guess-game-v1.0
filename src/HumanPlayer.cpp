#include "HumanPlayer.h"

using namespace std;

#include <ctype.h> //for is digit 
HumanPlayer::HumanPlayer() {}

/* Constructer */
HumanPlayer::HumanPlayer(const string name): Player(name) 
{
	_score = 0;
}

bool isNumber(string input) {
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] != '0' && input[i] != '1' && input[i] != '2' && 
            input[i] != '3' && input[i] != '4' && input[i] != '5' &&
            input[i] != '6' && input[i] != '7' && input[i] != '8' &&
            input[i] != '9')
                return false;
    }
    return true;
}

/* Invoke this if Player is HumanPlayer */
int HumanPlayer::getGuess()
{
    string guess;
	cout << "Enter your guess: ";
    cin >> guess;

    bool status = isNumber(guess);
    if (status == true) {
        _guess = stoi(guess);
    }
    /* Check input condition */
    while (status != true || _guess < 0 || _guess > 100)
    {
        cout << "Invalid number. Please re-enter: ";
        cin >> guess;
        status = isNumber(guess);
        if (status == true)
            _guess = stoi(guess);
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