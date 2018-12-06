-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 24-10-2018 a las 01:11:58
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
-- Base de datos: `flota_autobus`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `autobus`
--

CREATE TABLE `autobus` (
  `idautobus` int(6) NOT NULL,
  `color` varchar(45) NOT NULL,
  `estado` varchar(45) NOT NULL,
  `placa` int(10) NOT NULL,
  `modelo_idmodelo` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `autobus_incidencia`
--

CREATE TABLE `autobus_incidencia` (
  `autobus_idautobus` int(6) NOT NULL,
  `incidencia_idincidencia` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `horario`
--

CREATE TABLE `horario` (
  `idhorario` int(6) NOT NULL,
  `hora_llegada` time NOT NULL,
  `hora_salida` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `incidencia`
--

CREATE TABLE `incidencia` (
  `idincidencia` int(6) NOT NULL,
  `tipo_incidencia` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `incidencia_parte`
--

CREATE TABLE `incidencia_parte` (
  `incidencia_idincidencia` int(6) NOT NULL,
  `parte_idparte` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ingreso`
--

CREATE TABLE `ingreso` (
  `idingreso` int(6) NOT NULL,
  `hora` time NOT NULL,
  `viajero_sub` int(3) NOT NULL,
  `viajero_baj` int(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ingreso_parada`
--

CREATE TABLE `ingreso_parada` (
  `ingreso_idingreso` int(6) NOT NULL,
  `parada_idparada` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `linea`
--

CREATE TABLE `linea` (
  `idlinea` int(6) NOT NULL,
  `num_linea` int(3) NOT NULL,
  `nombre` varchar(45) NOT NULL,
  `autobus_idautobus` int(6) NOT NULL,
  `parada_idparada` int(6) NOT NULL,
  `horario_idhorario` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `modelo`
--

CREATE TABLE `modelo` (
  `idmodelo` int(6) NOT NULL,
  `modelo` varchar(45) NOT NULL,
  `capacidad` int(3) NOT NULL,
  `combustible` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `parada`
--

CREATE TABLE `parada` (
  `idparada` int(6) NOT NULL,
  `numero` int(3) DEFAULT NULL,
  `nombre` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `parte`
--

CREATE TABLE `parte` (
  `idparte` int(6) NOT NULL,
  `fecha` date NOT NULL,
  `coste` float NOT NULL,
  `descripcion` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `autobus`
--
ALTER TABLE `autobus`
  ADD PRIMARY KEY (`idautobus`),
  ADD KEY `fk_autobus_modelo` (`modelo_idmodelo`);

--
-- Indices de la tabla `autobus_incidencia`
--
ALTER TABLE `autobus_incidencia`
  ADD PRIMARY KEY (`autobus_idautobus`,`incidencia_idincidencia`),
  ADD KEY `fk_autobus_has_incidencia_incidencia1` (`incidencia_idincidencia`);

--
-- Indices de la tabla `horario`
--
ALTER TABLE `horario`
  ADD PRIMARY KEY (`idhorario`);

--
-- Indices de la tabla `incidencia`
--
ALTER TABLE `incidencia`
  ADD PRIMARY KEY (`idincidencia`);

--
-- Indices de la tabla `incidencia_parte`
--
ALTER TABLE `incidencia_parte`
  ADD PRIMARY KEY (`incidencia_idincidencia`,`parte_idparte`),
  ADD KEY `fk_incidencia_has_parte_parte1` (`parte_idparte`);

--
-- Indices de la tabla `ingreso`
--
ALTER TABLE `ingreso`
  ADD PRIMARY KEY (`idingreso`);

--
-- Indices de la tabla `ingreso_parada`
--
ALTER TABLE `ingreso_parada`
  ADD PRIMARY KEY (`ingreso_idingreso`,`parada_idparada`),
  ADD KEY `fk_ingreso_has_parada_parada1` (`parada_idparada`);

--
-- Indices de la tabla `linea`
--
ALTER TABLE `linea`
  ADD PRIMARY KEY (`idlinea`),
  ADD KEY `fk_linea_autobus1` (`autobus_idautobus`),
  ADD KEY `fk_linea_parada1` (`parada_idparada`),
  ADD KEY `fk_linea_horario1` (`horario_idhorario`);

--
-- Indices de la tabla `modelo`
--
ALTER TABLE `modelo`
  ADD PRIMARY KEY (`idmodelo`);

--
-- Indices de la tabla `parada`
--
ALTER TABLE `parada`
  ADD PRIMARY KEY (`idparada`);

--
-- Indices de la tabla `parte`
--
ALTER TABLE `parte`
  ADD PRIMARY KEY (`idparte`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `autobus`
--
ALTER TABLE `autobus`
  MODIFY `idautobus` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `horario`
--
ALTER TABLE `horario`
  MODIFY `idhorario` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `incidencia`
--
ALTER TABLE `incidencia`
  MODIFY `idincidencia` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `ingreso`
--
ALTER TABLE `ingreso`
  MODIFY `idingreso` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `linea`
--
ALTER TABLE `linea`
  MODIFY `idlinea` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `modelo`
--
ALTER TABLE `modelo`
  MODIFY `idmodelo` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `parada`
--
ALTER TABLE `parada`
  MODIFY `idparada` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `parte`
--
ALTER TABLE `parte`
  MODIFY `idparte` int(6) NOT NULL AUTO_INCREMENT;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `autobus`
--
ALTER TABLE `autobus`
  ADD CONSTRAINT `fk_autobus_modelo` FOREIGN KEY (`modelo_idmodelo`) REFERENCES `modelo` (`idmodelo`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `autobus_incidencia`
--
ALTER TABLE `autobus_incidencia`
  ADD CONSTRAINT `fk_autobus_has_incidencia_autobus1` FOREIGN KEY (`autobus_idautobus`) REFERENCES `autobus` (`idautobus`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_autobus_has_incidencia_incidencia1` FOREIGN KEY (`incidencia_idincidencia`) REFERENCES `incidencia` (`idincidencia`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `incidencia_parte`
--
ALTER TABLE `incidencia_parte`
  ADD CONSTRAINT `fk_incidencia_has_parte_incidencia1` FOREIGN KEY (`incidencia_idincidencia`) REFERENCES `incidencia` (`idincidencia`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_incidencia_has_parte_parte1` FOREIGN KEY (`parte_idparte`) REFERENCES `parte` (`idparte`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `ingreso_parada`
--
ALTER TABLE `ingreso_parada`
  ADD CONSTRAINT `fk_ingreso_has_parada_ingreso1` FOREIGN KEY (`ingreso_idingreso`) REFERENCES `ingreso` (`idingreso`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_ingreso_has_parada_parada1` FOREIGN KEY (`parada_idparada`) REFERENCES `parada` (`idparada`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `linea`
--
ALTER TABLE `linea`
  ADD CONSTRAINT `fk_linea_autobus1` FOREIGN KEY (`autobus_idautobus`) REFERENCES `autobus` (`idautobus`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_linea_horario1` FOREIGN KEY (`horario_idhorario`) REFERENCES `horario` (`idhorario`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_linea_parada1` FOREIGN KEY (`parada_idparada`) REFERENCES `parada` (`idparada`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
