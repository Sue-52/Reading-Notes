#include<iostream>
#include <cstring>
#pragma warning(disable:4996) // �������ȫ���ⱨ��

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
    
    strncpy(full_name, last_name, 20);//strcnpy�ǽ�ָ�����ȵ��ַ������Ƶ�ָ����������
    strcat(full_name, ", ");//������char��������
    strncat(full_name, first_name, 20);//���ַ���ĩβ׷��n���ַ�
    full_name[20 - 1] = '\0';
    
    cout << "here is the information in a single string: " << full_name << endl;
    
    return 0;
}