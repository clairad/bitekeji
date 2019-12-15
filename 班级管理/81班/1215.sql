--查询工资高于2000或岗位为MANAGER的雇员，同时还要满足他们的姓名首字母为大写的J

select ename, job, sal from emp where (sal > 2000 or job = "MANAGER") and ename like "J%";

--按照部门号升序而雇员的工资降序排序

select ename, deptno, sal from emp order by deptno, sal desc;

--使用年薪进行降序排序

select ename, sal, comm, (sal + ifnull(comm, 0)) * 12 as ysal from emp order by ysal desc;

--显示工资最高的员工的名字和工作岗位

select ename, sal, job from emp order by sal desc limit 1;

--显示工资高于平均工资的员工信息

select ename, sal, avgsal from emp, (select avg(sal) as avgsal from emp) as tmp where sal > avgsal;

--显示每个部门的平均工资和最高工资

select deptno, avg(sal) as avgsal, max(sal) as maxsal from emp group by deptno;

select emp.deptno, dname, avg(sal) as avgsal, max(sal) as maxsal from emp, dept where emp.deptno = dept.deptno group by deptno;

--显示平均工资低于2000的部门号和它的平均工资

select deptno, avg(sal) as avgsal from emp group by deptno having avgsal < 2000;

select deptno, format(avgsal, 2) from (select deptno, avg(sal) as avgsal from emp group by deptno) as base1,(select 2000 as cmp) as base2 where avgsal < cmp;

--显示每种岗位的雇员总数，平均工资

select job, count(*) as pnum, format(avg(sal), 2) as avgsal from emp group by job;



create table trantest(
	id int unsigned primary key auto_increment,
	name varchar(20)
);

start transaction;
insert into trantest value
(1, "特朗普"),
(2, "奥巴马");

savepoint s2;

insert into trantest value
(3, "林肯"),
(4, "尼克松");

savepoint s4;

insert into trantest value
(5, "华盛顿"),
(6, "罗斯福");

savepoint s6;

insert into trantest value
(7, "肯尼迪"),
(8, "艾森豪威尔");



--1、InnoDB有外键
--2、MyISAM会记录表项总数
--3、InnoDB是聚集索引
--4、MyISAM支持全文索引
--5、InnoDB支持事务


--便签模型
--便签表

--编号
--标题
--内容
--内容是否私密
--背景颜色
--是否提醒
--提醒时间
--创建时间
--修改时间
--所属分组

create table memo(
	memoId int unsigned primary key auto_increment,
	title varchar(255) not null,
	textInfo varchar(1024) not null default "",
	textPrivateFlag bool not null default false,
	color int unsigned not null default 0,
	clockFlag bool not null default false,
	createTime datetime not null,
	modifyTime timestamp not null,
	groupId int unsigned not null default 0,
	
	foreign key (groupId) references memoGroup(groupId)
);

--2.2 便签组模型
--便签组

--编号
--组名称
--创建时间
--修改时间

create table memoGroup(
	groupId int unsigned primary key auto_increment,
	groupName varchar(255) not null,
	createTime datetime not null,
	modifyTime timestamp not null
);

insert into memoGroup value(0, "defaultGroup", now(), now());

--2.3 便签分享模型
--便签分享

--编号
--标签编号
--分享备注
--分享时间

create table memoShare(
	shareId int unsigned primary key auto_increment,
	memoId int unsigned not null,
	otherMsg varchar(512),
	shareTime timestamp not null,
	
	foreign key (memoId) references memo(memoId)
);



