#include <iostream>
const int ArSize = 10;

int main_second()
{
	using namespace std;

	int donation[ArSize];          // 数值数组
	double average = 0;            // 平均值
	double num = 0;                // 大于平均值的个数
	double sum = 0;			       // 总和

	cout << "最多输入10个数字，输入任意非数字结束\n";

	int i = 0;
	// 循环添加并累加数值
	while (i < 10 && cin >> donation[i])
	{
		sum += donation[i];
		++i;
	}

	// 计算大于平均值的个数
	for (int j = 0; j < i; j++)
	{
		if (donation[i] > average)
			num++;
	}
	// 平均值
	average = sum / i;

	cout << "数组中共有" << i << "个数，其中大于平均值" << average << "的有" << num << "个。";

	return 0;
}