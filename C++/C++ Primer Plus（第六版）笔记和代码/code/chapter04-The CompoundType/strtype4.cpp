#include <iostream>
#include <string>
#include <cstring>

int main()
{
	using namespace std;

	// ���ñ���
	char charr[20];
	string str;

	// ���롢������ֵ
	cout << "Length of string in char before input: "
		<< strlen(charr) << endl;
	cout << "Length of string in str before input: "
		<< str.size() << endl;
	cout << "Enter a line of text:\n";
	cin.getline(charr, 20);

	return 0;
}