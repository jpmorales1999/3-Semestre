-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 06-10-2018 a las 18:25:41
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
-- Base de datos: `transportes`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `camion`
--

CREATE TABLE `camion` (
  `matricula` varchar(45) NOT NULL COMMENT 'Identificador del coche',
  `modelo` varchar(45) NOT NULL,
  `tipo` varchar(45) NOT NULL,
  `potencia` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `camionero`
--

CREATE TABLE `camionero` (
  `dni` int(10) NOT NULL,
  `telefono` varchar(45) NOT NULL,
  `direccion` varchar(45) NOT NULL,
  `salario` float NOT NULL,
  `poblacion` varchar(45) NOT NULL,
  `nombre` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `camionero_camion`
--

CREATE TABLE `camionero_camion` (
  `camionero_dni` int(10) NOT NULL,
  `camion_matricula` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `paquete`
--

CREATE TABLE `paquete` (
  `codigo_paquete` int(6) NOT NULL COMMENT 'Codigo identificador del paquete',
  `descripcion` varchar(100) NOT NULL,
  `destinatario` varchar(45) NOT NULL,
  `direccion_destinatario` varchar(45) NOT NULL,
  `provincia_codigo_provincia` int(6) NOT NULL,
  `camionero_dni` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `provincia`
--

CREATE TABLE `provincia` (
  `codigo_provincia` int(6) NOT NULL COMMENT 'Codigo identifacador de la provincia',
  `nombre` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `camion`
--
ALTER TABLE `camion`
  ADD PRIMARY KEY (`matricula`);

--
-- Indices de la tabla `camionero`
--
ALTER TABLE `camionero`
  ADD PRIMARY KEY (`dni`);

--
-- Indices de la tabla `camionero_camion`
--
ALTER TABLE `camionero_camion`
  ADD PRIMARY KEY (`camionero_dni`,`camion_matricula`),
  ADD KEY `fk_camionero_has_camion_camion1` (`camion_matricula`);

--
-- Indices de la tabla `paquete`
--
ALTER TABLE `paquete`
  ADD PRIMARY KEY (`codigo_paquete`),
  ADD KEY `fk_paquete_provincia1` (`provincia_codigo_provincia`),
  ADD KEY `fk_paquete_camionero1` (`camionero_dni`);

--
-- Indices de la tabla `provincia`
--
ALTER TABLE `provincia`
  ADD PRIMARY KEY (`codigo_provincia`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `paquete`
--
ALTER TABLE `paquete`
  MODIFY `codigo_paquete` int(6) NOT NULL AUTO_INCREMENT COMMENT 'Codigo identificador del paquete';

--
-- AUTO_INCREMENT de la tabla `provincia`
--
ALTER TABLE `provincia`
  MODIFY `codigo_provincia` int(6) NOT NULL AUTO_INCREMENT COMMENT 'Codigo identifacador de la provincia';

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `camionero_camion`
--
ALTER TABLE `camionero_camion`
  ADD CONSTRAINT `fk_camionero_has_camion_camion1` FOREIGN KEY (`camion_matricula`) REFERENCES `camion` (`matricula`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_camionero_has_camion_camionero1` FOREIGN KEY (`camionero_dni`) REFERENCES `camionero` (`dni`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `paquete`
--
ALTER TABLE `paquete`
  ADD CONSTRAINT `fk_paquete_camionero1` FOREIGN KEY (`camionero_dni`) REFERENCES `camionero` (`dni`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_paquete_provincia1` FOREIGN KEY (`provincia_codigo_provincia`) REFERENCES `provincia` (`codigo_provincia`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
