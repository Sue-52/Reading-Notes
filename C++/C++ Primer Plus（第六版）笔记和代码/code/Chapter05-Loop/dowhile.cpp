#include <iostream>

int main_dowhile()
{
	using namespace std;

	int n;

	cout << "Enter numbers in the range 1-10 to find ";
	cout << "my favourite number \n";
	do
	{
		cin >> n;
	} while (n != 3);

	cout << "Yes, 3 is my favourite.\n";

	return 0;
}