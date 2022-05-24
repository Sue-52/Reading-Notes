---
title: 第二十三章：Mysql 触发器
lang: en-US
---

# 第二十三章：Mysql 触发器

Mysql 的语句在需要时被执行，存储过程亦是如此。但是，如果某些语句在事件发生时自动执行。

Ex：

- 每当一个顾客到了某个数据库表时，都检查其电话号码格式是否正确，州的缩写是否为大写；
- 每订购一个产品，从库存数量中自动减去订购数量。

所有这些例子的共同之处是它们都需要在某个表发生更改时自动处理。这确切地说就是触发器。触发器是MySQL响应以下任意语句而自动执行的一条MySQL语句（或位于BEGIN和END语句之间的一组语句）：

- DELETE
- INSERT
- UPDATE

触发器是与表有关的数据库对象，指在 insert/update/delete 之前或之后，触发并执行触发器中定义的SQL语句集合。触发器的这种特性可以协助应用在数据库端确保数据的完整性 , 日志记录 , 数据校验等操作 。

使用别名 OLD 和 NEW 来引用触发器中发生变化的记录内容，这与其他的数据库是相似的。现在触发器还只支持行级触发，不支持语句级触发。

|   触发器类型    |                    NEW 和 OLD的使用                     |
| :-------------: | :-----------------------------------------------------: |
| INSERT 型触发器 |             NEW 表示将要或者已经新增的数据              |
| UPDATE 型触发器 | OLD 表示修改之前的数据 , NEW 表示将要或已经修改后的数据 |
| DELETE 型触发器 |             OLD 表示将要或者已经删除的数据              |

## 创建触发器

注意点：

- 唯一的触发器名
- 触发器关联的表
- 触发器响应的活动（DELETE、INSERT、UPDATE）
- 触发器如何执行（处理之前和之后）

> 保持每个数据库的触发器名唯一，但不是在每个数据库中唯一。这表示同一数据库中的两个表可具有相同名字的触发器。这在其他每个数据库触发器名必须唯一的DBMS中是不允许的，而且以后的MySQL版本很可能会使命名规则更为严格。因此，现在最好是在数据库范围内使用唯一的触发器名。

语法格式：

~~~mysql
create trigger trigger_name 

before/after insert/update/delete

on tbl_name 

[ for each row ]  -- 行级触发器

begin

	trigger_stmt ;

end;
~~~

> 仅支持表 只有表才支持触发器，视图不支持（临时表也不支持）。

触发器按每个表每个事件每次地定义，每个表每个事件每次只允许一个触发器。因此，每个表最多支持6个触发器（每条INSERT、UPDATE和DELETE的之前和之后）。单一触发器不能与多个事件或多个表关联，所以，如果你需要一个对INSERT和UPDATE操作执行的触发器，则应该定义两个触发器。

> 如果BEFORE触发器失败，则Mysql将不执行请求的操作。此外，如果BEFORE触发器或语句本身失败，MySQL将不执行AFTER触发器（如果有的话）。

## 删除触发器

语法格式：

~~~mysql
DROP TRIGGER trigger_name;
~~~

触发器是无法更新或覆盖的，修改一个触发器必须先删除它然后重新创建。

~~~mysql
DROP TRIGGER IF EXISTS trigger_name;
~~~

## 使用触发器

### INSERT 触发器

但是在书写：

~~~mysql
CREATE TRIGGER newproduct AFTER INSERT ON products
FOR EACH ROW SELECT 'Product added'
~~~

出现报错：**Not allowed to return a result set from a trigger**

那是因为在 Mysql5 之后不允许触发器返回任何结果因此使用into @变量名，将结果赋值到变量中，用select调用即可修改为：

~~~mysql
-- 变量名用@引导
CREATE TRIGGER newproduct AFTER INSERT ON products
FOR EACH ROW SELECT 'Product added' INTO @asd
~~~

INSERT 触发器的注意点：

- 在INSERT触发器代码内，可引用一个名为NEW的虚拟表，访问被插入的行；
- 在BEFORE INSERT触发器中，NEW中的值也可以被更新（允许更改被插入的值）；
- 对于AUTO_INCREMENT列，NEW在INSERT执行之前包含0，在INSERT执行之后包含新的自动生成值。

~~~mysql
USE `mysql_scirpt`;
DROP TRIGGER IF EXISTS `prods`;

DELIMITER $$
-- $$ -- 在MySQL中放开该注释

CREATE TRIGGER `prods`
AFTER INSERT 
ON `mysql_scirpt`.`products`

FOR EACH ROW SELECT 'Product Added' INTO @getMessage;
DELIMITER ;

SELECT @getMessage; -- NULL

INSERT INTO `mysql_scirpt`.`products`(prod_id,vend_id,prod_name,prod_price,prod_desc)
VALUES ('XCE03',1001,'3 ton anvil',20.49,'3 ton anvil, black, complete with handy hook and carrying case');

SELECT @getMessage; -- Product Added
~~~

> BEFORE或AFTER？ 通常，将BEFORE用于数据验证和净化（目的是保证插入表中的数据确实是需要的数据）。本提示也适用于UPDATE触发器。

![image-20211029104320270](https://gitee.com/sue201982/mysql/raw/master/img/202110292225933.png)

### DELETE 触发器

DELETE 触发器须知：

- 在DELETE触发器代码内，你可以引用一个名为OLD的虚拟表，访问被删除的行；
- OLD中的值全都是只读的，不能更新。

~~~mysql
USE `mysql_scirpt`;

DROP TRIGGER IF EXISTS `prodsDel`;

DELIMITER $$
-- $$

CREATE TRIGGER `prodsDel`
AFTER DELETE 
ON `mysql_scirpt`.`products`

FOR EACH ROW SELECT 'Product Deleted' INTO @getDeleteMessage;

DELIMITER ;

SELECT @getDeleteMessage; -- NULL

DELETE FROM products WHERE prod_id = 'XCE04'; 
	

SELECT @getDeleteMessage; -- Product Deleted
~~~

![image-20211029105943307](https://gitee.com/sue201982/mysql/raw/master/img/202110292225934.png)

### INSERT 触发器

但是在书写：

~~~mysql
CREATE TRIGGER newproduct AFTER INSERT ON products
FOR EACH ROW SELECT 'Product added'
~~~

出现报错：**Not allowed to return a result set from a trigger**

那是因为在 Mysql5 之后不允许触发器返回任何结果因此使用into @变量名，将结果赋值到变量中，用select调用即可修改为：

~~~mysql
-- 变量名用@引导
CREATE TRIGGER newproduct AFTER INSERT ON products
FOR EACH ROW SELECT 'Product added' INTO @asd
~~~

INSERT 触发器的注意点：

- 在INSERT触发器代码内，可引用一个名为NEW的虚拟表，访问被插入的行；
- 在BEFORE INSERT触发器中，NEW中的值也可以被更新（允许更改被插入的值）；
- 对于AUTO_INCREMENT列，NEW在INSERT执行之前包含0，在INSERT执行之后包含新的自动生成值。

~~~mysql
USE `mysql_scirpt`;
DROP TRIGGER IF EXISTS `prods`;

DELIMITER $$
-- $$ -- 在MySQL中放开该注释

CREATE TRIGGER `prods`
AFTER INSERT 
ON `mysql_scirpt`.`products`

FOR EACH ROW SELECT 'Product Added' INTO @getMessage;
DELIMITER ;

SELECT @getMessage; -- NULL

INSERT INTO `mysql_scirpt`.`products`(prod_id,vend_id,prod_name,prod_price,prod_desc)
VALUES ('XCE03',1001,'3 ton anvil',20.49,'3 ton anvil, black, complete with handy hook and carrying case');

SELECT @getMessage; -- Product Added
~~~

> BEFORE或AFTER？ 通常，将BEFORE用于数据验证和净化（目的是保证插入表中的数据确实是需要的数据）。本提示也适用于UPDATE触发器。

![image-20211029104320270](https://gitee.com/sue201982/mysql/raw/master/img/202110292225933.png)


### Update 触发器

UPDATE 触发器注意事项：

- 在UPDATE触发器代码中，你可以引用一个名为OLD的虚拟表访问以前（UPDATE语句前）的值，引用一个名为NEW的虚拟表访问新更新的值；
- 在BEFORE UPDATE触发器中，NEW中的值可能也被更新（允许更改将要用于UPDATE语句中的值）；
- OLD中的值全都是只读的，不能更新。

~~~mysql
USE `mysql_scirpt`;

DROP TRIGGER IF EXISTS `prodsUpt`;

DELIMITER $$
-- $$

CREATE TRIGGER `prodsUpt`
AFTER UPDATE 
ON `mysql_scirpt`.`products`

FOR EACH ROW SELECT 'Product Updated' INTO @getUpdateMessage;

DELIMITER ;

SELECT @getUpdateMessage; -- NULL

UPDATE products SET vend_id = '1002' WHERE prod_id = 'XCE05'; 
	
SELECT @getUpdateMessage; -- Product Deleted
~~~

![image-20211029110542828](https://gitee.com/sue201982/mysql/raw/master/img/202110292225935.png)

## 进一步介绍

- 与其他DBMS相比，MySQL 5中支持的触发器相当初级。未来的MySQL版本中有一些改进和增强触发器支持的计划。
- 创建触发器可能需要特殊的安全访问权限，但是，触发器的执行是自动的。如果INSERT、UPDATE或DELETE语句能够执行，则相关的触发器也能执行。
- 应该用触发器来保证数据的一致性（大小写、格式等）。在触发器中执行这种类型的处理的优点是它总是进行这种处理，而且是透明地进行，与客户机应用无关。
- 触发器的一种非常有意义的使用是创建审计跟踪。使用触发器，把更改（如果需要，甚至还有之前和之后的状态）记录到另一个表非常容易。
- 遗憾的是，MySQL触发器中不支持CALL语句。这表示不能从触发器内调用存储过程。所需的存储过程代码需要复制到触发器内。
- Old和New是Mysql自己封装好的函数，调用old可以获取到数据修改前的内容`old.xxx`获取，new可以获取到修改后的数据
