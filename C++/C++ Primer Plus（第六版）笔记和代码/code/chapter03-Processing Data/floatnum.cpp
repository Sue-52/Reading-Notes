// floatnum.cpp -- floating-point types
#include <iostream>

int main()
{
	using namespace std;

	// fixed - point
	cout.setf(ios_base::fixed, ios_base::floatfield);
	// good to about 6 places
	float tub = 10.0 / 3.0;
	// good to about 15 places
	double mint = 10.0 / 3.0;
	// million
	const float million = 1.0e6;

	// 输出结果
	cout << "tub = " << tub;
	cout << ", a million tubs = "
		<< million * tub;
	cout << ", \nand ten million tubs = ";
	cout << 10 * million * tub << endl;

	cout << "mint = " << mint << ", a million tubs = ";
	cout << million * mint << endl;

	// float 显示小数点后6位
	cout << 1.234f << endl;


	return 0;
}