-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 08-10-2018 a las 17:31:43
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
-- Base de datos: `startrek`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `actor`
--

CREATE TABLE `actor` (
  `idactor` int(6) NOT NULL COMMENT 'Identificador unico del actor',
  `nombre` varchar(80) NOT NULL,
  `personaje` varchar(45) NOT NULL,
  `fecha_nacimiento` date NOT NULL,
  `nacionalidad` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `capitulo`
--

CREATE TABLE `capitulo` (
  `idcapitulo` int(6) NOT NULL COMMENT 'Identificador unico del capitulo',
  `temporada` int(2) NOT NULL,
  `titulo` varchar(45) NOT NULL,
  `orden_filmacion` int(10) NOT NULL,
  `fecha_emision` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `capitulo_planeta`
--

CREATE TABLE `capitulo_planeta` (
  `capitulo_idcapitulo` int(6) NOT NULL,
  `planeta_codigo` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `nave`
--

CREATE TABLE `nave` (
  `codigo` int(6) NOT NULL COMMENT 'Identificador unico de la nave',
  `nombre` varchar(45) NOT NULL,
  `num_tripulantes` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `nave_planeta`
--

CREATE TABLE `nave_planeta` (
  `nave_codigo` int(6) NOT NULL,
  `planeta_codigo` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pelicula`
--

CREATE TABLE `pelicula` (
  `idpelicula` int(6) NOT NULL COMMENT 'Identificador unico de la entidad pelicula',
  `peliculas_proyectadas` int(2) NOT NULL,
  `ano_estreno` date NOT NULL,
  `titulo` varchar(45) NOT NULL,
  `director` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `pelicula_personaje`
--

CREATE TABLE `pelicula_personaje` (
  `pelicula_idpelicula` int(6) NOT NULL,
  `personaje_idpersonaje` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `personaje`
--

CREATE TABLE `personaje` (
  `idpersonaje` int(6) NOT NULL COMMENT 'Identificador del personaje',
  `nombre` varchar(45) NOT NULL,
  `raza` varchar(45) NOT NULL,
  `graduacion_militar` varchar(45) NOT NULL,
  `actor_idactor` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `personaje_capitulo`
--

CREATE TABLE `personaje_capitulo` (
  `personaje_idpersonaje` int(6) NOT NULL,
  `capitulo_idcapitulo` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `planeta`
--

CREATE TABLE `planeta` (
  `codigo` int(6) NOT NULL COMMENT 'Identificador unico del planeta',
  `nombre` varchar(45) NOT NULL,
  `galaxia` varchar(45) NOT NULL,
  `descripcion_problema` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `actor`
--
ALTER TABLE `actor`
  ADD PRIMARY KEY (`idactor`);

--
-- Indices de la tabla `capitulo`
--
ALTER TABLE `capitulo`
  ADD PRIMARY KEY (`idcapitulo`);

--
-- Indices de la tabla `capitulo_planeta`
--
ALTER TABLE `capitulo_planeta`
  ADD PRIMARY KEY (`capitulo_idcapitulo`,`planeta_codigo`),
  ADD KEY `fk_capitulo_has_planeta_planeta1` (`planeta_codigo`);

--
-- Indices de la tabla `nave`
--
ALTER TABLE `nave`
  ADD PRIMARY KEY (`codigo`);

--
-- Indices de la tabla `nave_planeta`
--
ALTER TABLE `nave_planeta`
  ADD PRIMARY KEY (`nave_codigo`,`planeta_codigo`),
  ADD KEY `fk_nave_has_planeta_planeta1` (`planeta_codigo`);

--
-- Indices de la tabla `pelicula`
--
ALTER TABLE `pelicula`
  ADD PRIMARY KEY (`idpelicula`);

--
-- Indices de la tabla `pelicula_personaje`
--
ALTER TABLE `pelicula_personaje`
  ADD PRIMARY KEY (`pelicula_idpelicula`,`personaje_idpersonaje`),
  ADD KEY `fk_pelicula_has_personaje_personaje1` (`personaje_idpersonaje`);

--
-- Indices de la tabla `personaje`
--
ALTER TABLE `personaje`
  ADD PRIMARY KEY (`idpersonaje`),
  ADD KEY `fk_personaje_actor` (`actor_idactor`);

--
-- Indices de la tabla `personaje_capitulo`
--
ALTER TABLE `personaje_capitulo`
  ADD PRIMARY KEY (`personaje_idpersonaje`,`capitulo_idcapitulo`),
  ADD KEY `fk_personaje_has_capitulo_capitulo1` (`capitulo_idcapitulo`);

--
-- Indices de la tabla `planeta`
--
ALTER TABLE `planeta`
  ADD PRIMARY KEY (`codigo`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `capitulo`
--
ALTER TABLE `capitulo`
  MODIFY `idcapitulo` int(6) NOT NULL AUTO_INCREMENT COMMENT 'Identificador unico del capitulo';

--
-- AUTO_INCREMENT de la tabla `nave`
--
ALTER TABLE `nave`
  MODIFY `codigo` int(6) NOT NULL AUTO_INCREMENT COMMENT 'Identificador unico de la nave';

--
-- AUTO_INCREMENT de la tabla `pelicula`
--
ALTER TABLE `pelicula`
  MODIFY `idpelicula` int(6) NOT NULL AUTO_INCREMENT COMMENT 'Identificador unico de la entidad pelicula';

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `capitulo_planeta`
--
ALTER TABLE `capitulo_planeta`
  ADD CONSTRAINT `fk_capitulo_has_planeta_capitulo1` FOREIGN KEY (`capitulo_idcapitulo`) REFERENCES `capitulo` (`idcapitulo`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_capitulo_has_planeta_planeta1` FOREIGN KEY (`planeta_codigo`) REFERENCES `planeta` (`codigo`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `nave_planeta`
--
ALTER TABLE `nave_planeta`
  ADD CONSTRAINT `fk_nave_has_planeta_nave1` FOREIGN KEY (`nave_codigo`) REFERENCES `nave` (`codigo`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_nave_has_planeta_planeta1` FOREIGN KEY (`planeta_codigo`) REFERENCES `planeta` (`codigo`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `pelicula_personaje`
--
ALTER TABLE `pelicula_personaje`
  ADD CONSTRAINT `fk_pelicula_has_personaje_pelicula1` FOREIGN KEY (`pelicula_idpelicula`) REFERENCES `pelicula` (`idpelicula`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_pelicula_has_personaje_personaje1` FOREIGN KEY (`personaje_idpersonaje`) REFERENCES `personaje` (`idpersonaje`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `personaje`
--
ALTER TABLE `personaje`
  ADD CONSTRAINT `fk_personaje_actor` FOREIGN KEY (`actor_idactor`) REFERENCES `actor` (`idactor`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `personaje_capitulo`
--
ALTER TABLE `personaje_capitulo`
  ADD CONSTRAINT `fk_personaje_has_capitulo_capitulo1` FOREIGN KEY (`capitulo_idcapitulo`) REFERENCES `capitulo` (`idcapitulo`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_personaje_has_capitulo_personaje1` FOREIGN KEY (`personaje_idpersonaje`) REFERENCES `personaje` (`idpersonaje`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
