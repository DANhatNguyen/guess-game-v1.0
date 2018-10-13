#include "Player.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Record.h"
#include "validation.h"

#include <iostream>
#include <string>
#include <ctime>

const std::string red = "\033[1;31m";
const std::string normal = "\033[0;32m";

Player* play(Player &player1, Player &player2);
int checkForWin(int guess, int answer);
std::string inputPlayerName();
void introduction();
int getOption();

enum MODE {DEFAULT, FRIEND, VALAK, EXIT};

int main()
{
    std::string name;
    int mode = DEFAULT;

    Record wallOfFame;

    introduction();

    std::cout << "Enter an option (1 - 3): ";
    mode = getOption();
    
    /* Vs Friend */
    if (mode == FRIEND) {
        std::cout << "Enter player 1 name: ";
        name = inputPlayerName();
        HumanPlayer firstPlayer(name);

        std::cout << "Enter player 2 name: ";
        name = inputPlayerName();
        HumanPlayer secondPlayer(name);

        /* start playing and return the winner */
        Player* winner = play(firstPlayer, secondPlayer);

        /* Add winner to record */
        bool status = wallOfFame.addWinner(*winner);

        /* 
        * @status indicates if winner is good enough to be in the top 10 
        * status = 0: not in top 10
        * status = 1: in top 10
        */
        if (status == 0)
            std::cout << "\nSorry! You're good, but not good enough to be"
                      <<  " on the Wall of Fame." << std::endl;
        
        /* Print out Wall of Fame */
        std::cout << "\n\t\tWALL OF FAME\n" << red << "Rank\t\tAttempts\t   Player" 
                  << normal << "\n";

        wallOfFame.printInfo();
    }
    
    /* Vs Computer */
    else if (mode == VALAK) {
        std::cout << "Enter your name: ";
        name = inputPlayerName();
        
        HumanPlayer firstPlayer(name);

        ComputerPlayer secondPlayer;

        Player* winner = play(firstPlayer, secondPlayer);

        /* Just write to the record if the winner is human */
        if (winner->getName() != "Valak") {
            bool status = wallOfFame.addWinner(*winner);
            if (status == 0)
                std::cout << "\nSorry! You're good, but not good enough to be"
                     << " on the Wall of Fame." << std::endl;
        }
        std::cout << "\n\t\tWALL OF FAME\n" << red << "Rank\t\tAttempts\t   Player" 
             << normal << "\n";

        wallOfFame.printInfo();
    }

    /* Exit */
    else if (mode == EXIT)
        return EXIT_SUCCESS;

    return EXIT_SUCCESS;
}   

/* Here explains the game's rules */
int checkForWin(int guess, int answer) 
{
    std::cout << "You guessed " << guess << ".";

    if (answer == guess) {
        std::cout << "You’re right! You win!" << std::endl;

        return 0; 
    } else if (answer < guess) {
        std::cout << "Your guess is too high.\n" << std::endl;

        return 1;
    } else {
        std::cout << "Your guess is too low.\n" << std::endl;

        return 2;
    }
}

Player* play(Player &player1, Player &player2) 
{
    time_t t;

    /* Seed for generating random number */ 
    srand((unsigned) time(&t));
    
    int answer = 0, guess = 0; 
    
    /* Generate a random number which ranges from 0 to 100 */
    answer = rand() % 100; 
    
    int win = 1;
    
    /* Game keeps proceeding until one wins */
    while (win != 0) {
        std::cout << player1.getName() << "’s turn to guess." << std::endl;
        guess = player1.getGuess();

        win = checkForWin(guess, answer);
        
        /* 
        * Invoke checking feedback for computer player 
        * human.checkFeedback does nothing.
        */
        player2.checkFeedback(win, guess);

        if (win == 0) 
            return &player1;
        
        std::cout << player2.getName() << "’s turn to guess." << std::endl; 
        guess = player2.getGuess();
        win = checkForWin(guess, answer);

        player2.checkFeedback(win, guess);
    }   

    return &player2;
}

std::string inputPlayerName()
{
    std::string name;

    bool nameEmpty = false;
    do {
        std::getline(std::cin, name, '\n');            
        if (name.empty()) {
            std::cout << "You have not entered your name.\n";
            std::cout << "Enter your name: ";
            nameEmpty = true;
        }
        else
            nameEmpty = false;
    } while (nameEmpty);
    
    return name;
}

void introduction() 
{
    std::cout << red << "\tTHE LUCKY NUMBER" << normal << std::endl;
    std::cout << "\t1. Play with a friend\n";
    std::cout << "\t2. Play with Valak\n";
    std::cout << "\t3. Exit game\n";
}

int getOption()
{
    int opt = DEFAULT;

    opt = getValidNumber();

    while(!isInRange(opt, 1, 3)) {
        std::cout << "Invalid option. Please enter an option from 1 - 3: ";
        opt = getValidNumber();
    }

    return opt;
}