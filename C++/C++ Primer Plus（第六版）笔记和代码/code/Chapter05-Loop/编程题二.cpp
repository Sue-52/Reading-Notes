#include <iostream>
#include <array>

const int ArSize = 101;

int main_second()
{
    using namespace std;

    array<long double, ArSize> ald;
    ald[1] = ald[0] = 1;

    for (int i = 2; i < ArSize; i++)
    {
        ald[i] = i * ald[i - 1];
    }

    for (int i = 0; i < ArSize; i++) {
        cout << i << "!=" << ald[i] << endl;
    }

    return 0;
}