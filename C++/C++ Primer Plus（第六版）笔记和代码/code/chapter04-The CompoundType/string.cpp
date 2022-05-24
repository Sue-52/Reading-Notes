#include <iostream>
#include <cstring>

int main_1()
{
	using namespace std;

	// 定义变量
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	// 输出结果
	cout << "Howdy! I'm " << name2;
	cout << "! What's your name? \n";
	cin >> name1;
	cout << "Well, " << name1 << ",your name has ";
	// sizeof 指出数组长度
	cout << "in an array of " << sizeof(name1) << " bytes.\n";
	cout << "Your initial is " << name1[0] << ".\n";
	name2[3] = '\0';
	cout << "Here are the first 3 characters of my name: ";
	cout << name2 << endl;

	return 0;
}