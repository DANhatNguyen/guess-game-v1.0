#ifndef RECORD_H
#define RECORD_H

#include "HumanPlayer.h"
#include "Player.h"

class Record
{
public:
	Record();
	~Record();
	void outputDetail();
	bool addWinner(Player &winner);
	void updateRecord();
private:
	HumanPlayer* contents[10];
	static int SIZE;
};
#endif