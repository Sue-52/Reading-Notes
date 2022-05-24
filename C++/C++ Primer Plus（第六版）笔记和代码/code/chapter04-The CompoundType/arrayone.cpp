// arrayone.cpp -- small arrays of integers
#include <iostream>

using namespace std;

int main()
{
	// ����ֻ�� 3 λ������
	int yams[3];
	// ��������ֵ
	yams[0] = 7;
	yams[1] = 7;
	yams[2] = 7;

	// ������ʼ������
	int yamcosts[3] = { 20, 30, 5 };
	// ע��㣺
	// ����������޷���ʼ�� yamcosts ������ÿ������������ֵ

	cout << "Total yams = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams costs ";
	cout << yamcosts[1] << " cents per yam.\n";
	
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout << "The total yam expense is " << total << " cents.\n";

	// 12 �ֽ�˵��ÿ������Ԫ��ռ���� 4 �ֽ�
	cout << "\nSize of yams array = " << sizeof yams;
	cout << " bytes.\n";
	// ��� 4 �ֽ�
	cout << "Size of one element = " << sizeof yams[0];
	cout << " bytes. \n";

	return 0;
}