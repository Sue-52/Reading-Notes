// string�п��Խ��� + �� = �� += �� > �����㣬��cstring�в��ܽ���������㡣
//�����������ͬ��������Ҫ��ʹ��string�����stringͷ�ļ�
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