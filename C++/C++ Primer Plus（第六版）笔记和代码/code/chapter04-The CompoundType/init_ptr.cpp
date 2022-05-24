#include <iostream>

int main_init_ptr()
{
	using namespace std;
	// 定义变量
	int higgens = 5;
	int* pt = &higgens;

	// int* pt;
	// pt = (int * ) 0xB8000000;

	cout << "Value of higgens = " << higgens
		<< "; Address of higgens = " << &higgens << endl;
	cout << "Value of *pt = " << *pt
		<< "; Address og pt = " << pt << endl;

	return 0;
}