#include <iostream>

int main_textin4()
{
	using namespace std;

	char ch;
	int count = 0;

	cout << "Enter characters; enter Ctrl + z to quit:\n";
	cin >> ch;

	while ((ch = cin.get()) != EOF)
	{
		cout.put(char(ch));
		++count;
	}

	cout << endl;
	cout << count << " characters read\n";

	return 0;
}