#include <iostream>

// structure declaration 声明结构
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main_structur()
{
	using namespace std;
	
	// 设置结构值
	inflatable guest =
	{
		"Glorious Gloria",
		1.88,
		29.99
	};
	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	};

	// 输出
	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name << "!\n";

	cout << "You can have both for $";
	cout << guest.price + pal.price << endl;

	return 0;
}