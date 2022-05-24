#include <iostream>
#include <array>

int main()
{
    using namespace std;

    const int number = 3;
    array<double, number> time;

    cout << "Enter the 1st grade: ";
    cin >> time[0];
    cout << "Enter the 2nd grade: ";
    cin >> time[1];
    cout << "Enter the 3rd grade: ";
    cin >> time[2];

    cout << "So the whole numbers of the grade is " << number << ".\n";
    cout << "The grades are: " << time[0] << ", " << time[1] << ", " << time[2] << ".\n";
    cout << "The average grade is " << (time[0] + time[1] + time[2]) / 3 << ".\n";

    return 0;
}