
desc numtest;
--查看表的列信息

show create table numtest;
--查看表的创建语句


insert into numtest(f) value(340282346638528860000000000000000000000);

--decimal(6,2)
--(有效数字位数，小数位数)

insert into numtest(de) value(9999.99);


create table chartest(
	str varchar(65535)
)charset=gbk;

create table timetest(
	id int,
	d date,
	dt datetime,
	ts timestamp
);

insert into timetest(dt) value(current_timestamp());

create table enumtest(
	gender enum("男", "女")
);

----------------约束-----------------

--1、not null

create table nulltest(
	id int not null,
	name varchar(20)
);


--2、default

create table defaulttest(
	id int not null default 0,
	name varchar(20) default "狗剩儿"
);

--3、comment

create table commenttest(
	id int not null default 0 comment "编号",
	name varchar(20) default "狗剩儿" comment "名字"
);
--show create table commenttest;

--4、zerofill

create table zftest(
	id int(5) zerofill
);

--5、主键

create table pktest2(
	id int unsigned,
	name varchar(20) not null,
	
	primary key (id, name)
);

insert into pktest2 value(17, "卢本伟");
insert into pktest2 value(1,  "毕福剑");
insert into pktest2 value(2,  "蔡徐坤");
insert into pktest2 value(2,  "杨超越");

--6、唯一键

create table unitest(
	id int unsigned primary key,
	name varchar(20) not null,
	email varchar(100) unique
);

insert into unitest(id, name) value(17, "卢本伟");
insert into unitest value(1,  "毕福剑", "123.com");
insert into unitest value(2,  "蔡徐坤", "123.com");

--7、自增长

create table aitest(
	id int unsigned primary key auto_increment,
	name varchar(20) not null
);

insert into aitest(id, name) value(17, "卢本伟");
insert into aitest(name) value("毕福剑");
insert into aitest(name) value("蔡徐坤");

insert into aitest(id, name) value(2, "杨超越");
insert into aitest(name) value("乔碧萝");
insert into aitest(name) value("杨颖");


--外键

--myISAM没有外键

create table toilet(
	id int unsigned primary key auto_increment,
	xpos double not null,
	ypos double not null,
	addres varchar(100),
	holenum int not null default 1
);

create table person(
	intime datetime,
	toilet_id int unsigned not null,
	hole_id int unsigned,
	
	foreign key (toilet_id) references toilet(id)
);

insert into toilet(xpos, ypos) value
(0, 0),
(0, 0),
(0, 0),
(0, 0),
(0, 0),
(0, 0);

insert into person(toilet_id) value(7);


--index

create table intest(
	id int unsigned,
	name varchar(20) not null,
	
	index (name)
);
