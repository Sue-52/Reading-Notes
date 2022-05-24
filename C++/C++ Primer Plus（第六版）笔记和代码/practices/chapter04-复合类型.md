## 第四章 - 复合类型

### 练习题

1. 如何声明下述数据？
	1. actor是由30个char组成的数组。
	2. betsie是由100个short组成的数组
	3. chuck是由13个float组成的数组。
	4. dipsea是由64个long double组成的数组。

~~~c++
#include <iostream>

int main()
{
	using namespace std;

	char actor[30];
	short betsie[100];
	float chuck[13];
	long double dipsea[64];

	return 0;
}
~~~

2. 使用模板类 array 而不是数组来完成问题 1。

~~~c++
#include <iostream>
#include <array>

int main()
{
	using namespace std;

	array<char, 30> actor;
	array<short, 100> betsie;
	array<float, 13> chuck;
	array<long double, 64> dipsea;

	return 0;
}
~~~

3. 声明一个包含 5 个元素的 int 数组，并将它初始化为前 5 个正奇数。

~~~c++
#include <iostream>
#include <array>

int main()
{
	using namespace std;

	int arr1[5] = { 1, 3, 5, 7, 9 };
	array<int, 5> arr2 = { 1, 3, 5, 7, 9 };

	return 0;
}
~~~

4. 编写一条语句，将问题 3 中数组第一个元素和最后一个元素的和赋给变量 even。

~~~c++
#include <iostream>

int main()
{
	using namespace std;

	int arr1[5] = { 1, 3, 5, 7, 9 };
	int even = arr1[4];

	return 0;
}
~~~

5. 编写一条语句，显示 float 数组 ideas 中的第2个元素的值。

~~~c++
#include <iostream>

int main()
{
	using namespace std;

	float arr1[5] = { 1.0, 3.0, 5.0, 7.0, 9.0 };
	cout << arr1[1] << endl;

	return 0;
}
~~~

6. 声明一个 char 的数组，并将其初始化为字符串 “cheeseburger”。

~~~c++
#include <iostream>

int main()
{
	using namespace std;

	char str[12] = "cheeseburger";

	return 0;
}
~~~

7. 声明一个 string 对象，并将其初始化为字符串 “Waldorf Salad”。

~~~c++
#include <iostream>
#include <array>
#include <vector>

int main()
{
	using namespace std;

	string str = "Waldorf Salad";

	return 0;
}
~~~

8. 设计一个描述鱼的结构声明。结构中应当包括品种、重量（整数，单位为盎司）和长度（英寸，包括小数）。

~~~c++
#include <iostream>

struct inflatable
{
	char variety;
	int weight;
	double length;
};

int main()
{
	using namespace std;
	return 0;
}
~~~

9. 声明一个问题 8 中定义的结构的变量，并对它进行初始化。

~~~c++
#include <iostream>

struct inflatable
{
	char variety;
	int weight;
	double length;
};

int main()
{
	using namespace std;

	inflatable thing =
	{
		'pc',
		30,
		34.5
	};

	cout << "Name: " << thing.variety << endl;
	cout << "Weigth: " << thing.weight << endl;
	cout << "Length: " << thing.length << endl;
	
	return 0;
}
~~~

10. 用 enum 定义一个名为 Response 的类型，它包含 Yes、No 和 Maybe 等枚举量，其中 Yes的值为 1, No 为 0，Maybe 为 2。

~~~c++
#include <iostream>
enum Response { No, Yes, Maybe };

int main()
{
	using namespace std;
		
	return 0;
}
~~~

11. 假设 ted 是一个 double 变量，请声明一个指向 ted 的指针，并使用该指针来显示 ted 的值。

~~~c++
#include <iostream>

int main()
{
	using namespace std;

	double ted = 13.3;
	double* pt = &ted;

	cout << "ted value: " << ted << endl;
	cout << "address: " << pt << endl;
	cout << "address value: " << *pt << endl;

	delete pt;
		
	return 0;
}
~~~

12. 假设 treacle 是一个包含 10 个元素的 float 数组，请声明一个指向 treacle 的第一个元素的指针，并使用该指针来显示数组的第一个元素和最后一个元素。

~~~c++
#include <iostream>

int main()
{
	using namespace std;

	double treacle[10] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };;
	double* pt = treacle;

	cout << "treacle first element: " << pt[0] << endl;
	cout << "treacle end element: " << pt[9] << endl;
		
	return 0;
}
~~~

13. 编写一段代码，要求用户输入一个正整数，然后创建一个动态的it数组，其中包含的元素数目等于用户输入的值。首先使用 new 来完成这项任务，再使用 vector 对象来完成这项任务。

~~~c++
#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	int num;

	cout << "Enter a number: ";
	cin >> num;
	// 通过指针保存数值
	int* newNum = new int(num);

	vector<int> it(num);
	it[0] = num;

	cout << it[0] << endl;
		
	return 0;
}
~~~

14. 下面的代码是否有效？如果有效，它将打印出什么结果？
    ~~~c++
    cout<<(int *)"Home of the jolly bytes"；
    ~~~

> 是有效的，改行作用是获取字符串的地址。
> 最终输出结果为该字符串所保存在内存中的地址。

15. 编写一段代码，给问题 8 中描述的结构动态分配内存，再读取该结构的成员的值。

~~~c++
#include <iostream>

struct inflatable
{
	char variety[20];
	int weight;
	double length;
};

int main()
{
	using namespace std;
	
	inflatable* fish = new inflatable;

	cout << "Enter a kind of fish: ";
	cin >> fish->variety;
	cout << fish->variety;

	return 0;
}
~~~

16. 程序清单4.6指出了混合输入数字和一行字符串时存储的问题。如果将下面的代码：
    ~~~c++
    cin.getline(address，80)；
    ~~~
    替换为：
    ~~~c++
    cin >> address；
    ~~~

> 使用cin>>address将使得程序跳过空白，直接找到非空白字符为止。然后它将读取字符，直到再次遇到空白为止。因此，它将跳过数字输入后的换行符，从而避免这种问题。另一方面，它只读取一个单词，而不是整行。

17. 声明一个 vector 对象和一个 array 对象，它们都包含 10 个 string 对象。指出所需的头文件，但不要使用 using。使用 const 来指定要包含的 string 对象数。

~~~c++
#include <iostream>
#include <vector>
#include <array>

const int str_num = { 10 };

int main()
{
	
	std::vector<std::string> vstr[10];
	std::array<std::string, 10> astr;

	return 0;
}
~~~

### 编程题

1. **编写一个C++程序，如下述输出示例所示的那样请求并显示信息：**
	~~~txt
	What is your first name? Betty Sue
	What is your last name? Yewe
	What letter grade do you deserve? B
	What is your age? 22
	Name: Yewe, Betty Sue
	Grade: C
	Age: 22
	~~~
	> **注意，该程序应该接受的名字包含多个单词。另外，程序将向下调整成绩，即向上调一个字母。假设用户请求 A、B 或 C，所以不必担心 D 和 F 之间的空档。**

~~~c++
#include <iostream>

struct person_info
{
	char first_name[20];
	char last_name[20];
	char grade[1];
	int age;
};

int main()
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
~~~

2. **修改程序清单4.4，使用C++string类而不是char数组**

~~~c++
#include <iostream>

int main()
{
    using namespace std;
    
    string name1, name2;
    string dessert;

    cout << "Enter your name:\n";
    cin >> name1 >> name2;// reads through newline
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name1 + " " + name2 << ".\n";
    // cin.get();
    
    return 0;
}
~~~

3. **编写一个程序，它要求用户首先输入其名，然后输入其姓；然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。请使用char数组和头文件cstring中的函数。下面是该程序运行时的情形：**
   ~~~txt
   Enter your first name: Flip
   Enter your last name: Fleming
   Here's the information in a single string: Fleming, Flip
   ~~~

~~~c++
#include<iostream>
#include <cstring>
#pragma warning(disable:4996) // 解决不安全问题报错

int main()
{
    using namespace std;
    char first_name[20];
    char last_name[20];
    char full_name[2 * 20 + 1];


    cout << "What is your first name?";
    cin >> first_name;
    cout << "what is your last name? ";
    cin >> last_name;
    
    strncpy(full_name, last_name, 20);//strcnpy是将指定长度的字符串复制到指定的数组中
    strcat(full_name, ", ");//将两个char类型连接
    strncat(full_name, first_name, 20);//在字符串末尾追加n个字符
    full_name[20 - 1] = '\0';
    
    cout << "here is the information in a single string: " << full_name << endl;
    
    return 0;
}
~~~

4. **编写一个程序，它要求用户首先输入其名，再输入其姓；然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。请使用string对象和头文件string中的函数。下面是该程序运行时的情形：**
   ~~~txt
   Enter your first name: Flip
   Enter your last name: Fleming
   Here's the information in a single string: Fleming, Flip
   ~~~

~~~c++
// string中可以进行+ 、= 、+= 、>等运算，而cstring中不能进行相关运算。
// 与上体大致相同，但本次要求使用string对象和string头文件
#include<iostream>
#include <string>

int main()
{
    using namespace std;

    string first_name ;
    string last_name ;
    string full_name;

    cout << "What is your first name?";
    cin >> first_name;
    cout << "what is your last name? ";
    cin >> last_name;
    
    full_name = first_name +','+' '+ last_name;
    
    cout << "here is the information in a single string: " << full_name << endl;

    return 0;
}
~~~

5. **结构CandyBar包含了3个成员。第一个成员存储了糖块的品牌；第二个成员存储糖块的重量（可以有小数）；第三个成员存储了糖块的卡路里含量（整数）。请编写一个程序，声明这个结构，创建一个名为snack的CandyBar变量，并将其成员分别初始化为“Mocha Munch”、2.3和350。初始化应在声明snack时进行。最后，程序显示snack变量的内容。**

~~~c++
#include <iostream>

struct CandyBar
{
	char brand[30];
	double weight;
	int calorie;
};

int main()
{
	using namespace std;

	CandyBar snack = {
		"Mocha Munch",
		2.3,
		350
	};

	cout << "CandyBar brand is: "
		<< snack.brand << endl;
	cout << "CandyBar weight is: "
		<< snack.weight << endl;
	cout << "CandyBar calorie is: "
		<< snack.calorie << endl;

	return 0;
}
~~~

6. **结构CandyBar包含3个成员，如编程练习5所示。请编写一个程序，创建一个包含3个元素的CandyBar数组，并将它们初始化为所选择的值，然后显示每个结构的内容。**

~~~c++
#include <iostream>

struct CandyBar
{
	char brand[30];
	double weight;
	int calorie;
};

int main()
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
~~~

7.  **William Wingate 从事比萨饼分析服务。对于每个披萨饼，他都需要记录下列信息：**
   - **披萨饼公司的名称，可以有多个单词组成。**
   - **披萨饼的直径。**
   - **披萨饼的重量。**
     **请设计一个能够存储这些信息的结构，并编写一个使用这种结构变量的程序。程序将请求用户输入上述信息，然后显示这些信息。请使用cin（或它的方法）和cout。**

~~~c++
#include <iostream>

struct William
{
    char brand[20];
    float diameter;
    float weight;
};

int main()
{
    using namespace std;

    William example;

    cout << "Please enter your pizza's information: " << endl;
    cout << "Brand: ";
    cin.getline(example.brand, 20);
    cout << "Diameter: ";
    cin >> example.diameter;
    cout << "Weight: ";
    cin >> example.weight;

    cout << "So the following is your pizza's information:" << endl;
    cout << "Brand: " << example.brand << ".\n";
    cout << "Diameter: " << example.diameter << "cm.\n";
    cout << "Weight: " << example.weight << "kg.\n";

    return 0;
}
~~~

8. **完成编程练习 7，但使用new来为结构分配内存，而不是声明一个结构变量。另外，让程序在请求输入比萨饼公司名称之前输入比萨饼的直径。**

~~~c++
#include <iostream>
#include <string>

struct William
{
    char brand[20];
    float diameter;
    float weight;
};

int main()
{
    using namespace std;

    William* example = new William;

    cout << "Please Enter your pizza's information: " << endl;
    cout << "Brand: ";
    cin.getline(example->brand, 20);
    cout << "Diameter: ";
    cin >> example->diameter;
    cin.get();
    cout << "Weight: ";
    cin >> example->weight;

    cout << "So the folowing is your pizza's  information:" << endl;
    cout << "Brand: " << example->brand << ".\n";
    cout << "Diameter: " << example->diameter << "cm.\n";
    cout << "Weight: " << example->weight << "kg.\n";
    
    delete[] example;

    return 0;
}
~~~

9. **完成编程练习 6，但使用new来动态分配数组，而不是声明一个包含3个元素的CandyBar数组。**

~~~c++
#include <iostream>
#include <string>

struct CandyBar
{
    char brand[80];
    double weight;
    int calorie;
};

int main()
{
    using namespace std;

    CandyBar* snack = new CandyBar[3];

    snack[0] = { "Mocha Munch",2.3,350 };
    snack[1] = { "Fruit Salad", 1.6, 140 };
    snack[2] = { "Fried Chicken", 2.4, 880 };

    cout << "The snack is following: " << endl;
    cout << "Brand: " << snack[0].brand << endl;
    cout << "Weight: " << snack[0].weight << endl;
    cout << "Calorie: " << snack[0].calorie << endl;
    cout << "Brand: " << snack[1].brand << endl;
    cout << "Weight: " << snack[1].weight << endl;
    cout << "Calorie: " << snack[1].calorie << endl;
    cout << "Brand: " << snack[2].brand << endl;
    cout << "Weight: " << snack[2].weight << endl;
    cout << "Calorie: " << snack[2].calorie << endl;

    delete[] snack;

    return 0;
}
~~~

10. **编写一个程序，让用户输入三次40码跑的成绩（如果您愿意，也可让用户输入40米跑的成绩），并显示次数和平均成绩。请使用一个array对象来存储数据（如果编译器不支持array类，请使用数组）。**

~~~c++
#include <iostream>
#include <array>

int main()
{
    using namespace std;

    const int number = 3;
    array<double, number> time;

    cout << "Enter the 1st grade: ";
    cin >> time[0];
    cout << "Enter the 2nd grade: ";
    cin >> time[1];
    cout << "Enter the 3rd grade: ";
    cin >> time[2];

    cout << "So the whole numbers of the grade is " << number << ".\n";
    cout << "The grades are: " << time[0] << ", " << time[1] << ", " << time[2] << ".\n";
    cout << "The average grade is " << (time[0] + time[1] + time[2]) / 3 << ".\n";

    return 0;
}
~~~
