// typecast.cpp -- forcing type changes
#include <iostream>

int main()
{
	using namespace std;

	// ��ʼ������
	int auks, bats, coots;

	// the following statement adds the values as double
	// the converts the result to int
	auks = 19.99 + 11.99;

	// these statements add value as int
	// ��ʽ C ���Ը�ʽ
	bats = (int)19.99 + (int)11.99;
	// ��ʽ C++ ���Ը�ʽ
	coots = int(19.99) + int(11.99);
	// ������
	cout << "auks = " << auks << endl;
	cout << "bats = " << bats << endl;
	cout << "coots = " << coots << endl;

	// ���� char ����
	char ch = 'z';
	// ��� ch
	cout << "The code for " << ch << " is "
		<< int(ch) << endl;
	// ʹ�� static_cast
	cout << "Yes, the code is "
		<< static_cast<int>(ch) << endl;

	return 0;
}