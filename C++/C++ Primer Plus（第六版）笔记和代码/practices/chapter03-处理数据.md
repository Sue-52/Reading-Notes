---
title: chapter03-Processing Data -- 处理数据
date: 2022-05-05 21:30:00
categories:
  - C++
tags:
  - C++
---

## chapter03-Processing Data -- 处理数据

> 目标：
>
> 1. 练习题
> 2. 编程题

### 练习题

1. 为什么 C++ 有多种整型？
   
   > short，int，long，long long
   
2. 声明与下描述相符的变量

   a. short 整形，值为 80

   b. unsigned int 整数，值为 42110

   c. 值为 3000000000 的整数
   
   >a.  short ribs = 80;
   >
   >b. undigned int q = 42110;
   >
   >c. long long ants = 3000000000;
   
3. C++ 提供了什么措施来防止超出整型的范围？

   > 并没有提供防止超出范围后的限制功能，但是可以使用 climits 来确定显示情况

4. 33L 与 33 之间有什么区别？

   > 33L 数字类型为 long，33则为 int

5. 下面两条 C++ 语句是否等价？

   ~~~c++
   char grade = 65;
   char grade = 'A';
   ~~~

   > 不相等，只有在使用 ASCII 码的时候，这两个数值是相等的。

6. 如何使用 C++ 来找出编码 88 表示的字符？指出至少两种方法。

   > 1. char num1 = 88;
   > 2. cout.put(char(88));
   > 3. char(88)
   > 4. (char)88

7. 将 long 值赋给 float 变量会导致舍入误差，将 long 值赋给 double 变量呢？将 longlong 值赋给 double 变量呢？

   > 取决于数据的类型，long为4位数，则无差别

8. 下列C++表达式的结果分别是多少？

   a. 8 * 9 + 2

   b. 6 * 3 / 4

   c. 3 / 4 * 6

   d. 6.0 * 3 / 4

   e. 15 % 4

   > a. 74
   >
   > b. 4
   >
   > c. 0
   >
   > d. 4.5
   >
   > e. 3

9. 假设 x1 和 x2 是两个 double 变量，您要将它们作为整数相加，再将结果赋给一个整型变量。请编写一条完成这项任务的 C++ 语句。如果要将它们作为 double 值相加并转换为 int 呢？

   > 1. int pos = int(x1) + int(x2);
   > 2. int pos = (int)x1 + (int)x2;

10. 下面每条语句声明的变量都是什么类型？

    a. auto cars = 15;

    b. auto iou = 150.37f;

    c. auto level = 'B';

    d. auto crat = U'/U00002155';

    e. auto fract = 8.25f/2.5
    
    > a. int
    >
    > b. float
    >
    > c. char
    >
    > d. char32_t
    >
    > e. double




### 编程题

1. 编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸），然后将身高转换为英尺和英寸。该程序使用下划线字符来指示输入位置。另外，使用一个 const 符号常量来表示转换因子。

   ~~~c++
   #include <iostream>
   
   int main()
   {
   	using namespace std;
   
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
   
   	return 0;
   }
   ~~~

   

2. 编写一个小程序，要求以几英尺几英寸的方式输入其身高，并以磅为单位输入其体重。（使用 3 个变量来存储这些信息。）该程序报告其BM（Body、 Mass、 Index，体重指数）。为了计算 BMI ，该程序以英寸的方式指出用户的身高（1英尺为12英寸），并将以英寸为单位的身高转换为以米为单位的身高（1英寸 = 0.0254米）。然后，将以磅为单位的体重转换为以千克为单位的体重（1千克 = 2.2磅）。最后，计算相应的BM一体重（千克）除以身高（米）的平方。用符号常量表示各种转换因子。

   ~~~c++
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
   ~~~

   

3. 编写一个程序，要求用户以度、分、秒的方式输入一个纬度，然后以度为单位显示该纬度。1度为60分，1分等于60秒，请以符号常量的方式表示这些值。对于每个输入值，应使用一个独立的变量存储它。下面是该程序运行时的情况：

   ~~~txt
   Enter a latitude in degrees, minutes, and seconds:
   First,enter the degrees：37
   Next,enter the minutes of arc：51
   Finally,enter the seconds of arc：19
   37 degrees，51 minutes，19 seconds 37.8553 degrees
   ~~~

   ~~~c++
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
   ~~~

   

4. 编写一个程序，要求用户以整数方式输入秒数（使用 long 或 longlong 变量存储），然后以天、小时、分钟和秒的方式显示这段时间。使用符号常量来表示每天有多少小时、每小时有多少分钟以及每分钟有多少秒。该程序的输出应与下面类似：

   ~~~txt
   Enter the number of seconds：31600000
   31600000 seconds = 365 days，17 hours，46 minutes，40 seconds
   ~~~

   ~~~c++
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
   ~~~

   

5. 编写一个程序，要求用户输入全球当前的人口和美国当前的人口（或其他国家的人口）。将这些信息存储在 long long 变量中，并让程序显示美国（或其他国家）的人口占全球人口的百分比。该程序的输出应与下面类似：

   ~~~txt
   Enter the world's population：6898758899
   Enter the population of the US：310783781
   The population of the Us is 4.504928% of the world population.
   ~~~

   ~~~c++
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
   ~~~

   

6. 编写一个程序，要求用户输入驱车里程（英里）和使用汽油量（加仑），然后指出汽车耗油量为一加仑的里程。如果愿意，也可以让程序要求用户以公里为单位输入距离，并以升为单位输入汽油量，然后指出欧洲风格的结果——即每100公里的耗油量（升）。

   ~~~c++
   #include <iostream>
   
   int main()
   {
   	using namespace std;
   
   	double mile = 0.0;
   	double gallon = 0.0;
   	double mile_per_gallon = 0.0;
   
   	cout << "Enter the distance in mile you drive: ";
   	cin >> mile;
   	cout << "Enter the comsumption of oil: ";
   	cin >> gallon;
   
   	mile_per_gallon = mile / gallon;
   	cout << "Average fuel comsuption: " << mile_per_gallon << " mile/gallon" << endl;
   
   	return 0;
   }
   ~~~

   

7. 编写一个程序，要求用户按欧洲风格输入汽车的耗油量（每100公里消耗的汽油量（升）），然后将其转换为美国风格的耗油量——每加仑多少英里。注意，除了使用不同的单位计量外，美国方法（距离/燃料）与欧洲方法（燃料/距离）相反。100 公里等于 62.14 英里，1 加仑等于 3.875 升。因此，19 mpg 大约合12.4/100km，27 mpg 大约合 8.71/100km。

   ~~~c++
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
   ~~~

   

