#include <iostream>

int main()
{
	using namespace std;

	int carrots;
	cout << "How many carrots do you have?" << endl;
	// ������ֵ
	// ע�⣺�������Ϣ���� carrots��
	// cin ����ͨ�����������һϵ���ַ�ת��Ϊ������Ϣ�ı����ܹ����յ���ʽ��
	// ������������ͱ�������ˣ������������ת��Ϊ�����洢������������ʽ��
	cin >> carrots;
	cout << "Here are two more. \n";
	carrots = carrots + 2;
	// ������
	cout << "Now you have " << carrots << " carrots" << endl;

	return 0;
}