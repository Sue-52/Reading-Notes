#include <iostream>

int main_use_new()
{
	using namespace std;

	// 定义变量
	int nights = 1001;
	int* pt = new int;
	*pt = 1001;

	// 动态创建数组
	int* psome = new int[10];
	// 清除内存
	delete[] psome;

	cout << "nights value = ";
	cout << nights << ": location " << &nights << endl;
	cout << "int "
		<< "value = " << *pt << ": location = "
		<< pt << endl;

	double* pd = new double;
	*pd = 10000001.0;

	cout << "double "
		<< "value = " << *pd << ": location = "
		<< pd << endl;
	cout << "location of pointer pd: " << &pd << endl;
	cout << "size od pt = " << sizeof(pt)
		<< ": size of *pt = " << sizeof(*pt) << endl;
	cout << "size od pd = " << sizeof(pd)
		<< ": size of *pd = " << sizeof(*pd) << endl;

	return 0;
}