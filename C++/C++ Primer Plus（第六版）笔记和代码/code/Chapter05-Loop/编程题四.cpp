#include <iostream>

int main_forth()
{
	using namespace std;

	// Daphne 利息 = 0.10 * 存款；
	// Cleo 利息 = 0.05 * 存款 + 存款；

	int Daphne = 100; 
	int Cleo = 100;

	int year = 0;
	while (Daphne >= Cleo)
	{
		Daphne += 10;
		Cleo *= 1.05;
		++year;
	}

	cout << year << " years later," << "Cleo > Daphne" << endl;
	cout << "Dephne:" << Daphne << endl;
	cout << "Cleo:" << Cleo << endl;

	return 0;
}