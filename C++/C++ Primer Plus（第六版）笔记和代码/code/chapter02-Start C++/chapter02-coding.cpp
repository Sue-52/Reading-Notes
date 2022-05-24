#include <iostream>
void printTime(int, int);

using namespace std;

int main()
{
	// �û�����Сʱ���ͷ�����
	// �����
	/*
		Enter the number of hours��9
		Enter the number of minutes��28
		Time��9:28
	*/

	// 1. ��������
	int hour;
	int minute;

	// 2.��������
	cout << "Please input the hour��";
	cin >> hour;
	cout << "Please input the minute��";
	cin >> minute;
	// 3.���ú���
	printTime(hour, minute);

	return 0;
}

void printTime(int hours, int minutes)
{
	cout << "Enter the number of hours��" << hours << endl;
	cout << "Enter the number of minutes��" << minutes << endl;
	cout << "Time��" << hours << ":" << minutes << endl;
}