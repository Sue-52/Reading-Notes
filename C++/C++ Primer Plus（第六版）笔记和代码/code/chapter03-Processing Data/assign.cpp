// assign.cpp -- type changes on initialization
#include <iostream>

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);

    // int converts to float
    float tree = 3;
    // double converts to int
    int guess(3.9832);
    // result not define in C++
    int debt = 7.2E12;

    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;

    return 0;
}