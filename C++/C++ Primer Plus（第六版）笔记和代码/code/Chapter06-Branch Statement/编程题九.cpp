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

    ifstream inFile;                 //����ifstream����
    inFile.open("excise6.txt");      //��ifstream�������ض��ļ�����
    if (!inFile.is_open())           //����Ƿ���ȷ���ļ�
    {
        exit(EXIT_FAILURE);
    }


    cout << "����������ߵ���Ŀ��";
    inFile >> num;
    inFile.get();
    message* full = new message[num];

    for (int i = 0; i < num; i++)
    {
        cout << "�������" << i + 1 << "λ����ߵ�������";
        inFile.get(full[i].name, 20).get();
        cout << "�������" << i + 1 << "λ����ߵ����";
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