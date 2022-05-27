#include <iostream>
// ���庯��
void showReport();
void choice_a();
void choice_b();
void choice_c();
void choice_d();

const int strsize = 30;
const int num = 5;
// ����ṹ
struct	bop {
    char fullname[strsize];  // real name
    char title[strsize];     // job title
    char bopname[strsize];   // secret BOP name
    int preference;          // 0 = fullname, 1 = title, 2 = bopname
};
// ������������
bop number[num] = {
    {"Wimp Macho", "WMͷ��", "WM��������",0},
    {"Raki Rhodes", "Junior Programmer","RR��������",1},
    {"Celia Laiter", "CLͷ��","MIPS",2},
    {"Hoppy Hipman", "Analyst Trainee","HH��������",1},
    {"Pat Hand", "PHͷ��","LOOPY",2}
};

using namespace std;

int main_forth()
{
    // ��ʾҪչʾ����
    showReport();

    char ch;
    // �������ݺͱ���
    while(cin >> ch && ch != 'q')
    {
        // ��֧�ж���������
        switch (ch)
        {
        case 'a':
            choice_a();
            break;
        case 'b':
            choice_b();
            break;
        case 'c':
            choice_c();
            break;
        case 'd':
            choice_d();
            break;
        default:
            cout << "Please enter a a, b, c, or d : ";
            break;
        }
        cout << "Next choice: ";
    }

    cout << "Bye!";

    return 0;
}
// Ҫչʾ����
void showReport()
{
    cout << "Benevolent Order of Programmers Report: \n";
    cout << "a. display by name              b. display by title\n";
    cout << "c. display by bopname           d. display by perference\n";
    cout << "q. quit\n";
}
// չʾ fullname
void choice_a()
{
    using namespace std;
    for (int i = 0; i < num; i++)
        cout << number[i].fullname << endl;
}
// չʾ title
void choice_b()
{
    using namespace std;
    for (int i = 0; i < num; i++)
        cout << number[i].title << endl;
}
// չʾ bopname
void choice_c()
{
    using namespace std;
    for (int i = 0; i < num; i++)
        cout << number[i].bopname << endl;
}
// ѡ��չʾ��Ϣ
void choice_d()
{
    using namespace std;
    for (int i = 0; i < num; i++)
    {
        if (number[i].preference == 0)
            cout << number[i].fullname << endl;
        else if (number[i].preference == 1)
            cout << number[i].title << endl;
        else if (number[i].preference == 2)
            cout << number[i].bopname << endl;
    }
}