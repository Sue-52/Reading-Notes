#include <iostream>

int main_textin2()
{
	using namespace std;

	char ch;
	int count = 0;

	cout << "Enter characters; enter # to quit:\n";
	cin.get(ch);

	while (ch !='#')
	{
		cout << ch;
		++count;
		cin.get(ch);
	}

	cout << endl;
	cout << count << " characters read\n";

	return 0;
}