#include <iostream>
#include <string>

int main_forstr2()
{
	using namespace std;

	string word;

	cout << "Enter a word: ";
	cin >> word;

	// physically modify string object
	char temp;
	int i, j;
	for (j = 0, i = word.size() - 1; j < i; --i, ++j)
	{
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}

	cout << word << "\nDone!\n";

	return 0;
}