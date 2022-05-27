#include <iostream>

int main_sixth()
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

    cout << "请输入捐献者的数目：";
    cin >> num;
    cin.get();
    message* full = new message[num];

    for (int i = 0; i < num; i++)
    {
        cout << "请输入第" << i + 1 << "位捐款者的姓名：";
        cin.get(full[i].name, 20).get();
        cout << "请输入第" << i + 1 << "位捐款者的数额：";
        cin >> full[i].money;
        cin.get();
    }

    // 捐款大于10000人员
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

    // 捐款小于10000人员
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