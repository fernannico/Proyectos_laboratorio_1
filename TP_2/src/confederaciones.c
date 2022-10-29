/*
 * confederaciones.c
 *
 *  Created on: 18 oct. 2022
 *      Author: User
 */
#include "nexo.h"

void CargarConfederacionesHarcodeadas(eConfederacion confederaciones[], int size){
	eConfederacion auxiliar[] = { {100, "CONMEBOL", "SUDAMERICA", 1916, BAJADO}, {101, "UEFA", "EUROPA", 1954, CARGADO}, {102, "AFC", "ASIA", 1954, CARGADO},
					{103, "CAF", "AFRICA", 1957, CARGADO}, {104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, CARGADO}, {105, "OFC", "OCEANIA", 1966, BAJADO}};

	for(int i = 0; i<size; i++){
		confederaciones[i] = auxiliar[i];
	}
}

///esto va en output?

int ContarConfederacionesCargadas(int* contadorConfederaciones, eConfederacion confederaciones[], int size){
	int retorno;
	int contadorConfedAux = 0;
	retorno = 0;

	if(contadorConfederaciones != NULL && size > 0){
		retorno = 1;
		for(int i = 0; i<size; i++){
			if(confederaciones[i].isEmpty == CARGADO){
				contadorConfedAux++;
			}
		}
		*contadorConfederaciones = contadorConfedAux;
	}

	return retorno;
}

int ValidarConfederacionCargada(eConfederacion confederaciones[], int* contadorConfederaciones, int size){
	int retorno = 0;

	if(ContarConfederacionesCargadas(contadorConfederaciones, confederaciones, size)== 1){
		if(*contadorConfederaciones > 0){
			retorno = 1;
		}
	}

	return retorno;
}

///cambiar que esta C
int buscarIndiceConfederacionPorId(eConfederacion confederaciones[],int id,int sizeConfed){
	int indice = -1;

	if(confederaciones != NULL && sizeConfed > 0){
		for(int i=0; i<sizeConfed; i++){
			if(confederaciones[i].id == id){
				indice = i;
				break;
			}
		}
	}

	return indice;
}


int MostrarConfederacionPorId(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones, int id){
	int retorno = -1;

	if(confederaciones != NULL && sizeConfed > 0){
		if(ValidarConfederacionCargada(confederaciones, contadorConfederaciones, sizeConfed)==1){
			for(int i = 0; i< sizeConfed; i++){
				if(confederaciones[i].isEmpty == CARGADO){
					if(confederaciones[i].id == id){
						retorno = 1;
						printf("\n============================================================");
						printf("\n| %-5s| %-9s| %-23s| %-15s|", "ID", "NOMBRE", "REGION", "AÑO CREACION");
						printf("\n------------------------------------------------------------");
						printf("\n| %-5d| %-9s| %-23s|   %-5d       |", confederaciones[i].id, confederaciones[i].nombre,
																		confederaciones[i].region, confederaciones[i].anioCreacion);
						break;
					}
				}
			}
			printf("\n============================================================");
		}
	}
	return retorno;
}

int ValidarConfederacionCargadaPorId(eConfederacion confederaciones[], int sizeConfed, int id){
	int retorno = -1;

	if(confederaciones != NULL && sizeConfed > 0){
		for(int c = 0; c<sizeConfed;c++){
			if(confederaciones[c].isEmpty == CARGADO && confederaciones[c].id == id){
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
