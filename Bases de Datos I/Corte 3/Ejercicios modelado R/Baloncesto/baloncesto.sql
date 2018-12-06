-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 22-10-2018 a las 21:37:25
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
-- Base de datos: `baloncesto`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `calendario`
--

CREATE TABLE `calendario` (
  `idcalendario` int(6) NOT NULL,
  `fecha` date NOT NULL,
  `hora` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `enfrentamiento`
--

CREATE TABLE `enfrentamiento` (
  `idenfrentamiento` int(6) NOT NULL,
  `enfrentamiento` varchar(80) NOT NULL,
  `local_visitante` varchar(45) NOT NULL,
  `jornada_idjornada` int(6) NOT NULL,
  `resultado_idresultado` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `equipo`
--

CREATE TABLE `equipo` (
  `idequipo` int(6) NOT NULL,
  `nombre` varchar(45) NOT NULL,
  `liga_idliga` int(6) NOT NULL,
  `sede_idsede` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `equipo_enfrentamiento`
--

CREATE TABLE `equipo_enfrentamiento` (
  `equipo_idequipo` int(6) NOT NULL,
  `enfrentamiento_idenfrentamiento` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `estadistica`
--

CREATE TABLE `estadistica` (
  `idestadistica` int(6) NOT NULL,
  `puntos` float NOT NULL,
  `faltas` int(3) NOT NULL,
  `asistencias` int(3) NOT NULL,
  `rebotes` int(3) NOT NULL,
  `jugador_idjugador` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `jornada`
--

CREATE TABLE `jornada` (
  `idjornada` int(6) NOT NULL,
  `num_jornada` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `jornada_calendario`
--

CREATE TABLE `jornada_calendario` (
  `jornada_idjornada` int(6) NOT NULL,
  `calendario_idcalendario` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `jugador`
--

CREATE TABLE `jugador` (
  `idjugador` int(6) NOT NULL,
  `nombre` varchar(80) NOT NULL,
  `estatura` float NOT NULL,
  `posicion` varchar(45) NOT NULL,
  `dorsal` int(3) NOT NULL,
  `equipo_idequipo` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `liga`
--

CREATE TABLE `liga` (
  `idliga` int(6) NOT NULL,
  `nombre` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `resultado`
--

CREATE TABLE `resultado` (
  `idresultado` int(6) NOT NULL,
  `resultado` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sede`
--

CREATE TABLE `sede` (
  `idsede` int(6) NOT NULL,
  `capacidad` int(10) NOT NULL,
  `pabellon` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `calendario`
--
ALTER TABLE `calendario`
  ADD PRIMARY KEY (`idcalendario`);

--
-- Indices de la tabla `enfrentamiento`
--
ALTER TABLE `enfrentamiento`
  ADD PRIMARY KEY (`idenfrentamiento`),
  ADD KEY `fk_enfrentamiento_jornada1` (`jornada_idjornada`),
  ADD KEY `fk_enfrentamiento_resultado1` (`resultado_idresultado`);

--
-- Indices de la tabla `equipo`
--
ALTER TABLE `equipo`
  ADD PRIMARY KEY (`idequipo`),
  ADD KEY `fk_equipo_liga` (`liga_idliga`),
  ADD KEY `fk_equipo_sede1` (`sede_idsede`);

--
-- Indices de la tabla `equipo_enfrentamiento`
--
ALTER TABLE `equipo_enfrentamiento`
  ADD PRIMARY KEY (`equipo_idequipo`,`enfrentamiento_idenfrentamiento`),
  ADD KEY `fk_equipo_has_enfrentamiento_enfrentamiento1` (`enfrentamiento_idenfrentamiento`);

--
-- Indices de la tabla `estadistica`
--
ALTER TABLE `estadistica`
  ADD PRIMARY KEY (`idestadistica`),
  ADD KEY `fk_estadistica_jugador1` (`jugador_idjugador`);

--
-- Indices de la tabla `jornada`
--
ALTER TABLE `jornada`
  ADD PRIMARY KEY (`idjornada`);

--
-- Indices de la tabla `jornada_calendario`
--
ALTER TABLE `jornada_calendario`
  ADD PRIMARY KEY (`jornada_idjornada`,`calendario_idcalendario`),
  ADD KEY `fk_jornada_has_calendario_calendario1` (`calendario_idcalendario`);

--
-- Indices de la tabla `jugador`
--
ALTER TABLE `jugador`
  ADD PRIMARY KEY (`idjugador`),
  ADD KEY `fk_jugador_equipo1` (`equipo_idequipo`);

--
-- Indices de la tabla `liga`
--
ALTER TABLE `liga`
  ADD PRIMARY KEY (`idliga`);

--
-- Indices de la tabla `resultado`
--
ALTER TABLE `resultado`
  ADD PRIMARY KEY (`idresultado`);

--
-- Indices de la tabla `sede`
--
ALTER TABLE `sede`
  ADD PRIMARY KEY (`idsede`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `calendario`
--
ALTER TABLE `calendario`
  MODIFY `idcalendario` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `enfrentamiento`
--
ALTER TABLE `enfrentamiento`
  MODIFY `idenfrentamiento` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `estadistica`
--
ALTER TABLE `estadistica`
  MODIFY `idestadistica` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `jornada`
--
ALTER TABLE `jornada`
  MODIFY `idjornada` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `jugador`
--
ALTER TABLE `jugador`
  MODIFY `idjugador` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `sede`
--
ALTER TABLE `sede`
  MODIFY `idsede` int(6) NOT NULL AUTO_INCREMENT;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `enfrentamiento`
--
ALTER TABLE `enfrentamiento`
  ADD CONSTRAINT `fk_enfrentamiento_jornada1` FOREIGN KEY (`jornada_idjornada`) REFERENCES `jornada` (`idjornada`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_enfrentamiento_resultado1` FOREIGN KEY (`resultado_idresultado`) REFERENCES `resultado` (`idresultado`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `equipo`
--
ALTER TABLE `equipo`
  ADD CONSTRAINT `fk_equipo_liga` FOREIGN KEY (`liga_idliga`) REFERENCES `liga` (`idliga`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_equipo_sede1` FOREIGN KEY (`sede_idsede`) REFERENCES `sede` (`idsede`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `equipo_enfrentamiento`
--
ALTER TABLE `equipo_enfrentamiento`
  ADD CONSTRAINT `fk_equipo_has_enfrentamiento_enfrentamiento1` FOREIGN KEY (`enfrentamiento_idenfrentamiento`) REFERENCES `enfrentamiento` (`idenfrentamiento`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_equipo_has_enfrentamiento_equipo1` FOREIGN KEY (`equipo_idequipo`) REFERENCES `equipo` (`idequipo`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `estadistica`
--
ALTER TABLE `estadistica`
  ADD CONSTRAINT `fk_estadistica_jugador1` FOREIGN KEY (`jugador_idjugador`) REFERENCES `jugador` (`idjugador`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `jornada_calendario`
--
ALTER TABLE `jornada_calendario`
  ADD CONSTRAINT `fk_jornada_has_calendario_calendario1` FOREIGN KEY (`calendario_idcalendario`) REFERENCES `calendario` (`idcalendario`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_jornada_has_calendario_jornada1` FOREIGN KEY (`jornada_idjornada`) REFERENCES `jornada` (`idjornada`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `jugador`
--
ALTER TABLE `jugador`
  ADD CONSTRAINT `fk_jugador_equipo1` FOREIGN KEY (`equipo_idequipo`) REFERENCES `equipo` (`idequipo`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
