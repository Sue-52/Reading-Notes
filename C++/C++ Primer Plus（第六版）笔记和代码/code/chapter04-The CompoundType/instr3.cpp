#include <iostream>

int main_4()
{
	using namespace std;

	// ���ñ���
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	// �������
	cout << "Enter your name: \n";
	// read string, newline
	// ��һ��get��ȡ������ֵ
	// �ڶ���getƴ��������ֵ
	cin.get(name, ArSize).get();
	cout << "Enter you favourite dessert:\n";
	cin.get(dessert, ArSize).get();

	// �������
	cout << "I have more delicious " << dessert;
	cout << " for you," << name << "\n";

	return 0;
}