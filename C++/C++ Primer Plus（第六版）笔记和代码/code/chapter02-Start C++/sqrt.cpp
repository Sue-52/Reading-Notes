#include <iostream>
#include <cmath>

int main()
{
	using namespace std;

	// 定义 double 类型的变量
	double area;
	cout << "Enter the floor area, in square feet, of your home:";
	// 输入数据
	cin >> area;
	// 创建 size 变量,存储运算后的结果
	double size;
	size = sqrt(area);
	// 输出结果
	cout << "That's the equivalent of a square " << size
		<< " feet to the side." << endl;
	cout << "How fascinating!" << endl;

	return 0;
}