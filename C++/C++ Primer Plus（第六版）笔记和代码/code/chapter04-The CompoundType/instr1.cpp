#include <iostream>

int main_2()
{
	using namespace std;

	// �������
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	// �������
	cout << "Enter your name: \n";
	cin >> name;
	cout << "Enter you favourite dessert:\n";
	cin >> dessert;

	// �������
	cout << "I have more delicious " << dessert;
	cout << " for you," << name << "\n";

	return 0;
}