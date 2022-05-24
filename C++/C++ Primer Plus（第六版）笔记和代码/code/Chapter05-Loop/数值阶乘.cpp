#include <iostream>

const int ArSize = 16;

int main_formore()
{
	using namespace std;

	long long factorials[ArSize];
	factorials[1] = factorials[0] = 1LL;

	// 计算阶乘并存储进数组中
	for (int i = 2; i < ArSize; i++)
	{
		factorials[i] = i * factorials[i - 1];
	};
	// 输出结果
	for (int i = 0; i < ArSize; i++)
		cout << i << "! = " << factorials[i] << endl;

	return 0;
}