
create database class81;

use class81;

create table test(
	id int,
	name char(20)
);

insert into test value(1, "蔡徐坤"), (2, "乔碧萝");


--[] {} |

--[] 可省略字段
--{} 不可省略字段
--|  多选一

--A [B | C | D] E {F | G} [H]


create database if not exists test2 charset=gbk;

create database if not exists test2 collate utf8_bin;


insert into test value(1, "A"), (2, "a"), (3, "B"), (4, "b");

--bit

create table bittest(b bit(32));


create table numtest(
	uti tinyint unsigned,
	ti tinyint,
	usi smallint unsigned,
	si smallint,
	ui int unsigned,
	i int,
	ubi bigint unsigned,
	bi bigint,
	
	uf float unsigned,
	f float,
	ud double unsigned,
	d double,
	ude decimal unsigned,
	de decimal
);

insert into numtest(uti) value(300);
insert into numtest(ubi) value(-1);
insert into numtest(si) value(50000);





