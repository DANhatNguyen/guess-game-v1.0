#include "Record.h"

Record::Record()
{
	std::ifstream in;
	std::string label;
	std::string score;

	/* Open record.dat */
	in.open("data/record.dat");

	/* error checking */
	if (in.fail()) {
		std::cout << "Failed to open file.\n";
		exit(1);
	}

	for (int i = 0; i < SIZE; i++) {
		std::getline(in, label);
		contents[i] = new HumanPlayer(label);

		/* get @score and convert it to int */
		getline(in, score);
		contents[i]->setScore(stoi(score));
	}

	in.close();
}

Record::~Record()
{
	for(int i = 0; i < SIZE; i++)
		delete contents[i];
}

/* Output Wall of Fame: score of top @SIZE players */
void Record::printInfo()
{
	// cout << "\n\t\tWALL OF FAME\nRank\t\tPlayer\t\tAttempts\n";
	for(int i = 0; i < SIZE; i++)
		std::cout << i + 1 << "\t\t   " << contents[i]->getScore() 
		     << "\t\t   " << contents[i]->getName() << std::endl;
	std::cout << std::endl;		
}

bool Record::addWinner(Player &winner)
{
    for(int i = 0; i < SIZE; i++) {
    	if(winner.getScore() < contents[i]->getScore()) {
    		/* Shift players down */
    		for(int j = SIZE - 1; j > i; j--) {
    			contents[j]->setName(contents[j-1]->getName());
    			contents[j]->setScore(contents[j-1]->getScore());
    		}

    		/* Add @winner to its corresponding position */
    		contents[i]->setName(winner.getName());
    		contents[i]->setScore(winner.getScore());

    		updateRecord();
    		return true;
    	}
    }
    return false;
}

void Record::updateRecord()
{
	std::ofstream out;

	out.open("data/record.dat");

	/* error checking */
	if(out.fail()) {
		std::cout << "Failed to open file.\n";
		exit(1);
	}

	for(int i = 0; i < SIZE; i++)
		out << contents[i]->getName() << "\n" << contents[i]->getScore() << std::endl;

	out.close();
}
