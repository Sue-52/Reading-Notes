#include <iostream>

int main_3()
{
	using namespace std;

	// ���ñ���
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	// �������
	cout << "Enter your name: \n";
	// read through newline ��ȡһ�е�����ֵ
	cin.getline(name, ArSize);
	cout << "Enter you favourite dessert:\n";
	cin.getline(dessert, ArSize);

	// �������
	cout << "I have more delicious " << dessert;
	cout << " for you," << name << "\n";

	return 0;
}