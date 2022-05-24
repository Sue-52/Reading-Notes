#include <iostream>

//转换因子
const float GALLON_TO_LITER = 3.875;
const float HKM_TO_MILE = 62.14;

//主函数
int main(void)
{
	using namespace std;										//编译指令
	float fuel_consume_eur, fuel_consume_us;

	cout << "Enter the fuel consume in europe(1 / 100km)：";
	cin >> fuel_consume_eur;

	fuel_consume_us = HKM_TO_MILE / (fuel_consume_eur / GALLON_TO_LITER);

	cout << "The fuel consume is " << fuel_consume_eur << " L/100km." << endl;
	cout << "The fuel consume is " << fuel_consume_us << " mpg(mile/gallon)." << endl;

	return 0;
}

// practice 1
/*
// 编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸），
// 然后将身高转换为英尺和英寸。该程序使用下划线字符来指示输入位置。
// 另外，使用一个const符号常量来表示转换因子。

int personHeight;
const int Foot = 12;  // 一英寸为 2.54 cm  // 输入72

// 输入数值
cout << "请输入身高（厘米）为单位：___\b\b\b";
cin >> personHeight;
cout << endl;

short getPersonHeight =  personHeight / 2.56;

// 输出结果
cout << "身高转换为："
	<< int(getPersonHeight) / Foot
	<< " 英尺，"
	<< int(getPersonHeight) % Foot
	<< " 英寸"
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

	int personFoot; // 用户英尺 // 6
	int personInch; // 用户英寸 // 0
	double personWeight; // 用户体重 // 30.45

	// 输入数据
	cout << "请用输入身高英尺：___\b\b\b";
	cin >> personFoot;
	cout << "请用输入身高英寸：___\b\b\b";
	cin >> personInch;
	cout << "请用输入身高体重：___\b\b\b";
	cin >> personWeight;

	// 数值转换
	double totalHeight = (personFoot * 12 + personInch) * miles; // 身高转换
	double totalWeight = personWeight * pound; // 体重转换
	// 身高平方值获取
	double doubleHeight = pow(totalHeight, 2);

	// 结算结果
	cout << "输出结果：" << endl;
	cout << "身高为：" << totalHeight << " 米" << endl;
	cout << "体重为：" << totalWeight << " 千克" << endl;
	cout << "BMI最终结果：" << totalWeight / doubleHeight << endl;

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

	// 输入数据
	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First,enter the degrees：";
	cin >> degree;
	cout << "Next,enter the minutes of arc：";
	cin >> minutes;
	cout << "Finally,enter the seconds of arc：";
	cin >> seconds;


	// 计算结果
	degrees = degree + (float(minutes) / DEGREE_TO_MINUTE) + (float(seconds) / MINUTE_TO_SECOND)/ DEGREE_TO_MINUTE;

	// 输出结果
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

	// 输入数据
	cout << "Enter the number of seconds：";
	cin >> totalSeconds;

	// 计算结果
	days = totalSeconds / 24 / 60 / 60;
	// cout << days;
	hours = totalSeconds % (24 * 60 * 60) /(60 * 60);
	// cout << hours;
	minutes = totalSeconds % (60 * 60) / 60;
	// cout << minutes;
	seconds = totalSeconds  % 60;

	// 输出结果
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

	// 用户输入数值
	cout << "Enter the world's population：";
	cin >> world_population;
	cout << "Enter the population of the US：";
	cin >> country_population;

	// 计算结果
	double proportion = double(country_population) / double(world_population) * 100;

	// 输出结果
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

	double mile = 0.0; // 英里
	double gallon = 0.0; // 汽油
	double mile_per_gallon = 0.0; // 存储结果

	// 输入数据
	cout << "Enter the distance in mile you drive: ";
	cin >> mile;
	cout << "Enter the comsumption of oil: ";
	cin >> gallon;

	// 计算结果
	mile_per_gallon = mile / gallon;

	// 输出
	cout << "Average fuel comsuption: " << mile_per_gallon << " mile/gallon" << endl;

	return 0;
}
*/

// practice 7
/*
#include <iostream>

//转换因子
const float GALLON_TO_LITER = 3.875;
const float HKM_TO_MILE = 62.14;

//主函数
int main(void)
{
	using namespace std;										//编译指令
	float fuel_consume_eur, fuel_consume_us;

	cout << "Enter the fuel consume in europe(1 / 100km)：";
	cin >> fuel_consume_eur;

	fuel_consume_us = HKM_TO_MILE / (fuel_consume_eur / GALLON_TO_LITER);

	cout << "The fuel consume is " << fuel_consume_eur << " L/100km." << endl;
	cout << "The fuel consume is " << fuel_consume_us << " mpg(mile/gallon)." << endl;

	return 0;
}
*/