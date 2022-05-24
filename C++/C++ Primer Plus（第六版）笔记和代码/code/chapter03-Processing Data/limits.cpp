// limits.cpp -- some integer limits
#include <iostream>
#include <climits>

int main()
{
	// 名称空间
	using namespace std;
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	// 通过 sizeof 获取其字节
	cout << "int is " << sizeof(n_int) << " bytes." << endl;
	cout << "short is " << sizeof(short) << " bytes." << endl;
	cout << "long is " << sizeof(long) << " bytes." << endl;
	cout << "long long is " << sizeof(long long) << " bytes." << endl;
	cout << endl;

	// 获取最大字节
	cout << "Maximum values:" << endl;
	cout << "int：" << n_int << endl;
	cout << "short：" << n_short << endl;
	cout << "long：" << n_long << endl;
	cout << "long long：" << n_llong << endl;
	cout << endl;

	// 获取最小字节
	cout << "Minimun int value = " << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;

	return 0;
}