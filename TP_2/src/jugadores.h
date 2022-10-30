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

/// \brief para cargar un array de estructuras de jugadores
/// \param jugadores dato del tipo estructura para cargar los campos de jugadores
/// \param size tamaño del array de estructuras jugadores
void CargarJugadoresHarcodeados(eJugador jugadores[], int size);

/// \brief para inicializar el campo estado del array de jugadores en LIBRES
/// \param jugadores dato del tipo estructura cuyos campos estado seran asignados como LIBRES en el array
/// \param size tamaño del array de estructuras jugadores
void InicializarEstadoJugadores(eJugador jugadores[], int size);

/// \brief para buscar el primer espacio libre del array
/// \param jugadores dato del tipo estructura donde se buscara el estado LIBRE
/// \param size tamaño del array de estructuras jugadores
/// \return retorna el primer indice del array cuyo elemento tiene el estado libre
int BuscarEspacioLibreJugadores(eJugador jugadores[], int size);

/// \brief  para cargar el campo posicion de un jugador
/// \param jugadores dato del tipo estructura donde cargar el campo posicion
/// \param indiceLibre el indice donde sera cargado la posicion
/// \return retorna 0 si pudo cargar la posicion y -1 si no fue posible
int CargarPosicion(eJugador jugadores[], int indiceLibre);

/// \brief dado un id de un jugador, nos retorna el indice del array donde se encuentra
/// \param jugadores dato del tipo estructura donde buscar el indice
/// \param sizeJugadores  tamaño del array de estructuras jugadores
/// \param id el ID del jugador de referencia para obtener el indice
/// \return retorna el indice donde se encuentra el jugador con el respectivo id
int buscarIndicePorIdJugador(eJugador jugadores[], int sizeJugadores, int id);

/// \brief para ordenar los jugadores por el id
/// \param jugadores dato del tipo estructura usado para ordenar
/// \param sizeJugadores tamaño del array de estructuras jugadores
void OrdenarJugadoresPorId(eJugador jugadores[], int sizeJugadores);

#endif /* JUGADORES_H_ */
