#include <iostream>

int main_fifth()
{
    using namespace std;
    double income;     // 个人工资
    double tax;        // 扣税总额

    cout << "请输入您的收入（tvarp）：";

    while (cin >> income && income != 'q')
    {
        if (income <= 5000)
            cout << "tax = " << 0 << " 税收.\n";
        else if (income >= 5001 && income <= 15000)
            cout << "tax = " << (income - 5000) * 0.1 << " 税收.\n";
        else if (income >= 15001 && income <= 35000)
            cout << "tax = " << (income - 15000) * 0.15 + (income - 5000) * 0.1 << " 税收.\n";
        else
            cout << "tax = " << (income - 35000) * 0.2 + (income - 15000) * 0.15 + (income - 5000) * 0.1 << " 税收.\n";
    }

    cout << "end";

    return 0;
}