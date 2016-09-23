#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int getNumNinjas();
int getNumZombies();
void printResults(int numNinjas, int numZombies, int startNinjas, int startZombies);
void simulateBattle(int &numNinjas, int &numZombies);

int main() {
	
	int numNinjas;
	int numZombies;
	
	int startNinjas;
	int startZombies;
	
	cout << "Welcome to the Ninja's VS Zombie's 1D Combat Simulator\n" << "This program was developed by Kurt Widdup, whilst learning C++ coding\n\n\n" << "Please enter your simulation numbers\n\n";

	numNinjas = getNumNinjas();
	startNinjas = numNinjas;

	numZombies = getNumZombies();
	startZombies = numZombies;

	simulateBattle(numNinjas, numZombies);

	printResults(numNinjas, numZombies, startNinjas, startZombies);


	system("PAUSE");

	return 0;
}

int getNumNinjas()
{
	int numNinjas;
	cout << "How many Ninja's will be in the battle: ";
	cin >> numNinjas;
	return numNinjas;
}

int getNumZombies()
{
	int numZombies;
	cout << "How many Zombie's will be in the battle: ";
	cin >> numZombies;
	return numZombies;
}

void simulateBattle(int &numNinjas, int &numZombies)
{

	int ninjaCurrentHP = 100;
	int ninjaBaseHP = 100;
	int ninjaDamage = 10;

	int zombieCurrentHP = 50;
	int zombieBaseHP = 50;
	int zombieDamage = 12;

	int attackFirst;

	static default_random_engine randomGenerator(time(NULL));
	uniform_real_distribution<float> attackRoll(0.0f, 1.0f);
	
	//Battle Loop
	while ((numNinjas > 0) && (numZombies > 0))
	{

		if (attackRoll(randomGenerator) <= 0.5f) {
			attackFirst = 1;
		}
		else {
			attackFirst = 0;
		}

		//attack
		if (attackFirst == 1) {
			//Ninja attacking
			if (attackRoll(randomGenerator) <= 0.5f) {
				zombieCurrentHP = zombieCurrentHP - ninjaDamage;
			}
			if (zombieCurrentHP <= 0) {
				numZombies--;
				zombieCurrentHP = zombieBaseHP;
			}

			//Zombie attacking
			if (attackRoll(randomGenerator) <= 0.5f) {
				ninjaCurrentHP = ninjaCurrentHP - zombieDamage;
			}
			if (ninjaCurrentHP <= 0) {
				numNinjas--;
				ninjaCurrentHP = ninjaBaseHP;
			}
		}
		else if (attackFirst == 0) {
			//Zombie Attacking
			if (attackRoll(randomGenerator) <= 0.5f) {
				ninjaCurrentHP = ninjaCurrentHP - zombieDamage;
			}
			if (ninjaCurrentHP <= 0) {
				numNinjas--;
				ninjaCurrentHP = ninjaBaseHP;
			}

			//Ninja attacking
			if (attackRoll(randomGenerator) <= 0.5f) {
				zombieCurrentHP = zombieCurrentHP - ninjaDamage;
			}
			if (zombieCurrentHP <= 0) {
				numZombies--;
				zombieCurrentHP = zombieBaseHP;
			}
		}
	}
}

void printResults(int numNinjas, int numZombies, int startNinjas, int startZombies)
{
	if (numNinjas <= 0) {
		cout << "\n\nZombie's Won!\n\n\n" << "BATTLE REPORT\n\n" << "Zombie's still alive: " << numZombies << endl << endl << "Zombie lives lost: " << startZombies - numZombies << endl << "Ninja lives lost: " << startNinjas - numNinjas << endl << endl;
	}
	else if (numZombies <= 0) {
		cout << "\n\nNinja's Won!\n\n\n" << "BATTLE REPORT\n\n" << "Ninja's still alive: " << numNinjas << endl << endl << "Ninja lives lost: " << startNinjas - numNinjas << endl << "Zombie lives lost: " << startZombies - numZombies << endl << endl;
	}
}