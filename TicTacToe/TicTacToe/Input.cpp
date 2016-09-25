#include "Input.h"
#include "Board.h"
#include <string>

using namespace std;


Input::Input()
{
	bool playerTurnDone = false;
}

int row;

//Row selection input
int Input::selectRow()
{
	cout << " please enter the row you wish to place your marker on: ";
	cin >> row;

	//offset users input
	row = offsetRowInput(row);

	if (row < 0 || row > 5) {
		cout << "\n\nBad input. Please try again\n\n";
		return -1;
	}

	return row;
}

int col;

//Column selection input
int Input::selectCol()
{
	
	cout << " please enter the column you wish to place your marker on: ";
	cin >> col;
	
	//offset users input
	col = offsetColInput(col);
	
	if (col < 0 || col > 5) {
		cout << "\n\nBad input. Please try again\n\n";
		return -1;
	}

	return col;
}


char Input::setPlayerName(int playerNum)
{
	//setup player
	char playerName;
	cout << "\nPlease enter Player " << playerNum << "'s name: ";
	cin >> playerName;
	cout << "\nWelcome " << playerName << endl;
	return playerName;
}


//offset users input to match array - array also contains grid layout
int Input::offsetRowInput(int rowSelect)
{
	if (rowSelect == 1) {
		row = 0;
	}
	if (rowSelect == 2) {
		row = 2;
	}
	if (rowSelect == 3) {
		row = 4;
	}
	if (rowSelect == 4) {
		row = 5;
	}
	if (rowSelect == 5) {
		row = 6;
	}

	return row;
}

int Input::offsetColInput(int colSelect)
{
	if (colSelect == 1) {
		col = 0;
	}
	if (colSelect == 2) {
		col = 2;
	}
	if (colSelect == 3) {
		col = 4;
	}
	if (colSelect == 4) {
		col = 5;
	}
	if (colSelect == 5) {
		col = 6;
	}

	return col;
}