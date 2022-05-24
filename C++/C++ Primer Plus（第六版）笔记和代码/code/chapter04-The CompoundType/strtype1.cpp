#include <iostream>

int main_strtype1()
{
	using namespace std;

	// 创建变量
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	// 输入
	cout << "Enter a kind of feline: ";
	cin >> charr1;
	cout << "Enter another kind of feline: ";
	cin >> str1;

	// 输出
	cout << charr1 << " " << charr2 << " "
		<< str1 << " " << str2 << endl;
	cout << "The third letter in " << charr2 << " is "
		<< charr2[2] << endl;
	cout << "The third letter in " << str2 << " is "
		<< str2[2] << endl;

	return 0;
}