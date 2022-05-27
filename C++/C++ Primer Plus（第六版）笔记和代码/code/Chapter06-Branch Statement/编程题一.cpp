#include <iostream>
#include <cctype>

int main_first()
{
	using namespace std;

	char ch;

	while (cin >> ch && ch != '@')
	{
		if (islower(ch))
		{
			ch = toupper(ch);
			cout << ch;
			continue;
		}
		else if (isupper(ch))
		{ 
			ch = tolower(ch);
			cout << ch;
			continue;
		}
	}

	return 0;
}