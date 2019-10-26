-- MySQL dump 10.14  Distrib 5.5.60-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: class45
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
-- Current Database: `class45`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `class45` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `class45`;

--
-- Table structure for table `test`
--

DROP TABLE IF EXISTS `test`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `test` (
  `id` int(10) unsigned DEFAULT NULL,
  `name` char(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `test`
--

LOCK TABLES `test` WRITE;
/*!40000 ALTER TABLE `test` DISABLE KEYS */;
INSERT INTO `test` VALUES (1,'蔡徐坤'),(2,'吴亦凡'),(3,'鹿晗'),(1,'蔡徐坤'),(2,'吴亦凡'),(3,'鹿晗');
/*!40000 ALTER TABLE `test` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-10-26 11:27:37
[clairad@localhost ~]$ mysqldump -u root -p -B class45 > class45.sql
Enter password: 
mysqldump: Got error: 1045: "Access denied for user 'root'@'localhost' (using password: YES)" when trying to connect
[clairad@localhost ~]$ mysqldump -u root -p -B class45 > class45.sql
Enter password: 
[clairad@localhost ~]$ cat class45.sql 
-- MySQL dump 10.14  Distrib 5.5.60-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: class45
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
-- Current Database: `class45`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `class45` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `class45`;

--
-- Table structure for table `test`
--

DROP TABLE IF EXISTS `test`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `test` (
  `id` int(10) unsigned DEFAULT NULL,
  `name` char(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `test`
--

LOCK TABLES `test` WRITE;
/*!40000 ALTER TABLE `test` DISABLE KEYS */;
INSERT INTO `test` VALUES (1,'蔡徐坤'),(2,'吴亦凡'),(3,'鹿晗'),(1,'蔡徐坤'),(2,'吴亦凡'),(3,'鹿晗');
/*!40000 ALTER TABLE `test` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-10-26 11:29:10
[clairad@localhost ~]$ vim class45.sql 
[clairad@localhost ~]$ 
Connection closed by foreign host.

Disconnected from remote host(CentOS7) at 13:04:49.

Type `help' to learn how to use Xshell prompt.
[c:\~]$ 

Connecting to 192.168.18.130:22...
Connection established.
To escape to local shell, press 'Ctrl+Alt+]'.

Last login: Sat Oct 26 14:38:00 2019 from 192.168.18.1
[clairad@localhost ~]$ mysqldump -uroot -p -B class45
Enter password: 
-- MySQL dump 10.14  Distrib 5.5.60-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: class45
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
-- Current Database: `class45`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `class45` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `class45`;

--
-- Table structure for table `aitest`
--

DROP TABLE IF EXISTS `aitest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `aitest` (
  `id` int(6) unsigned zerofill NOT NULL AUTO_INCREMENT,
  `name` varchar(20) DEFAULT NULL,
  `gender` enum('男','女','保密') DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `aitest`
--

LOCK TABLES `aitest` WRITE;
/*!40000 ALTER TABLE `aitest` DISABLE KEYS */;
INSERT INTO `aitest` VALUES (000001,'金星','保密'),(000002,'郭德纲','男'),(000003,'于谦','男'),(000004,'赵本山','保密');
/*!40000 ALTER TABLE `aitest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `comtest`
--

DROP TABLE IF EXISTS `comtest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `comtest` (
  `id` int(11) DEFAULT NULL COMMENT '学号',
  `name` varchar(20) DEFAULT NULL COMMENT '姓名',
  `gender` enum('男','女','保密') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `comtest`
--

LOCK TABLES `comtest` WRITE;
/*!40000 ALTER TABLE `comtest` DISABLE KEYS */;
/*!40000 ALTER TABLE `comtest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `deftest`
--

DROP TABLE IF EXISTS `deftest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `deftest` (
  `id` int(11) DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `gender` enum('男','女','保密') DEFAULT '男'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `deftest`
--

LOCK TABLES `deftest` WRITE;
/*!40000 ALTER TABLE `deftest` DISABLE KEYS */;
INSERT INTO `deftest` VALUES (1,'蔡徐坤','男'),(2,'杨超越','男'),(3,'乔碧萝','男');
/*!40000 ALTER TABLE `deftest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `doubletest`
--

DROP TABLE IF EXISTS `doubletest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `doubletest` (
  `ftest` float DEFAULT NULL,
  `uftest` float unsigned DEFAULT NULL,
  `dtest` double(5,1) DEFAULT NULL,
  `udtest` double(5,1) unsigned DEFAULT NULL,
  `detest` decimal(7,2) DEFAULT NULL,
  `udetest` decimal(7,2) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `doubletest`
--

LOCK TABLES `doubletest` WRITE;
/*!40000 ALTER TABLE `doubletest` DISABLE KEYS */;
INSERT INTO `doubletest` VALUES (4.61289e23,4.71306e30,NULL,NULL,NULL,NULL),(NULL,NULL,-2009.3,1029.6,NULL,NULL),(NULL,NULL,-2009.3,1029.7,NULL,NULL),(NULL,NULL,NULL,NULL,-20098.00,1029.67);
/*!40000 ALTER TABLE `doubletest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `enumtest`
--

DROP TABLE IF EXISTS `enumtest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `enumtest` (
  `gender` enum('男','女','保密') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `enumtest`
--

LOCK TABLES `enumtest` WRITE;
/*!40000 ALTER TABLE `enumtest` DISABLE KEYS */;
INSERT INTO `enumtest` VALUES ('男'),('保密'),('保密'),('女');
/*!40000 ALTER TABLE `enumtest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `inttest`
--

DROP TABLE IF EXISTS `inttest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `inttest` (
  `tint` tinyint(4) DEFAULT NULL,
  `utint` tinyint(3) unsigned DEFAULT NULL,
  `sint` smallint(6) DEFAULT NULL,
  `usint` smallint(5) unsigned DEFAULT NULL,
  `mint` int(11) DEFAULT NULL,
  `uint` int(10) unsigned DEFAULT NULL,
  `bint` bigint(20) DEFAULT NULL,
  `ubint` bigint(20) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `inttest`
--

LOCK TABLES `inttest` WRITE;
/*!40000 ALTER TABLE `inttest` DISABLE KEYS */;
INSERT INTO `inttest` VALUES (100,100,NULL,NULL,NULL,NULL,NULL,NULL),(NULL,NULL,NULL,NULL,NULL,NULL,136497183,371894172984);
/*!40000 ALTER TABLE `inttest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `myclass`
--

DROP TABLE IF EXISTS `myclass`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `myclass` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `myclass`
--

LOCK TABLES `myclass` WRITE;
/*!40000 ALTER TABLE `myclass` DISABLE KEYS */;
INSERT INTO `myclass` VALUES (1,'天秀班'),(2,'老实人班');
/*!40000 ALTER TABLE `myclass` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `nulltest`
--

DROP TABLE IF EXISTS `nulltest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `nulltest` (
  `a` int(11) NOT NULL,
  `b` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `nulltest`
--

LOCK TABLES `nulltest` WRITE;
/*!40000 ALTER TABLE `nulltest` DISABLE KEYS */;
INSERT INTO `nulltest` VALUES (1,2),(2,NULL);
/*!40000 ALTER TABLE `nulltest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `primtest`
--

DROP TABLE IF EXISTS `primtest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `primtest` (
  `id` int(6) unsigned zerofill NOT NULL DEFAULT '000000',
  `name` varchar(20) NOT NULL DEFAULT '',
  `gender` enum('男','女','保密') DEFAULT NULL,
  PRIMARY KEY (`id`,`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `primtest`
--

LOCK TABLES `primtest` WRITE;
/*!40000 ALTER TABLE `primtest` DISABLE KEYS */;
INSERT INTO `primtest` VALUES (000001,'二丫','女'),(000001,'小沈阳','保密'),(000002,'沈腾','男'),(000003,'常远','男');
/*!40000 ALTER TABLE `primtest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pritest`
--

DROP TABLE IF EXISTS `pritest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pritest` (
  `id` int(6) unsigned zerofill NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `gender` enum('男','女','保密') DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pritest`
--

LOCK TABLES `pritest` WRITE;
/*!40000 ALTER TABLE `pritest` DISABLE KEYS */;
INSERT INTO `pritest` VALUES (000001,'小沈阳','保密'),(000002,'沈腾','男'),(000003,'常远','男');
/*!40000 ALTER TABLE `pritest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `student` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(20) DEFAULT NULL,
  `class_id` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `class_id` (`class_id`),
  CONSTRAINT `student_ibfk_1` FOREIGN KEY (`class_id`) REFERENCES `myclass` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (1,'吴秀波',1),(2,'蔡徐坤',1);
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `timetest`
--

DROP TABLE IF EXISTS `timetest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `timetest` (
  `id` int(11) DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `ttest` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `timetest`
--

LOCK TABLES `timetest` WRITE;
/*!40000 ALTER TABLE `timetest` DISABLE KEYS */;
INSERT INTO `timetest` VALUES (1,'蔡徐坤','2019-10-26 07:07:35'),(2,'杨超越','2019-10-26 07:07:35'),(3,'乔碧萝','2019-10-26 07:07:35'),(1,'蔡徐坤','2019-10-26 07:32:19'),(2,'杨超越','2019-10-26 07:32:19'),(3,'乔碧萝','2019-10-26 07:32:19');
/*!40000 ALTER TABLE `timetest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `untest`
--

DROP TABLE IF EXISTS `untest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `untest` (
  `id` int(6) unsigned zerofill DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `gender` enum('男','女','保密') DEFAULT NULL,
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `untest`
--

LOCK TABLES `untest` WRITE;
/*!40000 ALTER TABLE `untest` DISABLE KEYS */;
INSERT INTO `untest` VALUES (NULL,'金星','保密'),(NULL,'郭德纲','男'),(NULL,'于谦','男'),(000001,'赵本山','男');
/*!40000 ALTER TABLE `untest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `zerotest`
--

DROP TABLE IF EXISTS `zerotest`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `zerotest` (
  `id` int(6) unsigned zerofill DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `gender` enum('男','女','保密') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `zerotest`
--

LOCK TABLES `zerotest` WRITE;
/*!40000 ALTER TABLE `zerotest` DISABLE KEYS */;
INSERT INTO `zerotest` VALUES (000001,'卢本伟','男'),(000010,'毕福剑','男'),(000100,'杨永信','男');
/*!40000 ALTER TABLE `zerotest` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-10-26 17:45:04
