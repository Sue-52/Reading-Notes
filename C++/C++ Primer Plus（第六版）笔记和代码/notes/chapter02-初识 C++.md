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
> 1. 进入 C++
> 2. C++ 语句
> 3. 其他 C++ 语句
> 4. 函数
> 5. 练习题

在正式开始前，需要进行 C++ 程序的了解和概述。



### 1. 进入 C++

> 目标：
>
> 1.  main() 函数
> 2. C++ 注释
> 3. C++ 预处理器和 iostream 文件
> 4. 头文件名
> 5. 名称空间
> 6. 使用 cout 进行 C++ 输出
> 7. C++ 源代码的格式化

首先，我们以一个案例的形式进入学习：

`myfirst.cpp`

~~~c++
// myfirst.cpp -- displays a message
// 头文件名
#include <iostream> // 预处理器编译指令
// 括号中为：形参列表（argument list）
int main() // 函数头
{ // 函数体
	// 命名空间
	// using namespace std; // 编译指令
	using std::cout;
	using std::endl;

	cout << "Come up and C++ me sometime \n" << endl; // 输出语句
	cout << "You won't regret it!" << endl;
	
	return 0; // 结束语句
}
~~~

- C++ 对大小写敏感（必须区分）
- 扩展名以 cpp 为主

当程序运行时，会产生一个独立的窗口，也可使用 `cin.get()` 命令打开窗口

在当前的案例中包含下述元素：

1. 注释，有前缀 // 标识
2. 预处理器遍历指令：#include
3. 函数头：int main()
4. 编译指令：using namespace
5. 函数体：{}
6. 显示消息语句：cout
7. 结束语句：return

在大概了解后，我们将进入更详细的了解。

#### 1. main() 函数

整体结构如下：

~~~c++
int main()
{
    statements;
    return 0;
}
~~~

在这整体结构中，大体由两部分组成：

1. int main() 为函数头
2. 花括号 {} 和中间内容为函数体

函数头对函数与程序其他部分之间的接口进行了总结；函数体是指出函数应该做什么计算机指令。并且内部所有语句都要以分号结尾用来结束语句。

![image-20220503234729942](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220503234729942.png)

在 main 函数中，最后一条语句叫做 返回语句（return statement），用于结束整个函数的运行。

**1. 作为接口的函数头：**

在函数名前的类型为该函数的返回值类型；函数括号中的信息为形参列表（argument list）或参数列表（parameter list）。

形参的作用是在程序调用该函数时传递给函数的内容。

**2. 为什么 main() 不能使用其他名称：**

因为 C++ 程序必须包含一个 main 函数，在程序运行时 main 函数是最先执行的，如果没有 则编译器指出 未定义 main 函数。

#### 2. C++ 注释

**单行注释以双斜杠（//）开头** 表示注释斜杠后的所有内容。

> 当程序复杂时，应该多多使用注释的方式进行程序的步骤说明和描述，便于理解和后续的修改。

**多行注释以 (`/**/`) ** 在 * 号内部进行书写注释

#### 3. C++ 预处理器和 iostream 文件

C++ 预处理器：主要目的是在程序进行主编译之前对源文件进行处理。

~~~c++
#include <iostream>
~~~

> 在源代码被编译前，替换或添加文本

iostream 文件：其中 io 指的是输入（input 进入程序的信息）和输出（output 从程序中发送出去的消息）。

#### 4. 头文件名

如 iostream 的文件叫做包含文件（include file）因为它们被包含在了其他文件中；也叫做头文件（header file）

并且因为兼容 C 语言等内容，其文件中可以添加 .h 的后缀。

约定如下：

| 头文件类型   | 约定                 | 示例       | 说明                                                       |
| ------------ | -------------------- | ---------- | ---------------------------------------------------------- |
| C++ 旧式风格 | 以 .h 结尾           | iostream.h | C++ 程序可以使用                                           |
| C 旧式风格   | 以 .h 结尾           | math.h     | C、C++ 程序可以使用                                        |
| C++ 新式风格 | 没有扩展名           | iostream   | C++ 程序可以使用，使用 namespace std                       |
| 转换后的 C   | 加前缀 c，没有扩展名 | cmath      | C++ 程序可以使用，可以使用不是 C 的可行，如：namespace std |

#### 5. 名称空间

当头文件使用 iostream 时，我们需要使用名称空间编译指令：

~~~c++
using namespace std；
~~~

在不使用前，我们需要在对应的语句前添加：

~~~c++
std::cout << "Hello World"
~~~

当使用后便可将前缀的 `std::` 省略，使代码风格简化。

>  也可以根据函数需求，在需要的函数中及你才能够添加。

#### 6. 使用 cout 进行 C++ 输出

输出语句如下：

~~~c++
std::cout << "Hello World" << endl;
~~~

其中 << 符号表示该语句将把这个字符串发送给 cout；指出了信息流动得到路径。

~~~c++
std::cout << string;
~~~

![image-20220504084223019](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220504084223019.png)

> 其实，在真正的运算中 << 表示的插入运算符看上去像按位左移运算符（<<），经过重载，同一个运算符将有不同的含义。

**1. 控制符 endl：**

一般位于语句结尾，将语句重启一行

**2. 换行符 \n：**

一般用于 字符串中，表示另起一行

#### 7. C++ 源代码的格式化

保持着：

~~~c++
// 第一行为头文件
#include <iostream>
// 设置名称空间(可选)
using namespace std;
// 主函数
int main()
{ // 函数体
    // 函数体内部内容
    statements;
    // 结束函数
    return 0;
}
~~~

![image-20220504090411992](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220504090411992.png)

**代码风格：**

- 每条语句独占一行
- 函数体的花括号独占一行
- 函数体内部语句相对于花括号进行缩进
- 函数名称相关的圆括号周围没有空白



### 2. C++ 语句

> 目标：
>
> 1. 声明语句和变量
> 2. 赋值语句

`carrot.cpp`

~~~c++
#include <iostream>

int main()
{
	using namespace std;

	// 声明变量
	// int: 存储数据的类型
	// carrots： 变量名
	int carrots;
	// 赋值变量
	carrots = 25;

	// 输出现在的结果
	cout << "I have " << carrots << " carrots" << endl;

	// 运算符
	carrots = carrots - 1;

	// 输出最终运算后的结果
	cout << "Crunch, crunch. Now I have " << carrots << " carrots" << endl;

	// 结束语句
	return 0;
}
~~~

![image-20220504092749187](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220504092749187.png)

#### 1. 声明语句和变量

格式：

~~~c++
数据类型 变量名；
int num;
~~~

在程序中声明语句叫做定义声明（defininig declaration）语句，简称定义（definition）。意味着他将导致编译器为变量分配内存空间。

![image-20220504102416188](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220504102416188.png)

#### 2. 赋值语句

所谓的赋值就是将数据传递到存储单元中。

~~~c++
变量名 = 值；
carrots = 15；
~~~



### 3. 其他 C++ 语句

> 目标：
>
> 1. 使用 cin
> 2. 使用 cout 进行拼接
> 3. 类简介

`getInfo.cpp`

~~~c++
#include <iostream>

int main()
{
	using namespace std;

	int carrots;
	cout << "How many carrots do you have?" << endl;
	// 输入数值
	// 注意：输入的信息流向 carrots。
	// cin 可以通过键盘输入的一系列字符转换为接收信息的变量能够接收的形式。
	// 这里输入的整型变量，因此，计算机该输入转换为用来存储整数的数字形式。
	cin >> carrots;
	cout << "Here are two more. \n";
	carrots = carrots + 2;
	// 输出结果
	cout << "Now you have " << carrots << " carrots" << endl;

	return 0;
}
~~~

该程序使用了 cin 的系特性：读取键盘输入并何为一句。

#### 1. 使用 cin

语法格式：

~~~c++
std::cin >> 变量名;
~~~

可知：信息从 cin 流向了 变量中；当数据输入后时， cin 使用 >> 运算符从输入流中抽取字符。

#### 2. 使用 cout 进行拼接

拼接语法：

~~~c++
std::cout << String << 变量 << String << endl;
~~~

当拼接语句过长时可以按照一下方法排列：

~~~c++
std::cout << String 
    << 变量 
    << String 
    << endl;
~~~

#### 3. 类简介

类是 C++ 中面向对象编程（OOP）的核心概念之一。

类是开发者i当以的一种数据类型；定义的类需要描述它能够表示说明信息和可对数据执行那些操作。

> 注意：类描述了一种数据类型的全部属性（包括了可使用它执行的操作），对象时根据这些描述创建的实体。

![image-20220504104700441](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220504104700441.png)



### 4. 函数

> 目标：
>
> 1. 使用有返回值的函数
> 2. 函数变体
> 3. 用户定义的函数
> 4. 用户定义有返回值的函数
> 5. 在多函数程序中使用 using 编译指令

进行函数的简单编写

#### 1. 使用有返回值的函数

`sqrt.cpp`

~~~c++
#include <iostream>
#include <cmath>

int main()
{
	using namespace std;

	// 定义 double 类型的变量
	double area;
	cout << "Enter the floor area, in square feet, of your home:";
	// 输入数据
	cin >> area;
	// 创建 size 变量,存储运算后的结果
	double size;
	size = sqrt(area);
	// 输出结果
	cout << "That's the equivalent of a square " << size
		<< " feet to the side." << endl;
	cout << "How fascinating!" << endl;

	return 0;
}
~~~

在这个示例中，使用了 C/C++ 库中的名为 sqrt() 的函数，它返回平方根结果。

![image-20220504105334122](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220504105334122.png)

通过调用该函数并传入对应的数值可以获取到对应的平方根数据，被调用的函数叫做调用函数（called function），包含函数调用的函数叫做调用函数（calling function）。

![image-20220504105356763](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220504105356763.png)

> 注意：
>
> 1. C++ 编译器必须知道函数的参数类型和返回值
> 2. C++ 程序应当为程序中使用的每个函数提供原型。

如：

~~~c++
// 返回值  函数名（传入数据的类型）
double sqrt(double)
~~~

原型的提供有两种方法实现：

- 在源文件中输入函数原型
- 包含头文件 cmath（老系统为math.h），其中定义了原型

推荐第二种方法，因为头文件更有可能使原型正确。原型只是用来描述接口。

#### 2. 函数变体

当函数需要多个形参时，使用逗号分隔

~~~c++
// 数据类型  函数名（数据类型1，数据类型2...）
double pow(double,double);
~~~

如果参入的参数为 void 则代表该函数不接受任何参数。（不写也可以）

#### 3. 用户定义的函数

`ourfunc.cpp`

~~~c++
#include <iostream>
// 函数头
void simon(int); // 定义一个 simon 的函数

// 放在函数外面所有的函数都无需添加std头；反之放在函数里面，只有当前函数可以使用
using namespace std;

int main()
{
	simon(3); // 调用 simon 函数
	cout << "Pick an integer: ";
	// 定义变量
	int count;
	// 输入值
	cin >> count;
	//调用函数
	simon(count);
	// 返回结果
	cout << "Done!!" << endl;
	// 结束进程
	return 0;

}

void simon(int n) {
	cout << "Simon says touch your toes " << n << " times" << endl;
}
~~~

所谓的用户自定义函数则是开发者根据程序的需求创建相应的方法用户解决该程序所需的问题。

定义的函数格式为：

~~~c++
// 函数原型
type functionName(argumentList);
// 函数
type functionName(argumentList)
{
    statements;
}
~~~

![image-20220504111842418](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220504111842418.png)

#### 4. 用户定义有返回值的函数

`convert.cpp`

~~~c++
#include <iostream>

// 题目：
// 计算浴室石英重量，1石英 = 14镑

// 定义函数类型
int stonetolb(int); // 函数原型

// 主函数
int main()
{
	using namespace std;
	// 声明石英数量变量
	int stone;
	cout << "Enter the weigth in stone: ";
	// 输入数量
	cin >> stone;
	// 调用函数计算
	int pounds = stonetolb(stone);
	// 输出结果
	cout << stone << " stone = " << pounds << " pounds." << endl;

	return 0;
}

int stonetolb(int sts)
{
	// return 14 * sts;
	int pounds = 14 * sts;
	return pounds;
}
~~~

函数分析：

1. 在主函数中定义了 stone 变量用于存储用户输入的值
2. 当用户输入之后，调用函数
3. 函数中执行运算方法后并将值返回出去
4. 通过 pounds 接收函数返回值
5. 最后将转换的数据输出

![image-20220504112239471](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220504112239471.png)

在 stonetolb 中的特性：

- 有函数头和函数体
- 接受一个参数
- 返回一个值
- 需要一个原型

#### 5. 在多函数程序中使用 using 编译指令

程序访问名称空间 std 的方法：

- 将using namespace std；放在函数定义之前，让文件中所有的函数都能够使用名称空间 std 中所有的元素。

- 将using namespace std；放在特定的函数定义中，让该函数能够使用名称空间 std 中的所有元素。

- 在特定的函数中使用类似using std:cout;这样的编译指令，而不是using namespace std；让该函数能够使用指定的元素，如：cout。

- 完全不使用编译指令usig，而在需要使用名称空间std中的元素时，使用前缀std:，如下所示：

  ~~~c++
  std：:cout << "I'm using cout and endl from the std namespace"<< std::endl；
  ~~~

  

