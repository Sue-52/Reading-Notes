#include <iostream>

struct CandyBar
{
	char brand[30];
	double weight;
	int calorie;
};

int main_sixth()
{
	using namespace std;

	CandyBar arr[3] = {
		{"Mocha Munch",2.3,350},
		{"Mocha Munch",2.3,350},
		{"Mocha Munch",2.3,350}
	};

	cout << "CandyBar brand is: "
		<< arr[0].brand << endl;
	cout << "CandyBar weight is: "
		<< arr[0].weight << endl;
	cout << "CandyBar calorie is: "
		<< arr[0].calorie << endl;	

	cout << "----------------------------" << endl;
	
	cout << "CandyBar brand is: "
		<< arr[1].brand << endl;
	cout << "CandyBar weight is: "
		<< arr[1].weight << endl;
	cout << "CandyBar calorie is: "
		<< arr[1].calorie << endl;	

	cout << "----------------------------" << endl;
	
	cout << "CandyBar brand is: "
		<< arr[2].brand << endl;
	cout << "CandyBar weight is: "
		<< arr[2].weight << endl;
	cout << "CandyBar calorie is: "
		<< arr[2].calorie << endl;

	return 0;
}