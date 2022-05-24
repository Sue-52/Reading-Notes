#include <iostream>
#include <vector>  // ��̬��������
#include <array>   // ��̬��������

using namespace std;

int main_choices()
{
	// C, ԭʼ�� C++ д��
	double arr1[4] = { 1.2, 1.3, 1.4, 1.5 };
	// C++98 STL д��
	vector<double> arr2(4);
	// û�б�ķ�������ʼ����ֵ �� C++98 ��
	arr2[0] = 1.0 / 3.0;
	arr2[1] = 1.0 / 5.0;
	arr2[2] = 1.0 / 7.0;
	arr2[3] = 1.0 / 9.0;

	// C++ 11 ��������ʼ�����鷽��
	array<double, 4> arr3 = { 3.14, 2.72, 1.62, 1.41 };
	array<double, 4> arr4;
	arr4 = arr3; // ����ֱ�Ӹ�ֵ

	// use array notation
	cout << "arr1[2]: " << arr1[2] << " at " << &arr1[2] << endl;
	cout << "arr2[2]: " << arr2[2] << " at " << &arr2[2] << endl;
	cout << "arr3[2]: " << arr3[2] << " at " << &arr3[2] << endl;
	cout << "arr4[2]: " << arr4[2] << " at " << &arr4[2] << endl;

	// misdeed
	// arr1[-2] = 20.2;
	// cout << "arr1[2]: " << arr1[-2] << " at " << &arr1[-2] << endl;
	// cout << "arr3[2]: " << arr3[2] << " at " << &arr3[2] << endl;
	// cout << "arr4[2]: " << arr4[2] << " at " << &arr4[2] << endl;

	return 0;
}