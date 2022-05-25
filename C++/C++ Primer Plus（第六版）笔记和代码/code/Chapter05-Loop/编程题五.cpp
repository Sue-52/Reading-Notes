#include <iostream>
#include <string>

int main_fifth()
{
    using namespace std;
    
    string month[12] = { "january", "February", "March", "April", "May", "June",
                        "July", "August", "Septemper", "October", "November", "December" };
    int sales[12], sum = 0;

    for (int i = 0; i < 12; i++)
    {
        cout << "please input the sales of " << month[i] << ": ";
        cin >> sales[i];
        cout << endl;
        sum += sales[i];
    }
    cout << "the sales of whole year is: " << sum;

    return 0;
}
