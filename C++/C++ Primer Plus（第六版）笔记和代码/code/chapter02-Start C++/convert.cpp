#include <iostream>

// ��Ŀ��
// ����ԡ��ʯӢ������1ʯӢ = 14��

// ���庯������
int stonetolb(int); // ����ԭ��

// ������
int main()
{
	using namespace std;
	// ����ʯӢ��������
	int stone;
	cout << "Enter the weigth in stone: ";
	// ��������
	cin >> stone;
	// ���ú�������
	int pounds = stonetolb(stone);
	// ������
	cout << stone << " stone = " << pounds << " pounds." << endl;

	return 0;
}

int stonetolb(int sts)
{
	// return 14 * sts;
	int pounds = 14 * sts;
	return pounds;
}