#include <iostream>
#include <string>  // make string class available
#include <cstring>  // C-style string library int main（）
#pragma warning(disable:4996) // 解决不安全问题报错

int main_strtype3()
{
	using namespace std;

	// 设置变量
	char charr1[20]; 
	char charr2[20] = "jaguar"; 
	string str1; 
	string str2 = "panther";

	// assignment for string objects and character arrays 
	str1 = str2;                 // copy str2 to strl 
	strcpy(charr1, charr2);      // /copy charr2 to charrl

	// appending for string objects and character arrays
	str1 += " paste";             // add paste to end of str1
	strcat(charr1, " juice");     // add juice to end of charrl

	// finding the length of a string object and a c-style string
	int len1 = str1.size();
	int len2 = strlen(charr1);

	// 输出结果
	cout << "The string " << str1 << " contains "
		<< len1 << " characters.\n"; 
	cout << "The string " << charr1 << " contains "
		<< len2 << " characters.\n";

	return 0;
}
