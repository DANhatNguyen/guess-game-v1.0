#ifndef RECORD_H
#define RECORD_H

#include "HumanPlayer.h"
#include "Player.h"

#include <fstream>
#include <iostream>
#include <string>

const int SIZE = 10;

class Record
{
public:
	Record();
	~Record();

	void printInfo();
	bool addWinner(Player &winner);
	void updateRecord();

private:
	HumanPlayer* contents[SIZE];
};

#endif