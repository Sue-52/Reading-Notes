#include <iostream>

struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main_assign_st()
{
	using namespace std;

	// 结构设置值
	inflatable bouquet =
	{
		"sunflowers",
		0.20,
		12.49
	};
	inflatable choice;

	// 设置、输出
	cout << "bouquet: " << bouquet.name << " for $";
	cout << bouquet.price << endl;

	choice = bouquet;
	cout << "choice: " << choice.name << " for $";
	cout << choice.price << endl;

	return 0;
}