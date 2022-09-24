/*
 * output.h
 *
 *  Created on: 17 sep. 2022
 *      Author: User
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_
#include <stdio.h>
#include <stdlib.h>

/// @brief imprime el menu principal en consola
/// @param costosHospedaje el valor acumulado de costos de hospedaje cargados hasta el momento
/// @param costosComida el valor acumulado de costos de comida cargados hasta el momento
/// @param costosTransporte el valor acumulado de costos de transporte cargados hasta el momento
/// @param contadorArqueros el valor acumulado de Arqueros cargados hasta el momento
/// @param contadorDefensores el valor acumulado de Defensores cargados hasta el momento
/// @param contadorMediocampistas el valor acumulado de Mediocampistas cargados hasta el momento
/// @param contadorDelanteros el valor acumulado de Delanteros cargados hasta el momento
void ImprimirMenu(int costosHospedaje, int costosComida, int costosTransporte, int contadorArqueros, int contadorDefensores, int contadorMediocampistas, int contadorDelanteros);

/// @brief imprime el submenu de costos de mantenimiento
/// @param costosHospedaje el valor acumulado de costos de hospedaje cargados hasta el momento
/// @param costosComida el valor acumulado de costos de comida cargados hasta el momento
/// @param costosTransporte el valor acumulado de costos de transporte cargados hasta el momento
void ImprimirSubmenuMantenimiento(int costosHospedaje, int costosComida, int costosTransporte);

/// @brief imprime el submenu de jugadores a elegir y la cantidad ingresada hasta el momento por posicion
/// @param contadorArqueros el valor acumulado de Arqueros cargados hasta el momento
/// @param contadorDefensores el valor acumulado de Defensores cargados hasta el momento
/// @param contadorMediocampistas el valor acumulado de Mediocampistas cargados hasta el momento
/// @param contadorDelanteros el valor acumulado de Delanteros cargados hasta el momento
void ImprimirCantidadJugadores(int contadorArqueros, int contadorDefensores, int contadorMediocampistas, int contadorDelanteros);

/// @brief imprime el submenu de confederaciones a elegir y la cantidad ingresada hasta el momento por cada una
/// @param uefa el valor acumulado de jugadores cargados en la UEFA hasta el momento
/// @param conmebol el valor acumulado de jugadores cargados en la CONMEBOL hasta el momento
/// @param concacaf el valor acumulado de jugadores cargados en la CONCACAF hasta el momento
/// @param afc el valor acumulado de jugadores cargados en la AFC hasta el momento
/// @param ofc el valor acumulado de jugadores cargados en la OFC hasta el momento
/// @param caf el valor acumulado de jugadores cargados en la CAF hasta el momento
void ImprimirSubmenuConfederaciones(int uefa, int conmebol, int concacaf, int afc, int ofc, int caf);

/// @brief imprime los calculos de promedio de jugadores de cada mercado.
/// @param promedioUefa el resultado del promedio de jugadores de la UEFA
/// @param promedioConmebol el resultado del promedio de jugadores de la CONMEBOL
/// @param promedioConcacaf el resultado del promedio de jugadores de la CONCACAF
/// @param promedioAfc el resultado del promedio de jugadores de la AFC
/// @param promedioOfc el resultado del promedio de jugadores de la OFC
/// @param promedioCaf el resultado del promedio de jugadores de la CAF
void ImprimirResultados(float promedioUefa, float promedioConmebol, float promedioConcacaf, float promedioAfc, float promedioOfc, float promedioCaf);

/// @brief para validar si se ingresaron valores en las opciones 1 y/o 2
/// @param banderaOpcion1 variable que va a indicar si se ingresaron todos los valores en la opcion 1
/// @param banderaOpcion2 variable que va a indicar si se ingresaron todos los valores en la opcion 2
/// @return retorna 0 si falta cargar datos y 1 si ya se cargaron los datos en ambas opciones
int ValidarIngresosDeDatos(int banderaOpcion1, int banderaOpcion2);

#endif /* OUTPUT_H_ */
