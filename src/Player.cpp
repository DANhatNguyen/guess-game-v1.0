#include "Player.h"

using namespace std;

Player::Player()
{
	_name = "UNDEFINED";
}

Player::Player(const string name)
{
	_name = name;
}

/* virtual destructer */
Player::~Player() {}

string Player::getName()
{
	return _name;
}

void Player::setName(const string name)
{
	_name = name;
}