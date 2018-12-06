-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 01-11-2018 a las 00:09:30
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
-- Base de datos: `reyes_magos`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `barrio`
--

CREATE TABLE `barrio` (
  `idbarrio` int(2) NOT NULL,
  `barrio` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `calle`
--

CREATE TABLE `calle` (
  `idcalle` int(6) NOT NULL,
  `calle` int(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `carrera`
--

CREATE TABLE `carrera` (
  `idcarrera` int(6) NOT NULL,
  `carrera` int(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `estrato`
--

CREATE TABLE `estrato` (
  `idestrato` int(6) NOT NULL,
  `estrato` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `evento`
--

CREATE TABLE `evento` (
  `idevento` int(6) NOT NULL,
  `fecha` date NOT NULL,
  `hora` time NOT NULL,
  `n_asistentes` int(3) NOT NULL,
  `carrera_idcarrera` int(6) NOT NULL,
  `estrato_idestrato` int(6) NOT NULL,
  `calle_idcalle` int(6) NOT NULL,
  `barrio_idbarrio` int(2) NOT NULL,
  `no_int` int(2) NOT NULL,
  `no_ext` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `grupo`
--

CREATE TABLE `grupo` (
  `idgrupo` int(6) NOT NULL,
  `intengrantes` int(2) NOT NULL,
  `barrio_idbarrio` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `grupo_evento`
--

CREATE TABLE `grupo_evento` (
  `grupo_idgrupo` int(6) NOT NULL,
  `evento_idevento` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `interpretacion`
--

CREATE TABLE `interpretacion` (
  `idinterpretacion` int(6) NOT NULL,
  `rey_mago` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `nino`
--

CREATE TABLE `nino` (
  `telefono_acudiente` varchar(45) NOT NULL,
  `nombre` varchar(15) NOT NULL,
  `ape_ma` varchar(15) NOT NULL,
  `ape_pa` varchar(15) NOT NULL,
  `vecino_DNI` int(10) NOT NULL,
  `regalo_idregalo` int(6) NOT NULL,
  `barrio_idbarrio` int(2) NOT NULL,
  `calle_idcalle` int(6) NOT NULL,
  `estrato_idestrato` int(6) NOT NULL,
  `carrera_idcarrera` int(6) NOT NULL,
  `no_int` int(2) NOT NULL,
  `no_ext` int(2) NOT NULL,
  `evento_idevento` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `regalo`
--

CREATE TABLE `regalo` (
  `idregalo` int(6) NOT NULL,
  `regalo` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `vecino`
--

CREATE TABLE `vecino` (
  `DNI` int(10) NOT NULL,
  `nombre` varchar(30) NOT NULL,
  `ape_ma` varchar(15) NOT NULL,
  `ape_pa` varchar(15) NOT NULL,
  `convencimiento` int(2) NOT NULL,
  `interpretacion_idinterpretacion` int(6) NOT NULL,
  `grupo_idgrupo` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `barrio`
--
ALTER TABLE `barrio`
  ADD PRIMARY KEY (`idbarrio`);

--
-- Indices de la tabla `calle`
--
ALTER TABLE `calle`
  ADD PRIMARY KEY (`idcalle`);

--
-- Indices de la tabla `carrera`
--
ALTER TABLE `carrera`
  ADD PRIMARY KEY (`idcarrera`);

--
-- Indices de la tabla `estrato`
--
ALTER TABLE `estrato`
  ADD PRIMARY KEY (`idestrato`);

--
-- Indices de la tabla `evento`
--
ALTER TABLE `evento`
  ADD PRIMARY KEY (`idevento`),
  ADD KEY `fk_evento_carrera1` (`carrera_idcarrera`),
  ADD KEY `fk_evento_estrato1` (`estrato_idestrato`),
  ADD KEY `fk_evento_calle1` (`calle_idcalle`),
  ADD KEY `fk_evento_barrio1` (`barrio_idbarrio`);

--
-- Indices de la tabla `grupo`
--
ALTER TABLE `grupo`
  ADD PRIMARY KEY (`idgrupo`),
  ADD KEY `fk_grupo_barrio1` (`barrio_idbarrio`);

--
-- Indices de la tabla `grupo_evento`
--
ALTER TABLE `grupo_evento`
  ADD PRIMARY KEY (`grupo_idgrupo`,`evento_idevento`),
  ADD KEY `fk_grupo_has_evento_evento1` (`evento_idevento`);

--
-- Indices de la tabla `interpretacion`
--
ALTER TABLE `interpretacion`
  ADD PRIMARY KEY (`idinterpretacion`);

--
-- Indices de la tabla `nino`
--
ALTER TABLE `nino`
  ADD PRIMARY KEY (`telefono_acudiente`),
  ADD KEY `fk_nino_vecino1` (`vecino_DNI`),
  ADD KEY `fk_nino_regalo1` (`regalo_idregalo`),
  ADD KEY `fk_nino_barrio1` (`barrio_idbarrio`),
  ADD KEY `fk_nino_calle1` (`calle_idcalle`),
  ADD KEY `fk_nino_estrato1` (`estrato_idestrato`),
  ADD KEY `fk_nino_carrera1` (`carrera_idcarrera`),
  ADD KEY `fk_nino_evento1` (`evento_idevento`);

--
-- Indices de la tabla `regalo`
--
ALTER TABLE `regalo`
  ADD PRIMARY KEY (`idregalo`);

--
-- Indices de la tabla `vecino`
--
ALTER TABLE `vecino`
  ADD PRIMARY KEY (`DNI`),
  ADD KEY `fk_vecino_interpretacion` (`interpretacion_idinterpretacion`),
  ADD KEY `fk_vecino_grupo1` (`grupo_idgrupo`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `barrio`
--
ALTER TABLE `barrio`
  MODIFY `idbarrio` int(2) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `evento`
--
ALTER TABLE `evento`
  MODIFY `idevento` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `grupo`
--
ALTER TABLE `grupo`
  MODIFY `idgrupo` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `interpretacion`
--
ALTER TABLE `interpretacion`
  MODIFY `idinterpretacion` int(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `regalo`
--
ALTER TABLE `regalo`
  MODIFY `idregalo` int(6) NOT NULL AUTO_INCREMENT;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `evento`
--
ALTER TABLE `evento`
  ADD CONSTRAINT `fk_evento_barrio1` FOREIGN KEY (`barrio_idbarrio`) REFERENCES `barrio` (`idbarrio`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_evento_calle1` FOREIGN KEY (`calle_idcalle`) REFERENCES `calle` (`idcalle`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_evento_carrera1` FOREIGN KEY (`carrera_idcarrera`) REFERENCES `carrera` (`idcarrera`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_evento_estrato1` FOREIGN KEY (`estrato_idestrato`) REFERENCES `estrato` (`idestrato`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `grupo`
--
ALTER TABLE `grupo`
  ADD CONSTRAINT `fk_grupo_barrio1` FOREIGN KEY (`barrio_idbarrio`) REFERENCES `barrio` (`idbarrio`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `grupo_evento`
--
ALTER TABLE `grupo_evento`
  ADD CONSTRAINT `fk_grupo_has_evento_evento1` FOREIGN KEY (`evento_idevento`) REFERENCES `evento` (`idevento`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_grupo_has_evento_grupo1` FOREIGN KEY (`grupo_idgrupo`) REFERENCES `grupo` (`idgrupo`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `nino`
--
ALTER TABLE `nino`
  ADD CONSTRAINT `fk_nino_barrio1` FOREIGN KEY (`barrio_idbarrio`) REFERENCES `barrio` (`idbarrio`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_nino_calle1` FOREIGN KEY (`calle_idcalle`) REFERENCES `calle` (`idcalle`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_nino_carrera1` FOREIGN KEY (`carrera_idcarrera`) REFERENCES `carrera` (`idcarrera`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_nino_estrato1` FOREIGN KEY (`estrato_idestrato`) REFERENCES `estrato` (`idestrato`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_nino_evento1` FOREIGN KEY (`evento_idevento`) REFERENCES `evento` (`idevento`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_nino_regalo1` FOREIGN KEY (`regalo_idregalo`) REFERENCES `regalo` (`idregalo`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_nino_vecino1` FOREIGN KEY (`vecino_DNI`) REFERENCES `vecino` (`DNI`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `vecino`
--
ALTER TABLE `vecino`
  ADD CONSTRAINT `fk_vecino_grupo1` FOREIGN KEY (`grupo_idgrupo`) REFERENCES `grupo` (`idgrupo`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_vecino_interpretacion` FOREIGN KEY (`interpretacion_idinterpretacion`) REFERENCES `interpretacion` (`idinterpretacion`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
