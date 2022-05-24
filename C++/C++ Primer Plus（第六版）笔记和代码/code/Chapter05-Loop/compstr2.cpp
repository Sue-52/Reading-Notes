#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string word = "?ate";

	// strcmp() 判断两个字符串是否相同
	for (char ch = 'a'; word != "mate"; ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}

	cout << "After loop ends, word is " << word << endl;


	return 0;
}