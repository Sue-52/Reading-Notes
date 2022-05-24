#include <iostream>
#include <string>

int main_forstr1()
{
	using namespace std;

	string word;
	cout << "Enter a word: ";
	cin >> word;

	// 循环反向输出字符串
	for (int i = word.size() - 1; i >= 0; i--)
	{
		cout << word[i];
	};

	cout << endl;
	cout << "-------------------" << endl;

	// 正常循环输出字符串
	for (int i = 0; i <= word.size() - 1; i++)
	{
		cout << word[i];
	}

	return 0;
}