
CREATE TABLE students (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
	sn INT NOT NULL UNIQUE COMMENT '学号',
	name VARCHAR(20) NOT NULL,
	qq VARCHAR(20)
);

1、表名后什么都不加
INSERT INTO students VALUES (100, 10000, '唐三藏', NULL);
INSERT INTO students VALUES (101, 10001, '孙悟空', '11111');

2、可以用逗号隔开多组输入

INSERT INTO students (id, sn, name) VALUES (102, 20001, '曹孟德'), (103, 20002, '孙仲谋');

3、有则覆盖，无则新增
INSERT INTO students (id, sn, name) VALUES (100, 10010, '唐大师') ON DUPLICATE KEY UPDATE sn = 10010, name = '唐大师';

INSERT INTO students (sn, name) VALUES (10086, '牛魔王') ON DUPLICATE KEY UPDATE sn = 10010, name = '牛魔王';
