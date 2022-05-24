---
title: Mysql的Explain详解
lang: en-US
---

# 附录B-Mysql的Explain详解

## 字段特性

|     字段      |                                                                                                   含义                                                                                                    |
| :-----------: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
|      id       |                                                             select查询的序列号，是一组数字，表示的是查询中执行select子句或者是操作表的顺序。                                                              |
|  select_type  |     表示 SELECT 的类型，常见的取值有 SIMPLE（简单表，即不使用表连接或者子查询）、PRIMARY（主查询，即外层的查询）、UNION（UNION 中的第二个或者后面的查询语句）、SUBQUERY（子查询中的第一个 SELECT）等      |
|     table     |                                                                                              输出结果集的表                                                                                               |
|     type      | 表示表的连接类型，性能由好到差的连接类型为( system  --->  const  ----->  eq_ref  ------>  ref  ------->  ref_or_null---->  index_merge  --->  index_subquery  ----->  range  ----->  index  ------> all ) |
| possible_keys |                                                                                        表示查询时，可能使用的索引                                                                                         |
|      key      |                                                                                            表示实际使用的索引                                                                                             |
|    key_len    |                                                                                              索引字段的长度                                                                                               |
|     rows      |                                                                                               扫描行的数量                                                                                                |
|     extra     |                                                                                           执行情况的说明和描述                                                                                            |

## 坏境准备

~~~mysql
CREATE TABLE `t_role` (
  `id` varchar(32) NOT NULL,
  `role_name` varchar(255) DEFAULT NULL,
  `role_code` varchar(255) DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique_role_name` (`role_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


CREATE TABLE `t_user` (
  `id` varchar(32) NOT NULL,
  `username` varchar(45) NOT NULL,
  `password` varchar(96) NOT NULL,
  `name` varchar(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique_user_username` (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


CREATE TABLE `user_role` (
  `id` int(11) NOT NULL auto_increment ,
  `user_id` varchar(32) DEFAULT NULL,
  `role_id` varchar(32) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_ur_user_id` (`user_id`),
  KEY `fk_ur_role_id` (`role_id`),
  CONSTRAINT `fk_ur_role_id` FOREIGN KEY (`role_id`) REFERENCES `t_role` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_ur_user_id` FOREIGN KEY (`user_id`) REFERENCES `t_user` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;




insert into `t_user` (`id`, `username`, `password`, `name`) values('1','super','$2a$10$TJ4TmCdK.X4wv/tCqHW14.w70U3CC33CeVncD3SLmyMXMknstqKRe','超级管理员');
insert into `t_user` (`id`, `username`, `password`, `name`) values('2','admin','$2a$10$TJ4TmCdK.X4wv/tCqHW14.w70U3CC33CeVncD3SLmyMXMknstqKRe','系统管理员');
insert into `t_user` (`id`, `username`, `password`, `name`) values('3','itcast','$2a$10$8qmaHgUFUAmPR5pOuWhYWOr291WJYjHelUlYn07k5ELF8ZCrW0Cui','test02');
insert into `t_user` (`id`, `username`, `password`, `name`) values('4','stu1','$2a$10$pLtt2KDAFpwTWLjNsmTEi.oU1yOZyIn9XkziK/y/spH5rftCpUMZa','学生1');
insert into `t_user` (`id`, `username`, `password`, `name`) values('5','stu2','$2a$10$nxPKkYSez7uz2YQYUnwhR.z57km3yqKn3Hr/p1FR6ZKgc18u.Tvqm','学生2');
insert into `t_user` (`id`, `username`, `password`, `name`) values('6','t1','$2a$10$TJ4TmCdK.X4wv/tCqHW14.w70U3CC33CeVncD3SLmyMXMknstqKRe','老师1');



INSERT INTO `t_role` (`id`, `role_name`, `role_code`, `description`) VALUES('5','学生','student','学生');
INSERT INTO `t_role` (`id`, `role_name`, `role_code`, `description`) VALUES('7','老师','teacher','老师');
INSERT INTO `t_role` (`id`, `role_name`, `role_code`, `description`) VALUES('8','教学管理员','teachmanager','教学管理员');
INSERT INTO `t_role` (`id`, `role_name`, `role_code`, `description`) VALUES('9','管理员','admin','管理员');
INSERT INTO `t_role` (`id`, `role_name`, `role_code`, `description`) VALUES('10','超级管理员','super','超级管理员');


INSERT INTO user_role(id,user_id,role_id) VALUES(NULL, '1', '5'),(NULL, '1', '7'),(NULL, '2', '8'),(NULL, '3', '9'),(NULL, '4', '8'),(NULL, '5', '10') ;
~~~

![1556122799330](https://gitee.com/sue201982/mysql/raw/master/img//1556122799330.png)

## explain 之 id

id 字段是 select查询的序列号，是一组数字，表示的是查询中执行select子句或者是操作表的顺序。有以下三种情况：

情况一：

- id 相同表示加载表的顺序是从上到下

~~~mysql
explain select * from t_role r,t_user u,user_role ur where r.id = ur.role_id and u.id = ur.user_id;
~~~

![image-20211119202002481](https://gitee.com/sue201982/mysql/raw/master/img//image-20211119202002481.png)

情况二：

- id 不同id值越大，优先级越高，越先被执行

~~~mysql
explain select * from t_role where id = (
	select role_id from user_role where user_id = (
		select id from t_user where username = 'stu1'
		)
	);
~~~

![image-20211119202130344](https://gitee.com/sue201982/mysql/raw/master/img//image-20211119202130344.png)

情况三：

- id 有相同，也有把不同，同时存在。id 相同的可以认为是一组，从上往下顺序执行；在所有的组中，id的值越大，优先级越高，越先执行。

~~~mysql
explain select * from t_role r, (
	select * from user_role ur where ur.user_id = '2'
	) a where r.id = a.role_id;
~~~

![image-20211119202255695](https://gitee.com/sue201982/mysql/raw/master/img//image-20211119202255695.png)

## explain 之 select_type

表示 SELECT 的类型，常见的取值，如下表所示：

| select_type  | 含义         |
| ------------ | ---------------------- |
| SIMPLE       | 简单的select查询，查询中不包含子查询或者UNION |
| PRIMARY      | 查询中若包含任何复杂的子查询，最外层查询标记为该标识    |
| SUBQUERY     | 在SELECT 或 WHERE 列表中包含了子查询 |
| DERIVED      | 在FROM 列表中包含的子查询，被标记为 DERIVED（衍生） MYSQL会递归执行这些子查询，把结果放在临时表中 |
| UNION        | 若第二个SELECT出现在UNION之后，则标记为UNION ； 若UNION包含在FROM子句的子查询中，外层SELECT将被标记为 ： DERIVED |
| UNION RESULT | 从UNION表获取结果的SELECT       |

~~~mysql
explain select * from t_role;
~~~

![image-20211119202649541](https://gitee.com/sue201982/mysql/raw/master/img//image-20211119202649541.png)

~~~mysql
explain select * from t_role where role_name = (
	select id from user_role ur where ur.role_id = 5
	);
~~~

![image-20211119202744655](https://gitee.com/sue201982/mysql/raw/master/img//image-20211119202744655.png)

~~~mysql
explain select * from t_role r , (
	select * from user_role ur where ur.user_id = 2
) a where r.id = a.role_id
~~~

**在 8.0 版本后 From 列表后面的子查询不会标记为： Derived**

~~~mysql
explain select * from t_role union select * from t_user;
~~~

![image-20211119202902350](https://gitee.com/sue201982/mysql/raw/master/img//image-20211119202902350.png)

## explain 之 table

展示这一行的数据是关于哪一张表的 

~~~mysql
explain select role_name,username,user_id from t_role,t_user,user_role;
~~~

![image-20211119203019840](https://gitee.com/sue201982/mysql/raw/master/img//image-20211119203019840.png)

## explain 之 type

