数据类型

1、数
bit[(m)]
tinyint [unsigned]
smallint [unsigned]
int [unsigned]
bigint [unsigned]
float[(m,d)]
double[(m,d)]
decimal(m,d)
2、字符串
char(size)
varchar(size) 21844 
3、时间
date
datetime
timestamp

约束
1、not null
2、default
3、comment
4、zerofill
5、primary key
6、auto_increment
7、unique key
8、foreign key

create table test(
	id int primary key,
	name varchar(6) not null,
	idcardnum int unique key
);

insert into test(id, name) value(1, "张三");
insert into test(id, name) value(2, "李四");
insert into test(id, name) value(3, "王五");

insert into test value(4, "张三", 112);
insert into test value(5, "王五", 211);
insert into test value(6, "李四", 112);

create table myclass(
	id int primary key,
	name varchar(6) not null
);

create table stu(
	id int primary key,
	name varchar(6) not null,
	class_id int not null,
	foreign key (class_id) references myclass(id)
);


商品goods
(商品编号goods_id，商品名goods_name, 单价unitprice, 商品类别category, 供应商provider)

create table goods (
	goods_id int unsigned primary key,
	goods_name varchar(64) not null,
	unitprice float not null,
	category varchar(32),
	provider varchar(64)
);

create table customer (
	customer_id int unsigned primary key,
	name varchar(16) not null,
	address varchar(128),
	email varchar(64) unique key,
	sex enum('男', '女'),
	card_id char(18)
);

create table purchase (
	order_id int unsigned primary key,
	customer_id int unsigned,
	goods_id int unsigned,
	nums int unsigned,
	foreign key (goods_id) references goods(goods_id),
	foreign key (customer_id) references customer(customer_id)
);


insert into stu value(7, "蔡徐坤", 1), (8, "皮几万", 2), (9, "杨超越", 1);

INSERT INTO stu (id, name, class_id) VALUES (4, "蔡徐坤", 1) ON DUPLICATE KEY UPDATE name = '唐大师', class_id = 2;

REPLACE INTO students (name, class_id) VALUES ('曹阿瞒', 2);



CREATE TABLE exam_result(
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(20) NOT NULL COMMENT '同学姓名',
    chinese float DEFAULT 0.0 COMMENT '语文成绩',
    math float DEFAULT 0.0 COMMENT '数学成绩',
    english float DEFAULT 0.0 COMMENT '英语成绩'
);


INSERT INTO exam_result(name, chinese, math, english) VALUES
('唐三藏', 67, 98, 56),
('孙悟空', 87, 78, 77),
('猪悟能', 88, 98, 90),
('曹孟德', 82, 84, 67),
('刘玄德', 55, 85, 45),
('孙权', 70, 73, 78),
('宋公明', 75, 65, 30)


REPLACE INTO exam_result (id, name, chinese, math, english) VALUES (6, '孙仲谋', 70, 73, 78); 

select name, math from exam_result;

select id, name, english from exam_result where english < 60;
select id, name, chinese from exam_result where chinese between 80 and 90;
select id, name, math from exam_result where math in (58, 59, 98, 99);

select id, name, math from exam_result where math = 58 or math = 59 or math = 98 or math = 99;

select id, name, math from exam_result where name like '孙%';

select id, name, chinese, english from exam_result where chinese > english;

孙某同学，否则要求总成绩 > 200 并且 语文成绩 < 数学成绩 并且 英语成绩 > 8

select id, name, chinese, math,  english, chinese + math + english 总分 from exam_result where name like '孙%' or (chinese + math + english > 200 and english > 80);





