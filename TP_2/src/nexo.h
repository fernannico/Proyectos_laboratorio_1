/*
 * nexo.h
 *
 *  Created on: 27 oct. 2022
 *      Author: User
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "jugadores.h"
#include "confederaciones.h"
#include "output.h"

void CargarJugador(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int* codigoAutoIncremental, int* contadorConfederaciones);
int AltaJugador(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int codigoAutoIncremental, int* contadorConfederaciones);
void DarDeBajaJugador(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int* contadorJugadores, int codigoAutoIncremental);
void ModificarJugador(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int* contadorJugadores, int* contadorConfederaciones, int codigoAutoIncremental);
int OrdenarJugadoresPorConfedYNombre(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int* contadorJugadores, int* contadorConfederaciones);
int ObtenerIndiceConfedMasAnios(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones);
int AcumularAniosConfed(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int indice/*, int* contadorConfederaciones*/);
int informarConfederacionMasAnios(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones);

int ContarJugadoresConfed(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int indice/*, int* contadorConfederaciones*/);
int ObtenerIndiceConfedMasJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores);
void MostrarConfederacionesConMasJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores);

#endif /* NEXO_H_ */
