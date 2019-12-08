--有一个商店的数据，记录客户及购物情况，有以下三个表组成：
--商品goods(商品编号goods_id，商品名goods_name, 单价unitprice, 商品类别category, 供应商provider)

create table `goods`(
	goods_id int unsigned primary key auto_increment,
	goods_name varchar(128) not null,
	unitprice decimal(8, 2) not null,
	category varchar(64) not null comment "商品类别",
	provider varchar(128) comment "供应商"
);

--客户customer(客户号customer_id,姓名name,住址address,邮箱email,性别sex，身份证card_id)

create table `customer`(
	customer_id int unsigned primary key auto_increment,
	name varchar(32) not null,
	address varchar(256),
	email varchar(128) unique,
	sex enum('男', '女', '保密') not null default '保密',
	card_id char(18) unique
);

--购买purchase(购买订单号order_id,客户号customer_ id,商品号goods_ id,购买数量nums)

create table purchase(
	order_id int unsigned primary key auto_increment,
	customer_id int unsigned not null,
	goods_id int unsigned not null,
	nums int unsigned not null default 1,
	
	foreign key (customer_id) references customer(customer_id),
	foreign key (goods_id) references goods(goods_id)
);

--要求：
--每个表的主外键
--客户的姓名不能为空值
--邮箱不能重复
--客户的性别(男，女)


create table altest(
	col1 int,
	col2 int,
	col3 int,
	col4 int
);

alter table altest add column col5 int;
alter table altest drop column col3;

alter table altest add column col3 int after col2;
alter table altest add column col0 int first;

alter table altest modify col3 float;
alter table altest change col3 col3_1 double;

--库和表的增删改查：create drop alter show
--表详细信息的查询：desc


--insert

CREATE TABLE students (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	sn INT NOT NULL UNIQUE COMMENT '学号',
	name VARCHAR(20) NOT NULL,
	qq VARCHAR(20)
);

insert into students value
(1, 10001, "于谦", null),
(2, 10002, "杨幂", 123456789),
(3, 10003, "本泽马", null),
(4, 10004, "李彦宏", 123456789);


insert into students value (1, 10001, "郭德纲", null) on duplicate key update name = "郭德纲";

insert into students(sn, name, qq) value (10002, "杨颖", null) on duplicate key update name = "杨颖";

replace into students(sn, name, qq) value(10003, "大师兄", 987654321);


--SELECT
--[DISTINCT] {* | {column [, column] ...}
--[FROM table_name]
--[WHERE ...]
--[ORDER BY column [ASC | DESC], ...]
--[LIMIT]


--DISTINCT 查重

create table disttest(
	id int,
	sn char(1)
);

insert into disttest value
(1, 'a'),
(2, 'b'),
(2, 'b'),
(3, 'c'),
(3, 'c'),
(3, 'c');

create table disttesttmp like disttest;
insert into disttesttmp select distinct * from disttest;
drop table disttest;
rename table disttesttmp to disttest;


--where

CREATE TABLE exam_result (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(20) NOT NULL COMMENT '同学姓名',
	yuwen float DEFAULT 0.0 COMMENT '语文成绩',
	shuxue float DEFAULT 0.0 COMMENT '数学成绩',
	yingyu float DEFAULT 0.0 COMMENT '英语成绩'
);


INSERT INTO exam_result (name, yuwen, shuxue, yingyu) VALUES
('胖到没裤子', 67, 98, 56),
('嗑瓜子猫', 87, 78, 77),
('熊猫队长', 88, 98, 90),
('不来也不去', 82, 84, 67),
('半日光辉', 55, 85, 45),
('卫什么', 70, 73, 78),
('嗑药小王子', 75, 65, 30);


select name, yuwen from exam_result;

--英语不及格的同学及英语成绩

select name, yingyu from exam_result where yingyu < 60;

--语文成绩在 [80, 90] 分的同学及语文成绩

select name, yuwen from exam_result where yuwen between 80 and 90;

--数学成绩是 58 或者 59 或者 98 或者 99 分的同学及数学成绩

select name, shuxue from exam_result where shuxue in(58, 59, 98, 99);

--姓孙的同学 及 孙某同学

select id, name from exam_result where name like "嗑%";

--语文成绩好于英语成绩的同学

select name, yuwen, yingyu from exam_result where yuwen > yingyu;

--总分在 200 分以下的同学

select name, yuwen, shuxue, yingyu, yuwen+shuxue+yingyu as total from exam_result where yuwen+shuxue+yingyu < 200;


--语文成绩 > 80 并且不姓孙的同学

select name, yuwen from exam_result where yuwen > 80 and name not like "嗑%";

--孙某同学，否则要求总成绩 > 200 并且 语文成绩 < 数学成绩 并且 英语成绩 > 80

select name, yuwen, shuxue, yingyu, yuwen+shuxue+yingyu as total from exam_result where (yuwen+shuxue+yingyu > 200 and yuwen < shuxue and yingyu > 80) or name like "嗑____";

--order by
--同学及数学成绩，按数学成绩升序显示

select name, shuxue from exam_result order by shuxue;

--查询同学各门成绩，依次按 数学降序，英语升序，语文升序的方式显示

select name, yuwen, shuxue, yingyu from exam_result order by shuxue desc, yingyu asc, yuwen asc;

--查询同学及总分，由高到低

select name, yuwen, shuxue, yingyu, yuwen+shuxue+yingyu as total from exam_result order by total desc;

--查询姓孙的同学或者姓曹的同学数学成绩，结果按数学成绩由高到低显示

select name, shuxue from exam_result where name like "嗑%" or name like "半%" order by shuxue desc;

--LIMIT

--显示总分前三名的学生

select name, yuwen, shuxue, yingyu, yuwen+shuxue+yingyu as total from exam_result order by total desc limit 3;

select name, yuwen, shuxue, yingyu, yuwen+shuxue+yingyu as total from exam_result order by total desc limit 6,3;

select name, yuwen, shuxue, yingyu, yuwen+shuxue+yingyu as total from exam_result order by total desc limit 3 offset 6;

--limit a,b    limit b offset a

--update

--UPDATE table_name SET column = expr [, column = expr ...]
--[WHERE ...] [ORDER BY ...] [LIMIT ...]

update exam_result set shuxue = 80 where name = "嗑瓜子猫";

--将曹孟德同学的数学成绩变更为 60 分，语文成绩变更为 70 分

update exam_result set shuxue = 60, yuwen = 70 where name = "不来也不去";

--将总成绩倒数前三的 3 位同学的数学成绩加上 30 分

update exam_result set shuxue = shuxue + 30 order by yuwen+shuxue+yingyu limit 3;

--将所有同学的语文成绩更新为原来的 2 倍

update exam_result set yuwen = yuwen * 2;

--delete

--DELETE FROM table_name [WHERE ...] [ORDER BY ...] [LIMIT ...]

--删除孙悟空同学的考试成绩

delete from exam_result where name = "嗑瓜子猫";


create table deltest(
	id int unsigned primary key auto_increment,
	name varchar(20)
);

insert into deltest(name) value
("a"),("b"),("c"),("d");

--truncate 截断

truncate deltest;

--truncate是整表操作，delete是逐行操作

--------------聚合函数----------------

select count(*) from exam_result;

select count(distinct shuxue) from exam_result;

select count(qq) from students;

select sum(shuxue) from exam_result;

select avg(shuxue) from exam_result;

select max(shuxue) from exam_result;

select min(shuxue) from exam_result;

--返回 > 70 分以上的数学最低分

select min(shuxue) from exam_result where shuxue > 70;

--group by

select count(*), deptno from emp group by deptno;

select avg(sal), deptno from emp group by deptno;

-------------多表查询--------------

select ename, sal, dname from emp, dept where emp.deptno = dept.deptno;

--显示员工FORD的上级领导的编号和姓名


select tmp1.ename, tmp2.empno, tmp2.ename from emp as tmp1, emp as tmp2 where tmp1.mgr = tmp2.empno;

select tmp2.empno, tmp2.ename from emp as tmp1, emp as tmp2 where tmp1.mgr = tmp2.empno and tmp1.ename = "FORD";

--子查询

select empno, ename from emp where empno = (select mgr from emp where ename = "FORD");

--单行单列的查询
--显示SMITH同一部门的员工

select ename, deptno from emp where deptno = (select deptno from emp where ename = "SMITH");

--多行单列的查询
--查询和10号部门的工作相同的雇员的名字，岗位，工资，部门号，但是不包含10自己的

select ename, job, sal, deptno from emp where job
in(select distinct job from emp where deptno = 10) and deptno <> 10;

--显示工资比部门30的所有员工的工资高的员工的姓名、工资和部门号

select ename, sal, deptno from emp where sal > all(select sal from emp where deptno = 30);


select ename, sal, deptno from emp where sal > any(select sal from emp where deptno = 30);


--单行多列的查询

--查询和SMITH的部门和岗位完全相同的所有雇员，不含SMITH本人

select empno, ename, job, deptno from emp where (deptno, job) = (select deptno, job from emp where ename = "SMITH") and ename <> "SMITH";

--------※※※from后的子查询※※※---------


--显示高于自己部门平均工资的员工的姓名、部门、工资、平均工资

select ename, job, sal, avgsal from emp, (select avg(sal) as avgsal, deptno from emp group by deptno) as avgform where emp.deptno = avgform.deptno and sal > avgsal;


create view avgform as select avg(sal) as avgsal, deptno from emp group by deptno;

select ename, job, sal, avgsal from emp, avgform where emp.deptno = avgform.deptno and sal > avgsal;

--查找每个部门工资最高的人的姓名、工资、部门、最高工资

select ename, job, sal, maxsal from emp, (select max(sal) as maxsal, deptno from emp group by deptno) as maxform where emp.deptno = maxform.deptno and sal = maxsal;


--显示每个部门的信息（部门名，编号，地址）和人员数量

select dname, dept.deptno, loc, count(*) from dept, emp where emp.deptno = dept.deptno group by emp.deptno;


select dname, dept.deptno, loc, pnum from dept, (select count(*) as pnum, deptno from emp group by deptno) as countform where countform.deptno = dept.deptno;

--view 视图

create view dnamesrch as select ename, dname from emp, dept where emp.deptno = dept.deptno;




