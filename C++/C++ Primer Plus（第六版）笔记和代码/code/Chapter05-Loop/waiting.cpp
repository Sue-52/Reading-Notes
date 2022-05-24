#include <iostream>
#include <ctime>

int main_waiting()
{
	using namespace std;

	float seconds;

	cout << "Enter the delay time, in seconds: ";
	cin >> seconds;

	clock_t delay = seconds * CLOCKS_PER_SEC;

	cout << "starting\a\n";
	clock_t start = clock();

	while (clock() - start < delay)
		;
	cout << "Done !!\a\n";

	return 0;
}