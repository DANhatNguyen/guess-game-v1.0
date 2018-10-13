#include "Player.h"

Player::Player()
{
	_name = "UNDEFINED";
}

Player::Player(const std::string name)
{
	_name = name;
}

/* virtual destructer */
Player::~Player() {}

std::string Player::getName()
{
	return _name;
}

void Player::setName(const std::string name)
{
	_name = name;
}




