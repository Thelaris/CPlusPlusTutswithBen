#include "GameManager.h"
#include <iostream>

#include "Board.h"
#include "Player.h"
#include "Input.h"

using namespace std;

Board gameBoard;
Player player1("");
Player player2("");
Input input;


bool isDone = false;


GameManager::GameManager()
{
	
	//start global loop
	while (isDone == false) {

		player1.setName(1);
		system("CLS");

		player2.setName(2);
		system("CLS");

		cout << "Welcome "; 
		player1.printName();
		cout << " and ";
		player2.printName();
		cout << ".\n\n" << "May the best player win!\n\n\n";

		system("PAUSE");
		system("CLS");

		cout << endl << endl << endl;

		gameBoard.initBoard();
		gameBoard.printBoard();

		//begin game
		while (playGame() == true) {
			playGame();
		}
		}
		

}





bool GameManager::playGame()
{
	bool gameover = false;

	//start game loop
	while (gameover == false) {

		int playerNumTurn = 1;
		int doLoop;

		//player 1 turn
		if (playerNumTurn == 1) {
			doLoop = 1;
			//start player turn loop
			while (doLoop == 1) {
				player1.printName();
				int row = input.selectRow();
				player1.printName();
				int col = input.selectCol();
				

				if (gameBoard.placeMarker(row, col, 1) == true) {
					doLoop = 0;
				}
			}

			system("cls");

			int checkIfWon = gameBoard.checkIfWon();

			cout << endl << endl << endl;

			gameBoard.printBoard();

			if (checkIfWon == 1) {

				player1.printName();
				cout << " WINS!!!\n\n";
				system("PAUSE");

				cout << "\nWould you like to play again? (Y)es, (N)o: ";
				char playAgain;
				cin >> playAgain;

				//restart
				if (playAgain == 'Y' || playAgain == 'y') {
					gameover = true;
					system("CLS");
					return false;
				}
				//quit
				else if (playAgain == 'N' || playAgain == 'n') {
					isDone = true;
					return false;
				}
			}


			playerNumTurn = 2;
		}

		//player 2 turn
		if (playerNumTurn == 2) {
			doLoop = 1;
			while (doLoop == 1) {
				player2.printName();
				int row = input.selectRow();
				player2.printName();
				int col = input.selectCol();



				if (gameBoard.placeMarker(row, col, 2) == true) {
					doLoop = 0;
					cout << doLoop;
				}
			}
			system("cls");
			int checkIfWon = gameBoard.checkIfWon();

			cout << endl << endl << endl;

			gameBoard.printBoard();

			if (checkIfWon == 2) {

				player2.printName();
				cout << " WINS!!!\n\n";
				system("PAUSE");

				cout << "\nWould you like to play again? (Y)es, (N)o: ";
				char playAgain;
				cin >> playAgain;

				if (playAgain == 'Y' || playAgain == 'y') {
					gameover = true;
					system("CLS");
					return false;

				}
				else if (playAgain == 'N' || playAgain == 'n') {
					isDone = true;
					return false;
				}
			}


			playerNumTurn = 1;
		}

		return true;
	}
}





