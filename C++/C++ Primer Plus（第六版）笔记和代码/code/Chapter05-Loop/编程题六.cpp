#include <iostream>
#include <string>

int main_sixth()
{
    using namespace std;
    // ������
    string year[3] = { "The First Year", "The Second Year;", "The Third Year;" };
    //  �����·�
    string month[12] = { "january", "February", "March", "April", "May", "June",
                        "July", "August", "Septemper", "October", "November", "December" };
    // �������۶�ά����
    int sales[3][12];
    int sums[3] = {};

    for (int i = 0; i < size(year); i++)
    {
        // ��ʾ��
        cout << "sales of " << year[i] << endl;
        // �����·�
        for (int j = 0; j < size(month); j++)
        {
            // �����Ӧ�·ݵ�����
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