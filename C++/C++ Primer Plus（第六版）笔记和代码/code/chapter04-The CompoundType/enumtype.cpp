#include <iostream>

enum spectrum { red, orange, blue, voilent, green };

int main_enum()
{
	using namespace std;

	spectrum color = red;

	cout << color;

	return 0;
}