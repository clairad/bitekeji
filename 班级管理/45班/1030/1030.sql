
--alter table 表名 add [column] 列名 类型 [约束] [first | after 列名]

alter table untest add column age int;

--alter table 表名 drop [column] 列名

alter table untest drop column age;

--modify可以修改某个字段的类型和约束

alter table untest modify age tinyint unsigned;

--change除了以上的功能，还能改字段名

alter table untest change age ages tinyint unsigned;

----------------------

CREATE TABLE students (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	sn INT NOT NULL UNIQUE COMMENT '学号',
	name VARCHAR(20) NOT NULL,
	qq VARCHAR(20)
);

INSERT INTO students VALUES
(100, 10000, '时间领主抓根宝', NULL),
(101, 10001, '潼潼', '11111'),
(102, 20001, '有只苦力怕', null),
(103, 20002, '元气大爷x', '22222');

INSERT INTO students VALUES
(100, 10000, '奈何桥楠', NULL) ON DUPLICATE KEY UPDATE name = '奈何桥楠';

INSERT INTO students VALUES
(105, 30001, '时间领主抓根宝', NULL) ON DUPLICATE KEY UPDATE id = 105;


REPLACE INTO students(id, sn, name) VALUES
(103, 30001, '会飞的小猪');
--on duplicate key 是针对某个数据操作的，而replace是整行操作


----------------SELECT---------------

SELECT
[DISTINCT] {* | {column [, column] ...}
[FROM table_name]
[WHERE ...]
[ORDER BY column [ASC | DESC], ...]
[LIMIT ...]

CREATE TABLE egres (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(20) NOT NULL COMMENT '同学姓名',
	chin float DEFAULT 0.0 COMMENT '语文成绩',
	math float DEFAULT 0.0 COMMENT '数学成绩',
	engl float DEFAULT 0.0 COMMENT '英语成绩'
);

INSERT INTO egres (name, chin, math, engl) VALUES
('太原老郭', 67, 98, 56),
('小球', 87, 78, 77),
('大乌龟', 88, 98, 90),
('李白入梦', 82, 84, 67),
('肥仔', 55, 85, 45),
('碧海潮生', 70, 73, 78),
('小鱼儿', 75, 65, 30);



create table distest(
	id int,
	name varchar(5)
);

insert into distest value
(1, 'w'),
(1, 'w'),
(1, 'w'),
(2, 'q'),
(2, 'q'),
(3, 't');

--去除表里的重复项
--DISTINCT

create table distesttmp like distest;

insert into distesttmp select distinct * from distest;

drop table distest;

rename table distesttmp to distest;

--WHERE

--英语不及格的同学及英语成绩

select name, engl from egres where engl < 60;

--语文成绩在[80, 90]分的同学及语文成绩

select name, chin from egres where chin <= 90 and chin >= 80;

select name, chin from egres where chin between 80 and 90;

--数学成绩是 58 或者 59 或者 98 或者 99 分的同学及数学成绩

select name, math from egres where math = 58 or math = 59 or math = 98 or math = 99;

select name, math from egres where math in(58, 59, 98, 99);

-- 姓孙的同学 及 孙某同学

select id, name from egres where name like "小%";

select id, name from egres where name like "小_";

--语文成绩好于英语成绩的同学

select name, chin, engl from egres where chin > engl;

--总分在 200 分以下的同学

select name, chin + engl + math as 总分 from egres where chin + engl + math < 200;

--语文成绩 > 80 并且不姓孙的同学

select name, chin from egres where chin > 80 and name not like "小%";

--孙某同学，否则要求总成绩 > 200 并且 语文成绩 < 数学成绩 并且 英语成绩 > 80


select name, chin, math, engl, chin + engl + math as 总分 from egres where name like "小%" or (chin + engl + math > 200 and chin < math and engl > 80);

--ORDER BY
--同学及数学成绩，按数学成绩升序显示

select name, math from egres order by math;

--数学相同就按语文排
select name, math, chin from egres order by math, chin desc;

--null比任意值都小


--LIMIT
--总分前三

select name, chin, math, engl, chin + engl + math as 总分 from egres order by 总分 desc limit 3;

--limit a,b 代表跳过前a行后打印b行，相当于limit b offset a


-------------UPDATE--------------

-- 将曹孟德同学的数学成绩变更为 60 分，语文成绩变更为 70 分

update egres set math = 60, chin = 70 where name = "李白入梦";

-- 将总成绩倒数前三的 3 位同学的数学成绩加上 30 分

update egres set math = math + 30 order by math + chin + engl limit 3;

--将所有同学的语文成绩更新为原来的 2 倍

update egres set chin = chin * 2;

------------DELETE--------------

delete from egres;
--不会影响自增

truncate egres; --对表操作





