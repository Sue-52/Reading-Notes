#include <iostream>

int main_fifth()
{
    using namespace std;
    double income;     // ���˹���
    double tax;        // ��˰�ܶ�

    cout << "�������������루tvarp����";

    while (cin >> income && income != 'q')
    {
        if (income <= 5000)
            cout << "tax = " << 0 << " ˰��.\n";
        else if (income >= 5001 && income <= 15000)
            cout << "tax = " << (income - 5000) * 0.1 << " ˰��.\n";
        else if (income >= 15001 && income <= 35000)
            cout << "tax = " << (income - 15000) * 0.15 + (income - 5000) * 0.1 << " ˰��.\n";
        else
            cout << "tax = " << (income - 35000) * 0.2 + (income - 15000) * 0.15 + (income - 5000) * 0.1 << " ˰��.\n";
    }

    cout << "end";

    return 0;
}