
CREATE TABLE test2(
	id int not null,
	name varchar(10) not null,
	sex varchar(3)
);

INSERT INTO test2(id, name, sex) VALUE(1, "蔡徐坤", '男');
INSERT INTO test2(id, name) VALUE(2, "冯提莫");


CREATE TABLE test(
	id int not null,
	name varchar(10) not null,
	age int unsigned default 18,
	sex varchar(3)
);

INSERT INTO test(id, name, sex) VALUE(1, "蔡徐坤", '男');
INSERT INTO test(id, name, age) VALUE(2, "冯提莫", 20);

CREATE TABLE test(
	id int not null comment '学号',
	name varchar(10) not null,
	sex varchar(3)
);

CREATE TABLE test(
	id int(4) unsigned zerofill,
	name varchar(10) not null,
	sex varchar(3)
);


CREATE TABLE test(
	id int(4) unsigned primary key,
	name varchar(10) not null,
	sex varchar(3)
);

INSERT INTO test(id, name, sex) VALUE(1, "吴亦凡", '男');
INSERT INTO test(id, name, age) VALUE(2, "杨超越", '女');

CREATE TABLE test(
	id int unsigned,
	course int unsigned,
	sex varchar(3),
	primary key(id, course)
);

CREATE TABLE test(
	id int(4) unsigned primary key auto_increment,
	name varchar(10) not null,
	sex varchar(3)
);

INSERT INTO test(name, sex) VALUE("吴亦凡", '男'),("杨超越", '女'),("蔡徐坤", '男'),("卢本伟", '男'),("毕福剑", '男');

CREATE TABLE test(
	id int(4) unsigned unique,
	name varchar(10) not null,
	sex varchar(3)
);

CREATE TABLE main(
	class_id int unsigned primary key auto_increment,
	name varchar(20) not null
);

CREATE TABLE stu(
	id int unsigned primary key auto_increment,
	name varchar(20) not null,
	class_id int unsigned,
	foreign key(class_id) references main(class_id)
);


商品goods(商品编号goods_id，商品名goods_name, 单价unitprice, 商品类别category, 供应商provider) 

CREATE TABLE goods(
	goods_id int unsigned primary key,
	goods_name varchar(128) not null,
	unitprice float(8,2) default 0.00,
	category varchar(32) not null,
	provider varchar(128)
);

客户customer(客户号customer_id,姓名name,住址address,邮箱email,性别sex，身份证card_id

CREATE TABLE customer(
	customer_id int unsigned primary key,
	name varchar(16) not null,
	address varchar(256),
	email varchar(128) unique,
	sex enum("男","女"),
	card_id char(18)
);

购买purchase(购买订单号order_id,客户号customer_id,商品号goods_id,购买数量nums)

CREATE TABLE purchase(
	order_id int unsigned primary key,
	customer_id int unsigned not null,
	goods_id int unsigned not null,
	nums int unsigned default 1
);

