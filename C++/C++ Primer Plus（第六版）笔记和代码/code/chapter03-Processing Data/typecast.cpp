// typecast.cpp -- forcing type changes
#include <iostream>

int main()
{
	using namespace std;

	// 初始化变量
	int auks, bats, coots;

	// the following statement adds the values as double
	// the converts the result to int
	auks = 19.99 + 11.99;

	// these statements add value as int
	// 旧式 C 语言格式
	bats = (int)19.99 + (int)11.99;
	// 新式 C++ 语言格式
	coots = int(19.99) + int(11.99);
	// 输出结果
	cout << "auks = " << auks << endl;
	cout << "bats = " << bats << endl;
	cout << "coots = " << coots << endl;

	// 定义 char 变量
	char ch = 'z';
	// 输出 ch
	cout << "The code for " << ch << " is "
		<< int(ch) << endl;
	// 使用 static_cast
	cout << "Yes, the code is "
		<< static_cast<int>(ch) << endl;

	return 0;
}