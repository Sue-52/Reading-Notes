#include <iostream>

int main_plus_one()
{
	using namespace std;

	int a = 20, b = 20;

	cout << "a   = " << a << ":   b = " << b << endl;
	// ǰ++��ʹ�õ�ǰֵ���м�����ٽ������ 1
	// ��++������ǰֵ�ȵ��� 1 �������ֵ
	cout << "a++ = " << a++ << ": ++b = " << ++b << endl;
	cout << "a   = " << a << ":   b = " << b << endl;

	return 0;
}