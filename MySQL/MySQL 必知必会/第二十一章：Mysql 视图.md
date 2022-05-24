---
title: 第二十一章：Mysql 视图
lang: en-US
---

# 第二十一章：Mysql 视图

视图是虚拟的表。与包含数据的表不一样，视图只包含使用时动态检索数据的查询。

下面是视图的一些常见应用。

- 重用SQL语句。
- 简化复杂的SQL操作。在编写查询后，可以方便地重用它而不必知道它的基本查询细节。
- 使用表的组成部分而不是整个表。
- 保护数据。可以给用户授予表的特定部分的访问权限而不是整个表的访问权限。
- 更改数据格式和表示。视图可返回与底层表的表示和格式不同的数据。

在视图创建之后，可以用与表基本相同的方式利用它们。可以对视图执行SELECT操作，过滤和排序数据，将视图联结到其他视图或表，甚至能添加和更新数据（添加和更新数据存在某些限制。）

重要的是知道视图仅仅是用来查看存储在别处的数据的一种设施。视图本身不包含数据，因此它们返回的数据是从其他表中检索出来的。在添加或更改这些表中的数据时，视图将返回改变过的数据。

## 规则和限制

下面是关于视图创建和使用的一些最常见的规则和限制。

- 与表一样，视图必须唯一命名（不能给视图取与别的视图或表相同的名字）。 
- 对于可以创建的视图数目没有限制。
- 为了创建视图，必须具有足够的访问权限。这些限制通常由数据库管理人员授予。
- 视图可以嵌套，即可以利用从其他视图中检索数据的查询来构造一个视图。
- ORDER BY可以用在视图中，但如果从该视图检索数据SELECT中也含有ORDER BY，那么该视图中的ORDER BY将被覆盖。
- 视图不能索引，也不能有关联的触发器或默认值。
- 视图可以和表一起使用。例如，编写一条联结表和视图的SELECT语句。

## 使用

- 视图用`CREATE VIEW 视图名 AS SELECT xxx FROM 表`语句来创建。
- 使用SHOW CREATE VIEW viewname；来查看创建视图的语句。
- 用DROP删除视图，其语法为DROP VIEW viewname;。 
- 更新视图时，可以先用DROP再用CREATE，也可以直接用CREATE OR REPLACE VIEW。如果要更新的视图不存在，则第2条更新语句会创建一个视图；如果要更新的视图存在，则第2条更新语句会替换原有视图。

## 利用视图简化复杂的联结

视图的最常见的应用之一是隐藏复杂的SQL，这通常都会涉及联结。

~~~mysql
CREATE VIEW productcustomers AS
SELECT cust_name,cust_contact,prod_id
FROM customers c, orders o,orderitems oi
WHERE c.cust_id = o.cust_id 
AND oi.order_num = o.order_num;
~~~

![image-20211025092422083](https://gitee.com/sue201982/mysql/raw/master/img/202110292226852.png)

~~~mysql
SHOW CREATE VIEW productcustomers;
~~~

![image-20211025092446816](https://gitee.com/sue201982/mysql/raw/master/img/202110292226853.png)

CREATE VIEW 中的内容：

~~~mysql
CREATE 
ALGORITHM=UNDEFINED 
DEFINER=`root`@`localhost` 
SQL SECURITY DEFINER VIEW `productcustomers` 
AS select `c`.`cust_name` 
AS `cust_name`,`c`.`cust_contact` 
AS `cust_contact`,`oi`.`prod_id` 
AS `prod_id` 
from ((`customers` `c` join `orders` `o`) join `orderitems` `oi`) 
where ((`c`.`cust_id` = `o`.`cust_id`) 
and (`oi`.`order_num` = `o`.`order_num`))
~~~

> 创建可重用的视图 创建不受特定数据限制的视图是一种好办法。扩展视图的范围不仅使得它能被重用，而且甚至更有用。这样做不需要创建和维护多个类似视图。


## 用视图重新格式化检索出的数据

~~~mysql
SELECT concat(rtrim(vend_name),"(",rtrim(vend_country),")")
AS vend_title
FROM vendors v
ORDER BY vend_name;
~~~

![image-20211025093443020](https://gitee.com/sue201982/mysql/raw/master/img/202110292226854.png)

现在，假如经常需要这个格式的结果。不必在每次需要时执行联结，创建一个视图，每次需要时使用它即可。

~~~mysql
CREATE VIEW vendorlocations AS
SELECT concat(rtrim(vend_name),"(",rtrim(vend_country),")")
AS vend_title
FROM vendors v
ORDER BY vend_name;
~~~

![image-20211025093616624](https://gitee.com/sue201982/mysql/raw/master/img/202110292226855.png)

过滤视图添加 WHERE 关键字进行判断

## 更新视图

视图是可更新的（即，可以对它们使用INSERT、UPDATE和DELETE）。更新一个视图将更新其基表（可以回忆一下，视图本身没有数据）。如果你对视图增加或删除行，实际上是对其基表增加或删除行。

如果视图定义中有以下操作，则不能进行视图的更新：

- 分组（使用GROUP BY和HAVING）；
- 联结；
- 子查询；
- 并；
- 聚集函数（Min()、Count()、Sum()等）；
- DISTINCT； 
- 导出（计算）列

> **将视图用于检索** 一般，应该将视图用于检索（SELECT语句）而不用于更新（INSERT、UPDATE和DELETE）。