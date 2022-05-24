// hexoct.cpp -- shows hex and octal literals
#include <iostream>

int main()
{
	using namespace std;

	// decimal integer literal ʮ��������������
	int chest = 42;
	// hexadecimal integer literal ʮ����������������
	int waist = 42;
	// octal integer literal �˽�������������
	int inseam = 42;

	cout << "Monsieur cuts a striking figure!" << endl;
	cout << "chest = " << chest << " (decimal for 42)"<< endl;
	cout << hex; // manipulator for changing number base
	cout << "waist = " << waist << " (hexadecimal for 42)\n";
	cout << oct;
	cout << "inseam = " << inseam << " (octal for 42)\n";

	return 0;
}