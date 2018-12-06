-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 08-10-2018 a las 22:33:58
-- Versión del servidor: 10.1.36-MariaDB
-- Versión de PHP: 7.2.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `supermercado`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `fruta`
--

CREATE TABLE `fruta` (
  `codigo` int(6) NOT NULL,
  `nombre` varchar(45) DEFAULT NULL,
  `fecha_vencimiento` date DEFAULT NULL,
  `estado` int(1) DEFAULT NULL,
  `color` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `fruta`
--

INSERT INTO `fruta` (`codigo`, `nombre`, `fecha_vencimiento`, `estado`, `color`) VALUES
(1, 'PERA', '2019-03-11', 1, NULL),
(2, 'MANZANA', '2019-03-19', 1, NULL),
(3, 'MANGO', '2019-03-29', 1, NULL),
(4, 'UVA', '2019-04-21', 1, NULL),
(5, 'BANANO', '2019-05-21', 1, NULL),
(6, 'PAPAYA', '2019-09-21', 1, NULL),
(7, 'MELON', '2019-09-29', 1, NULL),
(8, 'MELOCOTON', '2020-03-29', 1, NULL),
(9, 'GRANADILLA', '2021-03-29', 1, NULL),
(10, 'FRESA', '2020-04-29', 1, NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `verdura`
--

CREATE TABLE `verdura` (
  `codigo` int(6) NOT NULL,
  `nombre` varchar(45) DEFAULT NULL,
  `fecha_vencimiento` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `verdura`
--

INSERT INTO `verdura` (`codigo`, `nombre`, `fecha_vencimiento`) VALUES
(1, 'BROCOLI', '2018-12-11'),
(2, 'ZANAHORIA', '2018-11-11'),
(3, 'TOMARE', '2019-12-11'),
(4, 'CEBOLLA', '2020-12-11'),
(5, 'PIMENTON', '2019-11-12'),
(6, 'PAPA', '2018-09-11'),
(7, 'YUCA', '2018-03-11'),
(8, 'APIO', '2018-02-11'),
(9, 'PEREJIL', '2018-01-11'),
(10, 'PAPA CRIOLLA', '2021-12-11');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `fruta`
--
ALTER TABLE `fruta`
  ADD PRIMARY KEY (`codigo`);

--
-- Indices de la tabla `verdura`
--
ALTER TABLE `verdura`
  ADD PRIMARY KEY (`codigo`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `fruta`
--
ALTER TABLE `fruta`
  MODIFY `codigo` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT de la tabla `verdura`
--
ALTER TABLE `verdura`
  MODIFY `codigo` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
