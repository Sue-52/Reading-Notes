---
title: chapter02-Start C++
date: 2022-05-03 21:30:00
categories:
  - C++
tags:
  - C++
---

## chapter02-Start C++ - 初识 C++

> 目标：
>
> 1. 练习题
> 2. 编程题

### 练习题

在 **附录J** 中可以找到所有复习题的答案。

1. C++程序的模块叫什么？

> 函数

2. 下面的预处理器编译指令是做什么用的？

   ~~~C++
    #include <iostream>
   ~~~

   > 将 iostream 文件添加到模块中，在代码被编译前替换文本

3. 下面的语句是做什么用的？
  
   ~~~C++
    using namespace std；
   ~~~

  > 是该程序可以使用 std 命名空间中的定义

4. 什么语句可以用来打印短语 “Hello,world” 然后开始新的一行？

   ~~~c++
   cout << "Hello,world" << endl;
   
   cout << "Hello,world \n"
   ~~~

5. 什么语句可以用来创建名为 cheeses 的整数变量？

   ~~~c++
   int cheeses;
   ~~~

6. 什么语句可以用来将值 32 赋给变量 cheeses ？

   ~~~c++
   cheeses = 32;
   ~~~

7. 什么语句可以用来将从键盘输入的值读入变量 cheeses 中？

   ~~~c++
   std::cin >> cheeses;
   ~~~

8. 什么语句可以用来打印“We have X varieties of cheese，”，其中 X 为变量 cheeses 的当前值。

   ~~~c++
   cout << "We have " << cheeses << " varieties of cheese."
   ~~~

9. 下面的函数原型指出了关于函数的哪些信息？
  
   ~~~C++
    int froop（double t）；  // 该函数返回整数类型的返回值，并且需要传入 double 类型的参数
    void rattle（int n）；  // 该函数没有返回值并且需要传入 整数类型的参数
    int prune（void） // 该函数返回整数类型的返回值，并且无形参
   ~~~


10. 定义函数时，在什么情况下不必使用关键字 return？
    
> 当前定义函数的返回值为 viod，则不需要 return
    
11. 假设您编写的main（）函数包含如下代码：

   ~~~C++
    cout <《 "please enter your PIN："
   ~~~

​	而编译器指出cout是一个未知标识符。导致这种问题的原因很可能是什么？指出3种修复这种问题的方法。

	1. 没写 `using namespace std`;
 	2. 没写头文件 `#include <iostream>`
 	3. 不写 `using namespace std`; 写`std::cout<<"........"`;


### 编程题

1. 编写一个C++程序，它显示您的姓名和地址。
   
~~~c++
   #include <iostream>
   
   using namespace std;
   
   int main()
   {
   	// 显示姓名和地址
   	
   	// 1.定义存储姓名和地址的变量
   	string name;
   	string address;
   	
       // 2. 创建行为
   	cout << "请输入姓名：";
   	cin >> name;
   	cout << "请输入地址：";
   	cin >> address;
   	
   	// 3. 输出结果
   	cout << "姓名：" << name << "\n" << "地址：" << address << endl;
   
   	return 0;
   }
   ~~~
   
   ![image-20220503174225753](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220503174225753.png)
   
2. 编写一个C++程序，它要求用户输入一个以 long 为单位的距离，然后将它转换为码（1 long等于 220 码）。

   ~~~c++
   #include <iostream>
   int getLong(int);
   
   using namespace std;
   
   int main()
   {
   	// 要求用户输入一个以 long 为单位的距离，然后将它转换为码（1 long等于 220 码）
   	
   	// 1.创建变量保存 long
   	int longData;
   
   	// 1.创建行为
   	cout << "Please input the long：";
   	cin >> longData;
   	// 2. 调用函数
   	int getLongData = getLong(longData);
   
   	// 3. 返回结果
   	cout << longData << " long = " << getLongData << " 码" << endl;
   
   	return 0;
   }
   // 定义函数用于计算结果并返回
   int getLong(int l)
   {
   	int L = l * 220;
   	return L;
   }
   ~~~

   ![image-20220503175103972](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220503175103972.png)

3. 编写一个C++程序，它使用3个用户定义的函数（包括main（）），并生成下面的输出：

   ~~~txt
    Three blind mice 
    Three blind mice 
    See how they run 
    See how they run
   ~~~

   其中一个函数要调用两次，该函数生成前两行：另一个函数也被调用两次，并生成其余的输出。

   ~~~c++
   #include <iostream>
   void firstPrint(void);
   void secondPrint(void);
   
   using namespace std;
   
   int main()
   {
   	// 输出：
   	/*
   		 Three blind mice	
   		 Three blind mice 
   		See how they run 
   		See how they run
   	*/
   
   	firstPrint();
   	firstPrint();
   	secondPrint();
   	secondPrint();
   
   	return 0;
   }
   
   void firstPrint(void)
   {
   	cout << "Three blind mice" << endl;
   }
   
   void secondPrint(void)
   {
   	cout << "See how they run" << endl;
   }
   ~~~

   ![image-20220503175613033](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220503175613033.png)

4. 编写一个程序，让用户输入其年龄，然后显示该年龄包含多少个月，如下所示：

   ~~~txt
   Input： Enter your age：29
   Output： 348（12 * 29）
   ~~~

   ~~~c++
   #include <iostream>
   int getMonths(int);
   
   using namespace std;
   
   int main()
   {
   	// 让用户输入其年龄，然后显示该年龄包含多少个月
   
   	// 1. 创建变量
   	int personAge;
   
   	// 2. 创建行为
   	cout << "Please input your age：";
   	cin >> personAge;
   	// 3. 调用函数获取月份
   	int getTotalMonths = getMonths(personAge);
   
   	// 4. 输出结果
   	cout << personAge << " age = " << getTotalMonths << " months" << endl;
   
   	return 0;
   }
   
   int getMonths(int age)
   {
   	int months = age * 12;
   	return months;
   }
   ~~~

   ![image-20220503180646224](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220503180646224.png)

5. 编写一个程序，其中的 main（）调用一个用户定义的函数（以摄氏温度值为参数，并返回相应的华氏温度值）。该程序按下面的格式要求用户输入摄氏温度值，并显示结果：

   ~~~txt
    Please enter a Celsius value：20
    20 degrees Celsius is 68 degrees Fahrenheit.
   ~~~

   下面是转换公式：

     **华氏温度 = 1.8 × 摄氏温度 + 32.0**

   ~~~c++
   #include <iostream>
   int fahrenheitScale(double);
   
   using namespace std;
   
   int main()
   {
   	// 让用户输入摄氏温度值,转换为华氏温度
   
   	// 1. 创建变量
   	double temperature;
   
   	// 2. 创建行为
   	cout << "Please input the temperature：";
   	cin >> temperature;
   	// 3. 调用方法
   	double fscale = fahrenheitScale(temperature);
   
   	// 4. 输出结果
   	cout << temperature << " 摄氏温度 = " << fscale << " 华氏温度" << endl;
   
   	return 0;
   }
   
   int fahrenheitScale(double scale)
   {
   	int fscale = 1.8 * scale +32.0;
   	return fscale;
   }
   ~~~

   ![image-20220503181516520](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220503181516520.png)

6. 编写一个程序，其 main（）调用一个用户定义的函数（以光年值为参数，并返回对应天文单位的值）。该程序按下面的格式要求用户输入光年值，并显示结果：

   ~~~txt
    1 光年 = 63240 天文单位
   ~~~

   ~~~c++
   #include <iostream>
   int fahrenheitScale(int);
   
   using namespace std;
   
   int main()
   {
   	// 让用户输入光年数值，转换为天文单位
   	// 1 光年 = 63240 天文单位
   
   	// 1. 创建变量
   	double lightYear;
   
   	// 2. 创建行为
   	cout << "Please input the temperature：";
   	cin >> lightYear;
   	// 3. 调用方法
   	double astronomy = calcAstronomy(lightYear);
   
   	// 4. 输出结果
   	cout << lightYear << " 光年 = " << astronomy << " 天文单位" << endl;
   
   	return 0;
   }
   
   int calcAstronomy(int year)
   {
   	int astronomy = 63240 * year;
   	return astronomy;
   }
   ~~~

   ![image-20220503200239111](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220503200239111.png)

7. 编写一个程序，要求用户输入小时数和分钟数。在 main（）函数中，将这两个值传递给一个 void 函数，后者以下面这样的格式显示这两个值：

   ~~~txt
    Enter the number of hours：9
    Enter the number of minutes：28
    Time：9:28
   ~~~

   ~~~c++
   #include <iostream>
   void printTime(int,int);
   
   using namespace std;
   
   int main()
   {
   	// 用户输入小时数和分钟数
   	// 输出：
   	/*
   		Enter the number of hours：9
   		Enter the number of minutes：28
   		Time：9:28
   	*/
   
   	// 1. 创建变量
   	int hour;
   	int minute;
   
   	// 2.创建方法
   	cout << "Please input the hour：";
   	cin >> hour;
   	cout << "Please input the minute：";
   	cin >> minute;
   	// 3.调用函数
   	printTime(hour, minute);
   
   	return 0;
   }
   
   void printTime(int hours,int minutes)
   {
   	cout << "Enter the number of hours：" << hours << endl;
   	cout << "Enter the number of minutes：" << minutes << endl;
   	cout << "Time：" << hours << ":" << minutes << endl;
   }
   ~~~

   ![image-20220503200920900](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220503200920900.png)

