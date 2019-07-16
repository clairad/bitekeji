--如何显示每个部门的平均工资和最高工资

select deptno, avg(sal), max(sal) from emp group by deptno;


--显示平均工资低于2000的部门和它的平均工资 

select deptno, avg(sal) from emp group by deptno having avg(sal) < 2000;

--查询工资高于500或岗位为MANAGER的雇员，同时还要满足他们的姓名首字母为大写的J

select empno, ename, sal, job from emp where (sal > 500 or job = "MANAGER") and ename like "J%";

--按照部门号升序而雇员的工资降序排序

select empno, ename, deptno, sal from emp order by deptno, sal desc;


--使用年薪进行降序排序

select empno, ename, deptno, sal, (sal + ifnull(comm, 0)) * 12 as "年薪" from emp order by (sal + ifnull(comm, 0)) * 12 desc;

--显示工资最高的员工的名字和工作岗位

select empno, ename, job from emp order by sal desc limit 1;

--显示工资高于平均工资的员工信息

--显示每种岗位的雇员总数，平均工资

select job, count(*), format(avg(sal), 2) from emp group by job;


--显示部门号为10的部门名，员工名和工资

select dname, ename, sal from dept, emp where emp.deptno = 10 and emp.deptno = dept.deptno;

--显示各个员工的姓名，工资，及工资级别

select ename, sal, grade from emp, salgrade where sal between losal and hisal;

--显示员工FORD的上级领导的编号和姓名

select leader.empno, leader.ename from emp leader, emp worker where leader.empno = worker.mgr and worker.ename = "FORD";

--in关键字；查询和10号部门的工作相同的雇员的名字，岗位，工资，部门号，但是不包含10自己的

select ename, job, sal, deptno from emp where job in (select job from emp where deptno = 10) and deptno <> 10;

--all关键字；显示工资比部门30的所有员工的工资高的员工的姓名、工资和部门号

select ename, sal, deptno from emp where sal > all(select sal from emp where deptno = 30);

select max(sal) from emp where deptno = 30;

--any关键字；显示工资比部门30的任意员工的工资高的员工的姓名、工资和部门号

select ename, sal, deptno from emp where sal > any(select sal from emp where deptno = 30);



