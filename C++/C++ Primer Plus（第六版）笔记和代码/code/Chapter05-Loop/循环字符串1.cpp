#include <iostream>
#include <string>

int main_forstr1()
{
	using namespace std;

	string word;
	cout << "Enter a word: ";
	cin >> word;

	// ѭ����������ַ���
	for (int i = word.size() - 1; i >= 0; i--)
	{
		cout << word[i];
	};

	cout << endl;
	cout << "-------------------" << endl;

	// ����ѭ������ַ���
	for (int i = 0; i <= word.size() - 1; i++)
	{
		cout << word[i];
	}

	return 0;
}