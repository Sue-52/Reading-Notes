#include <iostream>
#include <fstream>
#include <cstdlib>

int n = 0;

int main_eighth()
{
	using namespace std;

	ifstream inFile;
	inFile.open("123.txt");
	if (!inFile.is_open())
	{
		exit(EXIT_FAILURE);
	}

	char ch;
	while (ch = inFile.get() != EOF)
	{
		n += 1;
	}
	cout << "×Ö·ûÊýÁ¿£º" << n << endl;

	return 0;
}