#include <iostream>

int main_second()
{
    using namespace std;
    
    string name1, name2;
    string dessert;

    cout << "Enter your name:\n";
    cin >> name1 >> name2;// reads through newline
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name1 + " " + name2 << ".\n";
    // cin.get();
    
    return 0;
}