#include <iostream>
const int ArSize = 10;

int main_second()
{
	using namespace std;

	int donation[ArSize];          // ��ֵ����
	double average = 0;            // ƽ��ֵ
	double num = 0;                // ����ƽ��ֵ�ĸ���
	double sum = 0;			       // �ܺ�

	cout << "�������10�����֣�������������ֽ���\n";

	int i = 0;
	// ѭ����Ӳ��ۼ���ֵ
	while (i < 10 && cin >> donation[i])
	{
		sum += donation[i];
		++i;
	}

	// �������ƽ��ֵ�ĸ���
	for (int j = 0; j < i; j++)
	{
		if (donation[i] > average)
			num++;
	}
	// ƽ��ֵ
	average = sum / i;

	cout << "�����й���" << i << "���������д���ƽ��ֵ" << average << "����" << num << "����";

	return 0;
}