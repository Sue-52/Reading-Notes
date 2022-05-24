#include <iostream>
#include <cstring>
#pragma warning(disable:4996) // 解决不安全问题报错

int main_ptrstr()
{
	using namespace std;

	// 定义变量
	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;

	// 输出
	cout << animal << " and "
		<< bird << endl;
	// 可能导致阻塞
	// cout << ps << "\n";

	cout << "Enter a kind of animal: ";
	cin >> animal;      // 输入必须小于 20 个字符

	ps = animal;
	cout << ps << "!\n";
	cout << "Before using strcpy():\n";
	cout << animal << " at "
		<< (int*)animal << endl;
	cout << ps << " at "
		<< (int*)ps << endl;

	// 创建新的内存
	ps = new char[strlen(animal) + 1];
	// 第一个参数：目标地址
	// 第二个参数：复制的字符串地址
	strcpy(ps, animal); // 复制
	cout << "After using strcpy():\n";
	cout << animal << " at "
		<< (int*)animal << endl;
	cout << ps << " at "
		<< (int*)ps << endl;

	// 清除内存
	delete[] ps;

	return 0;
}