#include <iostream>
#include <string>

using namespace std;



class CheckerBoard {
public:
	void initBoard() {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (((x + y) % 2) == 0) {
					board[y][x] = '.';
				}
				else {
					board[y][x] = '*';
				}
			}
		}
	}

	void placeRedPieces() {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 8; x++) {
				if (((x + y) % 2) == 0)
					board[y][x] = 'R';
			}
		}

	}

	void placeBlackPieces() {
		for (int y = 5; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (((x + y) % 2) == 0)
					board[y][x] = 'B';
			}
		}

	}
	
	void printBoard() {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				cout << board[y][x];
			}
			cout << endl;
		}
	}

private:
	char board[8][8];
};


int main()
{

	CheckerBoard checkerBoard;
	checkerBoard.initBoard();
	checkerBoard.placeRedPieces();
	checkerBoard.placeBlackPieces();
	checkerBoard.printBoard();

	

	system("PAUSE");
	return 0;
}