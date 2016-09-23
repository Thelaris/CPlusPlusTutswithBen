#include <iostream>
#include <string>

using namespace std;

const int numItems = 6;
const string shopItemNames[numItems] = { "Boots", "Sword", "Helmet", "Bacon", "Popcorn", "Alcohol" };

void printInventory(const int playerInventory[numItems]);
void printShop();
bool buyItems(int playerInventory[numItems]);

int main()
{
	//Tells us when the game is over
	bool isDone = false;

	//Store players inventory in an array
	int playerInventory[numItems] = { 0, 0, 0, 1, 0, 0 };

	cout << "***Welcome to the item shop***\n\n";


	//Game loop
	while (isDone == false) {
	
		printShop();
	
		printInventory(playerInventory);

		isDone = buyItems(playerInventory);

		cout << "\n\n\n";
	}


	system("PAUSE");
	return 0;
}

void printInventory(const int playerInventory[numItems]) 
{
	cout << "Your inventory contains: \n";
	for (int i = 0; i < numItems; i++) {
		if (playerInventory[i] > 0) {
			cout << playerInventory[i] << "x " << shopItemNames[i] << endl;
		}
	}
	cout << endl;
}

void printShop() {
	cout << "Shop Inventory: \n";

	for (int i = 0; i < numItems; i++) {
		cout <<  i + 1 << ". " << shopItemNames[i] << endl;

	}
	cout << "*************************\n\n";
}

bool buyItems(int playerInventory[numItems]) {
	int input;
	cout << "What would you like to buy? Enter -1 to quit. Enter (" << 1 << "-" << numItems << "): ";
	cin >> input;

	if (input == -1) {
		return true; //Program is over
	}

	if (input - 1 < 0 || input > numItems) {
		cout << "Bad input!\n\n";
		return false; // Keep going
	}

	playerInventory[input - 1]++;
	return false;
}