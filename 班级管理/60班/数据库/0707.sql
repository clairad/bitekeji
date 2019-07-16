GBK
GB2312


UNICODE

10XXXXXX 
110XXXXX XXXXXXXX XXXXXXX

BIG5
GB

drop table test;
create table test(
	id int not null comment "学号",
	name varchar(20) not null comment "姓名"
);

create table n2(
	id int(4) zerofill
);


create table p1(
	id int unsigned primary key,
	name varchar(20),
	sex char(2)
);

create table p2(
	id int unsigned,
	name varchar(20),
	sex char(2),
	primary key(id, name)
);

insert into p2 value
(1, "蔡徐坤", '男'),
(2, "卢本伟", '男'),
(3, "杨超越", '女');

insert into p2 value
(3, "杨颖", '女');
(4, "杨超越", '女');


create table au(
	id int unsigned primary key auto_increment,
	name varchar(20) not null
);

insert into au(name) value
("蔡徐坤"),
("卢本伟"),
("杨超越");


create table uk(
	id int unsigned primary key auto_increment,
	name varchar(20) not null,
	qq bigint unique key
);


insert into uk(name, qq) value
("蔡徐坤", 123456789),
("卢本伟", 234567891),
("杨超越", 345678912);

create table tech(
	tech_id int unsigned  primary key auto_increment,
	tech_name varchar(10) not null,
	tech_decribe varchar(10)
);

create table hero(
	hero_id int unsigned  primary key auto_increment,
	hero_name varchar(10) not null,
	hero_techid int unsigned,
	hero_decribe varchar(10),
	foreign key (hero_techid) references tech(tech_id)
);


insert into tech(tech_name) value
("漫天飞羽"),
("轻舞成双"),
("无极之道");

insert into hero(hero_name, hero_techid) value
("霞", 3),
("洛", 1),
("易", 2);

insert into hero(hero_name, hero_techid) value ("妲己", 4);

insert into hero(hero_name, hero_techid) value ("大乔", null);

--商品goods(商品编号goods_id，商品名goods_name, 单价unitprice, 商品类别category, 供应商provider) 

create table goods (
	goods_id int unsigned primary key auto_increment comment "商品编号",
	goods_name varchar(50) not null comment "商品名",
	unitprice float(8,2) default 0 comment "单价",
	category varchar(20) not null comment "商品类别",
	provider varchar(50) comment "供应商"
);

--客户customer(客户号customer_id,姓名name,住址address,邮箱email,性别sex，身份证card_id) 

create table customer (
	customer_id int unsigned primary key auto_increment comment "客户号",
	name varchar(20) not null comment "姓名",
	address varchar(200) comment "住址",
	email varchar(80) unique key comment "邮箱",
	sex enum("男", "女") comment "性别",
	card_id char(18) unique key comment "身份证号"
);

--购买purchase(购买订单号order_id,客户号customer_id,商品号goods_id,购买数量nums)

create table purchase (
	order_id int unsigned primary key auto_increment comment "订单号",
	customer_id int unsigned not null comment "客户号",
	goods_id int unsigned not null comment "商品号",
	nums int unsigned not null default 1 comment "购买数量",
	
	foreign key (customer_id) references customer(customer_id),
	foreign key (goods_id) references goods(goods_id)
);


CREATE TABLE students (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	sn INT NOT NULL UNIQUE COMMENT '学号',
	name VARCHAR(20) NOT NULL,
	qq VARCHAR(20)
);

INSERT INTO students (id, sn, name) VALUES
(102, 20001, '曹孟德'),
(103, 20002, '孙仲谋');


INSERT INTO students (id, sn, name) VALUES (100, 10010, '唐大师')
ON duplicate key update sn = 10010, name = '唐大师';




