#include <iostream>

int main_ifelse()
{
	using namespace std;

	char ch;
	cout << "Type, and I shall repeat.\n";
	cin.get(ch);

	while (ch != '.')
	{
		if (ch == '\n')
		{
			cout << ch;
		}
		else {
			cout << ++ch; // ASUCIIÂë++
		}
		cin.get(ch);
	}

	cout << "\nPlease sxcuse the slight confusion.\n";

	return 0;
}