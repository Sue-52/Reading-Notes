---
title: 附录C：Mysql 存储过程案例
lang: en-US
---

## 案例：随机生成10000条数据

创建表格：

~~~mysql
create table dept1(
  id int unsigned primary key auto_increment,
  deptno mediumint unsigned not null default 0,
  dname varchar(20) not null default "",
  loc varchar(13) not null default ""
)engine=innodb default charset=gbk;

create table emp1(
  id int unsigned primary key auto_increment,
  empno mediumint unsigned not null default 0,/*编号*/
  ename varchar(20) not null default "",/*姓名*/
  job varchar(9) not null default "",/*工作*/
  mgr mediumint unsigned not null default 0,/*上级编号*/
  hiredate date not null,/*入职时间*/
  sal decimal(7,2) not null, /*薪水*/
  comm decimal(7,2) not null,/*红利*/
  deptno mediumint unsigned not null default 0/*部门编号*/
)engine=innodb default charset=gbk;
~~~

### 随机数生成函数

~~~mysql
CREATE DEFINER=`root`@`localhost` FUNCTION `mysql_deep_learning`.`RandomNum`() RETURNS int
BEGIN
  	DECLARE i INT DEFAULT 0;

    set i = FLOOR(100+RAND()*(10 - 1 + 1) + 1);

    RETURN i;
   
END
~~~

### 随机字符串生成函数

~~~mysql
CREATE DEFINER=`root`@`localhost` FUNCTION `mysql_deep_learning`.`RandomStr`(n int) RETURNS varchar(255) CHARSET utf8mb4
BEGIN
	
	DECLARE char_str varchar(100) DEFAULT 'abcdefghijklmnopqrstuvwsyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
	DECLARE return_str VARCHAR(255) DEFAULT '';
	DECLARE i int DEFAULT 0;
	
	WHILE i<n DO
		SET return_str = CONCAT(return_str,SUBSTRING(char_str FROM FLOOR(1+RAND()*52) FOR 1));
		SET i = i+1;
	END WHILE;

    RETURN return_str;
END
~~~

### 生成 dept1 表格数据

~~~mysql
CREATE DEFINER=`root`@`localhost` PROCEDURE `mysql_deep_learning`.`CreateDataOfDept`(`start` int(10),max_num int(10))
BEGIN
	DECLARE i int DEFAULT 0;
	SET autocommit = 0;
	
	REPEAT 
		SET i = i + 1;
		INSERT INTO dept1 (deptno,dname,loc) VALUES ((`start` + i),RandomStr(10),RandomStr(8));
		until i = max_num
	END REPEAT;
	
	COMMIT;

END
~~~

### 生成 emp1 表格数据

~~~mysql
CREATE DEFINER=`root`@`localhost` PROCEDURE `mysql_deep_learning`.`CreateDataOfEmp`(`start` int(10),max_num int(10))
BEGIN
	DECLARE i int DEFAULT 0;
	SET autocommit = 0;

	REPEAT 
		SET i = i + 1;
		INSERT INTO emp1 (empno,ename,job,mgr,hiredate,sal,comm,deptno) 
		VALUES ((`start` + i),RandomStr(6),'saleman',0001,CURDATE(),2000,400,RandomNum());
		until i = max_num
	END REPEAT;

	COMMIT;

END
~~~

