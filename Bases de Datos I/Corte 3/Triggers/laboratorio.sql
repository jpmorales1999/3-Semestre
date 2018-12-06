-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 04-11-2018 a las 19:01:27
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
-- Base de datos: `laboratorio`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cargos`
--

CREATE TABLE `cargos` (
  `nro` int(6) NOT NULL,
  `fecha` datetime DEFAULT NULL,
  `id_cliente` varchar(12) DEFAULT NULL,
  `valor` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `cargos`
--

INSERT INTO `cargos` (`nro`, `fecha`, `id_cliente`, `valor`) VALUES
(3, NULL, '0', 40);

--
-- Disparadores `cargos`
--
DELIMITER $$
CREATE TRIGGER `cargo_AI` AFTER INSERT ON `cargos` FOR EACH ROW BEGIN
DECLARE saldos FLOAT;
SELECT saldo INTO saldos FROM cartera WHERE id_cliente = new.id_cliente;
INSERT INTO extracto(fecha, nro, id_cliente, operacion, valor, saldo) VALUES
(now(), NEW.nro, NEW.id_cliente, "CARGO", new.valor, saldos+NEW.valor);
UPDATE cartera SET saldo = saldos+NEW.valor WHERE id_cliente = NEW.id_cliente;
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cartera`
--

CREATE TABLE `cartera` (
  `id_cliente` varchar(12) DEFAULT NULL,
  `cliente` varchar(35) DEFAULT NULL,
  `saldo` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `cartera`
--

INSERT INTO `cartera` (`id_cliente`, `cliente`, `saldo`) VALUES
('0', 'RAMON', 800);

--
-- Disparadores `cartera`
--
DELIMITER $$
CREATE TRIGGER `actu_cartera` AFTER UPDATE ON `cartera` FOR EACH ROW BEGIN
INSERT INTO extracto(fecha, nro, id_cliente, operacion, valor, saldo) VALUES
(now(), 0, NEW.id_cliente, "ACTUALIZACION", 0, 0);
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `cuenta` AFTER INSERT ON `cartera` FOR EACH ROW INSERT INTO extracto (fecha, nro, id_cliente, operacion, valor, saldo) VALUES (now(), 0, NEW.id_cliente, "Creacion CTA", 0, 0)
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `extracto`
--

CREATE TABLE `extracto` (
  `fecha` datetime DEFAULT NULL,
  `nro` int(6) DEFAULT NULL,
  `id_cliente` varchar(12) DEFAULT NULL,
  `operacion` varchar(15) DEFAULT NULL,
  `valor` float DEFAULT NULL,
  `saldo` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `extracto`
--

INSERT INTO `extracto` (`fecha`, `nro`, `id_cliente`, `operacion`, `valor`, `saldo`) VALUES
('2018-11-02 17:59:48', 0, '0', 'Creacion CTA', 0, 0),
('2018-11-04 12:17:28', 1, '0', 'Pago', 10, 490),
('2018-11-04 12:25:52', 2, '0', 'Pago', 30, 460),
('2018-11-04 12:37:39', 3, '0', 'CARGO', 40, 500),
('2018-11-04 12:51:02', 0, '0', 'ACTUALIZACION', 0, 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pagos`
--

CREATE TABLE `pagos` (
  `nro` int(6) NOT NULL,
  `fecha` datetime DEFAULT NULL,
  `id_cliente` varchar(12) DEFAULT NULL,
  `valor` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `pagos`
--

INSERT INTO `pagos` (`nro`, `fecha`, `id_cliente`, `valor`) VALUES
(1, NULL, '0', 10),
(2, NULL, '0', 30);

--
-- Disparadores `pagos`
--
DELIMITER $$
CREATE TRIGGER `saldocartera` AFTER INSERT ON `pagos` FOR EACH ROW BEGIN
DECLARE saldos float;
SELECT saldo INTO saldos FROM cartera WHERE id_cliente=new.id_cliente;
INSERT INTO extracto (fecha, nro, id_cliente, operacion, valor, saldo) VALUES
(now(),new.nro,new.id_cliente,"Pago",new.valor,saldos-new.valor);
update cartera set saldo = saldos-new.valor where id_cliente = new.id_cliente;
END
$$
DELIMITER ;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `cargos`
--
ALTER TABLE `cargos`
  ADD PRIMARY KEY (`nro`);

--
-- Indices de la tabla `pagos`
--
ALTER TABLE `pagos`
  ADD PRIMARY KEY (`nro`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `cargos`
--
ALTER TABLE `cargos`
  MODIFY `nro` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT de la tabla `pagos`
--
ALTER TABLE `pagos`
  MODIFY `nro` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
