#include <iostream>

int main_for()
{
	using namespace std;
	// ������
	// 1. i = 0�� ���ó�ʼֵ
	// 2. i < 5�� ѭ���ĳ�ʼ�����֣�loop initialization��
	// 4. i++�� ��ֵ������increment operator��
	for (int i = 0; i < 5; i++)
	{
		// 3. ѭ����
		cout << "This is for loop" << endl;
	}
	// �����ʽ��
	// for (initialization; test-expression; update-expression)
	//		{ body }

	return 0;
}