#include <iostream>

struct inflatable
{
	char name[20];
	float volume;
	double price;
	// ֻ���� int��long��double ����
	union id {
		long id_int;
		double id_dou;
	};
};

int main_arrstruc()
{
	using namespace std;

	// ��������ṹֵ
	inflatable guests[2] = {
		{"Bambi", 0.5, 21.99},
		{"Godzilla", 2000, 565.99}
	};

	// ���
	cout << "The guests " << guests[0].name << " and "
		<< guests[1].name << "\nhave a combined volume of "
		<< guests[0].volume + guests[1].volume
		<< " cubic feet .\n";

	return 0;
}