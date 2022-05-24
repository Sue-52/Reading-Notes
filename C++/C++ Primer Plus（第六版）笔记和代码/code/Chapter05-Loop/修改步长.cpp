#include <iostream>

int main_step()
{
	using namespace std;

	int by;

	cout << "Entere an integer: ";
	cin >> by;
	cout << "Counting by " << by << "s:\n";
	for (int i = 0; i < 100; i = i + by)
	{
		cout << i << endl;
	}

	return 0;
}