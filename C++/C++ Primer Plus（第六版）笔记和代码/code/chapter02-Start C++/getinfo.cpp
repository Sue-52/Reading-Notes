#include <iostream>

int main()
{
	using namespace std;

	int carrots;
	cout << "How many carrots do you have?" << endl;
	// 输入数值
	// 注意：输入的信息流向 carrots。
	// cin 可以通过键盘输入的一系列字符转换为接收信息的变量能够接收的形式。
	// 这里输入的整型变量，因此，计算机该输入转换为用来存储整数的数字形式。
	cin >> carrots;
	cout << "Here are two more. \n";
	carrots = carrots + 2;
	// 输出结果
	cout << "Now you have " << carrots << " carrots" << endl;

	return 0;
}