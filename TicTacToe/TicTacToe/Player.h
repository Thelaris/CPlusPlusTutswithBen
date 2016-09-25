#pragma once
#include <string>


using namespace std;

class Player
{
public:
	Player();
	Player(string name);


	void printName();
	void setName(int playerNum);


private:
	string _name;

};

