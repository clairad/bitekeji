-- MySQL dump 10.14  Distrib 5.5.60-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: class81
-- ------------------------------------------------------
-- Server version	5.5.60-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `class81`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `class81` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `class81`;

--
-- Table structure for table `aitest`
--

DROP TABLE IF EXISTS `aitest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `aitest` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `aitest`
--

LOCK TABLES `aitest` WRITE;
/*!40000 ALTER TABLE `aitest` DISABLE KEYS */;
INSERT INTO `aitest` VALUES (2,'杨超越'),(17,'卢本伟'),(18,'毕福剑'),(19,'蔡徐坤'),(20,'乔碧萝'),(21,'杨颖');
/*!40000 ALTER TABLE `aitest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `altest`
--

DROP TABLE IF EXISTS `altest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `altest` (
  `col0` int(11) DEFAULT NULL,
  `col1` int(11) DEFAULT NULL,
  `col2` int(11) DEFAULT NULL,
  `col2_1` int(11) DEFAULT NULL,
  `col3_1` double DEFAULT NULL,
  `col4` int(11) DEFAULT NULL,
  `col5` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `altest`
--

LOCK TABLES `altest` WRITE;
/*!40000 ALTER TABLE `altest` DISABLE KEYS */;
/*!40000 ALTER TABLE `altest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bittest`
--

DROP TABLE IF EXISTS `bittest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bittest` (
  `b` bit(32) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bittest`
--

LOCK TABLES `bittest` WRITE;
/*!40000 ALTER TABLE `bittest` DISABLE KEYS */;
INSERT INTO `bittest` VALUES ('\0\0\0A');
/*!40000 ALTER TABLE `bittest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `commenttest`
--

DROP TABLE IF EXISTS `commenttest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `commenttest` (
  `id` int(11) NOT NULL DEFAULT '0' COMMENT '编号',
  `name` varchar(20) DEFAULT '狗剩儿' COMMENT '名字'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `commenttest`
--

LOCK TABLES `commenttest` WRITE;
/*!40000 ALTER TABLE `commenttest` DISABLE KEYS */;
/*!40000 ALTER TABLE `commenttest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
  `customer_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `address` varchar(256) DEFAULT NULL,
  `email` varchar(128) DEFAULT NULL,
  `sex` enum('男','女','保密') NOT NULL DEFAULT '保密',
  `card_id` char(18) DEFAULT NULL,
  PRIMARY KEY (`customer_id`),
  UNIQUE KEY `email` (`email`),
  UNIQUE KEY `card_id` (`card_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `defaulttest`
--

DROP TABLE IF EXISTS `defaulttest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `defaulttest` (
  `id` int(11) NOT NULL DEFAULT '0',
  `name` varchar(20) DEFAULT '狗剩儿'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `defaulttest`
--

LOCK TABLES `defaulttest` WRITE;
/*!40000 ALTER TABLE `defaulttest` DISABLE KEYS */;
INSERT INTO `defaulttest` VALUES (2,'狗剩儿'),(0,'乔碧萝殿下'),(0,NULL);
/*!40000 ALTER TABLE `defaulttest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `deltest`
--

DROP TABLE IF EXISTS `deltest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `deltest` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `deltest`
--

LOCK TABLES `deltest` WRITE;
/*!40000 ALTER TABLE `deltest` DISABLE KEYS */;
INSERT INTO `deltest` VALUES (1,'a'),(2,'b'),(3,'c'),(4,'d');
/*!40000 ALTER TABLE `deltest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `disttest`
--

DROP TABLE IF EXISTS `disttest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `disttest` (
  `id` int(11) DEFAULT NULL,
  `sn` char(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `disttest`
--

LOCK TABLES `disttest` WRITE;
/*!40000 ALTER TABLE `disttest` DISABLE KEYS */;
INSERT INTO `disttest` VALUES (1,'a'),(2,'b'),(3,'c');
/*!40000 ALTER TABLE `disttest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `enumtest`
--

DROP TABLE IF EXISTS `enumtest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `enumtest` (
  `gender` enum('男','女') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `enumtest`
--

LOCK TABLES `enumtest` WRITE;
/*!40000 ALTER TABLE `enumtest` DISABLE KEYS */;
INSERT INTO `enumtest` VALUES ('男'),('女'),('男'),('女');
/*!40000 ALTER TABLE `enumtest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `exam_result`
--

DROP TABLE IF EXISTS `exam_result`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `exam_result` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL COMMENT '同学姓名',
  `yuwen` float DEFAULT '0' COMMENT '语文成绩',
  `shuxue` float DEFAULT '0' COMMENT '数学成绩',
  `yingyu` float DEFAULT '0' COMMENT '英语成绩',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `exam_result`
--

LOCK TABLES `exam_result` WRITE;
/*!40000 ALTER TABLE `exam_result` DISABLE KEYS */;
INSERT INTO `exam_result` VALUES (1,'胖到没裤子',134,98,56),(3,'熊猫队长',176,98,90),(4,'不来也不去',140,90,67),(5,'半日光辉',110,115,45),(6,'卫什么',140,73,78),(7,'嗑药小王子',150,95,30);
/*!40000 ALTER TABLE `exam_result` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `goods`
--

DROP TABLE IF EXISTS `goods`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `goods` (
  `goods_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `goods_name` varchar(128) NOT NULL,
  `unitprice` decimal(8,2) NOT NULL,
  `category` varchar(64) NOT NULL COMMENT '商品类别',
  `provider` varchar(128) DEFAULT NULL COMMENT '供应商',
  PRIMARY KEY (`goods_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `goods`
--

LOCK TABLES `goods` WRITE;
/*!40000 ALTER TABLE `goods` DISABLE KEYS */;
/*!40000 ALTER TABLE `goods` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `intest`
--

DROP TABLE IF EXISTS `intest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `intest` (
  `id` int(10) unsigned DEFAULT NULL,
  `name` varchar(20) NOT NULL,
  KEY `name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `intest`
--

LOCK TABLES `intest` WRITE;
/*!40000 ALTER TABLE `intest` DISABLE KEYS */;
/*!40000 ALTER TABLE `intest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `memo`
--

DROP TABLE IF EXISTS `memo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `memo` (
  `memoId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `title` varchar(255) NOT NULL,
  `textInfo` varchar(1024) NOT NULL DEFAULT '',
  `textPrivateFlag` tinyint(1) NOT NULL DEFAULT '0',
  `color` int(10) unsigned NOT NULL DEFAULT '0',
  `clockFlag` tinyint(1) NOT NULL DEFAULT '0',
  `createTime` datetime NOT NULL,
  `modifyTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `groupId` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`memoId`),
  KEY `groupId` (`groupId`),
  CONSTRAINT `memo_ibfk_1` FOREIGN KEY (`groupId`) REFERENCES `memoGroup` (`groupId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `memo`
--

LOCK TABLES `memo` WRITE;
/*!40000 ALTER TABLE `memo` DISABLE KEYS */;
/*!40000 ALTER TABLE `memo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `memoGroup`
--

DROP TABLE IF EXISTS `memoGroup`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `memoGroup` (
  `groupId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `groupName` varchar(255) NOT NULL,
  `createTime` datetime NOT NULL,
  `modifyTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`groupId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `memoGroup`
--

LOCK TABLES `memoGroup` WRITE;
/*!40000 ALTER TABLE `memoGroup` DISABLE KEYS */;
INSERT INTO `memoGroup` VALUES (1,'defaultGroup','2019-12-15 15:23:43','2019-12-15 07:23:43');
/*!40000 ALTER TABLE `memoGroup` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `memoShare`
--

DROP TABLE IF EXISTS `memoShare`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `memoShare` (
  `shareId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `memoId` int(10) unsigned NOT NULL,
  `otherMsg` varchar(512) DEFAULT NULL,
  `shareTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`shareId`),
  KEY `memoId` (`memoId`),
  CONSTRAINT `memoShare_ibfk_1` FOREIGN KEY (`memoId`) REFERENCES `memo` (`memoId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `memoShare`
--

LOCK TABLES `memoShare` WRITE;
/*!40000 ALTER TABLE `memoShare` DISABLE KEYS */;
/*!40000 ALTER TABLE `memoShare` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `nulltest`
--

DROP TABLE IF EXISTS `nulltest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `nulltest` (
  `id` int(11) NOT NULL,
  `name` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `nulltest`
--

LOCK TABLES `nulltest` WRITE;
/*!40000 ALTER TABLE `nulltest` DISABLE KEYS */;
INSERT INTO `nulltest` VALUES (17,'卢本伟'),(1,NULL);
/*!40000 ALTER TABLE `nulltest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `numtest`
--

DROP TABLE IF EXISTS `numtest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `numtest` (
  `uti` tinyint(3) unsigned DEFAULT NULL,
  `ti` tinyint(4) DEFAULT NULL,
  `usi` smallint(5) unsigned DEFAULT NULL,
  `si` smallint(6) DEFAULT NULL,
  `ui` int(10) unsigned DEFAULT NULL,
  `i` int(11) DEFAULT NULL,
  `ubi` bigint(20) unsigned DEFAULT NULL,
  `bi` bigint(20) DEFAULT NULL,
  `uf` float unsigned DEFAULT NULL,
  `f` float DEFAULT NULL,
  `ud` double unsigned DEFAULT NULL,
  `d` double DEFAULT NULL,
  `ude` decimal(6,2) unsigned DEFAULT NULL,
  `de` decimal(6,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `numtest`
--

LOCK TABLES `numtest` WRITE;
/*!40000 ALTER TABLE `numtest` DISABLE KEYS */;
INSERT INTO `numtest` VALUES (NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,9999.99),(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,-9999.99),(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,9999.99,NULL),(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,9999.99,NULL);
/*!40000 ALTER TABLE `numtest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `person`
--

DROP TABLE IF EXISTS `person`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `person` (
  `intime` datetime DEFAULT NULL,
  `toilet_id` int(10) unsigned NOT NULL,
  `hole_id` int(10) unsigned DEFAULT NULL,
  KEY `toilet_id` (`toilet_id`),
  CONSTRAINT `person_ibfk_1` FOREIGN KEY (`toilet_id`) REFERENCES `toilet` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `person`
--

LOCK TABLES `person` WRITE;
/*!40000 ALTER TABLE `person` DISABLE KEYS */;
INSERT INTO `person` VALUES (NULL,5,NULL);
/*!40000 ALTER TABLE `person` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pktest`
--

DROP TABLE IF EXISTS `pktest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pktest` (
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `name` varchar(20) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pktest`
--

LOCK TABLES `pktest` WRITE;
/*!40000 ALTER TABLE `pktest` DISABLE KEYS */;
INSERT INTO `pktest` VALUES (1,'毕福剑'),(2,'蔡徐坤'),(17,'卢本伟');
/*!40000 ALTER TABLE `pktest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pktest2`
--

DROP TABLE IF EXISTS `pktest2`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pktest2` (
  `id` int(10) unsigned NOT NULL DEFAULT '0',
  `name` varchar(20) NOT NULL,
  PRIMARY KEY (`id`,`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pktest2`
--

LOCK TABLES `pktest2` WRITE;
/*!40000 ALTER TABLE `pktest2` DISABLE KEYS */;
INSERT INTO `pktest2` VALUES (1,'毕福剑'),(2,'杨超越'),(2,'蔡徐坤'),(17,'卢本伟');
/*!40000 ALTER TABLE `pktest2` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `purchase`
--

DROP TABLE IF EXISTS `purchase`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `purchase` (
  `order_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `customer_id` int(10) unsigned NOT NULL,
  `goods_id` int(10) unsigned NOT NULL,
  `nums` int(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`order_id`),
  KEY `customer_id` (`customer_id`),
  KEY `goods_id` (`goods_id`),
  CONSTRAINT `purchase_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`),
  CONSTRAINT `purchase_ibfk_2` FOREIGN KEY (`goods_id`) REFERENCES `goods` (`goods_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `purchase`
--

LOCK TABLES `purchase` WRITE;
/*!40000 ALTER TABLE `purchase` DISABLE KEYS */;
/*!40000 ALTER TABLE `purchase` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `students`
--

DROP TABLE IF EXISTS `students`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `students` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `sn` int(11) NOT NULL COMMENT '学号',
  `name` varchar(20) NOT NULL,
  `qq` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `sn` (`sn`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `students`
--

LOCK TABLES `students` WRITE;
/*!40000 ALTER TABLE `students` DISABLE KEYS */;
INSERT INTO `students` VALUES (1,10001,'郭德纲',NULL),(2,10002,'杨颖','123456789'),(4,10004,'李彦宏','123456789'),(7,10003,'大师兄','987654321');
/*!40000 ALTER TABLE `students` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `test`
--

DROP TABLE IF EXISTS `test`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `test` (
  `id` int(11) DEFAULT NULL,
  `name` char(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `test`
--

LOCK TABLES `test` WRITE;
/*!40000 ALTER TABLE `test` DISABLE KEYS */;
INSERT INTO `test` VALUES (1,'A'),(2,'a'),(3,'B'),(4,'b');
/*!40000 ALTER TABLE `test` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `timetest`
--

DROP TABLE IF EXISTS `timetest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `timetest` (
  `id` int(11) DEFAULT NULL,
  `d` date DEFAULT NULL,
  `dt` datetime DEFAULT NULL,
  `ts` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `timetest`
--

LOCK TABLES `timetest` WRITE;
/*!40000 ALTER TABLE `timetest` DISABLE KEYS */;
INSERT INTO `timetest` VALUES (1,NULL,NULL,'2019-12-04 11:40:16'),(NULL,NULL,'2019-12-04 19:44:27','2019-12-04 11:44:27');
/*!40000 ALTER TABLE `timetest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `toilet`
--

DROP TABLE IF EXISTS `toilet`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `toilet` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `xpos` double NOT NULL,
  `ypos` double NOT NULL,
  `addres` varchar(100) DEFAULT NULL,
  `holenum` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `toilet`
--

LOCK TABLES `toilet` WRITE;
/*!40000 ALTER TABLE `toilet` DISABLE KEYS */;
INSERT INTO `toilet` VALUES (1,0,0,NULL,1),(2,0,0,NULL,1),(3,0,0,NULL,1),(4,0,0,NULL,1),(5,0,0,NULL,1),(6,0,0,NULL,1);
/*!40000 ALTER TABLE `toilet` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `trantest`
--

DROP TABLE IF EXISTS `trantest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `trantest` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `trantest`
--

LOCK TABLES `trantest` WRITE;
/*!40000 ALTER TABLE `trantest` DISABLE KEYS */;
INSERT INTO `trantest` VALUES (1,'特朗普'),(2,'奥巴马'),(3,'林肯'),(4,'尼克松');
/*!40000 ALTER TABLE `trantest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `unitest`
--

DROP TABLE IF EXISTS `unitest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `unitest` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(20) NOT NULL,
  `email` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `unitest`
--

LOCK TABLES `unitest` WRITE;
/*!40000 ALTER TABLE `unitest` DISABLE KEYS */;
INSERT INTO `unitest` VALUES (1,'毕福剑','123.com'),(17,'卢本伟',NULL);
/*!40000 ALTER TABLE `unitest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `zftest`
--

DROP TABLE IF EXISTS `zftest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `zftest` (
  `id` int(5) unsigned zerofill DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `zftest`
--

LOCK TABLES `zftest` WRITE;
/*!40000 ALTER TABLE `zftest` DISABLE KEYS */;
INSERT INTO `zftest` VALUES (00010),(00100),(00007),(01002),(100000);
/*!40000 ALTER TABLE `zftest` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-12-15 15:29:17