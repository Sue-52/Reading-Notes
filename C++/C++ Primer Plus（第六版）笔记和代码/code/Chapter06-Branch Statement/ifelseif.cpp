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
		
		// 如果输入数值小于 Fave 的结果
		if (n < Fave)
		{
			cout << "Too low -- guess again: ";
		}
		// 如果输入数值大于 Fave 的结果
		else if (n > Fave)
		{
			cout << "Too hight -- guess again: ";
		}
		// 正确及俄国
		else
		{
			cout << Fave << " is right! \n";
		}

	// 只要循环不等于 Fave 就会一直执行
	} while (n != Fave);
	
	return 0;
}