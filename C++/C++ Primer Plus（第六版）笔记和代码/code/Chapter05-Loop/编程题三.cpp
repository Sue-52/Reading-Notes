#include <iostream>

int main_third()
{
	using namespace std;

	int num;
	int sum = 0;

	cout << "Enter the number,unit 0 quit. \n";

	do
	{
		cin >> num;
		cout << "Enter the number is: " << num << "\n";
		sum += num;
	} while (num != 0);

	cout << "total number is: " << sum;

	return 0;
}