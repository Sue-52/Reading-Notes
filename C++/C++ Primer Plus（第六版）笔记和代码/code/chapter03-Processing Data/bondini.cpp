// bondini.cpp -- using escape sequences
#include <iostream>

int main()
{
	using namespace std;
	// 转义字符使用
	cout << "\aOperation \"HyperHype\" is now activated!\n";
	cout << "Enter your agent code:_____\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "\aYou enterd " << code << "...\n";
	cout << "\aCode verified! Proceed with Plan 23!\n";


	return 0;
}