#include <iostream>
// �����ṹ
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main_newstrct()
{
	using namespace std;

	//��̬�����ṹ
	inflatable* ps = new inflatable;

	// �ṹ���������
	cout << "Enter name of inflatable item: ";
	cin.get(ps->name, 20);

	// �ṹ��� volume
	cout << "Enter volume in cubic feet: ";
	cin >> (*ps).volume;

	// �ṹ����� price
	cout << "Enter price: $";
	cin >> ps->price;

	// ���
	cout << "Name: " << (*ps).name << endl;
	cout << "Volume: " << ps->volume << endl;
	cout << "Price: $" << ps->price << endl;
	
	// ����ڴ�
	delete ps;

	return 0;
}