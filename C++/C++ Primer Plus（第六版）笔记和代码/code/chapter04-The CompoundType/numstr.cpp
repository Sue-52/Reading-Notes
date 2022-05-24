#include <iostream>

int main_numstr()
{
	using namespace std;

	// 设置变量
	int year;
	char address[80];

	// 输入
	cout << "What year was your house built?\n";
	cin >> year;
	cin.get();
	cout << "What is its street address?\n";
	// 在 year 输入完后生成换行符，而 getline 认为是一个空行，
	cin.getline(address, 80);

	// 输出
	cout << "Year built：" << year << endl;
	cout << "Address：" << address << endl;
	cout << "Done! \n";

	return 0;
}