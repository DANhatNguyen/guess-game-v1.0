#include "Player.h"

using namespace std;

Player::Player()
{
	_name = "UNDEFINED";
}

Player::Player(string name)
{
	_name = name;
}

string 
Player::getName()
{
	return _name;
}

void 
Player::changeName(string new_name)
{
	_name = new_name;
}