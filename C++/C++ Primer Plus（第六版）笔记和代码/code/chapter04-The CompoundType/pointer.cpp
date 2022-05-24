#include <iostream>

int main_pointer()
{
	using namespace std;

	// ���ñ���
	int updates = 6;
	// ����ָ��
	int* p_updates;
	p_updates = &updates;

	// express values two ways
	cout << "Values: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;

	// express address two ways
	cout << "Addresses: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;

	// use pointer to change value
	*p_updates = *p_updates + 1;
	cout << "Now updates = " << updates << endl;

	return 0;
}