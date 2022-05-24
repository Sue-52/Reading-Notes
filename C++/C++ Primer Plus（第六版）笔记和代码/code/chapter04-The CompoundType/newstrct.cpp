#include <iostream>
// 创建结构
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main_newstrct()
{
	using namespace std;

	//动态创建结构
	inflatable* ps = new inflatable;

	// 结构中添加姓名
	cout << "Enter name of inflatable item: ";
	cin.get(ps->name, 20);

	// 结构添加 volume
	cout << "Enter volume in cubic feet: ";
	cin >> (*ps).volume;

	// 结构中添加 price
	cout << "Enter price: $";
	cin >> ps->price;

	// 输出
	cout << "Name: " << (*ps).name << endl;
	cout << "Volume: " << ps->volume << endl;
	cout << "Price: $" << ps->price << endl;
	
	// 清除内存
	delete ps;

	return 0;
}