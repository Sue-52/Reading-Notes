#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
    using namespace std;

    struct message
    {
        char name[20];
        double money;
    };
    int num;
    int j = 0;
    int k = 0;

    ifstream inFile;                 //声明ifstream对象
    inFile.open("excise6.txt");      //将ifstream对象与特定文件关联
    if (!inFile.is_open())           //检查是否正确打开文件
    {
        exit(EXIT_FAILURE);
    }


    cout << "请输入捐献者的数目：";
    inFile >> num;
    inFile.get();
    message* full = new message[num];

    for (int i = 0; i < num; i++)
    {
        cout << "请输入第" << i + 1 << "位捐款者的姓名：";
        inFile.get(full[i].name, 20).get();
        cout << "请输入第" << i + 1 << "位捐款者的数额：";
        inFile >> full[i].money;
        inFile.get();
    }

    cout << "Grand Patrons:\n";
    for (int i = 0; i < num; i++)
    {
        if (full[i].money > 10000)
        {
            cout << full[i].name << "\t\t\t" << full[i].money << endl;
            j++;
        }
    }
    if (j == 0)
        cout << "none\n";

    cout << "Patrons:\n";
    for (int i = 0; i < num; i++)
    {
        if (full[i].money <= 10000)
        {
            cout << full[i].name << "\t\t\t" << full[i].money << endl;
            k++;
        }
    }
    if (k == 0)
        cout << "none\n";

    return 0;
}