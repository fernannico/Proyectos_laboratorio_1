/*
 * jugadores.c
 *
 *  Created on: 18 oct. 2022
 *      Author: User
 */
#include "nexo.h"

void CargarJugadoresHarcodeados(eJugador jugadores[], int size){
	eJugador auxiliar[] = { {1, "Lionel Messi", "Delantero", 10, 104, 200000, 5, CARGADO}, {2, "Enzo Copetti", "Mediocampo", 9, 103, 86000, 4, CARGADO},
							{3, "Palermo", "Delantero", 9, 103, 75000, 3, CARGADO}, {4, "Neymar", "Delantero", 10, 104, 200000, 5, CARGADO}};

	for(int i = 0; i<size; i++){
		if(auxiliar[i].isEmpty == CARGADO)
			jugadores[i] = auxiliar[i];
	}
}
///--------------------------------------------------------------

void InicializarEstadoJugadores(eJugador jugadores[], int size){
	for(int i = 0; i<size; i++){
		jugadores[i].isEmpty = LIBRE;
	}
}

int BuscarEspacioLibreJugadores(eJugador jugadores[], int size){
	int indiceLibre = -1;

	for(int i = 0; i < size; i++){
		if(jugadores[i].isEmpty == LIBRE){
			indiceLibre = i;
			break;
		}
	}
	return indiceLibre;
}

///--------------------------------------------------------------

int ContarJugadoresCargados(int* contadorJugadores, eJugador jugadores[], int size){
	int retorno;
	int contadorJugadoresAux = 0;
	retorno = 0;

	if(contadorJugadores != NULL && size > 0){
		retorno = 1;
		for(int i = 0; i<size; i++){
			if(jugadores[i].isEmpty == CARGADO){
				contadorJugadoresAux++;
			}
		}
		*contadorJugadores = contadorJugadoresAux;
	}

	return retorno;
}

int ValidarJugadorCargado(eJugador jugadores[], int* contadorJugadores, int size){
	int retorno = 0;

	if(ContarJugadoresCargados(contadorJugadores, jugadores, size)==1){
		if(*contadorJugadores > 0){
			retorno = 1;
		}
	}

	return retorno;
}


int CargarPosicion(eJugador jugadores[], int indiceLibre){
	int posicion;
	int retorno = -1;

	MostrarSubmenuPosicion();
	if(utn_getNumero(&posicion, "\nPosicion: ", "\nError", 1, 4, 1)== 0){
		retorno = 0;
		switch (posicion) {
			case 1:
				strcpy(jugadores[indiceLibre].posicion, "Arquero");
				break;
			case 2:
				strcpy(jugadores[indiceLibre].posicion, "Defensor");
				break;
			case 3:
				strcpy(jugadores[indiceLibre].posicion, "Mediocampo");
				break;
			case 4:
				strcpy(jugadores[indiceLibre].posicion, "Delantero");
				break;
			default:
				printf("\Error");
				break;
		}
	}

	return retorno;
}

void OrdenarJugadoresPorId(eJugador jugadores[], int sizeJugadores){
	eJugador jugadorAux;

	for(int i = 0;i<sizeJugadores-1; i++){
		for(int j = i+1; j<sizeJugadores; j++){
			if(jugadores[j].isEmpty == CARGADO && jugadores[i].id > jugadores[j].id){
				jugadorAux = jugadores[i];
				jugadores[i] = jugadores[j];
				jugadores[j] = jugadorAux;
			}
		}
	}
}


int CalcularInformeSalarios(eJugador jugadores[], int sizeJugadores, int* contadorJugadores){
	int retorno = -1;
	float acumuladorSalarios;
	float promedioSalarios;
	int contadorJugadoresMayorProm;
	acumuladorSalarios = 0;
	contadorJugadoresMayorProm = 0;

	acumuladorSalarios = CalcularTotalSalarios(jugadores, sizeJugadores, contadorJugadores);
	promedioSalarios = CalcularPromedio(acumuladorSalarios, *contadorJugadores);

	for(int i = 0; i < sizeJugadores;i++){
		if(jugadores[i].isEmpty == CARGADO && jugadores[i].salario > promedioSalarios){
			contadorJugadoresMayorProm++;
		}
	}

	MostrarInformeSalarios(acumuladorSalarios, promedioSalarios, contadorJugadoresMayorProm);

	return retorno;
}

float CalcularTotalSalarios(eJugador jugadores[], int sizeJugadores, int* contadorJugadores){
	float acumulador;
	acumulador = 0;

	if(ValidarJugadorCargado(jugadores, contadorJugadores, sizeJugadores)==1){
		for(int i = 0; jugadores[i].isEmpty == LIBRE || i < sizeJugadores; i++){
			if(jugadores[i].isEmpty == CARGADO){
				acumulador += jugadores[i].salario;
			}
		}
	}
	return acumulador;
}

///--------------------------------------------------------------

int buscarIndicePorIdJugador(eJugador jugadores[], int sizeJugadores, int id){
	int indice;

	if(jugadores != NULL && sizeJugadores > 0){
		for(int i = 0; i<sizeJugadores;i++){
			if(id == jugadores[i].id){
				indice = i;
				break;
			}
		}
	}
	return indice;
}





