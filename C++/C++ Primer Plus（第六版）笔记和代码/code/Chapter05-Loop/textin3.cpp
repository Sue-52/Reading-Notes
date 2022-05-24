#include <iostream>

int main_textin3()
{
	using namespace std;

	char ch;
	int count = 0;

	cout << "Enter characters; enter Ctrl + z to quit:\n";
	cin >> ch;

	while (cin.fail() == false)
	{
		cout << ch;
		++count;
		cin.get(ch);
	}

	cout << endl;
	cout << count << " characters read\n";

	return 0;
}