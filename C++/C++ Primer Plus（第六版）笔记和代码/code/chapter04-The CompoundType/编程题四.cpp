// string中可以进行 + 、 = 、 += 、 > 等运算，而cstring中不能进行相关运算。
//与上体大致相同，但本次要求使用string对象和string头文件
#include<iostream>
#include <string>

int main_forth()
{
    using namespace std;

    string first_name;
    string last_name;
    string full_name;

    cout << "What is your first name?";
    cin >> first_name;
    cout << "what is your last name? ";
    cin >> last_name;

    full_name = first_name + ',' + ' ' + last_name;

    cout << "here is the information in a single string: " << full_name << endl;

    return 0;
}