#include <iostream>
#include <cmath>

int main()
{
	using namespace std;

	// ���� double ���͵ı���
	double area;
	cout << "Enter the floor area, in square feet, of your home:";
	// ��������
	cin >> area;
	// ���� size ����,�洢�����Ľ��
	double size;
	size = sqrt(area);
	// ������
	cout << "That's the equivalent of a square " << size
		<< " feet to the side." << endl;
	cout << "How fascinating!" << endl;

	return 0;
}