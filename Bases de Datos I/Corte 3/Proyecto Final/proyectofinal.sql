-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 22-11-2018 a las 23:52:00
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
-- Base de datos: `proyectofinal`
--

DELIMITER $$
--
-- Procedimientos
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `empleados_estrato` (`EST` INT)  BEGIN
SELECT documento, nombre, ape_pa, ape_ma, fecha_nacimiento, sueldo FROM empleado WHERE estrato_id_estrato=EST;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `parametro_ape` (IN `inicial` VARCHAR(1))  BEGIN
SELECT nombre, ape_pa, ape_ma FROM empleado WHERE ape_pa LIKE CONCAT('%',inicial,'%');
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `total_empleados` ()  BEGIN
SELECT COUNT(*) AS TOTAL_EMPLEADOS FROM empleado;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `total_mujeres` ()  BEGIN
SELECT COUNT(*) AS TOTAL_MUJERES FROM empleado WHERE sexo_id_sexo=2;
END$$

--
-- Funciones
--
CREATE DEFINER=`root`@`localhost` FUNCTION `barrios` () RETURNS TEXT CHARSET utf8 BEGIN
RETURN (SELECT COUNT(barrio) FROM barrio);
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `buscar_empleado` (`NUM` INT) RETURNS TEXT CHARSET utf8 BEGIN
RETURN (SELECT nombre FROM empleado WHERE documento=NUM);
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `buscar_sueldo` (`NUM` INT) RETURNS TEXT CHARSET utf8 BEGIN
RETURN (SELECT sueldo FROM empleado WHERE documento=NUM);
END$$

CREATE DEFINER=`root`@`localhost` FUNCTION `hombres_total` (`sx` INT) RETURNS INT(11) BEGIN
RETURN (SELECT COUNT(*) FROM empleado WHERE sexo_id_sexo=sx);
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `auditoria`
--

CREATE TABLE `auditoria` (
  `fecha` datetime DEFAULT NULL,
  `operacion` varchar(45) DEFAULT NULL,
  `nombre` varchar(45) DEFAULT NULL,
  `sueldo` float DEFAULT NULL,
  `fecha_nacimiento` date DEFAULT NULL,
  `usuario` varchar(45) DEFAULT NULL,
  `anterior_nombre` varchar(45) DEFAULT NULL,
  `anterior_sueldo` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `auditoria`
--

INSERT INTO `auditoria` (`fecha`, `operacion`, `nombre`, `sueldo`, `fecha_nacimiento`, `usuario`, `anterior_nombre`, `anterior_sueldo`) VALUES
('2018-11-22 16:16:04', 'UPDATE', 'DIEGO ALEJANDRO', 700000, NULL, 'root@localhost', 'DIEGO', 700000),
('2018-11-22 16:32:38', 'DELETE', 'ALFREDO', 1500000, '1970-03-04', 'root@localhost', NULL, NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `barrio`
--

CREATE TABLE `barrio` (
  `id_barrio` int(6) NOT NULL,
  `barrio` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `barrio`
--

INSERT INTO `barrio` (`id_barrio`, `barrio`) VALUES
(1, 'EL PRADO'),
(2, 'EL CARMEN'),
(3, 'LAURELES'),
(4, 'PINARES'),
(5, 'ALAMOS'),
(6, 'LOMA DE LA VIRGEN'),
(7, 'EL TREBOL'),
(8, 'LOS LLANOS'),
(9, 'SANTA MARIA'),
(10, 'SANTA MARIA REAL'),
(11, 'CENTRO'),
(12, 'LA CASTELLANA'),
(13, 'SAN JERONIMO'),
(14, 'LA ESTACION'),
(15, 'LA INVASION'),
(16, 'SANTA ANA'),
(17, 'CAMBULOS'),
(18, 'PRADO NORTE'),
(19, 'LOS ROSALES'),
(20, 'CONQUISTADORES'),
(21, 'GUAYACANES'),
(22, 'LA INDEPENDENCIA'),
(23, 'SAN GABRIEL'),
(24, 'VILLA HELENA'),
(25, 'ARGOS'),
(26, 'LOS LAGOS');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `calle`
--

CREATE TABLE `calle` (
  `id_calle` int(6) NOT NULL,
  `calle` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `calle`
--

INSERT INTO `calle` (`id_calle`, `calle`) VALUES
(1, 'CALLE 1'),
(2, 'CALLE 2'),
(3, 'CALLE 3'),
(4, 'CALLE 4'),
(5, 'CALLE 5'),
(6, 'CALLE 6'),
(7, 'CALLE 7'),
(8, 'CALLE 8'),
(9, 'CALLE 9'),
(10, 'CALLE 10'),
(11, 'CALLE 11'),
(12, 'CALLE 12'),
(13, 'CALLE 13'),
(14, 'CALLE 14'),
(15, 'CALLE 15'),
(16, 'CALLE 16'),
(17, 'CALLE 17'),
(18, 'CALLE 18'),
(19, 'CALLE 19'),
(20, 'CALLE 20'),
(21, 'CALLE 21');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `carrera`
--

CREATE TABLE `carrera` (
  `id_carrera` int(6) NOT NULL,
  `carrera` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `carrera`
--

INSERT INTO `carrera` (`id_carrera`, `carrera`) VALUES
(1, 'CARRERA 1'),
(2, 'CARRERA 2'),
(3, 'CARRERA 3'),
(4, 'CARRERA 4'),
(5, 'CARRERA 5'),
(6, 'CARRERA 6'),
(7, 'CARRERA 7'),
(8, 'CARRERA 8'),
(9, 'CARRERA 9'),
(10, 'CARRERA 10'),
(11, 'CARRERA 11'),
(12, 'CARRERA 12'),
(13, 'CARRERA 13'),
(14, 'CARRERA 14'),
(15, 'CARRERA 15'),
(16, 'CARRERA 16'),
(17, 'CARRERA 17');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `comun`
--

CREATE TABLE `comun` (
  `id_comun` int(6) NOT NULL,
  `empleado_documento` int(12) NOT NULL,
  `departamento_id_departamento` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `comun`
--

INSERT INTO `comun` (`id_comun`, `empleado_documento`, `departamento_id_departamento`) VALUES
(1, 878938016, 1),
(2, 591894160, 1),
(3, 774010023, 1),
(4, 991989224, 1),
(5, 148699297, 2),
(6, 679531369, 2),
(7, 362760470, 2),
(8, 336933833, 2),
(9, 254974387, 3),
(10, 263975799, 3),
(11, 1580929935, 3),
(12, 364172399, 3),
(13, 791169189, 4),
(14, 129279380, 4),
(15, 1580929934, 4),
(16, 141019842, 4),
(17, 694364209, 5),
(18, 699480372, 5),
(19, 269515084, 5),
(20, 802458821, 5),
(21, 954909614, 6),
(22, 429946089, 6),
(23, 660237318, 6),
(24, 1146206818, 7),
(25, 579396386, 7),
(26, 710340994, 7),
(27, 142779128, 8),
(28, 230331279, 8),
(29, 1112773184, 9),
(30, 442969563, 9),
(31, 225906528, 9),
(32, 335385868, 9),
(33, 618418975, 7),
(34, 916327439, 8),
(35, 363179271, 8),
(36, 319957250, 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `comun_supervisor`
--

CREATE TABLE `comun_supervisor` (
  `comun_id_comun` int(6) NOT NULL,
  `supervisor_id_supervisor` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `comun_supervisor`
--

INSERT INTO `comun_supervisor` (`comun_id_comun`, `supervisor_id_supervisor`) VALUES
(1, 1),
(2, 1),
(3, 1),
(4, 1),
(5, 1),
(6, 1),
(7, 1),
(8, 2),
(9, 2),
(10, 2),
(11, 2),
(12, 2),
(13, 3),
(14, 3),
(15, 3),
(16, 3),
(17, 3),
(18, 3),
(19, 4),
(20, 4),
(21, 4),
(22, 4),
(23, 4),
(24, 4),
(25, 5),
(26, 5),
(27, 5),
(28, 5),
(29, 5),
(30, 5),
(31, 6),
(32, 6),
(33, 6),
(34, 6),
(35, 6),
(36, 6);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `departamento`
--

CREATE TABLE `departamento` (
  `id_departamento` int(6) NOT NULL,
  `departamento` varchar(45) NOT NULL,
  `jefe_id_jefe` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `departamento`
--

INSERT INTO `departamento` (`id_departamento`, `departamento`, `jefe_id_jefe`) VALUES
(1, 'FINANZAS', 1),
(2, 'GERENCIA', 2),
(3, 'COMPRAS', 3),
(4, 'RECURSOS HUMANOS', 4),
(5, 'PRODUCCION', 5),
(6, 'CONTROL DE GESTION', 6),
(7, 'MARKETING', 7),
(8, 'VENTAS', 8),
(9, 'ADMINISTRACION', 9);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `departamento_lugar`
--

CREATE TABLE `departamento_lugar` (
  `departamento_id_departamento` int(6) NOT NULL,
  `lugar_id_lugar` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `departamento_lugar`
--

INSERT INTO `departamento_lugar` (`departamento_id_departamento`, `lugar_id_lugar`) VALUES
(1, 1),
(1, 10),
(2, 2),
(2, 9),
(3, 3),
(3, 8),
(4, 4),
(4, 7),
(5, 5),
(5, 6),
(6, 1),
(6, 6),
(7, 2),
(7, 7),
(8, 3),
(8, 8),
(9, 4),
(9, 9);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `departamento_proyecto`
--

CREATE TABLE `departamento_proyecto` (
  `departamento_id_departamento` int(6) NOT NULL,
  `proyecto_id_proyecto` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `departamento_proyecto`
--

INSERT INTO `departamento_proyecto` (`departamento_id_departamento`, `proyecto_id_proyecto`) VALUES
(1, 4),
(2, 5),
(3, 1),
(3, 4),
(4, 6),
(5, 2),
(5, 4),
(6, 5),
(6, 6),
(7, 1),
(8, 3),
(9, 3);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `empleado`
--

CREATE TABLE `empleado` (
  `documento` int(12) NOT NULL,
  `nombre` varchar(45) NOT NULL,
  `ape_pa` varchar(30) NOT NULL,
  `ape_ma` varchar(30) NOT NULL,
  `sueldo` float NOT NULL,
  `fecha_nacimiento` date NOT NULL,
  `sexo_id_sexo` int(6) NOT NULL,
  `no_int` int(2) NOT NULL,
  `no_ext` int(2) NOT NULL,
  `calle_id_calle` int(6) DEFAULT NULL,
  `carrera_id_carrera` int(6) DEFAULT NULL,
  `estrato_id_estrato` int(6) NOT NULL,
  `barrio_id_barrio` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `empleado`
--

INSERT INTO `empleado` (`documento`, `nombre`, `ape_pa`, `ape_ma`, `sueldo`, `fecha_nacimiento`, `sexo_id_sexo`, `no_int`, `no_ext`, `calle_id_calle`, `carrera_id_carrera`, `estrato_id_estrato`, `barrio_id_barrio`) VALUES
(16205700, 'RAMIRO', 'FERNANDEZ', 'ACEVEDO', 800000, '1954-03-14', 1, 54, 89, NULL, 4, 3, 2),
(31414884, 'NORHA MILENA', 'TAMES', 'CARDOZO', 1200000, '1969-08-10', 2, 15, 92, NULL, 3, 4, 1),
(129279380, 'JHONATAN', 'ECHEVERRY', 'RENTERIA', 450000, '1974-09-18', 1, 24, 78, NULL, 8, 5, 22),
(141019842, 'JUAN CAMILO', 'MOLINA', 'DIAZ', 450000, '1990-04-29', 1, 75, 169, 19, NULL, 1, 7),
(142779128, 'NICOLAS', 'AGUIRRE', 'MURIEL', 1200000, '1982-07-27', 1, 78, 162, NULL, 13, 6, 22),
(147308165, 'CRISTIAN STIVEN', 'GONZALEZ', 'ARANGO', 1800000, '1987-02-26', 1, 17, 67, NULL, 10, 3, 11),
(148699297, 'DANIELA', 'CASTAÑO', 'GIRALDO', 3000000, '1990-12-24', 2, 78, 90, NULL, 15, 1, 7),
(177287636, 'YAKELIN', 'HURTADO', 'GONZALES', 250000, '1998-11-25', 2, 62, 104, 11, NULL, 5, 17),
(225906528, 'SARA MARITZA', 'RAMIREZ', 'MORALES', 900000, '1964-03-13', 2, 15, 67, NULL, 3, 4, 1),
(230331279, 'NICOLAS', 'BENEDETTI', 'GUZMAN', 5000000, '1998-05-14', 1, 11, 99, NULL, 8, 4, 11),
(254974387, 'ISABELLA', 'QUINTERO', 'RIOS', 2460000, '1980-04-25', 2, 21, 56, NULL, 3, 3, 2),
(260391518, 'ESTEFFANIA', 'CARVAJAL', 'ARISTIZABAL', 2500000, '1994-06-22', 2, 26, 49, NULL, 3, 3, 8),
(263975799, 'ISABELLA', 'MAZUERA', 'MARTINEZ', 2900000, '1959-12-12', 2, 65, 98, 16, NULL, 4, 21),
(269515084, 'JUAN PABLO', 'GARCIA', 'CAÑAS', 1600000, '1986-05-30', 1, 14, 114, NULL, 13, 5, 10),
(319957250, 'VIVIANA', 'MOSQUERA', 'CRUZ', 800000, '1974-05-05', 2, 14, 37, NULL, 3, 3, 8),
(335385868, 'SEBASTIAN', 'SOLEIBE', 'GOMEZ', 1000000, '2000-10-06', 1, 15, 56, NULL, 3, 4, 1),
(336933833, 'ISABELLA', 'MARIN', 'RODRIGUEZ', 1200000, '1999-09-30', 2, 145, 158, NULL, 13, 7, 17),
(362760470, 'DIEGO ALEJANDRO', 'RUIZ', 'ARIZA', 700000, '1979-01-10', 1, 45, 48, 12, NULL, 3, 9),
(363179271, 'VICTOR', 'ROBLES', 'RUIZ', 4200000, '1984-04-04', 1, 97, 35, 15, NULL, 5, 18),
(364172399, 'ISABELLA', 'RODRIGUEZ', 'PEREZ', 6500000, '1994-04-09', 2, 50, 70, NULL, 7, 5, 10),
(429946089, 'LAURA NATHALIA', 'GUTIERREZ', 'REYES', 1680000, '1986-12-03', 2, 24, 94, NULL, 12, 3, 23),
(431699927, 'KEITTY ', 'LOPEZ', 'ARANDA', 1900000, '1987-09-29', 2, 23, 43, NULL, 12, 6, 23),
(442969563, 'ROBERTO', 'CANO', 'MONTOYA', 1400000, '1985-05-05', 1, 14, 102, 15, NULL, 2, 19),
(479425986, 'FEDERICO', 'INZUA', 'REYES', 2800000, '1975-06-06', 1, 65, 98, 18, NULL, 2, 15),
(579396386, 'MAURICIO', 'LOPEZ', 'CAMPIÑO', 500000, '1999-11-13', 1, 63, 79, 13, NULL, 5, 13),
(591894160, 'ANGELICA', 'VELASQUEZ', 'POSADA', 1300000, '1999-02-10', 2, 15, 178, NULL, 3, 4, 1),
(618418975, 'SEBASTIAN', 'REVELO', 'MONTANCHEZ', 1000000, '1999-11-26', 1, 54, 88, 14, NULL, 3, 4),
(628435612, 'JORGE ELIECER', 'BARRAGAN', 'GIRALDO', 850000, '1967-11-12', 1, 7, 77, 18, NULL, 7, 26),
(660237318, 'MARIANA', 'TABARES', 'MONTOYA', 1800000, '1988-09-12', 2, 12, 16, NULL, 3, 3, 5),
(679531369, 'DANNA ', 'ROJAS', 'LLANOS', 980000, '2000-12-26', 2, 49, 78, NULL, 6, 5, 22),
(694364209, 'JUAN CAMILO', 'CALDERON', 'LEON', 1700000, '1999-01-11', 1, 108, 250, NULL, 5, 4, 3),
(697032403, 'CRISTIANO', 'RONALDO', 'NAZARIO', 250000000, '1982-07-08', 1, 38, 75, NULL, 4, 6, 11),
(699480372, 'JUAN ESTEBAN', 'CAÑAS', 'ZAPATA', 2700000, '1999-04-07', 1, 11, 121, NULL, 13, 6, 21),
(710340994, 'MAURICIO', 'MONTOYA', 'ABADIA', 980000, '1995-06-08', 1, 4, 36, NULL, 9, 4, 3),
(768823339, 'YORDAN', 'DENILSON', 'QUINTERO', 1700000, '1999-11-28', 1, 45, 96, 12, NULL, 2, 12),
(774010023, 'CAMILO', 'SESTO', 'LOPERA', 2400000, '1985-05-15', 1, 35, 35, NULL, 17, 1, 6),
(789721882, 'LUIS HENRIQUE', 'MIRANDA', 'LEYTON', 4000000, '1952-12-18', 1, 36, 36, 9, NULL, 1, 14),
(791169189, 'JAMES DAVID', 'RODRIGUEZ', 'GARCIA', 500000000, '1993-01-14', 1, 56, 94, 19, NULL, 7, 26),
(802458821, 'JUAN SEBASTIAN', 'RODRIGUEZ', 'VESGA', 150000, '1994-08-17', 1, 18, 76, NULL, 17, 1, 14),
(851179656, 'RADAMEL FALCAO', 'GARCIA', 'SANTA', 18000000, '1981-03-11', 1, 62, 98, 9, NULL, 5, 18),
(878938016, 'ALFONSO', 'ZAPATA', 'MURILLO', 800000, '1987-01-14', 1, 7, 77, NULL, 12, 5, 24),
(916327439, 'SOFIA', 'ORREGO', 'SALAZAR', 3000000, '1974-04-11', 2, 12, 112, NULL, 15, 7, 26),
(954909614, 'LAURA', 'SANCHEZ', 'MIRANDA', 1200000, '1994-05-12', 2, 16, 43, 16, NULL, 5, 23),
(974378723, 'ABRAHAM', 'LOPERA', 'SANCHEZ', 9300000, '1956-12-03', 1, 87, 98, 16, NULL, 5, 24),
(991989224, 'DANIEL', 'CORREA', 'GONZALES', 750000, '1999-08-29', 1, 98, 125, 11, NULL, 4, 20),
(1112773181, 'JUAN FERNANDO', 'QUINTERO', 'MARTINEZ', 1500000, '1987-03-11', 1, 5, 55, 14, NULL, 3, 9),
(1112773184, 'PAULA ANDREA', 'MORALES', 'TAMES', 1500000, '1991-05-11', 2, 3, 29, 15, NULL, 3, 2),
(1112793169, 'JUAN PABLO', 'MORALES', 'TAMES', 3500000, '1999-03-11', 1, 15, 52, NULL, 3, 4, 1),
(1122145504, 'JULIAN EDUARDO', 'REYES', 'CALDERON', 1850000, '1999-08-23', 1, 6, 87, 20, NULL, 1, 25),
(1146206818, 'MARIANO', 'RIVAS', 'FUENZALIDA', 650000, '1978-09-12', 1, 54, 78, 21, NULL, 1, 6),
(1580929934, 'JHON FREDY', 'VELASQUEZ', 'ARANGO', 900000, '1984-07-12', 1, 2, 59, NULL, 4, 3, 11),
(1580929935, 'ISABELLA', 'RODRIGUEZ', 'PEREZ', 6500000, '1994-04-09', 2, 20, 40, NULL, 7, 5, 10);

--
-- Disparadores `empleado`
--
DELIMITER $$
CREATE TRIGGER `empleaDE_BD` BEFORE DELETE ON `empleado` FOR EACH ROW BEGIN
INSERT INTO auditoria(fecha, operacion, nombre, sueldo, fecha_nacimiento, usuario) VALUES
(now(), "DELETE", old.nombre, old.sueldo, old.fecha_nacimiento, CURRENT_USER());
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `empleaMo_MB` BEFORE UPDATE ON `empleado` FOR EACH ROW BEGIN
INSERT INTO auditoria(fecha, operacion, anterior_nombre, nombre, anterior_sueldo, sueldo, usuario) VALUES
(now(), "UPDATE", old.nombre, new.nombre, old.sueldo, new.sueldo, CURRENT_USER());
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `emplea_AI` AFTER INSERT ON `empleado` FOR EACH ROW INSERT INTO auditoria(fecha, operacion, nombre, sueldo, fecha_nacimiento, usuario) VALUES
(NOW(), "INSERT", NEW.nombre, NEW.sueldo, NEW.fecha_nacimiento, CURRENT_USER());
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `estrato`
--

CREATE TABLE `estrato` (
  `id_estrato` int(6) NOT NULL,
  `estrato` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `estrato`
--

INSERT INTO `estrato` (`id_estrato`, `estrato`) VALUES
(1, 'ESTRATO 1'),
(2, 'ESTRATO 2'),
(3, 'ESTRATO 3'),
(4, 'ESTRATO 4'),
(5, 'ESTRATO 5'),
(6, 'ESTRATO 6'),
(7, 'ESTRATO 7');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `jefe`
--

CREATE TABLE `jefe` (
  `id_jefe` int(6) NOT NULL,
  `fecha_inicio` date NOT NULL,
  `empleado_documento` int(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `jefe`
--

INSERT INTO `jefe` (`id_jefe`, `fecha_inicio`, `empleado_documento`) VALUES
(1, '2018-11-22', 1112793169),
(2, '2018-03-24', 31414884),
(3, '2017-05-19', 974378723),
(4, '2017-01-11', 16205700),
(5, '2016-09-12', 1122145504),
(6, '2017-10-08', 177287636),
(7, '2015-07-08', 768823339),
(8, '2016-09-14', 851179656),
(9, '2017-02-19', 260391518);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `lugar`
--

CREATE TABLE `lugar` (
  `id_lugar` int(6) NOT NULL,
  `lugar` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `lugar`
--

INSERT INTO `lugar` (`id_lugar`, `lugar`) VALUES
(1, 'PISO #1'),
(2, 'PISO #2'),
(3, 'PISO #3'),
(4, 'PISO #4'),
(5, 'PISO #5'),
(6, 'PISO #6'),
(7, 'PISO #7'),
(8, 'PISO #8'),
(9, 'PISO #9'),
(10, 'PISO #10');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `proyecto`
--

CREATE TABLE `proyecto` (
  `id_proyecto` int(6) NOT NULL,
  `proyecto` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `proyecto`
--

INSERT INTO `proyecto` (`id_proyecto`, `proyecto`) VALUES
(1, 'PROYECTO DE INVESTIGACION'),
(2, 'PROYECTO DE INNOVACION'),
(3, 'PROYECTO DE CIENCIAS'),
(4, 'PROYECTO DE EMPRENDIMIENTO'),
(5, 'PROYECTO DE AULA'),
(6, 'PROYECTO AMBIENTAL'),
(7, 'PROYECTO INTEGRADOR');

--
-- Disparadores `proyecto`
--
DELIMITER $$
CREATE TRIGGER `proyecDE_BD` BEFORE DELETE ON `proyecto` FOR EACH ROW BEGIN
INSERT INTO auditoria(fecha, operacion, nombre, usuario) VALUES
(now(), "DELETE", old.proyecto, CURRENT_USER());
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `proyecMo_MB` BEFORE UPDATE ON `proyecto` FOR EACH ROW BEGIN
INSERT INTO auditoria(fecha, operacion, anterior_nombre, nombre, usuario) VALUES
(now(), "UPDATE", old.proyecto, new.proyecto, CURRENT_USER());
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `proyec_AI` AFTER INSERT ON `proyecto` FOR EACH ROW INSERT INTO auditoria(fecha, operacion, nombre, usuario) VALUES
(NOW(), "INSERT", NEW.proyecto, CURRENT_USER());
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `proyecto_comun`
--

CREATE TABLE `proyecto_comun` (
  `proyecto_id_proyecto` int(6) NOT NULL,
  `comun_id_comun` int(6) NOT NULL,
  `num_horas` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `proyecto_comun`
--

INSERT INTO `proyecto_comun` (`proyecto_id_proyecto`, `comun_id_comun`, `num_horas`) VALUES
(1, 1, '05:00:00'),
(1, 2, '03:00:00'),
(1, 3, '02:00:00'),
(1, 12, '03:15:00'),
(1, 19, '01:00:00'),
(1, 20, '02:00:00'),
(1, 21, '00:30:00'),
(1, 32, '05:45:00'),
(2, 1, '05:00:00'),
(2, 4, '01:00:00'),
(2, 5, '03:00:00'),
(2, 6, '00:30:00'),
(2, 7, '06:00:00'),
(2, 13, '02:00:00'),
(2, 22, '05:00:00'),
(2, 23, '07:30:00'),
(2, 24, '00:40:00'),
(3, 2, '01:00:00'),
(3, 3, '03:00:00'),
(3, 8, '10:00:00'),
(3, 9, '11:30:00'),
(3, 14, '03:00:00'),
(3, 25, '10:00:00'),
(3, 26, '13:00:00'),
(3, 27, '04:30:00'),
(3, 28, '06:40:00'),
(3, 32, '13:00:00'),
(3, 33, '10:30:00'),
(3, 34, '14:20:00'),
(3, 35, '03:50:00'),
(4, 7, '02:00:00'),
(4, 10, '07:00:00'),
(4, 11, '10:10:00'),
(4, 29, '01:00:00'),
(4, 30, '03:00:00'),
(4, 31, '01:00:00'),
(5, 4, '03:50:00'),
(5, 12, '05:40:00'),
(5, 13, '08:40:00'),
(5, 14, '09:00:00'),
(5, 15, '00:50:00'),
(5, 18, '07:00:00'),
(5, 26, '08:00:00'),
(5, 36, '01:00:00'),
(6, 5, '01:10:00'),
(6, 9, '05:40:00'),
(6, 16, '03:00:00'),
(6, 17, '01:40:00'),
(6, 18, '04:00:00'),
(6, 29, '03:00:00');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sexo`
--

CREATE TABLE `sexo` (
  `id_sexo` int(6) NOT NULL,
  `sexo` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `sexo`
--

INSERT INTO `sexo` (`id_sexo`, `sexo`) VALUES
(1, 'MASCULINO'),
(2, 'FEMENINO');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `supervisor`
--

CREATE TABLE `supervisor` (
  `id_supervisor` int(6) NOT NULL,
  `relacion_empleado` varchar(45) NOT NULL,
  `empleado_documento` int(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `supervisor`
--

INSERT INTO `supervisor` (`id_supervisor`, `relacion_empleado`, `empleado_documento`) VALUES
(1, 'TRABAJO', 697032403),
(2, 'TRABAJO', 147308165),
(3, 'TRABAJO', 479425986),
(4, 'TRABAJO', 628435612),
(5, 'TRABAJO', 431699927),
(6, 'TRABAJO', 789721882);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `supervisor_proyecto`
--

CREATE TABLE `supervisor_proyecto` (
  `supervisor_id_supervisor` int(6) NOT NULL,
  `proyecto_id_proyecto` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `supervisor_proyecto`
--

INSERT INTO `supervisor_proyecto` (`supervisor_id_supervisor`, `proyecto_id_proyecto`) VALUES
(1, 1),
(1, 6),
(2, 2),
(2, 3),
(2, 5),
(3, 3),
(4, 4),
(5, 5),
(6, 6);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ubicacion`
--

CREATE TABLE `ubicacion` (
  `id_ubicacion` int(6) NOT NULL,
  `ubicacion` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `ubicacion`
--

INSERT INTO `ubicacion` (`id_ubicacion`, `ubicacion`) VALUES
(1, 'SALA DE JUNTAS'),
(2, 'AUDITORIO PRINCIPAL'),
(3, 'PARQUE '),
(4, 'SALA DE CONFERENCIAS');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ubicacion_proyecto`
--

CREATE TABLE `ubicacion_proyecto` (
  `ubicacion_id_ubicacion` int(6) NOT NULL,
  `proyecto_id_proyecto` int(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `ubicacion_proyecto`
--

INSERT INTO `ubicacion_proyecto` (`ubicacion_id_ubicacion`, `proyecto_id_proyecto`) VALUES
(1, 2),
(1, 4),
(2, 3),
(2, 5),
(3, 5),
(3, 6),
(4, 1),
(4, 2),
(4, 3),
(4, 4);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `barrio`
--
ALTER TABLE `barrio`
  ADD PRIMARY KEY (`id_barrio`);

--
-- Indices de la tabla `calle`
--
ALTER TABLE `calle`
  ADD PRIMARY KEY (`id_calle`);

--
-- Indices de la tabla `carrera`
--
ALTER TABLE `carrera`
  ADD PRIMARY KEY (`id_carrera`);

--
-- Indices de la tabla `comun`
--
ALTER TABLE `comun`
  ADD PRIMARY KEY (`id_comun`),
  ADD KEY `fk_comun_empleado1` (`empleado_documento`),
  ADD KEY `fk_comun_departamento1` (`departamento_id_departamento`);

--
-- Indices de la tabla `comun_supervisor`
--
ALTER TABLE `comun_supervisor`
  ADD PRIMARY KEY (`comun_id_comun`,`supervisor_id_supervisor`),
  ADD KEY `fk_comun_has_supervisor_supervisor1` (`supervisor_id_supervisor`);

--
-- Indices de la tabla `departamento`
--
ALTER TABLE `departamento`
  ADD PRIMARY KEY (`id_departamento`),
  ADD KEY `fk_departamento_jefe1` (`jefe_id_jefe`);

--
-- Indices de la tabla `departamento_lugar`
--
ALTER TABLE `departamento_lugar`
  ADD PRIMARY KEY (`departamento_id_departamento`,`lugar_id_lugar`),
  ADD KEY `fk_departamento_has_lugar_lugar1` (`lugar_id_lugar`);

--
-- Indices de la tabla `departamento_proyecto`
--
ALTER TABLE `departamento_proyecto`
  ADD PRIMARY KEY (`departamento_id_departamento`,`proyecto_id_proyecto`),
  ADD KEY `fk_departamento_has_proyecto_proyecto1` (`proyecto_id_proyecto`);

--
-- Indices de la tabla `empleado`
--
ALTER TABLE `empleado`
  ADD PRIMARY KEY (`documento`),
  ADD KEY `fk_empleado_sexo1` (`sexo_id_sexo`),
  ADD KEY `fk_empleado_calle1` (`calle_id_calle`),
  ADD KEY `fk_empleado_carrera1` (`carrera_id_carrera`),
  ADD KEY `fk_empleado_estrato1` (`estrato_id_estrato`),
  ADD KEY `fk_empleado_barrio1` (`barrio_id_barrio`);

--
-- Indices de la tabla `estrato`
--
ALTER TABLE `estrato`
  ADD PRIMARY KEY (`id_estrato`);

--
-- Indices de la tabla `jefe`
--
ALTER TABLE `jefe`
  ADD PRIMARY KEY (`id_jefe`),
  ADD KEY `fk_jefe_empleado1` (`empleado_documento`);

--
-- Indices de la tabla `lugar`
--
ALTER TABLE `lugar`
  ADD PRIMARY KEY (`id_lugar`);

--
-- Indices de la tabla `proyecto`
--
ALTER TABLE `proyecto`
  ADD PRIMARY KEY (`id_proyecto`);

--
-- Indices de la tabla `proyecto_comun`
--
ALTER TABLE `proyecto_comun`
  ADD PRIMARY KEY (`proyecto_id_proyecto`,`comun_id_comun`),
  ADD KEY `fk_proyecto_has_comun_comun1` (`comun_id_comun`);

--
-- Indices de la tabla `sexo`
--
ALTER TABLE `sexo`
  ADD PRIMARY KEY (`id_sexo`);

--
-- Indices de la tabla `supervisor`
--
ALTER TABLE `supervisor`
  ADD PRIMARY KEY (`id_supervisor`),
  ADD KEY `fk_supervisor_empleado1` (`empleado_documento`);

--
-- Indices de la tabla `supervisor_proyecto`
--
ALTER TABLE `supervisor_proyecto`
  ADD PRIMARY KEY (`supervisor_id_supervisor`,`proyecto_id_proyecto`),
  ADD KEY `fk_supervisor_has_proyecto_proyecto1` (`proyecto_id_proyecto`);

--
-- Indices de la tabla `ubicacion`
--
ALTER TABLE `ubicacion`
  ADD PRIMARY KEY (`id_ubicacion`);

--
-- Indices de la tabla `ubicacion_proyecto`
--
ALTER TABLE `ubicacion_proyecto`
  ADD PRIMARY KEY (`ubicacion_id_ubicacion`,`proyecto_id_proyecto`),
  ADD KEY `fk_ubicacion_has_proyecto_proyecto1` (`proyecto_id_proyecto`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `calle`
--
ALTER TABLE `calle`
  MODIFY `id_calle` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- AUTO_INCREMENT de la tabla `carrera`
--
ALTER TABLE `carrera`
  MODIFY `id_carrera` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT de la tabla `comun`
--
ALTER TABLE `comun`
  MODIFY `id_comun` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=37;

--
-- AUTO_INCREMENT de la tabla `departamento`
--
ALTER TABLE `departamento`
  MODIFY `id_departamento` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT de la tabla `empleado`
--
ALTER TABLE `empleado`
  MODIFY `documento` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1580929936;

--
-- AUTO_INCREMENT de la tabla `estrato`
--
ALTER TABLE `estrato`
  MODIFY `id_estrato` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT de la tabla `jefe`
--
ALTER TABLE `jefe`
  MODIFY `id_jefe` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT de la tabla `lugar`
--
ALTER TABLE `lugar`
  MODIFY `id_lugar` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT de la tabla `sexo`
--
ALTER TABLE `sexo`
  MODIFY `id_sexo` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT de la tabla `supervisor`
--
ALTER TABLE `supervisor`
  MODIFY `id_supervisor` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT de la tabla `ubicacion`
--
ALTER TABLE `ubicacion`
  MODIFY `id_ubicacion` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `comun`
--
ALTER TABLE `comun`
  ADD CONSTRAINT `fk_comun_departamento1` FOREIGN KEY (`departamento_id_departamento`) REFERENCES `departamento` (`id_departamento`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_comun_empleado1` FOREIGN KEY (`empleado_documento`) REFERENCES `empleado` (`documento`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `comun_supervisor`
--
ALTER TABLE `comun_supervisor`
  ADD CONSTRAINT `fk_comun_has_supervisor_comun1` FOREIGN KEY (`comun_id_comun`) REFERENCES `comun` (`id_comun`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_comun_has_supervisor_supervisor1` FOREIGN KEY (`supervisor_id_supervisor`) REFERENCES `supervisor` (`id_supervisor`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `departamento`
--
ALTER TABLE `departamento`
  ADD CONSTRAINT `fk_departamento_jefe1` FOREIGN KEY (`jefe_id_jefe`) REFERENCES `jefe` (`id_jefe`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `departamento_lugar`
--
ALTER TABLE `departamento_lugar`
  ADD CONSTRAINT `fk_departamento_has_lugar_departamento` FOREIGN KEY (`departamento_id_departamento`) REFERENCES `departamento` (`id_departamento`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_departamento_has_lugar_lugar1` FOREIGN KEY (`lugar_id_lugar`) REFERENCES `lugar` (`id_lugar`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `departamento_proyecto`
--
ALTER TABLE `departamento_proyecto`
  ADD CONSTRAINT `fk_departamento_has_proyecto_departamento1` FOREIGN KEY (`departamento_id_departamento`) REFERENCES `departamento` (`id_departamento`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_departamento_has_proyecto_proyecto1` FOREIGN KEY (`proyecto_id_proyecto`) REFERENCES `proyecto` (`id_proyecto`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `empleado`
--
ALTER TABLE `empleado`
  ADD CONSTRAINT `fk_empleado_barrio1` FOREIGN KEY (`barrio_id_barrio`) REFERENCES `barrio` (`id_barrio`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_empleado_calle1` FOREIGN KEY (`calle_id_calle`) REFERENCES `calle` (`id_calle`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_empleado_carrera1` FOREIGN KEY (`carrera_id_carrera`) REFERENCES `carrera` (`id_carrera`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_empleado_estrato1` FOREIGN KEY (`estrato_id_estrato`) REFERENCES `estrato` (`id_estrato`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_empleado_sexo1` FOREIGN KEY (`sexo_id_sexo`) REFERENCES `sexo` (`id_sexo`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `jefe`
--
ALTER TABLE `jefe`
  ADD CONSTRAINT `fk_jefe_empleado1` FOREIGN KEY (`empleado_documento`) REFERENCES `empleado` (`documento`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `proyecto_comun`
--
ALTER TABLE `proyecto_comun`
  ADD CONSTRAINT `fk_proyecto_has_comun_comun1` FOREIGN KEY (`comun_id_comun`) REFERENCES `comun` (`id_comun`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_proyecto_has_comun_proyecto1` FOREIGN KEY (`proyecto_id_proyecto`) REFERENCES `proyecto` (`id_proyecto`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `supervisor`
--
ALTER TABLE `supervisor`
  ADD CONSTRAINT `fk_supervisor_empleado1` FOREIGN KEY (`empleado_documento`) REFERENCES `empleado` (`documento`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `supervisor_proyecto`
--
ALTER TABLE `supervisor_proyecto`
  ADD CONSTRAINT `fk_supervisor_has_proyecto_proyecto1` FOREIGN KEY (`proyecto_id_proyecto`) REFERENCES `proyecto` (`id_proyecto`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_supervisor_has_proyecto_supervisor1` FOREIGN KEY (`supervisor_id_supervisor`) REFERENCES `supervisor` (`id_supervisor`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Filtros para la tabla `ubicacion_proyecto`
--
ALTER TABLE `ubicacion_proyecto`
  ADD CONSTRAINT `fk_ubicacion_has_proyecto_proyecto1` FOREIGN KEY (`proyecto_id_proyecto`) REFERENCES `proyecto` (`id_proyecto`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_ubicacion_has_proyecto_ubicacion1` FOREIGN KEY (`ubicacion_id_ubicacion`) REFERENCES `ubicacion` (`id_ubicacion`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
