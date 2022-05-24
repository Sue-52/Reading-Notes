#include <iostream>

int main_num_for()
{
	using namespace std;

	cout << "Enter the starting coutdown value: ";
	int limit;
	cin >> limit;
	int i = 0;
	for (i = limit; i; i--)
		cout << "i = " << i << endl;
	cout << "Done now that i = " << i << endl;

	return 0;
}