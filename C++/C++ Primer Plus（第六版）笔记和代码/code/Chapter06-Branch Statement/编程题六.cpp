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

    cout << "����������ߵ���Ŀ��";
    cin >> num;
    cin.get();
    message* full = new message[num];

    for (int i = 0; i < num; i++)
    {
        cout << "�������" << i + 1 << "λ����ߵ�������";
        cin.get(full[i].name, 20).get();
        cout << "�������" << i + 1 << "λ����ߵ����";
        cin >> full[i].money;
        cin.get();
    }

    // ������10000��Ա
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

    // ���С��10000��Ա
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