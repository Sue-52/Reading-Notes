#include <iostream>
#include <cstring>
#pragma warning(disable:4996) // �������ȫ���ⱨ��

int main_ptrstr()
{
	using namespace std;

	// �������
	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;

	// ���
	cout << animal << " and "
		<< bird << endl;
	// ���ܵ�������
	// cout << ps << "\n";

	cout << "Enter a kind of animal: ";
	cin >> animal;      // �������С�� 20 ���ַ�

	ps = animal;
	cout << ps << "!\n";
	cout << "Before using strcpy():\n";
	cout << animal << " at "
		<< (int*)animal << endl;
	cout << ps << " at "
		<< (int*)ps << endl;

	// �����µ��ڴ�
	ps = new char[strlen(animal) + 1];
	// ��һ��������Ŀ���ַ
	// �ڶ������������Ƶ��ַ�����ַ
	strcpy(ps, animal); // ����
	cout << "After using strcpy():\n";
	cout << animal << " at "
		<< (int*)animal << endl;
	cout << ps << " at "
		<< (int*)ps << endl;

	// ����ڴ�
	delete[] ps;

	return 0;
}