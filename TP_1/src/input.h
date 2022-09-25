/*
 * input.h
 *
 *  Created on: 19 sep. 2022
 *      Author: User
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define UEFA 1
#define CONMEBOL 2
#define CONCACAF 3
#define AFC 4
#define OFC 5
#define CAF 6

int esNumerica(char * cadena, int limite);

int getInt(int * pResultado);

int myGets(char * cadena, int longitud);

int utn_getNumero(int * pResultado, char* mensaje, char * mensajeError, int minimo, int maximo, int reintentos);

int esFlotante(char* cadena);

int getFloat(float* pResultado);

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

char ValidarSeguirNoSeguir(char * mensaje, char * mensajeError);

void CargarUnJugador(int* numeroCamiseta, int* pUefa, int* pConmebol, int* pConcacaf, int* pAfc, int* pOfc, int* pCaf);

#endif /* INPUT_H_ */
