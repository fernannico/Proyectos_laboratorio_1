/*
 * jugadores.h
 *
 *  Created on: 18 oct. 2022
 *      Author: User
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

#define LIBRE 0
#define CARGADO 1
#define BAJADO 2
#define TAMJ 3000

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;


void CargarJugadoresHarcodeados(eJugador jugadores[], int size);
void InicializarEstadoJugadores(eJugador jugadores[], int size);
int BuscarEspacioLibreJugadores(eJugador jugadores[], int size);

int CargarPosicion(eJugador jugadores[], int indiceLibre);

int buscarIndicePorIdJugador(eJugador jugadores[], int sizeJugadores, int id);
void OrdenarJugadoresPorId(eJugador jugadores[], int sizeJugadores);

#endif /* JUGADORES_H_ */
