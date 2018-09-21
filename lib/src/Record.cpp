#include "Record.h"
#include "HumanPlayer.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int Record::SIZE = 10;

Record::Record()
{
	ifstream in;
	string label;
	int record;
	
	in.open("bin/record.dat");
	if(in.fail())
	{
		cout << "ERROR!\n";
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

void Record::outputDetail()
{
	cout << "\n\t\tLEADERBOARDS\nRank\t\tPlayer\t\tAttempts\n";
	for(int i = 0; i < SIZE; i++)
		cout << i + 1 << "\t\t" << contents[i]->getName() 
		     << "\t\t   " << contents[i]->getScore() << endl;
	cout << endl;		
}

bool Record::addWinner(string name, int score)
{
    for(int i = 0; i < SIZE; i++)
    {
    	if(score < contents[i]->getScore())
    	{
    		for(int j = SIZE - 1; j > i; j--)
    		{
    			contents[j]->changeName(contents[j-1]->getName());
    			contents[j]->changeScore(contents[j-1]->getScore());
    		}
    		contents[i]->changeName(name);
    		contents[i]->changeScore(score);

    		updateRecord();
    		return true;
    	}
    }
    return false;
}

void Record::updateRecord()
{
	ofstream out;

	out.open("bin/record.dat");
	if(out.fail())
	{
		cout << "ERROR!\n";
		exit(1);
	}

	for(int i = 0; i < SIZE; i++)
		out << contents[i]->getName() << "\n" << contents[i]->getScore() << endl;

	out.close();
}