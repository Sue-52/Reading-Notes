#include <iostream>
// 定义函数
void showReport();
void choice_a();
void choice_b();
void choice_c();
void choice_d();

const int strsize = 30;
const int num = 5;
// 定义结构
struct	bop {
    char fullname[strsize];  // real name
    char title[strsize];     // job title
    char bopname[strsize];   // secret BOP name
    int preference;          // 0 = fullname, 1 = title, 2 = bopname
};
// 定义数组数据
bop number[num] = {
    {"Wimp Macho", "WM头衔", "WM秘密姓名",0},
    {"Raki Rhodes", "Junior Programmer","RR秘密姓名",1},
    {"Celia Laiter", "CL头衔","MIPS",2},
    {"Hoppy Hipman", "Analyst Trainee","HH秘密姓名",1},
    {"Pat Hand", "PH头衔","LOOPY",2}
};

using namespace std;

int main_forth()
{
    // 显示要展示内容
    showReport();

    char ch;
    // 输入内容和遍历
    while(cin >> ch && ch != 'q')
    {
        // 分支判断输入内容
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
// 要展示内容
void showReport()
{
    cout << "Benevolent Order of Programmers Report: \n";
    cout << "a. display by name              b. display by title\n";
    cout << "c. display by bopname           d. display by perference\n";
    cout << "q. quit\n";
}
// 展示 fullname
void choice_a()
{
    using namespace std;
    for (int i = 0; i < num; i++)
        cout << number[i].fullname << endl;
}
// 展示 title
void choice_b()
{
    using namespace std;
    for (int i = 0; i < num; i++)
        cout << number[i].title << endl;
}
// 展示 bopname
void choice_c()
{
    using namespace std;
    for (int i = 0; i < num; i++)
        cout << number[i].bopname << endl;
}
// 选择展示信息
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