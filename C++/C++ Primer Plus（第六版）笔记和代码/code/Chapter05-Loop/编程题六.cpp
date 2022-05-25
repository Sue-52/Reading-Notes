#include <iostream>
#include <string>

int main_sixth()
{
    using namespace std;
    // 定义年
    string year[3] = { "The First Year", "The Second Year;", "The Third Year;" };
    //  定义月份
    string month[12] = { "january", "February", "March", "April", "May", "June",
                        "July", "August", "Septemper", "October", "November", "December" };
    // 定义销售二维数组
    int sales[3][12];
    int sums[3] = {};

    for (int i = 0; i < size(year); i++)
    {
        // 显示年
        cout << "sales of " << year[i] << endl;
        // 遍历月份
        for (int j = 0; j < size(month); j++)
        {
            // 输入对应月份的销售
            cout << "please input the sales of " << month[j] << ": ";
            // 
            cin >> sales[i][j];
            cout << endl;
            sums[i] += sales[i][j];
        }
        cout << "the sales of " << year[i] << " is: " << sums[i] << endl;
    }

    cout << "the sales of three years is: " << sums[0] + sums[1] + sums[2] << endl;

    return 0;
}