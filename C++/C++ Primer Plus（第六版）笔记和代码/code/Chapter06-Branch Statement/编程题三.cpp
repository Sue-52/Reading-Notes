#include <iostream>

int main_third()
{
	using namespace std;

	char ch;

	cout << "Please enter one of the following choices:\n";
	cout << "c) carnivore           p) pianist\n";
	cout << "t) tree                g) game\n";

	while (cin >> ch)
	{
		switch (ch)
		{
		case 'c':
			cout << "A maple is a tree.";
			break;
		case 'p':
			cout << "A maple is a tree.";
			break;
		case 't':
			cout << "A maple is a tree.";
			break;
		case 'g':
			cout << "A maple is a tree.";
			break;
		default:
			cout << "Please enter a c, p, t, or g: ";
			break;
		}
	}

	return 0;
}