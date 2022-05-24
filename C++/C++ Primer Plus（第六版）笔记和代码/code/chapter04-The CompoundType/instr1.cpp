#include <iostream>

int main_2()
{
	using namespace std;

	// 定义变量
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	// 输如操作
	cout << "Enter your name: \n";
	cin >> name;
	cout << "Enter you favourite dessert:\n";
	cin >> dessert;

	// 输出操作
	cout << "I have more delicious " << dessert;
	cout << " for you," << name << "\n";

	return 0;
}