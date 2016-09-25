#pragma once
#include <iostream>
#include <string>

class Input
{
public:
	Input();

	int selectRow();
	int selectCol();
	char setPlayerName(int playerNum);
	int offsetRowInput(int rowSelect);
	int offsetColInput(int colSelect);

private:

};

