#include <iostream>

int main_if()
{
	using namespace std;

	// 定义变量
	char ch;
	int spaces = 0;
	int total = 0;

	// 输入
	cin.get(ch);

	// 循环判断
	while (ch != '.')
	{
		if (ch == ' ')
		{
			++spaces;
		};
		++total;

		cin.get(ch);
	}

	cout << spaces << " spaces, " << total;
	cout << " characters total in sentence\n";

	return 0;
}