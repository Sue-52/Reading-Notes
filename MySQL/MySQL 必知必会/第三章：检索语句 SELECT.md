---
title: 第三章：检索语句 SELECT
lang: en-US
---

# 第三章： 检索语句 SELECT

`SELECT` 语句用于检索表的数据
语法格式：

~~~mysql
select xxx from 表名
~~~

## 检索单个列表数据

~~~mysql
select 列名 from 表名;
~~~

利用 `SELECT` 语句从 cities 表中检索一个名为：`name` 的列。所需的列名在 `SELECT` 关键字之后给出， FROM 关键在指出从中检索数据的表名。

## 检索多个列表数据

~~~mysql
select 列名1，列名2... from 表名;
~~~

通过给定的多个 列名... 进行检索

![image-20211013195213117](https://gitee.com/sue201982/mysql/raw/master/img/202110292227928.png)


## 检索所有列表数据

~~~mysql
select * from 表名;
~~~

如果给定一个通配符（*），则返回表中所有列。列的顺序一般是列在表定义中出现的顺序。但有时候并不是这样的，表的模式的变化（如添加或删除列）可能会导致顺序的变化。

![image-20211013195736139](https://gitee.com/sue201982/mysql/raw/master/img/202110292227929.png)


## 检索不同的行数据（去重）

当我们需要查看表中不同的数据，将重复的值去除的话 可以使用 `DISTINCT` 关键字。

~~~mysql
select type from cities;
~~~

![image-20211013200243176](https://gitee.com/sue201982/mysql/raw/master/img/202110292227930.png)

上图我们发现了有许多重复的数据，这是我们不想要看到的

~~~
select distinct type from cities;
~~~

![image-20211013200353438](https://gitee.com/sue201982/mysql/raw/master/img/202110292227931.png)

DISTINCT关键字应用于所有列而不仅是前置它的列。如果给出SELECT DISTINCT type, code，除非指定的两个列都不同，否则所有行都将被
检索出来。


## 使用完全限定的表名

~~~mysql
select 表名.列名 from 数据库名.表名
~~~

将语法限定在只用**该数据库下的这个表中的列才能获取**

![image-20211013200705559](https://gitee.com/sue201982/mysql/raw/master/img/202110292227932.png)