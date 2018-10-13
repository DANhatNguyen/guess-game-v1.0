#include "validation.h"

#include <iostream>

enum MODE {DEFAULT, FRIEND, VALAK, EXIT};

int getOption();
std::string inputPlayerName();

int main(void)
{
	int mode = DEFAULT;
	mode = getOption();

	std::string name; 
	name = inputPlayerName();

	return 0;
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