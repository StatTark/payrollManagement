-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Anamakine: 127.0.0.1
-- Üretim Zamanı: 22 Ara 2020, 12:44:17
-- Sunucu sürümü: 10.4.16-MariaDB
-- PHP Sürümü: 7.4.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Veritabanı: `payroll_managament`
--

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `company`
--

CREATE TABLE `company` (
  `comId` int(11) NOT NULL,
  `depId` int(11) DEFAULT NULL,
  `companyName` varchar(100) COLLATE utf8_turkish_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `company`
--

INSERT INTO `company` (`comId`, `depId`, `companyName`) VALUES
(1, 1, 'ARSTECH');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `departments`
--

CREATE TABLE `departments` (
  `depId` int(11) NOT NULL,
  `managerId` int(11) DEFAULT NULL,
  `depName` varchar(50) COLLATE utf8_turkish_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `departments`
--

INSERT INTO `departments` (`depId`, `managerId`, `depName`) VALUES
(1, 5, 'IT'),
(2, 9, 'Purchasing'),
(3, 4, 'Human Resources'),
(4, 10, 'Advertisement'),
(5, 11, 'Public Relations');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `employees`
--

CREATE TABLE `employees` (
  `empId` int(11) NOT NULL,
  `depId` int(11) DEFAULT NULL,
  `titId` int(11) DEFAULT NULL,
  `personId` int(11) DEFAULT NULL,
  `startDate` timestamp NULL DEFAULT current_timestamp(),
  `sumOvertime` int(11) DEFAULT NULL,
  `salary` decimal(10,4) DEFAULT NULL,
  `timeOfFire` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `employees`
--

INSERT INTO `employees` (`empId`, `depId`, `titId`, `personId`, `startDate`, `sumOvertime`, `salary`, `timeOfFire`) VALUES
(1, 5, 1, 1, '0000-00-00 00:00:00', 10, '4000.0000', NULL),
(2, 4, 1, 8, '0000-00-00 00:00:00', 0, '3850.0000', NULL),
(3, 3, 2, 5, '0000-00-00 00:00:00', 40, '9000.0000', NULL),
(4, 3, 3, 6, '0000-00-00 00:00:00', 20, '10000.0000', NULL),
(5, 1, 3, 3, '0000-00-00 00:00:00', 0, '6600.0000', NULL),
(6, 1, 2, 2, '0000-00-00 00:00:00', 40, '6050.0000', NULL),
(7, 2, 2, 4, '0000-00-00 00:00:00', NULL, '8500.0000', NULL),
(8, 3, 2, 7, '0000-00-00 00:00:00', NULL, '8000.0000', NULL),
(9, 2, 3, 9, '0000-00-00 00:00:00', NULL, '10000.0000', NULL),
(10, 4, 3, 10, '0000-00-00 00:00:00', NULL, '10000.0000', NULL),
(11, 5, 3, 11, '0000-00-00 00:00:00', NULL, '10000.0000', NULL),
(13, 5, 1, 17, '2020-12-21 17:55:02', 30, '750.0000', NULL),
(14, 3, 1, 18, '2020-12-22 11:39:06', 50, '1000.0000', NULL);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `payments`
--

CREATE TABLE `payments` (
  `paymentsId` int(11) NOT NULL,
  `empId` int(11) DEFAULT NULL,
  `payment` double DEFAULT NULL,
  `time` date NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `payments`
--

INSERT INTO `payments` (`paymentsId`, `empId`, `payment`, `time`) VALUES
(1, 10, 10000, '2020-12-20'),
(2, 1, 4000, '2020-12-22'),
(3, 2, 3850, '2020-12-22'),
(4, 3, 9000, '2020-12-22'),
(5, 4, 10000, '2020-12-22'),
(6, 5, 6600, '2020-12-22'),
(7, 6, 6050, '2020-12-22'),
(8, 7, 8500, '2020-12-22'),
(9, 8, 8000, '2020-12-22'),
(10, 9, 10000, '2020-12-22'),
(11, 10, 10000, '2020-12-22'),
(12, 11, 10000, '2020-12-22'),
(13, 13, 750, '2020-12-22'),
(14, 14, 1000, '2020-12-22');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `person`
--

CREATE TABLE `person` (
  `personId` int(11) NOT NULL,
  `name` varchar(40) COLLATE utf8_turkish_ci DEFAULT NULL,
  `dateOfBirth` date DEFAULT NULL,
  `gender` varchar(6) COLLATE utf8_turkish_ci DEFAULT NULL,
  `phoneNumber` varchar(12) COLLATE utf8_turkish_ci DEFAULT NULL,
  `address` varchar(200) COLLATE utf8_turkish_ci DEFAULT NULL,
  `email` varchar(150) COLLATE utf8_turkish_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `person`
--

INSERT INTO `person` (`personId`, `name`, `dateOfBirth`, `gender`, `phoneNumber`, `address`, `email`) VALUES
(1, 'Brah brahson', '1990-08-10', 'Male', '905050505', 'Yolo Mahallesi.\r\nBrah Caddesi.\r\n1881. Sokak\r\nNo:209\r\nKat: 14', 'mymail@arstech.com'),
(2, 'Erwin Rommel', '1944-10-14', 'Male', '905050505', 'Yolo Mahallesi.\r\nBrah Caddesi.\r\n1881. Sokak\r\nNo:209\r\nKat: 14', 'mymail@arstech.com'),
(3, 'Erich von Manstein', '1887-11-24', 'Male', '905050505', 'Yolo Mahallesi.\r\nBrah Caddesi.\r\n1881. Sokak\r\nNo:209\r\nKat: 14', 'mymail@arstech.com'),
(4, 'Heinz Guderian', '1888-04-15', 'Male', '905050505', 'Yolo Mahallesi.\r\nBrah Caddesi.\r\n1881. Sokak\r\nNo:209\r\nKat: 14', 'mymail@arstech.com'),
(5, 'Emir Timur', '1339-04-09', 'Male', '905050505', 'Semerkand Mahallesi.\r\nBrah Caddesi.\r\n1881. Sokak\r\nNo:209\r\nKat: 14', 'mymail@arstech.com'),
(6, 'Tomris Hatun', '0006-06-06', 'Female', '905050505', 'Yolo Mahallesi.\r\nBrah Caddesi.\r\n1881. Sokak\r\nNo:209\r\nKat: 14', 'mymail@arstech.com'),
(7, 'Sabiha Gokcen', '1913-05-22', 'Female', '905050505', 'Ankara Mahallesi.\r\nBrah Caddesi.\r\n1881. Sokak\r\nNo:209\r\nKat: 14', 'mymail@arstech.com'),
(8, 'Lookat ThisDude', '1994-12-12', 'Male', '905050505', 'Yolo Mahallesi.\r\nBrah Caddesi.\r\n1881. Sokak\r\nNo:209\r\nKat: 14', 'mymail@arstech.com'),
(9, 'Ahmet Tarik Bayburutlu', '2000-05-05', 'Male', '9051234', 'Yildirim mah. Bilmem ne cad.', 'crayziboi@hotfire.com'),
(10, 'Pelin Baykaliguess', '1999-05-05', 'Female', '9051234', 'Yildirim mah. Bilmem ne cad.', 'kek@kek.com'),
(11, 'Asude Idontknow', '1999-05-05', 'Female', '9051234', 'Yildirim mah. Bilmem ne cad.', 'mail@mail.com'),
(17, 'Tarik Sahin', '1992-12-12', 'Male', '123', '123 ma', '321'),
(18, 'Ornek Emp', '2000-12-12', 'male', '90123123', 'asd das asd', 'asdasd@');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `titles`
--

CREATE TABLE `titles` (
  `titId` int(11) NOT NULL,
  `titleName` varchar(50) COLLATE utf8_turkish_ci DEFAULT NULL,
  `perHourCost` double DEFAULT NULL,
  `workHourPerMonth` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `titles`
--

INSERT INTO `titles` (`titId`, `titleName`, `perHourCost`, `workHourPerMonth`) VALUES
(1, 'Junior Worker', 30, 160),
(2, 'Senior Worker', 50, 160),
(3, 'Manager', 75, 160);

--
-- Dökümü yapılmış tablolar için indeksler
--

--
-- Tablo için indeksler `company`
--
ALTER TABLE `company`
  ADD PRIMARY KEY (`comId`),
  ADD KEY `depId` (`depId`);

--
-- Tablo için indeksler `departments`
--
ALTER TABLE `departments`
  ADD PRIMARY KEY (`depId`);

--
-- Tablo için indeksler `employees`
--
ALTER TABLE `employees`
  ADD PRIMARY KEY (`empId`),
  ADD KEY `depId` (`depId`,`titId`,`personId`),
  ADD KEY `titId` (`titId`),
  ADD KEY `personId` (`personId`);

--
-- Tablo için indeksler `payments`
--
ALTER TABLE `payments`
  ADD PRIMARY KEY (`paymentsId`),
  ADD KEY `empId` (`empId`);

--
-- Tablo için indeksler `person`
--
ALTER TABLE `person`
  ADD PRIMARY KEY (`personId`);

--
-- Tablo için indeksler `titles`
--
ALTER TABLE `titles`
  ADD PRIMARY KEY (`titId`);

--
-- Dökümü yapılmış tablolar için AUTO_INCREMENT değeri
--

--
-- Tablo için AUTO_INCREMENT değeri `company`
--
ALTER TABLE `company`
  MODIFY `comId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- Tablo için AUTO_INCREMENT değeri `departments`
--
ALTER TABLE `departments`
  MODIFY `depId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Tablo için AUTO_INCREMENT değeri `employees`
--
ALTER TABLE `employees`
  MODIFY `empId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- Tablo için AUTO_INCREMENT değeri `payments`
--
ALTER TABLE `payments`
  MODIFY `paymentsId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- Tablo için AUTO_INCREMENT değeri `person`
--
ALTER TABLE `person`
  MODIFY `personId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- Tablo için AUTO_INCREMENT değeri `titles`
--
ALTER TABLE `titles`
  MODIFY `titId` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Dökümü yapılmış tablolar için kısıtlamalar
--

--
-- Tablo kısıtlamaları `company`
--
ALTER TABLE `company`
  ADD CONSTRAINT `company_ibfk_1` FOREIGN KEY (`depId`) REFERENCES `departments` (`depId`);

--
-- Tablo kısıtlamaları `employees`
--
ALTER TABLE `employees`
  ADD CONSTRAINT `employees_ibfk_1` FOREIGN KEY (`depId`) REFERENCES `departments` (`depId`),
  ADD CONSTRAINT `employees_ibfk_2` FOREIGN KEY (`titId`) REFERENCES `titles` (`titId`),
  ADD CONSTRAINT `employees_ibfk_3` FOREIGN KEY (`personId`) REFERENCES `person` (`personId`);

--
-- Tablo kısıtlamaları `payments`
--
ALTER TABLE `payments`
  ADD CONSTRAINT `payments_ibfk_1` FOREIGN KEY (`empId`) REFERENCES `employees` (`empId`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
