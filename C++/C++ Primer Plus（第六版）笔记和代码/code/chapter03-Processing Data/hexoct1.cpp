// hexoct.cpp -- shows hex and octal literals
#include <iostream>

int main()
{
	using namespace std;

	// decimal integer literal ʮ��������������
	int chest = 42;
	// hexadecimal integer literal ʮ����������������
	int waist = 0x42;
	// octal integer literal �˽�������������
	int inseam = 042;

	cout << "Monsieur cuts a striking figure!\n";
	cout << "chest = " << chest << " (42 in decimal)\n";
	cout << "waist = " << waist << " (0x42 in hex)\n";
	cout << "inseam = " << inseam << " (042 in octal)\n";

	return 0;
}