#include <iostream>
#include <string>

int main_compstr2()
{
	using namespace std;

	string word = "?ate";

	// strcmp() �ж������ַ����Ƿ���ͬ
	for (char ch = 'a'; word != "mate"; ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}

	cout << "After loop ends, word is " << word << endl;


	return 0;
}