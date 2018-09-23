#include "Record.h"

using namespace std;

int Record::SIZE = 10;

Record::Record()
{
	ifstream in;
	string label;
	int record;

	/* Open record.dat */
	in.open("../data/record.dat");

	/* error checking */
	if(in.fail())
	{
		cout << "Failed to open file.\n";
		exit(1);
	}

	for(int i = 0; i < SIZE; i++)
	{
		in >> label >> record;
		contents[i] = new HumanPlayer(label);
		contents[i]->changeScore(record);
	}

	in.close();
}

Record::~Record()
{
	for(int i = 0; i < SIZE; i++)
		delete contents[i];
}

/* Output Wall of Fame: score of top 10 players */
void 
Record::outputDetail()
{
	cout << "\n\t\tWALL OF FAME\nRank\t\tPlayer\t\tAttempts\n";
	for(int i = 0; i < SIZE; i++)
		cout << i + 1 << "\t\t" << contents[i]->getName() 
		     << "\t\t   " << contents[i]->getScore() << endl;
	cout << endl;		
}

bool 
Record::addWinner(Player &winner)
{
    for(int i = 0; i < SIZE; i++)
    {
    	if(winner.getScore() < contents[i]->getScore())
    	{
    		/* Shift players down */
    		for(int j = SIZE - 1; j > i; j--)
    		{
    			contents[j]->changeName(contents[j-1]->getName());
    			contents[j]->changeScore(contents[j-1]->getScore());
    		}

    		/* Add @winner to its corresponding position */
    		contents[i]->changeName(winner.getName());
    		contents[i]->changeScore(winner.getScore());

    		updateRecord();
    		return true;
    	}
    }
    return false;
}

void 
Record::updateRecord()
{
	ofstream out;

	out.open("../bin/record.dat");

	/* error checking */
	if(out.fail())
	{
		cout << "Failed to open file.\n";
		exit(1);
	}

	for(int i = 0; i < SIZE; i++)
		out << contents[i]->getName() << "\n" << contents[i]->getScore() << endl;

	out.close();
}