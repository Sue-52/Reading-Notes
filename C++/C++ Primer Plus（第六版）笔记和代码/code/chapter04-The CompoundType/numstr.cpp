#include <iostream>

int main_numstr()
{
	using namespace std;

	// ���ñ���
	int year;
	char address[80];

	// ����
	cout << "What year was your house built?\n";
	cin >> year;
	cin.get();
	cout << "What is its street address?\n";
	// �� year ����������ɻ��з����� getline ��Ϊ��һ�����У�
	cin.getline(address, 80);

	// ���
	cout << "Year built��" << year << endl;
	cout << "Address��" << address << endl;
	cout << "Done! \n";

	return 0;
}