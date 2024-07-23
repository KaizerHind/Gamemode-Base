-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 23-07-2024 a las 03:43:33
-- Versión del servidor: 10.4.32-MariaDB
-- Versión de PHP: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `dbserver`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `users`
--

CREATE TABLE `users` (
  `ID` int(11) NOT NULL,
  `TypeAdmin` int(20) NOT NULL DEFAULT 0,
  `Name` varchar(25) NOT NULL,
  `Password` varchar(65) NOT NULL,
  `Skin` int(3) NOT NULL,
  `Gender` int(11) NOT NULL,
  `Age` int(2) NOT NULL,
  `Score` int(4) NOT NULL DEFAULT 1,
  `Money` int(11) DEFAULT 5000,
  `Health` float NOT NULL DEFAULT 100,
  `Armour` float NOT NULL DEFAULT 0,
  `Died` smallint(3) NOT NULL,
  `Country` varchar(100) NOT NULL,
  `Account_Register` varchar(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci DEFAULT '0',
  `Acc_Last_Session` varchar(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci DEFAULT '0',
  `--------` varchar(0) DEFAULT NULL,
  `InteriorID` int(10) NOT NULL DEFAULT 0,
  `VirtualWorldID` int(10) NOT NULL DEFAULT 0,
  `PosX` float DEFAULT 0,
  `PosY` float DEFAULT 0,
  `PosZ` float DEFAULT 0,
  `PosA` float DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `users`
--
ALTER TABLE `users`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
