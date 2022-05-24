#include <iostream>

struct person_info
{
	char first_name[20];
	char last_name[20];
	char grade[1];
	int age;
};

int main_first()
{
	using namespace std;

	person_info* people = new person_info;

	cout << "What is your first name?";
	cin >> people->first_name;
	cout << "What is your last name?";
	cin >> people->last_name;
	cout << "What letter grade do you deserve?";
	cin >> people->grade;
	cout << "What is your age?";
	cin >> people->age;

	cout << "Name: " << people->last_name
		<< ", " << people->first_name << endl;
	cout << "Grade: " << people->grade << endl;
	cout << "Age: " << people->age << endl;
	return 0;
}