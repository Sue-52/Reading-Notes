#include <iostream>

const int Fave = 27;

int main_ifelseif()
{
	using namespace std;

	int n;

	cout << "Enter a number in the range 1-100 to find.\n";
	cout << "My favourite number is: ";
	
	do
	{
		cin >> n;
		
		// ���������ֵС�� Fave �Ľ��
		if (n < Fave)
		{
			cout << "Too low -- guess again: ";
		}
		// ���������ֵ���� Fave �Ľ��
		else if (n > Fave)
		{
			cout << "Too hight -- guess again: ";
		}
		// ��ȷ�����
		else
		{
			cout << Fave << " is right! \n";
		}

	// ֻҪѭ�������� Fave �ͻ�һֱִ��
	} while (n != Fave);
	
	return 0;
}