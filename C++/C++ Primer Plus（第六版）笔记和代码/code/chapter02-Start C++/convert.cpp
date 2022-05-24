#include <iostream>

// 题目：
// 计算浴室石英重量，1石英 = 14镑

// 定义函数类型
int stonetolb(int); // 函数原型

// 主函数
int main()
{
	using namespace std;
	// 声明石英数量变量
	int stone;
	cout << "Enter the weigth in stone: ";
	// 输入数量
	cin >> stone;
	// 调用函数计算
	int pounds = stonetolb(stone);
	// 输出结果
	cout << stone << " stone = " << pounds << " pounds." << endl;

	return 0;
}

int stonetolb(int sts)
{
	// return 14 * sts;
	int pounds = 14 * sts;
	return pounds;
}