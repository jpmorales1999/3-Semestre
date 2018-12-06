-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 08-10-2018 a las 23:02:03
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
-- Base de datos: `aerolinea`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `avion`
--

CREATE TABLE `avion` (
  `idavion` int(6) NOT NULL,
  `nro_placa` int(10) DEFAULT NULL,
  `modelo` varchar(45) NOT NULL,
  `tiempo_vuelo` time DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `avion`
--

INSERT INTO `avion` (`idavion`, `nro_placa`, `modelo`, `tiempo_vuelo`) VALUES
(1, NULL, 'AlrBus15', NULL),
(2, NULL, 'Comp115', NULL),
(3, NULL, 'AlrBus10', NULL),
(4, NULL, 'Comp101', NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `destino`
--

CREATE TABLE `destino` (
  `iddestino` int(6) NOT NULL,
  `nombre_aeropuerto` varchar(45) NOT NULL,
  `ciudad` varchar(45) NOT NULL,
  `pais` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `piloto`
--

CREATE TABLE `piloto` (
  `idpiloto` int(6) NOT NULL,
  `cedula` int(10) NOT NULL,
  `nombre` varchar(45) NOT NULL,
  `apellido` varchar(45) NOT NULL,
  `fecha_nacimiento` date DEFAULT NULL,
  `lugar_nacimiento` varchar(45) DEFAULT NULL,
  `telefono` varchar(45) DEFAULT NULL,
  `correo` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `piloto`
--

INSERT INTO `piloto` (`idpiloto`, `cedula`, `nombre`, `apellido`, `fecha_nacimiento`, `lugar_nacimiento`, `telefono`, `correo`) VALUES
(1, 1112793121, 'JAMES', 'RODRIGUEZ', NULL, NULL, NULL, NULL),
(2, 1112793122, 'CRISTIANO', 'RONALDO', NULL, NULL, NULL, NULL),
(3, 1112793123, 'BOB', 'MARLEY', NULL, NULL, NULL, NULL),
(4, 1112793124, 'LIONEL', 'FALCAO', NULL, NULL, NULL, NULL),
(5, 1112793125, 'FAUSTO', 'VALDERRAMA', NULL, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipolicencia`
--

CREATE TABLE `tipolicencia` (
  `idtipolicencia` int(6) NOT NULL,
  `nrolicencia` int(10) NOT NULL,
  `fecha_ven` date NOT NULL,
  `fecha_exp` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `tipolicencia`
--

INSERT INTO `tipolicencia` (`idtipolicencia`, `nrolicencia`, `fecha_ven`, `fecha_exp`) VALUES
(1, 31414887, '2020-01-22', '2018-03-11'),
(2, 16205800, '2018-10-31', '2017-08-10'),
(3, 1121457896, '2019-09-13', '2017-07-02'),
(4, 18911616, '2020-11-13', '2017-10-09'),
(5, 31414881, '2018-11-08', '2018-08-06');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipolicencia_piloto`
--

CREATE TABLE `tipolicencia_piloto` (
  `tipolicencia_idtipolicencia` int(6) NOT NULL,
  `piloto_idpiloto` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipovuelo`
--

CREATE TABLE `tipovuelo` (
  `idtipovuelo` int(6) NOT NULL,
  `descripcion` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `tipovuelo`
--

INSERT INTO `tipovuelo` (`idtipovuelo`, `descripcion`) VALUES
(1, 'CHARTER'),
(2, 'REGULAR'),
(3, 'INTERCONTINENTAL'),
(4, 'ONE WAY'),
(5, 'LARGO RECORRIDO'),
(6, 'DIRECTO'),
(7, 'LOW COST');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `vuelo`
--

CREATE TABLE `vuelo` (
  `nrovuelo` int(6) NOT NULL,
  `duracion_vuelo` time NOT NULL,
  `aerolinea` varchar(45) NOT NULL,
  `hora_salida` time NOT NULL,
  `hora_llegada` time NOT NULL,
  `puerta_embarque` varchar(45) NOT NULL,
  `piloto_idpiloto` int(6) NOT NULL,
  `tipovuelo_idtipovuelo` int(6) NOT NULL,
  `avion_idavion` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `vuelo`
--

INSERT INTO `vuelo` (`nrovuelo`, `duracion_vuelo`, `aerolinea`, `hora_salida`, `hora_llegada`, `puerta_embarque`, `piloto_idpiloto`, `tipovuelo_idtipovuelo`, `avion_idavion`) VALUES
(1, '02:15:00', 'AVIANCA', '08:00:00', '10:15:00', 'GATE1', 1, 1, 1),
(2, '00:30:00', 'LAN', '09:15:00', '09:40:00', 'GATE2', 2, 2, 2),
(3, '14:00:00', 'AVIANCA', '06:00:00', '20:00:00', 'SALIDAINTERNACIONAL', 3, 3, 3),
(4, '02:05:00', 'LAN', '11:00:00', '13:05:00', 'GATE1', 1, 4, 1),
(5, '06:15:00', 'FLY EMILATES', '10:30:00', '16:45:00', 'GATE1', 2, 5, 2),
(6, '02:00:00', 'FLY EMILATES', '09:10:00', '11:10:00', 'GATE5', 4, 6, 2),
(7, '01:10:00', 'LAN', '21:40:00', '22:50:00', 'GATE2', 3, 7, 4),
(8, '08:00:00', 'AVIANCA', '18:00:00', '02:00:00', 'SALIDAINTERNACIONAL', 2, 3, 4),
(9, '01:00:00', 'AVIANCA', '17:00:00', '18:00:00', 'GATE5', 4, 7, 1),
(10, '02:00:00', 'LAN', '03:00:00', '05:00:00', 'GATE2', 5, 1, 4);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `vuelo_destino`
--

CREATE TABLE `vuelo_destino` (
  `vuelo_nrovuelo` int(6) NOT NULL,
  `destino_iddestino` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `avion`
--
ALTER TABLE `avion`
  ADD PRIMARY KEY (`idavion`);

--
-- Indices de la tabla `destino`
--
ALTER TABLE `destino`
  ADD PRIMARY KEY (`iddestino`);

--
-- Indices de la tabla `piloto`
--
ALTER TABLE `piloto`
  ADD PRIMARY KEY (`idpiloto`);

--
-- Indices de la tabla `tipolicencia`
--
ALTER TABLE `tipolicencia`
  ADD PRIMARY KEY (`idtipolicencia`);

--
-- Indices de la tabla `tipolicencia_piloto`
--
ALTER TABLE `tipolicencia_piloto`
  ADD PRIMARY KEY (`tipolicencia_idtipolicencia`,`piloto_idpiloto`),
  ADD KEY `fk_tipolicencia_has_piloto_piloto1` (`piloto_idpiloto`);

--
-- Indices de la tabla `tipovuelo`
--
ALTER TABLE `tipovuelo`
  ADD PRIMARY KEY (`idtipovuelo`);

--
-- Indices de la tabla `vuelo`
--
ALTER TABLE `vuelo`
  ADD PRIMARY KEY (`nrovuelo`),
  ADD KEY `fk_vuelo_piloto1` (`piloto_idpiloto`),
  ADD KEY `fk_vuelo_tipovuelo1` (`tipovuelo_idtipovuelo`),
  ADD KEY `fk_vuelo_avion1` (`avion_idavion`);

--
-- Indices de la tabla `vuelo_destino`
--
ALTER TABLE `vuelo_destino`
  ADD PRIMARY KEY (`vuelo_nrovuelo`,`destino_iddestino`),
  ADD KEY `fk_vuelo_has_destino_destino1` (`destino_iddestino`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `avion`
--
ALTER TABLE `avion`
  MODIFY `idavion` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT de la tabla `piloto`
--
ALTER TABLE `piloto`
  MODIFY `idpiloto` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT de la tabla `tipovuelo`
--
ALTER TABLE `tipovuelo`
  MODIFY `idtipovuelo` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT de la tabla `vuelo`
--
ALTER TABLE `vuelo`
  MODIFY `nrovuelo` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `tipolicencia_piloto`
--
ALTER TABLE `tipolicencia_piloto`
  ADD CONSTRAINT `fk_tipolicencia_has_piloto_piloto1` FOREIGN KEY (`piloto_idpiloto`) REFERENCES `piloto` (`idpiloto`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_tipolicencia_has_piloto_tipolicencia1` FOREIGN KEY (`tipolicencia_idtipolicencia`) REFERENCES `tipolicencia` (`idtipolicencia`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `vuelo`
--
ALTER TABLE `vuelo`
  ADD CONSTRAINT `fk_vuelo_avion1` FOREIGN KEY (`avion_idavion`) REFERENCES `avion` (`idavion`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_vuelo_piloto1` FOREIGN KEY (`piloto_idpiloto`) REFERENCES `piloto` (`idpiloto`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_vuelo_tipovuelo1` FOREIGN KEY (`tipovuelo_idtipovuelo`) REFERENCES `tipovuelo` (`idtipovuelo`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `vuelo_destino`
--
ALTER TABLE `vuelo_destino`
  ADD CONSTRAINT `fk_vuelo_has_destino_destino1` FOREIGN KEY (`destino_iddestino`) REFERENCES `destino` (`iddestino`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_vuelo_has_destino_vuelo` FOREIGN KEY (`vuelo_nrovuelo`) REFERENCES `vuelo` (`nrovuelo`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
