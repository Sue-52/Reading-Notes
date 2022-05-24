#include <iostream>

int main_block()
{
	using namespace std;

	double number;
	double sum = 0.0;

	cout << "The Amazing Accounto will sum and average ";
	cout << "fivve numbers for you." << endl;
	cout << "Please enter five numbers:\n";

	// for循环内部定义变量，在 for循环执行完成后立即释放
	for (int i = 1; i <= 5; i++)
	{
		cout << "Value: " << i << " : ";
		cin >> number;
		sum += number;
	}

	cout << "Five exquisite choices indeed: ";
	cout << "The sum to " << sum << endl;
	cout << " and the average is " << sum / 5 << ".\n";

	return 0;
}