#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;


int main()
{
	default_random_engine randomGenerator(time(NULL));
	uniform_real_distribution<float> attackRoll(0.0f, 1.0f);

	float rolledNumber = attackRoll(randomGenerator);

	cout << "I am attacking! " << rolledNumber << endl;


	if (rolledNumber <= 0.3f) {
		cout << "HIT!\n";
	}
	else {
		cout << "Missed...\n";
	}
		system("PAUSE");
		return 0;
}