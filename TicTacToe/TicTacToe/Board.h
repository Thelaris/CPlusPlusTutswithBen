#pragma once
#include <iostream>


using namespace std;

class Board
{
public:

	Board();



	void initBoard();

	void printBoard();

	bool placeMarker(int row, int col, int currentPlayer);
	
	bool wasPlaced();

	int checkIfWon();



private:

	char gameBoard[5][5];
};

