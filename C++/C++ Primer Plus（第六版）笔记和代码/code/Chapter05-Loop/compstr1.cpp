#include <iostream>
#include <cstring>

int main_compstr1()
{
	using namespace std;

	char word[5] = "?ate";

	// strcmp() 判断两个字符串是否相同
	for (char ch = 'a'; strcmp(word, "mate"); ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}

	cout << "After loop ends, word is " << word << endl;

	return 0;
}