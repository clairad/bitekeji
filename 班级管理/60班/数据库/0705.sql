show databases;

create database class60;
use class60;

create table student(
	id int,
	age int,
	name char(5),
	sex char(1)
);

insert into `student` value
(1, 18, "蔡徐坤", '男'),
(2, 20, "卢本伟", '男'),
(3, 22, "杨超越", '女'),
(3, 23, "品如", '女');

select * from student;


A [B {C | D | H}]{E | F}[G]

A F

A B E

BIT[(m)]
m的取值是[1, 64]

FLOAT[(m, d)] [UNSIGNED]
m是有效数字位数
d是小数位数



FLOAT(4,2)

-99.99~99.99



