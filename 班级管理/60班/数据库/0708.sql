update students set score = 90 where name = "孙悟空";

update students set qq = 12345, score = 60 where name = "曹阿瞒";

update students set score = score * 2;

delete from students where name = "孙悟空";

truncate students;


CREATE TABLE egres (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(20) NOT NULL COMMENT '同学姓名',
	chin float DEFAULT 0.0 COMMENT '语文成绩',
	math float DEFAULT 0.0 COMMENT '数学成绩',
	engl float DEFAULT 0.0 COMMENT '英语成绩'
);

INSERT INTO egres (name, chin, math, engl) VALUES
('唐三藏', 67, 98, 56),
('孙悟空', 87, 78, 77),
('猪悟能', 88, 98, 90),
('曹孟德', 82, 84, 67),
('刘玄德', 55, 85, 45),
('孙权', 70, 73, 78),
('宋公明', 75, 65, 30);

SELECT
	[DISTINCT] {* | {column [, column] ...}
	[FROM table_name]
	[WHERE ...]
	[ORDER BY column [ASC | DESC], ...]
	[LIMIT ...];

select name from egres;

select id 学号, name 姓名, chin + math + engl 总分 from egres;

--英语不及格的同学及英语成绩 ( < 60 )
select name, engl from egres where engl < 60;

--语文成绩在 [80, 90] 分的同学及语文成绩

select name, chin from egres where chin between 80 and 90;

--数学成绩是 58 或者 59 或者 98 或者 99 分的同学及数学成绩 

select name, math from egres where
math in(58, 59, 98, 99);

--姓孙的同学 及 孙某同学 
select id, name from egres where name like "孙%";

select id, name from egres where name like "孙_";

--语文成绩好于英语成绩的同学
select name, chin, engl from egres where chin > engl;

--总分在 200 分以下的同学 
select name, chin + engl + math 总分 from egres where chin + engl + math < 200;

--语文成绩 > 80 并且不姓孙的同学 

select name, chin from egres where chin > 80 and name not like "孙%";

--孙某同学，否则要求总成绩 > 200 并且 语文成绩 < 数学成绩 并且 英语成绩 > 80 

select name, chin, math, engl, chin + engl + math 总分 from egres where name like "孙%" or (chin + engl + math > 200 and chin < math and engl > 80);

--查询 qq 号已知的同学姓名
select name, qq from egres where not qq <=> null;



select id, name, chin + math + engl 总分 from egres order by chin + math + engl desc;

select id, name, qq, chin + math + engl 总分 from egres order by qq , chin + math + engl desc;

--查询姓孙的同学或者姓曹的同学数学成绩，结果按数学成绩由高到低显示 
select id, name, math from egres where name like "曹%" or name like "孙%" order by math desc;


--从第五(4+1)行开始显示3行，4可以省略
select * from egres limit 4, 3;
select * from egres limit 3 offset 4;


select * from egres order by chin + math + engl desc limit 3;

insert into disttest2 select distinct * from disttest;

rename table disttest2 to disttest;

--统计班级共有多少同学 
select count(*) from egres;
select avg(math) from egres;
select sum(math) from egres;

select avg(math + chin + engl) 平均总分 from egres;


select count(math) from egres where math > 70;




