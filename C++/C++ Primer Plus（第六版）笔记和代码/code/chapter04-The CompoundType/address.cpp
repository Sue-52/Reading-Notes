#include <iostream>

int main_address()
{
	using namespace std;
	// 定义变量
	int donute = 6;
	double cups = 4.5;

	cout << "donuts value = " << donute;
	cout << " and dontus address = " << &donute << endl;

	cout << "cups value = " << cups;
	cout << " and cups address = " << &cups << endl;

	return 0;
}