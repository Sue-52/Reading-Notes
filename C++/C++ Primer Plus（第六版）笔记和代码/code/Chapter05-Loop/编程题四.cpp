#include <iostream>

int main_forth()
{
	using namespace std;

	// Daphne ��Ϣ = 0.10 * ��
	// Cleo ��Ϣ = 0.05 * ��� + ��

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