#include "Player.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "Record.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
  
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

    while(cin.fail() || opt < 1 || opt > 3)
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid option. Please choose again: ";
        cin >> opt;   
    }

    if(opt == 1)
    {
        cout << "Enter player 1 name: ";
        cin >> name;
        HumanPlayer object_1(name);
        cout << "Enter player 2 name: ";
        cin >> name;
        HumanPlayer object_2(name);
            
        Player* winner = play(object_1, object_2);
        bool a = chart.addWinner(*winner);
        if(a == 0)
            cout << "\nSorry! You're good, but not good enough to be"
                 <<  " on the Wall of Fame." << endl;
        chart.outputDetail();
    }
        
    else if(opt == 2)
    {
        cout << "Enter your name: ";
        cin >> name;
        HumanPlayer object_1(name);
        ComputerPlayer object_2;
                
        Player* winner = play(object_1, object_2);
        if(winner->getName() != "Valak")
        {
            bool a = chart.addWinner(*winner);
            if(a == 0)
            cout << "\nSorry! You're good, but not good enough to be"
                 << " on the Wall of Fame." << endl;
        }
                
        chart.outputDetail();
    }

    else if(opt == 3)
        return EXIT_SUCCESS;

    return EXIT_SUCCESS;
}   

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
    srand((unsigned) time(&t));
    int answer = 0, guess = 0; 
    answer = rand() % 100; 
    int win = 1;
    while (win != 0)
    {
        cout << player1.getName() << "’s turn to guess." << endl; 
        guess = player1.getGuess();
        win = checkForWin(guess, answer);
        player1.checkFeedback(win, guess);
        player2.checkFeedback(win, guess);
        
        if (win == 0) 
            return &player1;
        
        cout << player2.getName() << "’s turn to guess." << endl; 
        guess = player2.getGuess();
        win = checkForWin(guess, answer);
        player1.checkFeedback(win, guess);
        player2.checkFeedback(win, guess);
    }   
    return &player2;
}