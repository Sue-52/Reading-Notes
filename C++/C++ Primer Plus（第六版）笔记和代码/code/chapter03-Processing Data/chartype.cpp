// chartype.cpp -- the char type
#include <iostream>

int main()
{
	using namespace std;
	
	// 定义 char 类型数据
	// 只能容纳一个字符
	char ch;

	cout << "Enter a charactor：" << endl;
	cin >> ch;
	cout << "Hola！";
	cout << "Thank you for the " << ch << " charactor" << endl;

	return 0;
}