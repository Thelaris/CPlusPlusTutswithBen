#include "Monster.h"
#include <iostream>


Monster::Monster()
{
	_name = "NONAME";
}

Monster::Monster(string name)
{
	_name = name;
}

void Monster::printName()
{
	cout << "My name is " << _name << endl;
}