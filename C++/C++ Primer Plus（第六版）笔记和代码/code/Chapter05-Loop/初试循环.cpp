#include <iostream>

int main_for()
{
	using namespace std;
	// 解析：
	// 1. i = 0； 设置初始值
	// 2. i < 5； 循环的初始化部分（loop initialization）
	// 4. i++； 数值递增（increment operator）
	for (int i = 0; i < 5; i++)
	{
		// 3. 循环体
		cout << "This is for loop" << endl;
	}
	// 大体格式：
	// for (initialization; test-expression; update-expression)
	//		{ body }

	return 0;
}