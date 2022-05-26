#include <iostream>

const int ArSize = 80;

int main_jump()
{
	using namespace std;

	char line[ArSize];
	int space = 0;

	cout << "Enter a line of text:\n";
	cin >> line;
	cout << "Complete line:\n" << line << endl;
	cout << "Line througth first period:\n";

	for (int i = 0; i < line[i] != '\0'; i++)
	{
		cout << line[i];
		if (line[i] == '.')
		{
			break;
		}
		if (line[i] != ' ')
		{
			continue;
		}
		space++;
	}
	cout << "\n" << space << " spaces\n";
	cout << "Done.\n";

	return 0;
}