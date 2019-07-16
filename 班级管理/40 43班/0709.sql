--查询和SMITH的部门和岗位完全相同的所有雇员，不含SMITH本人

select empno, ename, deptno, job from emp where (deptno, job) = (select deptno, job from emp where ename = "SMITH") and ename <> "SMITH";



create table tttt(
	id int unsigned,
	name varchar(20),
	sex varchar(2),
	primary key (id, name)
);

select ename, deptno, sal, asal from emp, (select avg(sal) asal, deptno dt from emp group by deptno) tmp where emp.sal > tmp.asal and emp.deptno=tmp.dt;

select ename, deptno, sal, format(asal,2) from emp, (select max(sal) asal, deptno dt from emp group by deptno) tmp where emp.sal = tmp.asal and emp.deptno=tmp.dt;

select dept.dname, dept.deptno, dept.loc, count(*) from dept, emp where dept.deptno = emp.deptno group by deptno;

select ename, sal, job from EMP where sal>2500 union select ename, sal, job from EMP where job='MANAGER';

select ename, sal, job from emp where sal>2500 union select ename, sal, job from emp where job='MANAGER';

select ename, sal, job from emp where sal>2500 or job='MANAGER';

