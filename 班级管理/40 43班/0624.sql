CREATE DATABASE class4043;
USE class4043

CREATE TABLE student(
	id int,
	name varchar(32),
	sex char(1)
);

INSERT INTO student (id, name, sex) VALUE (1, '张三', '男');
INSERT INTO student (id, name, sex) VALUE (2, '李四', '女');
INSERT INTO student (id, name, sex) VALUE (3, '王五', '男');

SELECT * FROM student;


命令语法：
中括号是可省略字段
大括号是必选字段
| 是或

A [B {C | D}] E



数据类型：

BIT[(m)]     m <= 64

float[(m, d)] [unsigned]

m是有效数字的位数，d是小数位数

-9999.99 ~ 9999.99

char(L) L <= 255


CREATE TABLE test(
	id int,
	name varchar(32),
	sex char(1),
	tm timestamp
);

varchar(L)

L是可变长度字符串的上限，其中，L的总长度不能超过65535个字节，所以在utf8下，21844（有1~3个字节用来存长度了）
，在GB编码下，是32766
