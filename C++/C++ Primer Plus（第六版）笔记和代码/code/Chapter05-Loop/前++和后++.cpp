#include <iostream>

int main_plus_one()
{
	using namespace std;

	int a = 20, b = 20;

	cout << "a   = " << a << ":   b = " << b << endl;
	// 前++：使用当前值进行计算后再将其递增 1
	// 后++：将当前值先递增 1 后计算数值
	cout << "a++ = " << a++ << ": ++b = " << ++b << endl;
	cout << "a   = " << a << ":   b = " << b << endl;

	return 0;
}