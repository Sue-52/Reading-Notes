#include <iostream>

int main_addpntrs()
{
	using namespace std;

	double wages[4] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3,2,1 };

	// 获取数组地址
	double* pw = wages;
	short* ps = &stacks[0];
	// 数组元素
	// pw = 0000007352EFF608, *pw = 10000
	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	// ps = 0000007352EFF644, *ps = 3
	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps += 1;
	cout << "Add 1 to the ps pointer:\n";
	// ps = 0000007352EFF646, *ps = 2
	cout << "ps = " << ps << ", *ps = " << *ps << endl;

	cout << "access two elements with array notation\n";
	// stacks[0] = 3, statcks[1] = 2
	cout << "stacks[0] = " << stacks[0]
		<< ", statcks[1] = " << stacks[1] << endl;
	cout << "access two elements with pointer notation\n";
	// *stack = 3, *(stacks + 1) = 2
	cout << "*stack = " << *stacks
		<< ", *(stacks + 1) = " << *(stacks + 1) << endl;

	// 32 = size of wages array
	cout << sizeof(wages) << " = size of wages array\n";
	// 8 = size of pw pointer
	cout << sizeof(pw) << " = size of pw pointer\n";

	return 0;
}