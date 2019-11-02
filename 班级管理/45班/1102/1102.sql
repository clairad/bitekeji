--select


--group by

select deptno, count(*) from emp group by deptno;

select deptno, avg(sal) as 平均工资 from emp group by deptno;

--显示每个部门的每种岗位的平均工资和最低工资

select deptno, job, avg(sal), min(sal) as 平均工资 from emp group by deptno, job;

--显示平均工资低于2000的部门和它的平均工资(having)

select deptno, avg(sal) as 平均工资 from emp group by deptno having avg(sal) < 2000;

--having是对group by查找后的结果进行筛选的，而where是对表里数据进行筛选的。

select empno, ename, dname from emp, dept where emp.deptno = dept.deptno;

--显示部门号为10的部门名，员工名和工资


select ename, dname, sal from emp, dept where emp.deptno = dept.deptno and emp.deptno = 10;


--显示各个员工的姓名，工资，及工资级别

select ename, sal, grade from emp, salgrade where sal between losal and hisal;

--显示员工FORD的上级领导的编号和姓名

select tmp2.empno, tmp2.ename from emp as tmp1, emp as tmp2 where tmp1.ename = 'FORD' and tmp1.mgr = tmp2.empno;


select empno, ename from emp where empno = (select mgr from emp where ename = 'FORD');

--子查询

--where后的子查询
--显示SMITH同一部门的员工

select empno, ename, deptno from emp where deptno = (select deptno from emp where ename = "SMITH");

--查询和10号部门的工作相同的雇员的名字，岗位，工资，部门号，但是不包含10自己的

select ename, job, sal, deptno from emp where job in(select distinct job from emp where deptno = 10) and deptno <> 10;

--显示工资比部门30的所有员工的工资高的员工的姓名、工资和部门号

select ename, sal, deptno from emp where sal > all(select sal from emp where deptno = 30);

--显示工资比部门30的任意员工的工资高的员工的姓名、工资和部门号

select ename, sal, deptno from emp where sal > any(select sal from emp where deptno = 30);

--查询和SMITH的部门和岗位完全相同的所有雇员，不含SMITH本人

select empno, ename, deptno, job from emp where (deptno, job) = (select deptno, job from emp where ename = "SMITH") and ename <> "SMITH";


--from后的子查询

--显示高于自己部门平均工资的员工的姓名、部门、工资、平均工资

select ename, emp.deptno, sal, avgsal from emp, (select deptno, avg(sal) as avgsal from emp group by deptno) as tmp where emp.deptno = tmp.deptno and sal > avgsal;

--查找每个部门工资最高的人的姓名、工资、部门、最高工资

select ename, emp.deptno, sal, maxsal from emp, (select deptno, max(sal) as maxsal from emp group by deptno) as tmp where emp.deptno = tmp.deptno and sal = maxsal;

--显示每个部门的信息（部门名，编号，地址）和人员数量

select dept.deptno, dname, loc, count(*) from dept, emp where dept.deptno = emp.deptno group by emp.deptno;


select dept.deptno, dname, loc, pnum from dept, (select deptno, count(*) as pnum from emp group by deptno) as tmp where dept.deptno = tmp.deptno;

---视图---

create view deptpnum as select deptno, count(*) as pnum from emp group by deptno;

select dept.deptno, dname, loc, pnum from dept, deptpnum where dept.deptno = deptpnum.deptno;

-------

create view empdeptname as
select ename, dname from emp, dept where emp.deptno = dept.deptno;

----内连接----

select ename, dname from emp inner join dept on emp.deptno = dept.deptno;


----外连接----


select ename, dname from emp left join dept on emp.deptno = dept.deptno;

select ename, dname from emp right join dept on emp.deptno = dept.deptno;


insert into emp value
(7911, 'CXK', 'SALESMAN', 7698, '1980-01-01', 800, NULL, NULL);




-------------------------------------



--查询工资高于500或岗位为MANAGER的雇员，同时还要满足他们的姓名首字母为大写的J

select ename, job, sal from emp where (sal > 500 or job = 'MANAGER') and ename like "J%";


--按照部门号升序而雇员的工资降序排序

select empno, ename, sal, deptno from emp order by deptno, sal desc;

--使用年薪进行降序排序

select ename, (sal + ifnull(comm, 0)) * 12 as 年薪 from emp order by 年薪 desc;

--显示工资最高的员工的名字和工作岗位

select ename, job from emp order by sal desc limit 1;


--显示工资高于平均工资的员工信息

select empno, ename, sal, avgsal from emp, (select avg(sal) as avgsal from emp) as tmp where sal > avgsal;


--显示每个部门的平均工资和最高工资

select deptno, avg(sal), max(sal) from emp group by deptno;


--显示平均工资低于2000的部门号和它的平均工资


select deptno, avg(sal) as avgsal from emp group by deptno having avgsal < 2000;

--显示每种岗位的雇员总数，平均工资

select job, count(*), avg(sal) from emp group by job;


---------------------------------


alter table emp add primary key(empno);
alter table emp add index(ename);

explain select * from emp where ename = 'CXK';

show keys from emp;



create table account(
	id int primary key,
	name varchar(50) not null default '',
	balance decimal(10, 2) not null default 0.0
);

insert into account value(1, "蔡徐坤", 2.2);
insert into account value(2, "乔碧萝", 3.5);
insert into account value(3, "卢本伟", 5.5);




--便签表
--编号
--标题
--内容是否私密
--背景颜色
--是否提醒
--提醒时间
--创建时间
--修改时间
--所属分组

create table memo(
	memo_id int unsigned primary key auto_increment,
	title varchar(1024) not null,
	content TEXT not null,
	private_flag bool not null default false,
	back_groud_color int unsigned not null default 16777215,
	wake_flag bool not null default false,
	create_time datetime not null,
	change_time datetime not null,
	group_id int unsigned,
	
	foreign key (group_id) references memo_group(group_id)
);


--便签组
--编号
--组名称
--创建时间
--修改时间


create table memo_group(
	group_id int unsigned primary key auto_increment,
	group_name varchar(255) not null,
	create_time datetime not null,
	change_time datetime not null
);

--编号
--标签编号
--分享备注
--分享时间

create table memo_share(
	share_id int unsigned primary key auto_increment,
	memo_id int unsigned not null,
	`other` varchar(1024),
	share_time datetime not null,
	
	foreign key (memo_id) references memo(memo_id)
);


