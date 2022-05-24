#include <iostream>
// 函数头
void simon(int); // 定义一个 simon 的函数

// 放在函数外面所有的函数都无需添加std头；反之放在函数里面，只有当前函数可以使用
using namespace std;

int main()
{
	simon(3); // 调用 simon 函数
	cout << "Pick an integer: ";
	// 定义变量
	int count;
	// 输入值
	cin >> count;
	//调用函数
	simon(count);
	// 返回结果
	cout << "Done!!" << endl;
	// 结束进程
	return 0;

}

void simon(int n) {
	cout << "Simon says touch your toes " << n << " times" << endl;
}