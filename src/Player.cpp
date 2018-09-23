#include <string>
#include "Player.h"

using namespace std;

Player::Player()
{
	name = "UNDEFINED";
}

Player::Player(string Name)
{
	name = Name;
}

string Player::getName()
{
	return name;
}

void Player::changeName(string new_name)
{
	name = new_name;
}