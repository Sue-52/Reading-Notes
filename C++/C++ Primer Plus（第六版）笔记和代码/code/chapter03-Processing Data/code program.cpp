#include <iostream>

//ת������
const float GALLON_TO_LITER = 3.875;
const float HKM_TO_MILE = 62.14;

//������
int main(void)
{
	using namespace std;										//����ָ��
	float fuel_consume_eur, fuel_consume_us;

	cout << "Enter the fuel consume in europe(1 / 100km)��";
	cin >> fuel_consume_eur;

	fuel_consume_us = HKM_TO_MILE / (fuel_consume_eur / GALLON_TO_LITER);

	cout << "The fuel consume is " << fuel_consume_eur << " L/100km." << endl;
	cout << "The fuel consume is " << fuel_consume_us << " mpg(mile/gallon)." << endl;

	return 0;
}

// practice 1
/*
// ��дһ��С����Ҫ���û�ʹ��һ������ָ���Լ�����ߣ���λΪӢ�磩��
// Ȼ�����ת��ΪӢ�ߺ�Ӣ�硣�ó���ʹ���»����ַ���ָʾ����λ�á�
// ���⣬ʹ��һ��const���ų�������ʾת�����ӡ�

int personHeight;
const int Foot = 12;  // һӢ��Ϊ 2.54 cm  // ����72

// ������ֵ
cout << "��������ߣ����ף�Ϊ��λ��___\b\b\b";
cin >> personHeight;
cout << endl;

short getPersonHeight =  personHeight / 2.56;

// ������
cout << "���ת��Ϊ��"
	<< int(getPersonHeight) / Foot
	<< " Ӣ�ߣ�"
	<< int(getPersonHeight) % Foot
	<< " Ӣ��"
	<< endl;
*/

// practice 2
/*
#include <iostream>
#include <cmath>

const double miles = 0.0254;
const double pound = 2.2;

int main()
{
	using namespace std;

	int personFoot; // �û�Ӣ�� // 6
	int personInch; // �û�Ӣ�� // 0
	double personWeight; // �û����� // 30.45

	// ��������
	cout << "�����������Ӣ�ߣ�___\b\b\b";
	cin >> personFoot;
	cout << "�����������Ӣ�磺___\b\b\b";
	cin >> personInch;
	cout << "��������������أ�___\b\b\b";
	cin >> personWeight;

	// ��ֵת��
	double totalHeight = (personFoot * 12 + personInch) * miles; // ���ת��
	double totalWeight = personWeight * pound; // ����ת��
	// ���ƽ��ֵ��ȡ
	double doubleHeight = pow(totalHeight, 2);

	// ������
	cout << "��������" << endl;
	cout << "���Ϊ��" << totalHeight << " ��" << endl;
	cout << "����Ϊ��" << totalWeight << " ǧ��" << endl;
	cout << "BMI���ս����" << totalWeight / doubleHeight << endl;

	return 0;
}
*/

// practice 3
/*
#include <iostream>

const int DEGREE_TO_MINUTE = 60;
const int MINUTE_TO_SECOND = 60;

int main()
{
	using namespace std;

	int degree, minutes, seconds;
	double degrees;

	// ��������
	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First,enter the degrees��";
	cin >> degree;
	cout << "Next,enter the minutes of arc��";
	cin >> minutes;
	cout << "Finally,enter the seconds of arc��";
	cin >> seconds;


	// ������
	degrees = degree + (float(minutes) / DEGREE_TO_MINUTE) + (float(seconds) / MINUTE_TO_SECOND)/ DEGREE_TO_MINUTE;

	// ������
	cout << degree << " degrees,"
		<< minutes << " minutes,"
		<< seconds << " seconds,"
		<< degrees << " degrees";

	return 0;
}
*/

// practice 4
/*
#include <iostream>

int main()
{
	using namespace std;

	long long totalSeconds;
	int days, hours, minutes, seconds;

	// ��������
	cout << "Enter the number of seconds��";
	cin >> totalSeconds;

	// ������
	days = totalSeconds / 24 / 60 / 60;
	// cout << days;
	hours = totalSeconds % (24 * 60 * 60) /(60 * 60);
	// cout << hours;
	minutes = totalSeconds % (60 * 60) / 60;
	// cout << minutes;
	seconds = totalSeconds  % 60;

	// ������
	cout << totalSeconds << " seconds = "
		<< days << " days,"
		<< hours << " hours,"
		<< minutes << " minutes,"
		<< seconds << " seconds" << endl;

	return 0;
}
*/

// practice 5
/*
#include <iostream>

int main()
{
	using namespace std;

	long long world_population, country_population;

	// �û�������ֵ
	cout << "Enter the world's population��";
	cin >> world_population;
	cout << "Enter the population of the US��";
	cin >> country_population;

	// ������
	double proportion = double(country_population) / double(world_population) * 100;

	// ������
	cout << "The population of the Us is " << proportion << "% of the world population." << endl;

	return 0;
}
*/

// practice 6
/*
#include <iostream>

int main()
{
	using namespace std;

	double mile = 0.0; // Ӣ��
	double gallon = 0.0; // ����
	double mile_per_gallon = 0.0; // �洢���

	// ��������
	cout << "Enter the distance in mile you drive: ";
	cin >> mile;
	cout << "Enter the comsumption of oil: ";
	cin >> gallon;

	// ������
	mile_per_gallon = mile / gallon;

	// ���
	cout << "Average fuel comsuption: " << mile_per_gallon << " mile/gallon" << endl;

	return 0;
}
*/

// practice 7
/*
#include <iostream>

//ת������
const float GALLON_TO_LITER = 3.875;
const float HKM_TO_MILE = 62.14;

//������
int main(void)
{
	using namespace std;										//����ָ��
	float fuel_consume_eur, fuel_consume_us;

	cout << "Enter the fuel consume in europe(1 / 100km)��";
	cin >> fuel_consume_eur;

	fuel_consume_us = HKM_TO_MILE / (fuel_consume_eur / GALLON_TO_LITER);

	cout << "The fuel consume is " << fuel_consume_eur << " L/100km." << endl;
	cout << "The fuel consume is " << fuel_consume_us << " mpg(mile/gallon)." << endl;

	return 0;
}
*/