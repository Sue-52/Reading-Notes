// arrayone.cpp -- small arrays of integers
#include <iostream>

using namespace std;

int main()
{
	// 创建只有 3 位的数组
	int yams[3];
	// 单独设置值
	yams[0] = 7;
	yams[1] = 7;
	yams[2] = 7;

	// 创建初始化数组
	int yamcosts[3] = { 20, 30, 5 };
	// 注意点：
	// 如果编译器无法初始化 yamcosts 数组则将每个索引单独赋值

	cout << "Total yams = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams costs ";
	cout << yamcosts[1] << " cents per yam.\n";
	
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "The total yam expense is " << total << " cents.\n";

	// 12 字节说明每个索引元素占用了 4 字节
	cout << "\nSize of yams array = " << sizeof yams;
	cout << " bytes.\n";
	// 输出 4 字节
	cout << "Size of one element = " << sizeof yams[0];
	cout << " bytes. \n";

	return 0;
}