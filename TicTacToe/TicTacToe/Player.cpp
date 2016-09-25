#include "player.h"
#include <iostream>


Player::Player()
{
	_name = "NewPlayer";
}

Player::Player(string name)
{
	_name = name;
}

void Player::printName()
{
	cout << _name;
}

void Player::setName(int playerNum)
{
	cout << "Please enter Player " << playerNum << "'s name: ";
	cin >> _name;

}