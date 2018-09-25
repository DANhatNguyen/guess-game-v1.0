#ifndef RECORD_H
#define RECORD_H

#include "HumanPlayer.h"
#include "Player.h"

#include <fstream>
#include <iostream>
#include <string>

class Record
{
public:
	Record();
	~Record();

	void setFilePath(const std::string file_path);
	std::string getFilePath();

	void printInfo();
	bool addWinner(Player &winner);
	void updateRecord();

private:
	std::string _file_path;
	
	const static int SIZE;
	HumanPlayer* contents[10];
};

#endif