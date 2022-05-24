---
title: 第二十二章：Mysql 存储过程
lang: en-US
---

# 第二十二章：Mysql 存储过程

存储过程和函数是  事先经过编译并存储在数据库中的一段 SQL 语句的集合，调用存储过程和函数可以简化应用开发人员的很多工作，减少数据在数据库和应用服务器之间的传输，对于提高数据处理的效率是有好处的。

存储过程和函数的区别在于函数必须有返回值，而存储过程没有。

函数：是一个有返回值的过程；

过程：是一个没有返回值的函数；

简单的来说就是为了以后的使用而保存的一条或多条Mysql语句的集合。

**作用：**

1. 使用存过过程，很多相似性的删除，更新，新增等操作就变得轻松了，并且以后也便于管理！
2. 存储过程因为SQL语句已经预编绎过了，因此运行的速度比较快。
3. 存储过程可以接受参数、输出参数、返回单个或多个结果集以及返回值。可以向程序返回错误原因。
4. 存储过程运行比较稳定，不会有太多的错误。只要一次成功，以后都会按这个程序运行。
5. 存储过程主要是在服务器上运行，减少对客户机的压力。
6. 存储过程可以包含程序流、逻辑以及对数据库的查询。同时可以实体封装和隐藏了数据逻辑。
7. 存储过程可以在单个存储过程中执行一系列SQL语句。
8. 存储过程可以从自己的存储过程内引用其它存储过程，这可以简化一系列复杂语句。

## 为什么使用存储过程

- 通过把处理封装在容易使用的单元中，简化复杂的操作（正如前面例子所述）。 
- 由于不要求反复建立一系列处理步骤，这保证了数据的完整性。如果所有开发人员和应用程序都使用同一（试验和测试）存储过程，则所使用的代码都是相同的。
这一点的延伸就是防止错误。需要执行的步骤越多，出错的可能性就越大。防止错误保证了数据的一致性。
- 简化对变动的管理。如果表名、列名或业务逻辑（或别的内容）有变化，只需要更改存储过程的代码。使用它的人员甚至不需要知道这些变化。
这一点的延伸就是安全性。通过存储过程限制对基础数据的访问减少了数据讹误（无意识的或别的原因所导致的数据讹误）的机会。
- 提高性能。因为使用存储过程比使用单独的SQL语句要快。
- 存在一些只能用在单个请求中的MySQL元素和特性，存储过程可以使用它们来编写功能更强更灵活的代码。

总结就是：简单、安全、高性能。

不过在将SQL代码转换为存储过程前，也必须知道其的缺陷：

- 一般来说，存储过程的编写比基本SQL语句复杂，编写存储过程需要更高的技能，更丰富的经验。
- 你可能没有创建存储过程的安全访问权限。许多数据库管理员限制存储过程的创建权限，允许用户使用存储过程，但不允许他们创建存储过程。

> Mysql将编写存储过程的安全和访问与执行存储过程的安全和访问区分开了。这样你不能（或不想）编写自己的存储过程，也仍然可以在适当的时候执行别的存储过程。

## 创建存储过程

**语法格式：**

~~~mysql
CREATE
    [DEFINER = { user | CURRENT_USER }]
　PROCEDURE sp_name ([proc_parameter[,...]])
    [characteristic ...] routine_body
 
proc_parameter:
    [ IN | OUT | INOUT ] param_name type
 
characteristic:
    COMMENT 'string'
  | LANGUAGE SQL
  | [NOT] DETERMINISTIC
  | { CONTAINS SQL | NO SQL | READS SQL DATA | MODIFIES SQL DATA }
  | SQL SECURITY { DEFINER | INVOKER }
 
routine_body:
　　Valid SQL routine statement
 
[begin_label:] BEGIN
　　[statement_list]
　　　　……
END [end_label]
~~~

- IN 输入参数：表示调用者向过程传入值（传入值可以是字面量或变量）
- OUT 输出参数：表示过程向调用者传出值(可以返回多个值)（传出值只能是变量）
- INOUT 输入输出参数：既表示调用者向过程传入值，又表示过程向调用者传出值（值只能是变量）

**声明语句结束符：**

~~~mysql
DELIMITER $$
或
DELIMITER //
~~~

**声明存储过程：**

~~~mysql
CREATE PROCEDURE demo_in_parameter(IN p_in int)  
~~~

**存储过程开始和结束符号：** -- 可嵌套多个

> 每个嵌套块及其中的每条语句，必须以分号结束，表示过程体结束的begin-end块(又叫做复合语句compound statement)，则不需要分号。

~~~mysql
BEGIN .... END
~~~

为语句块贴标签：

~~~mysql
[begin_label:] BEGIN
　　[statement_list]
END [end_label]
~~~

**变量赋值：**

~~~mysql
SET @p_in=1
~~~

**变量定义：**

~~~mysql
-- Declere 变量名 数据类型...
DECLARE l_int int unsigned default 4000000; 
~~~

**创建Mysql存储过程、存储函数：**

~~~mysql
CREATE PROCEDURE 存储过程名（参数）
~~~

**存储过程体：**

~~~mysql
CREATE FUNCTION 存储函数名（参数）
~~~

Ex：

- 首先，在你选择的数据库下的出发过程中创建文件，并将你要写的存储过程写在`源`中并保存。

~~~mysql
CREATE DEFINER=`root`@`localhost` 
PROCEDURE `mysql_scirpt`.`01.CreateStorage`( IN `01.创建存储过程` VARCHAR ( 50 ) )

BEGIN
#Routine body goes here...
SELECT
	AVG( prod_price ) AS "商品平均值" 
FROM
	products;

END
~~~

- 然后，选择你所在的`database`点击存储过程 

![image-20211027171017065](https://gitee.com/sue201982/mysql/raw/master/img/202110292225541.png)

- 最后，会生成一段SQL语句，直接执行后就可以看到结果了

~~~mysql
{ CALL mysql_scirpt.`01.CreateStorage`(:01_创建存储过程) }
~~~

- 运行结果，如图：

![创建存储过程](https://gitee.com/sue201982/mysql/raw/master/img/202110292225542.gif)

::: details 如何在sql文件中直接书写存储过程

~~~mysql
USE mysql_scirpt;

DROP PROCEDURE IF EXISTS mysql_scirpt.myTry;

DELIMITER //
CREATE PROCEDURE myTry(IN 表名 varchar(50))

BEGIN
	pass...
END

DELIMITER ;
~~~

:::

## 删除存储过程

语法格式：

~~~mysql
DROP PROCEDUCE/FUNCTION xxx
~~~

~~~mysql
DROP PROCEDURE myTry 
~~~

![image-20211027174519517](https://gitee.com/sue201982/mysql/raw/master/img/202110292225543.png)

> 如果指定的过程不存在，则`Drop Procedure` 将产生一个错误。当过程存在则删除。可以使用`Drop Procedure If Exists`

## 检查存储过程

为显示用来创建一个存储过程的CREATE语句，使用SHOW CREATEPROCEDURE语句：

~~~mysql
SHOW CREATE PROCEDURE XXX;
~~~

为了获得包括何时、由谁创建等详细信息的存储过程列表，使用SHOW PROCEDURE STATUS。

**限制过程状态结果**: SHOW PROCEDURE STATUS列出所有存储过程。为限制其输出，可使用LIKE指定一个过滤模式，例如：

~~~mysql
SHOW PROCEDURE STATUS LIEK 'XXX';
~~~

## 存储过程语法

存储过程是可以编程的，意味着可以使用变量，表达式，控制结构 ， 来完成比较复杂的功能。

### 变量

变量（variable）内存中一个特定的位置，用来临时存储数据。

在调用时，这条语句并不显示是任何数据。它返回以后可以显示（或在其他处理中使用）的变量。

语法格式：

~~~mysql
DECLARE var_name[,...] type [DEFAULT value]
~~~

通过 DECLARE 可以定义一个局部变量，该变量的作用范围只能在 BEGIN…END 块中，，并且必须在复合语句的开头，在任何其它语句之前；可以被用在嵌套的块中，除了那些用相同名字声明变量的块。

果要给变量提供一个默认值，使用DEFAULT子句(值可以是常数，也可以指定为一个表达式)；如果没有DEFAULT子句，初始值为NULL。

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`03.CreateVariable`;

DELIMITER $$
$$
CREATE PROCEDURE mysql_scirpt.`03.CreateVariable`(OUT num1 int)
BEGIN
	DECLARE num2 int DEFAULT 200;
	SET num1 = num2;
END$$
DELIMITER ;

CALL `03.CreateVariable`(@num);
SELECT @num;
~~~

局部变量的作用域：
　　
	也就是变量能正常使用而不出错的程序块的范围。

在嵌套块的情况下，
　　
	在外部块中声明的变量可以在内部块中直接使用；
	在内部块中声明的变量只能在内部块中使用。

![image-20211027210926499](https://gitee.com/sue201982/mysql/raw/master/img/202110292225544.png)

> `@` 所声明的变量相当于在外部起到一个占位符的作用。且必须要使用 call方法进行调用后。

~~~mysql
CALL `03.CreateVariable`(@num);
SELECT @num;
~~~

### IF 条件判断

语法格式：

- **IF ... then单次判断：**

语法格式：

~~~mysql
IF expression THEN 
   statements;
END IF;
~~~

如果表达式(expression)计算结果为TRUE，那么将执行statements语句，否则控制流将传递到END IF之后的下一个语句。

执行流程图：

![img](https://gitee.com/sue201982/mysql/raw/master/img/202110292225545.png)

- **Else 双判断：**

语法格式：

~~~mysql
IF expression THEN
   statements;
ELSE
   else-statements;
END IF;
~~~

如果表达式计算结果为FALSE时执行语句，请使用IF ELSE语句

流程图：

![img](https://gitee.com/sue201982/mysql/raw/master/img/202110292225546.png)

- **多条件判断：**

~~~mysql
IF expression THEN
   statements;
ELSEIF elseif-expression THEN
   elseif-statements;
...
ELSE
   else-statements;
END IF;
~~~

如果表达式(expression)求值为TRUE，则IF分支中的语句(statements)将执行；如果表达式求值为FALSE，则如果elseif_expression的计算结果为TRUE，MySQL将执行elseif-expression，否则执行ELSE分支中的else-statements语句。

流程图：

![img](https://gitee.com/sue201982/mysql/raw/master/img/202110292225547.png)

- **案例：**

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`04.CreateIF`;

/* 需求：
 * 180身高 -- 高
 * 170-180身高 - 中
 * 170以下 - 一般
 * */

DELIMITER $$
$$
CREATE PROCEDURE mysql_scirpt.`04.CreateIF`()
BEGIN
	DECLARE height int DEFAULT 175;
	DECLARE description varchar(50);
	
	IF height >= 180 THEN
		SET description = "高";
	ELSEIF height >=170 AND height < 180 THEN 
		SET description = "中";
	ELSE 
		SET description = "一般";
	END IF;
	
	SELECT description;
END$$
DELIMITER ;

CALL mysql_scirpt.`04.CreateIF`();
~~~

![image-20211027224447072](https://gitee.com/sue201982/mysql/raw/master/img/202110292225548.png)

### 传递参数

开发中的存储过程几乎都需要参数，也是这些参数使得传递参数更加灵活。

Mysql中，参数有三种模式：`IN`、`OUT`、`INOUT`

- `IN`：是默认模式。在存储过程中定义 IN 参数时，调用程序必须将参数传递给存储过程。另外， `IN` 参数的值是被保护。这意味着即使在存储过程中更改了 `IN` 参数的值，在存储过程结束后仍保留其原始值。存储过程只是用 `IN` 参数副本。
- `OUT`：可以在从存储过程中更改 `OUT` 参数的值，并将其更改后新值传递回调用程序。请注意，存储过程在启动时无法访问OUT参数的初始值。
- `INOUT`：INOUT参数是IN和OUT参数的组合。这意味着调用程序可以传递参数，并且存储过程可以修改INOUT参数并将新值传递回调用程序。

语法格式：

~~~mysql
create procedure procedure_name([in/out/inout] 参数名   参数类型)
~~~

- **案例1：IN 参数的使用**

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`05.CreateParameter`;

DELIMITER $$
$$
CREATE PROCEDURE mysql_scirpt.`05.CreateParameter`(IN height int)
BEGIN
	DECLARE description varchar(50) DEFAULT '';
	
	IF height >= 180 THEN
		SET description = "高";
	ELSEIF height >=170 AND height < 180 THEN 
		SET description = "中";
	ELSE 
		SET description = "一般";
	END IF;
	
	SELECT concat('身高：',height,'身材：',description) AS '描述';

END$$
DELIMITER ;
~~~

执行存储过程：

~~~mysql
{ CALL mysql_scirpt.`05.CreateParameter`(这里输入身高) }
~~~

![image-20211028083937908](https://gitee.com/sue201982/mysql/raw/master/img/202110292225549.png)

- **案例2：OUT 参数使用**

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`06.CreateParamOut`;

DELIMITER $$
$$
CREATE DEFINER=`root`@`localhost` PROCEDURE `mysql_scirpt`.`06.CreateParamOut`(
	OUT id int
)
BEGIN
	SELECT id AS id_inner_1; -- 1.结果 1
	IF id IS NOT NULL THEN -- 3.因为 OUT参数，我们无法获取外部传来的值
		SET id = id + 1;
		SELECT id AS id_inner_2;
	ELSE
		SELECT 1 INTO id; -- 4.进入ELSE语句，将id赋值为 1
	END IF;
	
	SELECT id AS id_inner_3; -- 2.结果 2

END$$
DELIMITER ;

SET @id = 10;
CALL `mysql_scirpt`.`06.CreateParamOut`(@id);
SELECT @id AS id_out; -- 5. 最后拿到 id 为 1
~~~

运行结束后我们可以看到三个结果：

~~~mysql
mysql> set @id = 10;
mysql> call pr_param_out(@id);
+------------+
| id_inner_1 |
+------------+
|       NULL |
+------------+
+------------+
| id_inner_3 |
+------------+
|          1 |
+------------+
 
mysql> select @id as id_out;
+--------+
| id_out |
+--------+
| 1      |
+--------+
~~~

可以看出，虽然我们设置了用户定义变量 @id 为 10，传递 @id 给存储过程后，在存储过程内部，id 的初始值总是 null（id_inner_1）。最后 id 值（id_out = 1）传回给调用者。所以 OUT 参数无法获取外部传来的参数。

- **案例：INOUT 参数使用**

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`07.CreateParamInOut`;

DELIMITER $$
$$
CREATE PROCEDURE mysql_scirpt.`07.CreateParamInOut`(
	INOUT id int
)
BEGIN
	SELECT id AS id_inner_1; -- 2. id = 10
	
	IF id IS NOT NULL THEN
		SET id = id+1; - 2. id+1 = 11
		SELECT id AS id_inner_2; -- 3. id = 11
	ELSE
		SELECT 1 INTO id;
	END IF;
	
	SELECT id AS id_inner_3; -- 4. id = 11

END$$
DELIMITER ;

SET @id = 10;
CALL mysql_scirpt.`07.CreateParamInOut`(@id); -- 1. 传入参数
SELECT @id AS id_out; -- 5. id = 11
~~~

执行结果：

~~~mysql
mysql> set @id = 10;
mysql> call pr_param_inout(@id);
+------------+
| id_inner_1 |
+------------+
|         10 |
+------------+
+------------+
| id_inner_2 |
+------------+
|         11 |
+------------+
+------------+
| id_inner_3 |
+------------+
|         11 |
+------------+
mysql> select @id as id_out;
+--------+
| id_out |
+--------+
| 11     |
+--------+
~~~

如果仅仅想把数据传给 MySQL 存储过程，那就使用“in” 类型参数；如果仅仅从 MySQL 存储过程返回值，那就使用“out” 类型参数；如果需要把数据传给 MySQL 存储过程，还要经过一些计算后再传回给我们，此时，要使用“inout” 类型参数。

### case 结构

- **简易的语法格式：**

~~~mysql
CASE case_value
    WHEN when_value THEN statement_list
    [WHEN when_value THEN statement_list] ...
    [ELSE statement_list]
END CASE
~~~

`case_value`是一个表达式，该值和每个when子句中的when_value值进行相等比较：

- 如果和某个when子句中的when_value值相等，则执行相应的then子句后面的语句statement_list；
- 如果没有when_value值相等，则执行else子句后面的statement_list。

**案例：**

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`08.CreateCaseOne`;

DELIMITER $$
$$
CREATE PROCEDURE mysql_scirpt.`08.CreateCaseOne`()
BEGIN
	DECLARE num int DEFAULT 3; -- 1. 给了num一个默认值 3
	
	CASE num -- 2. 条件判断 num
		WHEN 2 THEN SELECT num; -- num为2是结果为其本身
		WHEN 3 THEN SELECT 0; -- num为3是结果输出0
	END CASE;

END$$
DELIMITER ;
~~~

- **检索case语法：**

~~~mysql
CASE
    WHEN search_condition THEN statement_list
    [WHEN search_condition THEN statement_list] ...
    [ELSE statement_list]
END CASE
~~~

对于每个when子句，判断后面的布尔表达式search_condition是否为true：
　
- 如果某个when子句的条件为true，则执行相应的then子句后面的语句statement_list；
- 如果所有的when子句的条件都不为true，则执行else后面的语句statement_list。

**案例：**

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`09.CreateCaseTwo`;

DELIMITER $$
$$
CREATE PROCEDURE mysql_scirpt.`09.CreateCaseTwo`(
	IN p1 int,
	IN p2 int,
	OUT p3 int
)
BEGIN
	CASE  -- 2. 进行判断
		WHEN p1 > p2 THEN SET p3 = 1;
		WHEN p1 = p2 THEN SET p3 = 2;
		ELSE SET p3 = 3;
	END CASE;
	SELECT p3; -- 输出
END$$
DELIMITER ;
CALL mysql_scirpt.`09.CreateCaseTwo`(200,100,@p3); -- 1. 传入参数
SELECT @p3; -- 输出
~~~

注意：

- 如果在case中，没有一个when子句的比较结果为true，并且没有写else部分，那么就抛出异常：‘Case not found for CASE statement’；
- statement_list如果有多条语句，使用begin…end块包围起来（复合语句）。

### while 循环

语法结构:

~~~mysql
[begin_label:] WHILE search_condition DO
    statement_list;
END WHILE [end_label];
~~~

首先判断循环开始条件search_condition是否为true(循环结束条件)：

- 如果为true，则执行循环体中的语句statement_list。每执行完一次，都要重新判断条件search_condition是否为true；
- 如果条件search_condition为false，则循环结束。

特点：**先判断，后执行。**

**案例：计算从1加到n的值**

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`10.CreateWhile`;

DELIMITER $$
$$
CREATE PROCEDURE mysql_scirpt.`10.CreateWhile`(IN n int)
BEGIN
	DECLARE total int DEFAULT 0;
	DECLARE num int DEFAULT 1;
	
	WHILE num<=n do -- 条件语句
		SET total = total + num;
		SET num = num + 1; -- num 递增，不写则进入死循环
	END WHILE;

	SELECT total;

END$$
DELIMITER ;

CALL mysql_scirpt.`10.CreateWhile`(10);
~~~

![image-20211028093603285](https://gitee.com/sue201982/mysql/raw/master/img/202110292225550.png)

### repeat 循环

语法格式：

~~~mysql
[begin_label:] REPEAT
    statement_list
UNTIL search_condition
END REPEAT [end_label]
~~~

反复执行循环体中的语句statement_list，直到until条件search_condition 为true时，循环结束

特点：**先执行，后判断**

有条件的循环控制语句, 当满足条件的时候退出循环 。while 是满足条件才执行，repeat 是满足条件就退出循环。

**案例：计算从1加到n的值**

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`11.CcreateRepeat`;

DELIMITER $$
$$
CREATE PROCEDURE mysql_scirpt.`11.CcreateRepeat`(IN n int)
BEGIN
	DECLARE total int DEFAULT 0;
	
	REPEAT 
		SET total = total + n;
		SET n = n - 1;
		until n = 0
	END REPEAT;

	SELECT total;
	
END$$
DELIMITER ;

CALL mysql_scirpt.`11.CcreateRepeat`(10)
~~~

![image-20211028094720133](https://gitee.com/sue201982/mysql/raw/master/img/202110292225551.png)

### loop 循环

语法格式：

~~~mysql
[begin_label:] LOOP
    statement_list ;
END LOOP [begin_label];
~~~

反复执行循环体中的语句，直到循环结束；循环的结束使用leave语句。

如果不在 statement_list 中增加退出循环的语句，那么 LOOP 语句可以用来实现简单的死循环。

### Leave 语句

作用：用来退出带标签的语句块或者循环
用处：用在 BEGIN ... END中或者循环中 (LOOP, REPEAT, WHILE)

语法格式：

~~~mysql
LEAVE  label ;
~~~

**案例：Loop 和 Leave**

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`12.CreateLoopAndLeave`;

DELIMITER $$
$$
CREATE PROCEDURE mysql_scirpt.`12.CreateLoopAndLeave`(
	IN n int
)
BEGIN
	DECLARE total int DEFAULT 0;
	-- ins：begin_label
	ins: LOOP
		IF n <= 0 THEN
			LEAVE ins;
		END IF;
	
	SET total = total + n;
	SET n = n -1;
	
	END LOOP ins;
	
	SELECT total;

END$$
DELIMITER ;

CALL mysql_scirpt.`12.CreateLoopAndLeave`(10);
~~~

![image-20211028101803523](https://gitee.com/sue201982/mysql/raw/master/img/202110292225552.png)

### iterate 语句

只能出现在循环LOOP、REPEAT和WHILE 中(有标签)

含义：跳出本次循环，开始一次新的循环。

语法格式：

~~~mysql
ITERATE  label;
~~~

### 游标/光标

**游标**：只能用来存储查询结果集的数据类型。

- 只读：无法通过光标更新基础表中的数据。
- 不可滚动：只能按照select语句确定的顺序获取行。不能以相反的顺序获取行。 此外，不能跳过行或跳转到结果集中的特定行。
- 敏感：有两种游标：敏感游标和不敏感游标。敏感游标指向实际数据，不敏感游标使用数据的临时副本。敏感游标比一个不敏感的游标执行得更快，因为它不需要临时拷贝数据。但是，对其他连接的数据所做的任何更改都将影响由敏感游标使用的数据，因此，如果不更新敏感游标所使用的数据，则更安全。 MySQL游标是敏感的。

**光标**：在存储过程或函数中，可以使用光标对结果集进行循环处理。

有时，需要在检索出来的行中前进或后退一行或多行。这就是使用游标的原因。游标（cursor）是一个存储在MySQL服务器上的数据库查询，它不是一条SELECT语句，而是被该语句检索出来的结果集。在存储了游标之后，应用程序可以根据需要滚动或浏览其中的数据。

游标主要用于交互式应用，其中用户需要滚动屏幕上的数据，并对数据进行浏览或做出更改。

游标涉及几个明确的步骤：

- 在能够使用游标前，必须声明（定义）它。这个过程实际上没有检索数据，它只是定义要使用的SELECT语句。
- 一旦声明后，必须打开游标以供使用。这个过程用前面定义的SELECT语句把数据实际检索出来。
- 对于填有数据的游标，根据需要取出（检索）各行。
- 在结束游标使用时，必须关闭游标。

光标的使用：

- 声明光标：

~~~mysql
DECLARE cursor_name CURSOR FOR select_statement;
~~~

cursor_name：光标名，用户自己设定，最好见名知意。
select_statement：完整的查询语句，查询表中的列名。

- 开启光标：

~~~mysql
OPEN cursor_name;
~~~

cursor_name：声明时的光标名。

- 捕获光标

~~~mysql
FETCH cursor_name INTO var_name...；(...表示可以有多个)
~~~

cursor_name：声明时的光标名。
var_name：自定义的变量名

- 关闭光标

~~~mysql
CLOSE cursor_name;
~~~

示例：

1. 初始化脚本

~~~mysql
create table emp(
  id int(11) not null auto_increment ,
  name varchar(50) not null comment '姓名',
  age int(11) comment '年龄',
  salary int(11) comment '薪水',
  primary key(`id`)
)engine=innodb default charset=utf8 ;

insert into emp(id,name,age,salary) values(null,'金毛狮王',55,3800),(null,'白眉鹰王',60,4000),(null,'青翼蝠王',38,2800),(null,'紫衫龙王',42,1800);
~~~

2. 生成脚本

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`13.CreateCursor`;

DELIMITER $$
$$
-- 查询emp表中数据, 并逐行获取进行展示
CREATE PROCEDURE mysql_scirpt.`13.CreateCursor`()
BEGIN
	-- 声明变量
	DECLARE e_id int(11);
	DECLARE e_name varchar(50);
	DECLARE e_age int(11);
	DECLARE e_salary int(11);
	-- 设置光标
	DECLARE emp_result CURSOR FOR SELECT * FROM emp;
	-- 开启光标
	OPEN emp_result;

	-- 捕获光标
	FETCH emp_result INTO e_id,e_name,e_age,e_salary;
	SELECT concat('id=',e_id,',name=',e_name,',age=',e_age,',salary=',e_salary);

	-- 关闭光标
	CLOSE emp_result;
END$$
DELIMITER ;
~~~

3. 通过循环获取游标数据

~~~mysql
DROP PROCEDURE IF EXISTS mysql_scirpt.`14.CreateGetCursor`;

DELIMITER $$
$$
CREATE PROCEDURE mysql_scirpt.`14.CreateGetCursor`()
BEGIN
	
 	DECLARE id int(11);
 	DECLARE name varchar(50);
 	DECLARE age int(11);
 	DECLARE salary int(11);
	DECLARE has_data int default 1;

	DECLARE emp_result CURSOR FOR SELECT * FROM emp;
	DECLARE EXIT handler FOR NOT FOUND SET has_data = 0;
	
	OPEN emp_result;
	
	REPEAT
		FETCH emp_result INTO id ,name,age,salary;
		SELECT concat('id=',id,',name=',name,',age=',age,',salary=',salary);
		until has_data = 0
	END REPEAT;

	CLOSE emp_result;

END$$
DELIMITER ;
~~~

逐条读取，无论表中的数据是什么都会全部读取出来。

## 存储过程函数

直接在sql文件中写的话会报错

~~~mysql
ERROR 1418 (HY000): This function has none of DETERMINISTIC, NO SQL, or READS SQL DATA in its declaration and binary logging is enabled (you might want to use the less safe log_bin_trust_function_creators variable)
~~~

原因：
这是我们开启了bin-log, 我们就必须指定我们的函数是否是
1 DETERMINISTIC 不确定的
2 NO SQL 没有SQl语句，当然也不会修改数据
3 READS SQL DATA 只是读取数据，当然也不会修改数据
4 MODIFIES SQL DATA 要修改数据
5 CONTAINS SQL 包含了SQL语句

其中在function里面，只有 DETERMINISTIC, NO SQL 和 READS SQL DATA 被支持。
如果我们开启了 bin-log, 我们就必须为我们的function指定一个参数。

输入语句：

~~~mysql
set global log_bin_trust_function_creators=TRUE;
~~~

语法格式：

~~~mysql
CREATE FUNCTION fn_name ([func_parameter[...]])
RETURNS type
[characteristic ...] routine_body
~~~

参数：

- fn_name 参数：表示存储函数的名称；
- func_parameter：表示存储函数的参数列表；
- RETURNS type：指定返回值的类型；
- characteristic 参数：指定存储函数的特性，该参数的取值与存储过程是一样的；
- routine_body 参数：表示 SQL 代码的内容，可以用 BEGIN...END 来标示 SQL 代码的开始和结束。

注意：在具体创建函数时，函数名不能与已经存在的函数名重名。除了上述要求外，推荐函数名命名（标识符）为 function_xxx 或者 func_xxx。

### 存储过程和存储函数的区别

函数只能返回一个变量的限制。而存储过程可以返回多个。
函数限制比较多，比如不能用临时表，只能用表变量。还有一些函数都不可用等等．而存储过程的限制相对就比较少。

特性区别：

- 一般来说，存储过程实现的功能要复杂一点，而函数的实现的功能针对性比较强。存储过程，功能强大，可以执行包括修改表等一系列数据库操作；用户定义函数不能用于执行一组修改全局数据库状态的操作。
- 对于存储过程来说可以返回参数，如记录集，而函数只能返回值或者表对象。函数只能返回一个变量；而存储过程可以返回多个。存储过程的参数可以有IN,OUT,INOUT三种类型，而函数只能有IN类~~存储过程声明时不需要返回类型，而函数声明时需要描述返回类型，且函数体中必须包含一个有效的RETURN语句。
- 存储过程，可以使用非确定函数，不允许在用户定义函数主体中内置非确定函数。
- 存储过程一般是作为一个独立的部分来执行（ EXECUTE 语句执行），而函数可以作为查询语句的一个部分来调用（SELECT调用），由于函数可以返回一个表对象，因此它可以在查询语句中位于FROM关键字的后面。 SQL语句中不可用存储过程，而可以使用函数。

### 使用

**案例: 定义一个存储过程, 请求满足条件的总记录数；**

~~~mysql
DROP FUNCTION IF EXISTS mysql_scirpt.`15.CreateFunction`;

DELIMITER $$
$$
CREATE FUNCTION mysql_scirpt.`15.CreateFunction`(vendID int)
RETURNS INT
BEGIN
	
	DECLARE num int;
	SELECT count(*) INTO num FROM products WHERE vend_id = vendID;
	
	RETURN num;
END$$
DELIMITER ;

SELECT mysql_scirpt.`15.CreateFunction`(1001);
~~~

