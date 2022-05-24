#include <iostream>

int main_4()
{
	using namespace std;

	// 设置变量
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	// 输如操作
	cout << "Enter your name: \n";
	// read string, newline
	// 第一个get读取输入数值
	// 第二个get拼接输入数值
	cin.get(name, ArSize).get();
	cout << "Enter you favourite dessert:\n";
	cin.get(dessert, ArSize).get();

	// 输出操作
	cout << "I have more delicious " << dessert;
	cout << " for you," << name << "\n";

	return 0;
}