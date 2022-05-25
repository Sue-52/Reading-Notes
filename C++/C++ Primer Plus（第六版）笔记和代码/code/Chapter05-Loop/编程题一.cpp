#include <iostream>

int minNum, maxNum, sum;

int main_first()
{
	using namespace std;


	cout << "Enter a small number:";
	cin >> minNum;
	cout << "Enter a large number:";
	cin >> maxNum;

	int i;
	for (i = minNum; i <= maxNum; ++i)
	{
		sum += i;
	}

	cout << "Total number from " << minNum << " to "
		<< maxNum << " is: " << sum;

	return 0;
}