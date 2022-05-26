#include <iostream>
#include <climits>

bool is_int(double);

int main_not()
{
	using namespace std;

	double num;

	cout << "Yo, dude! Enter an integerr value: ";
	cin >> num;

	while (!is_int(num))
	{
		cout << "Out of range -- please try again: ";
		cin >> num;
	}
	int val = int(num);
	cout << "You've enterd the integerr " << val
		<< endl;
	return 0;

	return 0;
}

bool is_int(double x)
{
	if (x <= INT_MAX && x >= INT_MIN)
	{
		return true;
	}
	else
	{
		return false;
	}
}