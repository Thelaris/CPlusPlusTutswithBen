#include <iostream>
#include <string>

#include "Monster.h"

using namespace std;

int main()
{

	Monster monsters[100];

	Monster monster1("Fred");
	Monster monster2("George");

	monster1.printName();
	monster2.printName();

	monsters[0].printName();

	system("PAUSE");
	return 0;
}


