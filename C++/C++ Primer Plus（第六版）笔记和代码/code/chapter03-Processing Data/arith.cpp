#include <iostream>

int main()
{
	using namespace std;
	float hats, heads;

	// float - point
	cout.setf(ios_base::fixed, ios_base::floatfield);

	cout << "Enter a number:";
	cin >> hats;
	cout << "Enter another number:";
	cin >> heads;

	cout << "hats = " << hats << endl;
	cout << "heads = " << heads << endl;

	// 计算数值
	cout << "hats - heads = " << hats - heads << endl;
	cout << "hats + heads = " << hats + heads << endl;
	cout << "hats * heads = " << hats * heads << endl;
	cout << "hats / heads = " << hats / heads << endl;

	return 0;
}