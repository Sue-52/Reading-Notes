#include <iostream>
#include <cstring>
#pragma warning(disable:4996) // �������ȫ���ⱨ��

using namespace std;
char* getname(void);  // ��������ԭ��

int main_delete()
{
	// ��������
	char* name;
	
	name = getname(); // ����������ֵ���浽name��
	cout << name << " at " << (int*)name << endl;
	// ����ڴ�
	delete[] name;

	// ���µ���
	name = getname();
	cout << name << " at " << (int*)name << endl;
	delete[] name;

	return 0;
}

char* getname()
{
	// ��������
	char temp[80];
	cout << "Enter last name:";
	cin >> temp;
	char* pn = new char[strlen(temp) + 1];
	// cout << strlen(temp) + 1 << endl;
	// ���Ƶ�ַ
	strcpy(pn, temp);

	return pn;
}