// hexoct.cpp -- shows hex and octal literals
#include <iostream>

int main()
{
	using namespace std;

	// decimal integer literal 十进制整数字面量
	int chest = 42;
	// hexadecimal integer literal 十六进制整数字面量
	int waist = 42;
	// octal integer literal 八进制整数字面量
	int inseam = 42;

	cout << "Monsieur cuts a striking figure!" << endl;
	cout << "chest = " << chest << " (decimal for 42)"<< endl;
	cout << hex; // manipulator for changing number base
	cout << "waist = " << waist << " (hexadecimal for 42)\n";
	cout << oct;
	cout << "inseam = " << inseam << " (octal for 42)\n";

	return 0;
}