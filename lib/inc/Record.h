#ifndef RECORD_H
#define RECORD_H

#include "HumanPlayer.h"

class Record
{
public:
	Record();
	~Record();
	void outputDetail();
	bool addWinner(std::string name, int score);
	void updateRecord();
private:
	HumanPlayer* contents[10];
	static int SIZE;
};
#endif