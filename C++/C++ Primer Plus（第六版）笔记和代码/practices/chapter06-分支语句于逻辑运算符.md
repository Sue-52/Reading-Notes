## chapter06-分支语句与逻辑运算符

> 1. 复习题
> 2. 编程题


### 复习题

**1. 请看下面两个计算空格和换行符数目的代码片段：**

~~~c++
// Version 1
while(cin.get(ch))
{
    if (ch == ' ')
        spaces++;
    if (ch == '\n')
        newlines++;
}
~~~

~~~c++
// Version 2
while (cin.get(ch))
{
    if (ch == ' ')
        spaces++;
    else if (ch == '\n')
        newlines++;
}
~~~

**第二种格式比第一种格式好在哪里呢？**

> 在 Version 1 中，通过 while 循环后，进入循环体内部会进行两次的判断，效率并不好。但是，在 Version 2 中进入循环体内部中只需有一个条件成立即可，无需过多的判断



**2. 在程序清单 6.2 中，用 ch+1 替换 ++ch 将发生什么情况呢？**

> ++ch 和 ch + 1 得到的数值相同。但是 ++ch 的类型为 char，将作为字符输出，而 ch + 1 是 int 类型 （因为将 char 和 int 相加），将作为数字输出。



**3. 请认真考虑下面的程序：**

~~~c++
#include <iostream>
using namespace std;
int main()
{
    char ch;
    int ct1, ct2;
    
    ct1 = ct2 = 0;
    while ((ch = cin.get()) != '$')
    {
        cout << ch;
        ct1++;
        if (ch = '$')
            ct2++;
        cout << ch;
    }
    cout << "ct1 = " << ct1 << ", ct2 = " << ct2 << "\n";
    
    return 0;
}
~~~

**假设输入如下（请在每行末尾按回车键）：**

~~~bash
Hi！
Send $10 or $20 now!
~~~

**则输出将是什么（还记得吗，输入被缓冲）？**

![image-20220526150658687](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220526150658687.png)



**4 .创建表示下述条件的逻辑表达式：**
	a. weight 大于或等于 115，但小于 125。
	b. ch 为 q 或 Q。
	c. x 为偶数，但不是 26。
	d. x 为偶数，但不是 26 的倍数。
	e. donation 为 1000 - 2000 或 guest 为 1。
	f. c 是小写字母或大写字母（假设小写字母是依次编码的，大写字母也是依次编码的，但在大小写字母间编码不是连续的）。

> a. 115 <= weight < 125
>
> b. ch == 'q' || ch =='Q'
>
> c. x % 2 == 0 && x != 26
>
> d. x % 2 == 0 && x % 26 != 0
>
> e. (donation >= 1000 && donation <=2000) || guest == 1
>
> f. (ch >= 'a' && ch <='z') || (ch>='A' && ch<='Z')



**5. 在英语中，“I will not not speak（我不会不说）”的意思与“I will speak（我要说）”相同。在C++ 中，!!x 是否与 x 相同呢？**

> !!x 获得的值为：true、false，为布尔值，而 x 是获取该数值的值



**6. 创建一个条件表达式，其值为变量的绝对值。也是说，如果变量 x 为正，则表达式的值为 x：但如果 x 为负，则表达式的值为 -x 一这是一个正值。**

> x > 0 ? x : -x;



**7.用switch改写下面的代码片段：**

~~~c++
if (ch == 'A')
    a_grade++;
else if (ch == 'B')
    b_grade++;
else if (ch == 'C')
    c_grade++;
else if (ch == 'D')
    d_grade++;
else
    f_grade++;
~~~

~~~c++
switch(ch)
    case 'A':
		a_grade++;
		break;
    case 'B':
		b_grade++;
		break;
    case 'C':
		c_grade++;
		break;
    case 'D':
		d_grade++;
		break;
    default:
		f_grade++;
		break;
~~~



**8. 对于程序清单6.10，与使用数字相比，使用字符（如 a 和 c ）表示菜单选项和case标签有何优点呢？（提示：想想用户输入q和输入5的情况。）**

> 如果使用整数标签，且用户输入了非整数（如q），则程序将因为整数输入不能处理字符而挂起。但是，如果使用字符标签，而用户输入了整数（如5），则字符输入将5作为字符处理。然后，switch语句的default部分将提示输入另一个字符。



**9. 请看下面的代码片段：**

~~~c++
int line = 0;
char ch;
while (cin.get(ch))
{
    if (ch =='Q')
        break;
    if (ch != '\n')
        continue;
    line++;
}
~~~

**请重写该代码片段，不要使用 break 和 continue 语句。**

~~~c++
int line = 0;
char ch;
while(cin.get(ch) && ch != 'Q')
{
    if (ch == '\n')
        line++;
}
~~~



### 编程题

**1. 编写一个程序，读取键盘输入，直到遇到@符号为止，并回显输入（数字除外），同时将大写字符转换为小写，将小写字符转换为大写（别忘了cctype函数系列）。**

~~~c++
#include <iostream>
#include <cctype>

int main()
{
	using namespace std;

	char ch;
	// 循环
	while (cin >> ch && ch != '@')
	{
        // 判断是否为小写
		if (islower(ch))
		{
			ch = toupper(ch);
			cout << ch;
			continue;
		}
        // 是否为大写
		else if (isupper(ch))
		{ 
			ch = tolower(ch);
			cout << ch;
			continue;
		}
	}

	return 0;
}
~~~

![image-20220526160900942](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220526160900942.png)

**2. 编写一个程序，最多将10个donation值读入到一个double数组中（如果您愿意，也可以使用模板类array）。程序遇到非数字输入时将结束输入，并报告这些数字的平均值以及数组中有多少个数字大于平均值。**

~~~c++
#include <iostream>
const int ArSize = 10;

int main()
{
	using namespace std;

	int donation[ArSize];          // 数值数组
	double average = 0;            // 平均值
	double num = 0;                // 大于平均值的个数
	double sum = 0;			       // 总和

	cout << "最多输入10个数字，输入任意非数字结束\n";

	int i = 0;
	// 循环添加并累加数值
	while (i < 10 && cin >> donation[i])
	{
		sum += donation[i];
		++i;
	}

	// 计算大于平均值的个数
	for (int j = 0; j < i; j++)
	{
		if (donation[i] > average)
			num++;
	}
	// 平均值
	average = sum / i;

	cout << "数组中共有" << i << "个数，其中大于平均值" << average << "的有" << num << "个。";

	return 0;
}
~~~

![image-20220526165009673](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220526165009673.png)

**3. 编写一个菜单驱动程序的雏形。该程序显示一个提供4个选项的菜单————每一个选项用一个字母标记。如果用户使用有效选项之外的字母进行响应，程序将提示用户输入一个有效的字母，直到用户这样做为止。然后，该程序使用一条switch语句，根据用户的选择执行一个简单的操作。
该程序的运行情况如下：**

~~~bash
Please enter one of the following choices:
c) carnivore                p) pianist
t) tree                     g) game
f
Please enter a, c, p, t, or g: q
Please enter a, c, p, t, or g: t
A maple is a tree.
~~~

~~~c++
#include <iostream>

int main()
{
	using namespace std;

	char ch;

	cout << "Please enter one of the following choices:\n";
	cout << "c) carnivore           p) pianist\n";
	cout << "t) tree                g) game\n";

	while (cin >> ch)
	{
		switch (ch)
		{
		case 'c':
			cout << "A maple is a tree.";
			break;
		case 'p':
			cout << "A maple is a tree.";
			break;
		case 't':
			cout << "A maple is a tree.";
			break;
		case 'g':
			cout << "A maple is a tree.";
			break;
		default:
			cout << "Please enter a c, p, t, or g: ";
			break;
		}
	}

	return 0;
}
~~~

![image-20220526195514677](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220526195514677.png)

**4. 加入Benevolent Order of Programmer后，在BOP大会上，人们可通过加入者的真实姓名、头衔或秘密BOP来了解他（她）。请编写一个程序，可以使用真实姓名、头衔、秘密姓名或成员preference（书中翻译为偏好，个人认为应该翻译为优先权）来      列出成员。编写该程序时，请使用下面的结构：**

~~~c++
//Benevolent Order of Programmers name structure
struct bop{
    char fullname[strsize];  // real name
    char title[strsize];     // job title
    char bopname[strsize];   // secret BOP name
    int preference;          // 0 = fullname, 1 = title, 2 = bopname
};
~~~

  **该程序创建一个由上述结构组成的小型数组，并将其初始化为适当的值。另外，该程序是用一个循环，让用户在下面的选项中进行选择：**

~~~bash
    a. display by name            b. display by title
    c. display by bopname         d. display by preference
    q. quit
~~~

  **注意，“display by preference”，并不意味着显示成员的preference，而是意味着根据成员的preference来列出成员。例如：如果preference为1，则选择d将显示程序员的头衔。该程序运行情况如下：**

~~~bash
Benevolent Order of Programmers Report
a. display by name            b. display by title
c. display by bopname         d. display by preference
q. quit
Enter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Junior Programmer
MIPS
Analyst Trainee
LOOPY
Next choice: q
Bye!    
~~~

~~~c++
#include <iostream>
// 定义函数
void showReport();
void choice_a();
void choice_b();
void choice_c();
void choice_d();

const int strsize = 30;
const int num = 5;
// 定义结构
struct	bop {
    char fullname[strsize];  // real name
    char title[strsize];     // job title
    char bopname[strsize];   // secret BOP name
    int preference;          // 0 = fullname, 1 = title, 2 = bopname
};
// 定义数组数据
bop number[num] = {
    {"Wimp Macho", "WM头衔", "WM秘密姓名",0},
    {"Raki Rhodes", "Junior Programmer","RR秘密姓名",1},
    {"Celia Laiter", "CL头衔","MIPS",2},
    {"Hoppy Hipman", "Analyst Trainee","HH秘密姓名",1},
    {"Pat Hand", "PH头衔","LOOPY",2}
};

using namespace std;

int main()
{
    // 显示要展示内容
    showReport();

    char ch;
    // 输入内容和遍历
    while(cin >> ch && ch != 'q')
    {
        // 分支判断输入内容
        switch (ch)
        {
        case 'a':
            choice_a();
            break;
        case 'b':
            choice_b();
            break;
        case 'c':
            choice_c();
            break;
        case 'd':
            choice_d();
            break;
        default:
            cout << "Please enter a a, b, c, or d : ";
            break;
        }
        cout << "Next choice: ";
    }

    cout << "Bye!";

    return 0;
}
// 要展示内容
void showReport()
{
    cout << "Benevolent Order of Programmers Report: \n";
    cout << "a. display by name              b. display by title\n";
    cout << "c. display by bopname           d. display by perference\n";
    cout << "q. quit\n";
}
// 展示 fullname
void choice_a()
{
    using namespace std;
    for (int i = 0; i < num; i++)
        cout << number[i].fullname << endl;
}
// 展示 title
void choice_b()
{
    using namespace std;
    for (int i = 0; i < num; i++)
        cout << number[i].title << endl;
}
// 展示 bopname
void choice_c()
{
    using namespace std;
    for (int i = 0; i < num; i++)
        cout << number[i].bopname << endl;
}
// 选择展示信息
void choice_d()
{
    using namespace std;
    for (int i = 0; i < num; i++)
    {
        if (number[i].preference == 0)
            cout << number[i].fullname << endl;
        else if (number[i].preference == 1)
            cout << number[i].title << endl;
        else if (number[i].preference == 2)
            cout << number[i].bopname << endl;
    }
}
~~~

![image-20220526201015624](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220526201015624.png)

**5. 在Neutronia王国，货币单位是tvarp，收入所得税的计算方式如下：
  5000 tvarp：不收税
  5001~15000 tvarps: 10%
  15001~35000 tvarps: 15%
  35000 tvarps以上: 20%**

~~~c++
#include <iostream>

int main()
{
    using namespace std;
    double income;     // 个人工资
    double tax;        // 扣税总额

    cout << "请输入您的收入（tvarp）：";

    while (cin >> income && income != 'q')
    {
        if (income <= 5000)
            cout << "tax = " << 0 << " 税收.\n";
        else if (income >= 5001 && income <= 15000)
            cout << "tax = " << (income - 5000) * 0.1 << " 税收.\n";
        else if (income >= 15001 && income <= 35000)
            cout << "tax = " << (income - 15000) * 0.15 + (income - 5000) * 0.1 << " 税收.\n";
        else
            cout << "tax = " << (income - 35000) * 0.2 + (income - 15000) * 0.15 + (income - 5000) * 0.1 << " 税收.\n";
    }

    cout << "end";

    return 0;
}
~~~

![image-20220526203250032](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220526203250032.png)

**6. 编写一个程序，记录捐助给“维护合法权益团体”的资金。该程序要求用户输入捐献者的数目，然后要求用户输入每一个捐献者的姓名和款项。这些信息被存储在一个动态分配的数组里。每一个结构有两个成员：用来存储姓名的字符数组（或string对象）和用来存储款项的double成员。读取所有数据后，程序将显示所有捐款超过10000的捐款者的姓名即捐款数额。该列表应包含一个标题，指出下面的捐款者是重要捐款人（Grand Patrons）。然后，程序将列出其他的捐款者，该列表要以Patrons开头。如果某种类别没有捐献者，则程序打印单词“none”。给程序只显示这两种类别，而不进行排序。**

~~~c++
#include <iostream>

int main()
{
    using namespace std;

    struct message
    {
        char name[20];
        double money;
    };
    int num;
    int j = 0;
    int k = 0;

    cout << "请输入捐献者的数目：";
    cin >> num;
    cin.get();
    message* full = new message[num];

    for (int i = 0; i < num; i++)
    {
        cout << "请输入第" << i + 1 << "位捐款者的姓名：";
        cin.get(full[i].name, 20).get();
        cout << "请输入第" << i + 1 << "位捐款者的数额：";
        cin >> full[i].money;
        cin.get();
    }

    // 捐款大于10000人员
    cout << "Grand Patrons:\n";
    for (int i = 0; i < num; i++)
    {
        if (full[i].money > 10000)
        {
            cout << full[i].name << "\t\t\t" << full[i].money << endl;
            j++;
        }
    }
    if (j == 0)
        cout << "none\n";

    // 捐款小于10000人员
    cout << "Patrons:\n";
    for (int i = 0; i < num; i++)
    {
        if (full[i].money <= 10000)
        {
            cout << full[i].name << "\t\t\t" << full[i].money << endl;
            k++;
        }
    }
    if (k == 0)
        cout << "none\n";

    return 0;
}
~~~

![image-20220526210252407](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220526210252407.png)

**7. 编写一个程序，每次读取一个单词，直到用户只输入q。然后，给程序指出有多少个单词以元音打头。有多少个单词以辅音打头，还有多少个单词不属于这两类。为此，方法之一是，使用isalpha()来区分以字母和其他字符打头的单词，然后对于通过了isalpha()测试的单词，使用if或switch语句来确定哪些以元音打头。该程序运行情况如下：**

~~~bash
Enter words (q to quit):
The 12 awesome oxen ambles
quietly across 15 meters of lawn. q
5 words beginning with vowels
4 words beginning with consonants
2 others
~~~

~~~c++
#include <iostream>
#include <string>
#include <cctype>

int isvowels(char);

int main()
{
    using namespace std;

    string word;
    int i = 0;
    int j = 0;
    int k = 0;

    cout << "Enter words (q to quit):\n";

    while (cin >> word && word != "q")
    {
        if (isalpha(word[0]))
        {
            if (isvowels(word[0]))
                i++;
            else
                j++;
        }
        else
            k++;
    }

    cout << i << " words beginning with vowels\n";
    cout << j << " words beginning with consonants\n";
    cout << k << " others";

    return 0;
}

int isvowels(char a)
{
    a = tolower(a);
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return 1;
    else
        return 0;
}
~~~

![image-20220527080455670](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220527080455670.png)

**8. 编写一个程序，它打开一个文件，逐字符地读取该文件，直到达到文件末尾，然后指出该文件中包含多少字符。**

```cpp
#include <iostream>
#include <fstream>
#include <cstdlib>

int n = 0;

int main()
{
	using namespace std;

	ifstream inFile;
	inFile.open("123.txt");
	if (!inFile.is_open())
	{
		exit(EXIT_FAILURE);
	}

	char ch;
	while (ch = inFile.get() != EOF)
	{
		n += 1;
	}
	cout << "字符数量：" << n << endl;

	return 0;
}
```

![image-20220527081154299](https://raw.githubusercontent.com/Sue-52/PicGo/main/images/image-20220527081154299.png)

**9. 完成编程练习6，但从文件中读取所需的信息。该文件的第一项应为捐款人数，余下的内容应为成对的行。在每一对中，第一行为捐款人姓名。第二行为捐款数额。即该文件类似于下面：**

~~~bash
   4
   Sam Stone
   2000
   Freida Flass
   100500
   Tammy Tubba
   5000
   Rich Raptor
   55000
~~~

~~~c++
#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
    using namespace std;

    struct message
    {
        char name[20];
        double money;
    };
    int num;
    int j = 0;
    int k = 0;

    ifstream inFile;                 //声明ifstream对象
    inFile.open("excise6.txt");      //将ifstream对象与特定文件关联
    if (!inFile.is_open())           //检查是否正确打开文件
    {
        exit(EXIT_FAILURE);
    }


    cout << "请输入捐献者的数目：";
    inFile >> num;
    inFile.get();
    message* full = new message[num];

    for (int i = 0; i < num; i++)
    {
        cout << "请输入第" << i + 1 << "位捐款者的姓名：";
        inFile.get(full[i].name, 20).get();
        cout << "请输入第" << i + 1 << "位捐款者的数额：";
        inFile >> full[i].money;
        inFile.get();
    }

    cout << "Grand Patrons:\n";
    for (int i = 0; i < num; i++)
    {
        if (full[i].money > 10000)
        {
            cout << full[i].name << "\t\t\t" << full[i].money << endl;
            j++;
        }
    }
    if (j == 0)
        cout << "none\n";

    cout << "Patrons:\n";
    for (int i = 0; i < num; i++)
    {
        if (full[i].money <= 10000)
        {
            cout << full[i].name << "\t\t\t" << full[i].money << endl;
            k++;
        }
    }
    if (k == 0)
        cout << "none\n";

    return 0;
}
~~~

