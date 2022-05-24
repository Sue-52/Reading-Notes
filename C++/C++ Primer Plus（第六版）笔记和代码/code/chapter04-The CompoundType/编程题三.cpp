#include<iostream>
#include <cstring>
#pragma warning(disable:4996) // 解决不安全问题报错

int main_third()
{
    using namespace std;
    char first_name[20];
    char last_name[20];
    char full_name[2 * 20 + 1];


    cout << "What is your first name?";
    cin >> first_name;
    cout << "what is your last name? ";
    cin >> last_name;
    
    strncpy(full_name, last_name, 20);//strcnpy是将指定长度的字符串复制到指定的数组中
    strcat(full_name, ", ");//将两个char类型连接
    strncat(full_name, first_name, 20);//在字符串末尾追加n个字符
    full_name[20 - 1] = '\0';
    
    cout << "here is the information in a single string: " << full_name << endl;
    
    return 0;
}