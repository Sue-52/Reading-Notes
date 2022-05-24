#include <iostream>
// 创建结构
struct antarctica_years_end
{
	int year;
};

using namespace std;

int main_mixtypes()
{
	// 创建类型变量
	antarctica_years_end s01, s02, s03;
	// 运算符赋值
	s01.year = 1998;
	// 创建指针
	antarctica_years_end* pa = &s02;
	// 赋值
	pa->year = 1999;
	// 创建结构数组
	antarctica_years_end trio[3];
	// 结构数组赋值
	trio[0].year = 2003;
	cout << trio->year << endl;
	
	// 创建结构数组并保存地址
	const antarctica_years_end* arp[3] = { &s01,&s02,&s03 };
	// 获取数据
	cout << arp[1]->year << endl;
	const antarctica_years_end** ppa = arp;
	// 自动判断类型
	auto ppd = arp;
	cout << (*ppa)->year << endl;
	cout << (*(ppa + 1))->year << endl;

	return 0;
}