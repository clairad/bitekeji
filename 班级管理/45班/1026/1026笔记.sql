create database class45;

use class45;

create table test(
	id int unsigned,
	name char(20)
);

insert into test value(1, '蔡徐坤');

insert into test values
(2, '吴亦凡'),
(3, '鹿晗');

select * from test;

insert into test values
(1, '蔡徐坤'),
(2, '吴亦凡'),
(3, '鹿晗');

--{}
--[]
--|

--A {B | C | D} E [F] {G | H} [I | J] K

show variables like 'character_set_database';
show variables like 'collation_database';


create database t1 collation utf8_bin;

--查看所有数据库或者当前库的所有表
show databases;
show tables;

--查看创建语句
show create database `NAME`;
show create table `NAME`;

rm -rf /home/aaa


--bit[(M)]

create table inttest(
	tint tinyint,
	utint tinyint unsigned,
	sint smallint,
	usint smallint unsigned,
	mint int,
	uint int unsigned,
	bint bigint,
	ubint bigint unsigned
);

insert into inttest(tint, utint) value(100, 100);


create table doubletest(
	ftest float,
	uftest float unsigned,
	dtest double(5, 1),
	udtest double(5, 1) unsigned,
	detest decimal(7, 2),
	udetest decimal(7, 2) unsigned
);

insert into doubletest(ftest, uftest) value(461289461378746918364671.2, 4713057191240791769085373697857.5);

insert into doubletest(dtest, udtest) value(-2009.3, 1029.6);

create table chartest(
	ch varchar(65535)
)charset=gbk;

create table timetest(
	id int,
	name varchar(20),
	ttest timestamp
);

insert into timetest(id, name) value(1, "蔡徐坤"),
(2, "杨超越"),
(3, "乔碧萝");



create table enumtest(
	gender enum("男","女","保密")
);

insert into enumtest value
(3), (2);


--非空约束

create table nulltest(
	a int not null,
	b int
);

--默认值

create table deftest(
	id int,
	name varchar(20),
	gender enum("男","女","保密") default '男'
);

insert into deftest(id, name) value
(1, "蔡徐坤"),
(2, "杨超越"),
(3, "乔碧萝");

--列描述
create table comtest(
	id int comment "学号",
	name varchar(20) comment "姓名",
	gender enum("男","女","保密")
);

--zerofill

create table zerotest(
	id int(6) zerofill,
	name varchar(20),
	gender enum("男","女","保密")
);


--主键

create table pritest(
	id int(6) zerofill primary key,
	name varchar(20),
	gender enum("男","女","保密")
);

insert into pritest value
(1, "小沈阳", "保密"),
(2, "沈腾", "男"),
(3, "常远", "男");

insert into pritest value
(1, "二丫", "女");


create table primtest(
	id int(6) zerofill,
	name varchar(20),
	gender enum("男","女","保密"),
	
	primary key(id, name)
);

insert into primtest value
(1, "小沈阳", "保密"),
(2, "沈腾", "男"),
(3, "常远", "男"),
(1, "二丫", "女");

--auto_increment

create table aitest(
	id int(6) unsigned zerofill primary key auto_increment,
	name varchar(20),
	gender enum("男","女","保密")
);

insert into aitest(name, gender) value
("金星", "保密"),
("郭德纲", "男"),
("于谦", "男");

insert into aitest(name, gender) value
("赵本山", "男");


--唯一键
create table untest(
	id int(6) unsigned zerofill unique,
	name varchar(20),
	gender enum("男","女","保密")
);

insert into untest(name, gender) value
("金星", "保密"),
("郭德纲", "男"),
("于谦", "男");

insert into untest(name, gender) value
(1, "赵本山", "男");

--外键

create table myclass(
	id int unsigned primary key,
	name varchar(20)
);




