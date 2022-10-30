/*
 * output.h
 *
 *  Created on: 19 oct. 2022
 *      Author: User
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include "jugadores.h"
#include "confederaciones.h"

/// \brief para mostrar el menu principal
void MostrarMenuPrincipal();

/// \brief para mostrar el submenu de posiciones en el alta de jugadores
void MostrarSubmenuPosicion();

/// \brief para mostrar el submenu de modificacion de jugadores
void MostrarSubmenuModificacion();

/// \brief para mostrar las confederaciones con sus detalles
/// \param confederaciones dato del tipo estructura para mostrar el detalle de sus campos
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \param contadorConfederaciones puntero al espacio de memoria donde se encuentra el contador de confederaciones
/// \return retorna 1 si hay confederaciones cargadas y las muestra y -1 si no las hay, no mostrando
int MostrarDetallesConfederaciones(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones);

/// \brief para mostrar el listado de confederaciones con sus jugadores
/// \param confederaciones dato del tipo estructura eConfederacion usado para mostrar el detalle de sus campos
/// \param jugadores dato del tipo estructura eJugador usado para mostrar el detalle de sus campos
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \param sizeJugadores  tamaño del array de estructuras jugadores
void MostrarConfederacionesConJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores);

/// \brief para mostrar las confederaciones cuyos estados estan BAJADO
/// \param confederaciones  dato del tipo estructura eConfederacion usado para mostrar el detalle de sus campos
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \return retorna 1 si la confederacion se encuentra bajada mostrando sus detalles y -1 si no
int MostrarConfederacionesBajadas(eConfederacion confederaciones[], int sizeConfed);

/// \brief informa la region con mas jugadores y sus detalles
/// \param confederaciones dato del tipo estructura eConfederacion usado para mostrar el detalle de sus campos
/// \param jugadores  dato del tipo estructura usado para mostrar el detalle de sus campos
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \param sizeJugadores  tamaño del array de estructuras jugadores
/// \param contadorConfederaciones puntero al espacio de memoria donde se encuentra el contador de confederaciones
/// \param contadorJugadores puntero al espacio de memoria donde se encuentra el contador de jugadores
void MostrarRegionConMasJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores);

/// \brief para mostrar los detalles de los jugadores cargados
/// \param jugadores  dato del tipo estructura eJugador usado para mostrar el detalle de sus campos
/// \param confederaciones dato del tipo estructura eConfederacion usado para mostrar el detalle de sus campos
/// \param sizeJugadores tamaño del array de estructuras jugadores
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \param contadorJugadores puntero al espacio de memoria donde se encuentra el contador de confederaciones
/// \return retorna 1 si los jugadores se encuentran cargados mostrando sus detalles y -1 si no
int MostrarDetallesJugadores(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int*contadorJugadores);

/// \brief para mostrar los detalles de una confederacion tomando el id como parametro
/// \param confederaciones dato del tipo estructura eConfederacion usado para mostrar el detalle de sus campos
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \param contadorConfederaciones puntero al espacio de memoria donde se encuentra el contador de confederaciones
/// \param id el id que se usa como parametro
/// \return retorna 1 si la confederacion esta cargada y se muestran los datos, y -1 si no
int MostrarConfederacionPorId(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones, int id);

/// \brief para mostrar el menu de informes
void MostrarMenuInformes();

/// \brief para mostrar los resultados del informe de salarios
/// \param acumuladorSalarios el acumulador total de salario de todos los jugadores cargados cuyas confederaciones estan cargadas
/// \param promedioSalarios el promedio entre los salarios totales y la cantidad de ellos
/// \param contadorJugadoresMayorProm contador de jugadores que superan el promedio
void MostrarInformeSalarios(float acumuladorSalarios, float promedioSalarios, int contadorJugadoresMayorProm);

/// \brief para mostar las opciones de ABM de confederaciones
void MostrarMenuABMConfed();

/// \brief para mostrar el menu de opciones de modificacion de confederaciones
void MostrarModificacionConfed();

#endif /* OUTPUT_H_ */
