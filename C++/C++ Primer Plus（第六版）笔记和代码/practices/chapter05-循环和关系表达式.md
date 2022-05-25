## chapter05 - 循环和关系表达式

> 1. 练习题
> 2. 编码题

### 练习题

**1.入口条件循环和出口条件循环之间的区别是什么？各种c++循环分别属于其中的哪一种？**

> 入口条件循环：在进入循环提前进行测试表达式，如果最初条件为 false，则不会进入循环体中，反之进入循环。
>
> 出口条件循环：在处理循环体之后评估表达式，哪怕最初条件为 false 都会执行循环一次。
>
> for、while 为入口条件循环；do...while... 则是出口条件循环

**2.如果下面的代码片段是有效程序的组成部分，它将打印什么内容？**

~~~c++
int i;
for (i = 0; i < 5; i++)
    cout << i;
cout << endl;
~~~

> 0、1、2、3、4

**3.如果下面的代码片段是有效程序的组成部分，它将打印什么内容？**

```c++
int j;
    for (j = 0; j < 11; j += 3)
        cout << j;
cout << endl << j << endl;
```

> 0、3、6、9
>
> 12

**4.如果下面代码是有效程序的组成部分，它将打印什么内容？**

```c++
int j = 5;
    while (++j < 9)
        cout << j++ << endl;
```

> 6、8

**5.如果下面代码是有效程序的组成部分，它将打印什么内容？**

```c++
int k = 8;
    do
        cout << "k=" << k << endl;
    while (k++ < 5);   
```

> k = 8

**6.编写一个打印 1、2、4、8、16、32、64 的 for 循环，每轮循环都将计数变量的值乘以2。**

```c++
for (int i = 1; i <= 64; i *= 2)
{
    cout << i << endl;
}
```

**7.如何在循环体中包括多条语句？**

> 1. 初始变量
> 2. 循环条件
> 3. 代码块
> 4. 增长步长

**8.下面的语句是否有效？如果无效，原因是什么？如果有效，它将完成什么工作？**

```c++
int x={1,024};
```

下面的语句又如何呢？

```c++
int y;
y = 1.024;
```

> 当然，第一条语句是有效的，表达式1,024由两个表达式组成——1和024，用逗号运算符链接。
> 值为右侧表达式的值。这是024，八进制为20，因此该表达式将20赋值给x。
>
> 第二条语句，运算符优先级将导致它被判定成这样：
> (y=1),024;
> 也就是说，左侧表达式将y设置成1，整个表达式的值(没有使用)为024或20(八进制)。

**9.在查看输入方面，cin >> ch 同 cin.get(ch) 和 ch = cin.get() 有什么不同？**

|            属性            |      **cin >> ch**      |             **cin.get(ch)**              | **ch = cin.get()**  |
| :------------------------: | :---------------------: | :--------------------------------------: | :-----------------: |
|     传递输入字符的方式     | 赋给参数 ch，不包括空格 |          赋给参数 ch，包括空格           | 将函数返回值赋给 ch |
| 用于字符输入时函数的返回值 |           无            | istream 对象（执行 bool 转换后为 true）  | int 类型的字符编码  |
|  到达 EOF 时函数的返回值   |           无            | istream 对象（执行 bool 转换后为 false） |         EOF         |

### 编码题

**1.编写一个要求用户输入两个整数的程序。该程序将计算并输出这两个整数之间（包括这两个整数）所有整数的和。这里假设先输入较小的整数。例如，如果用户输入的是2和9，则程序将指出2~9之间所有整数的和为44。**

~~~c++
#include <iostream>
// 定义变量
int minNum, maxNum, sum;

int main()
{
	using namespace std;
	
    // 用户输入最小值和最大值
	cout << "Enter a small number:";
	cin >> minNum;
	cout << "Enter a large number:";
	cin >> maxNum;
	
    // 循环遍历并累加
	int i;
	for (i = minNum; i <= maxNum; ++i)
	{
		sum += i;
	}

    // 输出数值
	cout << "Total number from " << minNum << " to "
		<< maxNum << " is: " << sum;

	return 0;
}
~~~

![image-20220524202303627](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220524202303627.png)

**2.使用array对象（而不是数组）和long double（而不是long long）重新编写程序清单5.4，并计算100！的值。**

```c++
#include <iostream>
#include <array>

const int ArSize = 101;

int main()
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
```

![image-20220524203014222](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220524203014222.png)

**3.编写一个要求用户输入数字的程序。每次输入后，程序都将报告到目前为止，所有输入的累计和，当用户输入0时，程序结束。**

```c++
#include <iostream>

int main()
{
	using namespace std;
	
    // 设置变量
	int num;
	int sum = 0;
	
    // 提示用户输入信息
	cout << "Enter the number,unit 0 quit. \n";

	do
	{
        // 输入数值
		cin >> num;
        // 展示用户输入数值
		cout << "Enter the number is: " << num << "\n";
		// 累加
        sum += num;
	} while (num != 0); // 判断条件

    // 输出结果
	cout << "total number is: " << sum;

	return 0;
}
```

![image-20220524205102901](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220524205102901.png)

**4.Daphne以10%的单利投资了100美元。也就是说，每一年的利润都是投资额的10%，即每年10美元：利息=0.10*原始存款。而Cleo在第一年投资100美元的盈利是5%–一共得到105美元。下一年的盈利是105美元的5%–即5.25美元，以此类推。请编写一个程序，计算多少年后，Cleo的投资价值超过Daphne的投资价值。并显示此时两个人的投资价值。**

~~~c++
#include <iostream>

int main()
{
	using namespace std;

	// Daphne 利息 = 0.10 * 存款；
	// Cleo 利息 = 0.05 * 存款 + 存款；

	int Daphne = 100; 
	int Cleo = 100;

	int year = 0;
	while (Daphne >= Cleo)
	{
		Daphne += 10;
		Cleo *= 1.05;
		++year;
	}

	cout << year << " years later," << "Cleo > Daphne" << endl;
	cout << "Dephne:" << Daphne << endl;
	cout << "Cleo:" << Cleo << endl;

	return 0;
}
~~~

![image-20220525081257352](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220525081257352.png)

**5.假设要销售《C++ For Fools》一书。请编写一个程序，输入全年中每个月的销售量（图书数量，而不是销售额）。程序通过循环，使用初始化为月份字符串的char*数组（或string对象数组）逐月进行提示，并将输入数据存储的int数组中。然后，程序计算数组中各元素的总数，并报告这一年的销售情况。**

~~~c++
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    
    string month[12] = { "january", "February", "March", "April", "May", "June",
                        "July", "August", "Septemper", "October", "November", "December" };
    int sales[12], sum = 0;

    for (int i = 0; i < 12; i++)
    {
        cout << "please input the sales of " << month[i] << ": ";
        cin >> sales[i];
        cout << endl;
        sum += sales[i];
    }
    cout << "the sales of whole year is: " << sum;

    return 0;
}
~~~



**6.完成编程练习5，但这一次使用一个二位数组来存储输入—3年中每个月的销售量。程序将报告每年销量以及三年的总销量。**

```c++
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    // 定义年
    string year[3] = { "The First Year", "The Second Year;", "The Third Year;" };
    //  定义月份
    string month[12] = { "january", "February", "March", "April", "May", "June",
                        "July", "August", "Septemper", "October", "November", "December" };
    // 定义销售二维数组
    int sales[3][12];
    int sums[3] = {};

    for (int i = 0; i < size(year); i++)
    {
        // 显示年
        cout << "sales of " << year[i] << endl;
        // 遍历月份
        for (int j = 0; j < size(month); j++)
        {
            // 输入对应月份的销售
            cout << "please input the sales of " << month[j] << ": ";
            // 
            cin >> sales[i][j];
            cout << endl;
            // 累加
            sums[i] += sales[i][j];
        }
        // 显示
        cout << "the sales of " << year[i] << " is: " << sums[i] << endl;
    }

    cout << "the sales of three years is: " << sums[0] + sums[1] + sums[2] << endl;

    return 0;
}
```



**7.设计一个名为car的结构，用它存储下述有关汽车的信息：生产商（存在字符数组或string对象中的字符串）、生产年份（整数）。编写一个程序向用户询问有多少辆汽车。随后，程序使用new来创建一个有相应数量的car结构组成的动态数组。接下来，程序提示用户输入每辆车的生产商（可能有多个单词组成）和年份信息。请注意，这需要特别小心，因为它将交替读取数值和字符串。最后，程序将显示每个结构的内容。该程序的运行情况如下：**

~~~bash
How many cars do you wish to catalog? 2
Car #1:
Please enter the make:Hudson Hornet
Please enter the year made:1952
Car #2:
Please enter the make:Kaiser
Please enter the year made:1951
Here is your collection:
1952 HUdson Hornet
1951 Kaiser
~~~

~~~c++
#include <iostream>
#include <string>
using namespace std;

struct car
{
    string make;
    int year;
};

int main()
{
    cout << "How many cars do you wish to catalog?";
    int carNum;
    cin >> carNum;
    cin.get();
    car *ps = new car[carNum];
    for (int i = 0; i < carNum; i++)
    {
        cout << "Car #" << i + 1 << ":" << endl;
        cout << "PLease enter the make:";
        getline(cin, ps[i].make);
        cout << "PLease enter the year made:";
        cin >> ps[i].year;
        cin.get();
    }
    cout << "Here is your collection:" << endl;
    for (int i = 0; i < carNum; i++)
    {
        cout << ps[i].year << " " << ps[i].make << endl;
    }
    delete[] ps;
    return 0;
}
~~~



**8.编写一个程序，它使用一个char数组和循环来每次读取一个单词，直到用户输入done为止。随后，该程序指出用户输入多少个单词（不包含done）。下面是程序的运行情况：**

```bash
Enter words(to stop,type the word done):
anteater birthday category dumpster
envy finagle geometry done for sure
You entered a total of 7words.
```

**您应在程序中包含头文件cstring，并使用strcmp()来进行比较测试。**

```c++
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "Enter words(to stop,type the word done):" << endl;
    int num = 0;
    char word[25];
    cin >> word;
    while (strcmp(word, "done") != 0)
    {
        num++;
        cin >> word;
    }
    cout << "You entered a total of " << num << " words." << endl;
    return 0;
}
```



**9.编写一个满足前一个练习的中描述的程序，但使用string对象而不是字符数组。请在程序中包含头文件string，并使用关系运算符来进行比较测试。**

```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Enter words(to stop,type the word done):" << endl;
    int num = 0;
    string word;
    cin >> word;
    while (word != "done")
    {
        num++;
        cin >> word;
    }
    cout << "You entered a total of " << num << " words." << endl;
    return 0;
}
```



**10.编写一个使用嵌套循环的程序，要求用户输入一个值，指出要显示多少行。然后，程序将显示相应行数的星号，其中第一行包括一个星号，第二行包括两个星号，以此类推。每一行包含的字符数等于用户指定的行数，在星号不够的情况下，在星号前面加句点。程序的运行情况如下：**

```c++
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter number of row:";
    int rows;
    cin >> rows;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= rows - i; j++)
        {
            cout << ".";
        }
        for (int k = 0; k < i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
```