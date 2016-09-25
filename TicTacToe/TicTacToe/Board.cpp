#include "Board.h"
#include <iostream>

#include "GameManager.h"

GameManager gameManager;

Board::Board()
{

}

void Board::initBoard()
{
/* Not used anymore
	for (int y = 0; y < 5; y += 2) {
		for (int x = 0; x < 5; x += 2) {
			gameBoard[y][x] = ' ';
		}
	}

	for (int y = 0; y < 5; y += 2) {
		for (int x = 1; x < 5; x += 2) {
			gameBoard[y][x] = '|';
		}
	}

	for (int y = 1; y < 5; y += 2) {
		for (int x = 0; x < 5; x += 2) {
			gameBoard[y][x] = '-';
		}
	}

	for (int y = 1; y < 5; y += 2) {
		for (int x = 1; x < 5; x += 2) {
			gameBoard[y][x] = '+';
		}
	}
*/


	//setup grid rows

	//Row 1
	for (int y = 0; y < 1; y++) {
		for (int x = 0; x < 5; x++) {
			if (((x + y) % 2) == 0) {
				gameBoard[y][x] = ' ';
			}
			else {
				gameBoard[y][x] = '|';
			}
		}
	}


	//Row 2
	for (int y = 1; y < 2; y++) {
		for (int x = 0; x < 5; x++) {
			if (((x + y) % 2) == 0) {
				gameBoard[y][x] = '+';
			}
			else {
				gameBoard[y][x] = '-';
			}
		}
	}


	//Row 3
	for (int y = 2; y < 3; y++) {
		for (int x = 0; x < 5; x++) {
			if (((x + y) % 2) == 0) {
				gameBoard[y][x] = ' ';
			}
			else {
				gameBoard[y][x] = '|';
			}
		}
	}


	//Row 4
	for (int y = 3; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			if (((x + y) % 2) == 0) {
				gameBoard[y][x] = '+';
			}
			else {
				gameBoard[y][x] = '-';
			}
		}
	}
	
	//Row 5

	for (int y = 4; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (((x + y) % 2) == 0) {
				gameBoard[y][x] = ' ';
			}
			else {
				gameBoard[y][x] = '|';
			}
		}
	}
	
}

void Board::printBoard()
{
	int gameRow;

	//Border Header
	cout << "     1|2|3 \n";
	cout << "     * * *\n";

	for (int y = 0; y < 5; y++) {
		if (y % 2 == 0)
		{
			//left-hand padding
			if (y == 0) {
				gameRow = 1;
				cout << "  " << gameRow << "* ";
			}
			else if (y == 2) {
				gameRow = 2;
				cout << "  " << gameRow << "* ";
			}
			else if (y == 4) {
				gameRow = 3;
				cout << "  " << gameRow << "* ";
			}

		}
		else  {
				cout << "  -  ";
			}

		

		for (int x = 0; x < 5; x++) {
			cout << gameBoard[y][x];
		}
		cout << endl;
	}
	cout << endl << endl << endl;
}



bool Board::placeMarker(int row, int col, int currentPlayer)
{
	//place Player 1's X marker
		if ((currentPlayer == 1) && (gameBoard[row][col] == ' ')) {
			gameBoard[row][col] = 'X';
			return true;
		}
		//place Player 2's O marker
		else if ((currentPlayer == 2) && (gameBoard[row][col] == ' ')) {
			gameBoard[row][col] = 'O';
			return true;
		}
		else {
			cout << "BAD INPUT!\n";
			return false;
		}
}

bool Board::wasPlaced()
{
	if (1 == 1) {
		return true;
	}
	else {
		return false;
	}
}


int Board::checkIfWon()
{
	//width
	if (gameBoard[0][0] == 'X' && gameBoard[0][2] == 'X' && gameBoard[0][4] == 'X') {
		return 1;
	}
	if (gameBoard[0][0] == 'O' && gameBoard[0][2] == 'O' && gameBoard[0][4] == 'O') {
		return 2;
	}
	if (gameBoard[2][0] == 'X' && gameBoard[2][2] == 'X' && gameBoard[2][4] == 'X') {
		return 1;
	}
	if (gameBoard[2][0] == 'O' && gameBoard[2][2] == 'O' && gameBoard[2][4] == 'O') {
		return 2;
	}
	if (gameBoard[4][0] == 'X' && gameBoard[4][2] == 'X' && gameBoard[4][4] == 'X') {
		return 1;
	}
	if (gameBoard[4][0] == 'O' && gameBoard[4][2] == 'O' && gameBoard[4][4] == 'O') {
		return 2;
	}


	//height
	if (gameBoard[0][0] == 'X' && gameBoard[2][0] == 'X' && gameBoard[4][0] == 'X') {
		return 1;
	}
	if (gameBoard[0][0] == 'O' && gameBoard[2][0] == 'O' && gameBoard[4][0] == 'O') {
		return 2;
	}
	if (gameBoard[0][2] == 'X' && gameBoard[2][2] == 'X' && gameBoard[4][2] == 'X') {
		return 1;
	}
	if (gameBoard[0][2] == 'O' && gameBoard[2][2] == 'O' && gameBoard[4][2] == 'O') {
		return 2;
	}
	if (gameBoard[0][4] == 'X' && gameBoard[2][4] == 'X' && gameBoard[4][4] == 'X') {
		return 1;
	}
	if (gameBoard[0][4] == 'O' && gameBoard[2][4] == 'O' && gameBoard[4][4] == 'O') {
		return 2;
	}


	//diagonal
	if (gameBoard[0][0] == 'X' && gameBoard[2][2] == 'X' && gameBoard[4][4] == 'X') {
		return 1;
	}
	if (gameBoard[0][0] == 'O' && gameBoard[2][2] == 'O' && gameBoard[4][4] == 'O') {
		return 2;
	}
	if (gameBoard[0][4] == 'X' && gameBoard[2][2] == 'X' && gameBoard[4][0] == 'X') {
		return 1;
	}
	if (gameBoard[0][4] == 'O' && gameBoard[2][2] == 'O' && gameBoard[4][0] == 'O') {
		return 2;
	}

	
	return 0;
	
}
