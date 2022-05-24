// module.cpp -- uses % operator to convert lbs to stone
#include <iostream>

int main()
{
  using namespace std;
  const int Lbs_per_stn = 14;
  int lbs;

  cout << "Enter weight in pounds: ";
  cin >> lbs;
  // whole stone
  int stone = lbs / Lbs_per_stn;
  // remainder in pounds
  int pounds = lbs % Lbs_per_stn;
  // 结果输出
  cout << lbs << " pounds are "
       << stone << " stone and "
       << pounds << " pound(s).\n";

  return 0;
}