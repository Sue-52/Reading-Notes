#include <iostream>
// ����ͷ
void simon(int); // ����һ�� simon �ĺ���

// ���ں����������еĺ������������stdͷ����֮���ں������棬ֻ�е�ǰ��������ʹ��
using namespace std;

int main()
{
	simon(3); // ���� simon ����
	cout << "Pick an integer: ";
	// �������
	int count;
	// ����ֵ
	cin >> count;
	//���ú���
	simon(count);
	// ���ؽ��
	cout << "Done!!" << endl;
	// ��������
	return 0;

}

void simon(int n) {
	cout << "Simon says touch your toes " << n << " times" << endl;
}