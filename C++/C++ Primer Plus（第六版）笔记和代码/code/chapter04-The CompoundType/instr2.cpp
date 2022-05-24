#include <iostream>

int main_3()
{
	using namespace std;

	// 设置变量
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	// 输如操作
	cout << "Enter your name: \n";
	// read through newline 读取一行的输入值
	cin.getline(name, ArSize);
	cout << "Enter you favourite dessert:\n";
	cin.getline(dessert, ArSize);

	// 输出操作
	cout << "I have more delicious " << dessert;
	cout << " for you," << name << "\n";

	return 0;
}