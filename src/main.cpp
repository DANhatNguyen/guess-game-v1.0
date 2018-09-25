#include "Player.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Record.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
  
using namespace std;

Player* play(Player &player1, Player &player2);
int checkForWin(int guess, int answer);

int main()
{
    int opt;
    string name;

    Record chart;

    cout << "Welcome to the guessing game! Please choose a mode: " << endl;
    cout << "\t1. Vs Friend\n\t2. Vs Valak\n\t3. Exit game\n" << endl;
    cin >> opt;

    /* Check if user input is valid */
    while (cin.fail() || opt < 1 || opt > 3)
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid option. Please choose again: ";
        cin >> opt;   
    }

    /* Vs Friend */
    if (opt == 1)
    {
        cin.ignore();
        cout << "Enter player 1 name: ";
        std::getline(std::cin, name);
        HumanPlayer object_1(name);

        
        cout << "Enter player 2 name: ";
        // cin.ignore();
        getline(cin, name);
        
        HumanPlayer object_2(name);
        
        /* start playing and return the winner */
        Player* winner = play(object_1, object_2);

        /* Add winner to record */
        bool status = chart.addWinner(*winner);

        /* 
        * @status indicates if winner is good enough to be in the top 10 
        * status = 0: not in top 10
        * status = 1: in top 10
        */
        if(status == 0)
            cout << "\nSorry! You're good, but not good enough to be"
                 <<  " on the Wall of Fame." << endl;
        
        /* Print out Wall of Fame */
        cout << "\n\t\tWALL OF FAME\nRank\t\tPlayer\t\tAttempts\n";
        chart.printInfo();
    }
    
    /* Vs Computer */
    else if (opt == 2)
    {
        cin.ignore();
        cout << "Enter your name: ";
        std::getline(std::cin, name);
        HumanPlayer object_1(name);

        ComputerPlayer object_2;

        Player* winner = play(object_1, object_2);

        /* Just write to the record if the winner is human */
        if (winner->getName() != "Valak")
        {
            bool status = chart.addWinner(*winner);
            if (status == 0)
                cout << "\nSorry! You're good, but not good enough to be"
                     << " on the Wall of Fame." << endl;
        }
        cout << "\n\t\tWALL OF FAME\nRank\t\tPlayer\t\tAttempts\n";
        chart.printInfo();
    }

    /* Exit */
    else if (opt == 3)
        return EXIT_SUCCESS;

    return EXIT_SUCCESS;
}   

/* Here explains the game's rules */
int checkForWin(int guess, int answer) 
{
    cout<< "You guessed " << guess << ".";

    if (answer == guess) 
    {
        cout<< "You’re right! You win!" << endl;
        return 0; 
    }
    
    else if (answer < guess)
    {
        cout<< "Your guess is too high.\n" << endl;
        return 1;
    }

    else
    {
        cout<< "Your guess is too low.\n" << endl;
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
    while (win != 0)
    {
        cout << player1.getName() << "’s turn to guess." << endl;
        guess = player1.getGuess();

        win = checkForWin(guess, answer);
        
        /* 
        * Invoke checking feedback for computer player 
        * human.checkFeedback does nothing.
        */
        player2.checkFeedback(win, guess);
        
        if (win == 0) 
            return &player1;
        
        cout << player2.getName() << "’s turn to guess." << endl; 
        guess = player2.getGuess();
        win = checkForWin(guess, answer);
        // player1.checkFeedback(win, guess);
        player2.checkFeedback(win, guess);
    }   

    return &player2;
}