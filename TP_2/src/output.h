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

void MostrarMenuPrincipal();
void MostrarSubmenuPosicion();
void MostrarSubmenuModificacion();

int MostrarDetallesConfederaciones(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones);
void MostrarConfederacionesConJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores);
int MostrarConfederacionesBajadas(eConfederacion confederaciones[], int sizeConfed);
void MostrarConfederacionesConMasJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores);

int MostrarDetallesJugadores(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int*contadorJugadores);
int MostrarConfederacionPorId(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones, int id);

void MostrarMenuInformes();
void MostrarInformeSalarios(float acumuladorSalarios, float promedioSalarios, int contadorJugadoresMayorProm);
void MostrarMenuABMConfed();
void MostrarModificacionConfed();

#endif /* OUTPUT_H_ */
