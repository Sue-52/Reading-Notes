#include <iostream>
#include <cstring>
#pragma warning(disable:4996) // 解决不安全问题报错

using namespace std;
char* getname(void);  // 声明函数原型

int main_delete()
{
	// 创建变量
	char* name;
	
	name = getname(); // 将函数返回值保存到name中
	cout << name << " at " << (int*)name << endl;
	// 清除内存
	delete[] name;

	// 重新调用
	name = getname();
	cout << name << " at " << (int*)name << endl;
	delete[] name;

	return 0;
}

char* getname()
{
	// 创建变量
	char temp[80];
	cout << "Enter last name:";
	cin >> temp;
	char* pn = new char[strlen(temp) + 1];
	// cout << strlen(temp) + 1 << endl;
	// 复制地址
	strcpy(pn, temp);

	return pn;
}