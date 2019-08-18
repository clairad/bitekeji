
create table `review`(
	id int(6) unsigned zerofill primary key auto_increment comment "主键",
	dbit bit(7),
	dint bigint(6),
	dfloat float,
	ddecimal decimal(6,2) unsigned,
	dchar char(10),
	dvar varchar(200) not null,
	dtime timestamp,
	denum enum("男", "女") default "男"
);

insert into review(dvar) value("蔡徐坤");

insert into review(dvar, dint, dchar) value("卢本伟", 17, "秒了我");

insert into review(dvar, dfloat, ddecimal) value("乔碧萝", 12345678, 9999.996);

insert into review(dvar, dfloat, ddecimal) value("乔碧萝", 12345678, 9999.994);

update review set denum = "女" where dvar = "乔碧萝";

alter table review modify dfloat float(10, 2);

insert into review(dbit, dvar) value(65, "吴亦凡");

update review set denum = 2 where dvar = "乔碧萝";

alter table review modify ddecimal decimal(4, 2);


CREATE TABLE students (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	sn INT NOT NULL UNIQUE COMMENT '学号', 
	name VARCHAR(20) NOT NULL,
	qq VARCHAR(20)
);

INSERT INTO students VALUES
(100, 10000, "七优", NULL),
(101, 10001, "李温柔", NULL),
(102, 10002, "千里之外", 11111),
(103, 10003, "大大诺", NULL),
(104, 10004, "云烟", 22222),
(105, 10005, "曼城界", NULL),
(106, 10006, "我爱可口可乐", NULL);


INSERT INTO students (id, sn, name) VALUES (100, 10010, '秋意浓') ON DUPLICATE KEY UPDATE name = '秋意浓';

REPLACE INTO students (sn, name) VALUES (10001, '山丘');

REPLACE INTO students (id, name) VALUES (106, '山丘');



--A { B | C [ D | E ] } [ F ] G [ H { I | J }]

--A G H
--A C F G H J
--A C E G H
--A B G


--	SELECT
--	[DISTINCT]
--	{* | {column [, column] ...}}
--	[FROM table_name]
--	[WHERE ...]
--	[ORDER BY column [ASC | DESC], ...]
--	[LIMIT ...];



CREATE TABLE egres (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(20) NOT NULL COMMENT '同学姓名',
	yuwen float DEFAULT 0.0 COMMENT '语文成绩',
	shuxue float DEFAULT 0.0 COMMENT '数学成绩',
	yingyu float DEFAULT 0.0 COMMENT '英语成绩'
);

INSERT INTO egres (name, yuwen, shuxue, yingyu) VALUES
('张哩咯', 67, 98, 56),
('舒克的弯弯睫毛', 87, 78, 77),
('轻疯拂面', 88, 98, 90),
('九口甜菜', 82, 84, 67),
('幸运的人儿', 55, 85, 45),
('暴躁果果', 70, 73, 78),
('张洋', 75, 65, 30);

--孙某同学，否则要求总成绩 > 200 并且 语文成绩 < 数学成绩 并且 英语成绩 > 80

select name, yuwen, shuxue, yingyu from egres where name like "张%" or (yuwen < shuxue and yuwen + shuxue + yingyu > 200 and yingyu > 80);

SELECT name, qq FROM students ORDER BY qq;

--数学降序，英语升序，语文升序

select name, shuxue, yingyu, yuwen from egres order by shuxue desc, yingyu, yuwen;

select name, shuxue, yingyu, yuwen, shuxue+yuwen+yingyu as 总分 from egres order by shuxue+yuwen+yingyu desc;


select name, shuxue, yingyu, yuwen, shuxue+yuwen+yingyu as 总分 from egres order by shuxue+yuwen+yingyu desc limit 3;

update egres set shuxue = 80 where name = "暴躁果果";

delete from egres where shuxue > 90;

delete from egres;

INSERT INTO egres (name, yuwen, shuxue, yingyu) VALUES
('张哩咯', 67, 98, 56);



select deptno, count(*) from emp group by deptno;

select deptno, avg(sal) from emp group by deptno having avg(sal) between 2000 and 2500;

select deptno, job, avg(sal) from emp group by job, deptno;



--查询工资高于500或岗位为MANAGER的雇员，同时还要满足他们的姓名首字母为大写的J

select empno, ename, sal, job from emp where (sal > 500 or job = "MANAGER") and ename like "J%";

--按照部门号升序而雇员的工资降序排序

select empno, deptno, ename, sal from emp order by deptno, sal desc;

--使用年薪进行降序排序

select ename, sal, comm, (sal + ifnull(comm, 0)) * 12 as 年薪 from emp order by 年薪 desc;

--显示工资最高的员工的名字和工作岗位



--显示工资高于平均工资的员工信息



--显示每个部门的平均工资和最高工资

select deptno, avg(sal), max(sal) from emp group by deptno;

--显示平均工资低于2000的部门号和它的平均工资
--显示每种岗位的雇员总数，平均工资




select ename, dname from emp, dept where emp.deptno = dept.deptno;


--显示部门号为10的部门名，员工名和工资

select dname, ename, sal from emp, dept where emp.deptno = dept.deptno and emp.deptno = 10;

--显示各个员工的姓名，工资，及工资级别

select ename, sal, grade from emp, salgrade where sal between losal and hisal;

--员工FORD的上级领导的编号和姓名

select back.empno, back.ename from emp as front, emp as back where front.ename = "FORD" and front.mgr = back.empno;

--显示SMITH同一部门的员工

select ename, deptno from emp where deptno = (select deptno from emp where ename = "SMITH");

--查询和10号部门的工作相同的雇员的名字，岗位，工资，部门号，但是不包含10自己


select ename, job, sal, deptno from emp where job in(select distinct job from emp where deptno = 10) and deptno <> 10;


--显示工资比部门30的所有员工的工资高的员工的姓名、工资和部门号

select ename, sal, deptno from emp where sal > all(select distinct sal from emp where deptno = 30);

--显示工资比部门30的任意员工的工资高的员工的姓名、工资和部门号

select ename, sal, deptno from emp where sal > any(select distinct sal from emp where deptno = 30);


--查询和SMITH的部门和岗位完全相同的所有雇员，不含SMITH本人

select empno, ename from emp where (deptno, job) = (select deptno, job from emp where ename = "SMITH") and ename <> "SMITH";


--显示高于自己部门平均工资的员工的姓名、部门、工资、平均工资


select deptno, avg(sal) as avgsal from emp group by deptno;


select ename, emp.deptno, sal, avgsal from emp, (select deptno, avg(sal) as avgsal from emp group by deptno) as tmp where tmp.deptno = emp.deptno and sal > avgsal;




create view deptAvgsal as select deptno, avg(sal) as avgsal from emp group by deptno;

select ename, emp.deptno, sal, avgsal from emp, deptAvgsal where deptAvgsal.deptno = emp.deptno and sal > avgsal;


--查找每个部门工资最高的人的姓名、工资、部门、最高工资

select ename, emp.deptno, sal, maxsal from emp, (select deptno, max(sal) as maxsal from emp group by deptno) as tmp where tmp.deptno = emp.deptno and sal = maxsal;


--显示每个部门的信息（部门名，编号，地址）和人员数量 

select dname, dept.deptno, loc, pnum from dept, (select deptno, count(*) as pnum from emp group by deptno) as tmp where tmp.deptno = dept.deptno;


select dname, dept.deptno, loc, count(*) as pnum from dept, emp where dept.deptno = emp.deptno group by emp.deptno;


select ename, sal, job from emp where sal>2500 union select ename, sal, job from emp where job='MANAGER';

select ename, sal, job from emp where sal>2500 or job='MANAGER';




