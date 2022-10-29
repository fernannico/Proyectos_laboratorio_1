/*
 * confederaciones.h
 *
 *  Created on: 18 oct. 2022
 *      Author: User
 */

#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_
#include <stdio.h>
#include <stdlib.h>

#define LIBRE 0
#define CARGADO 1
#define BAJADO 2
#define TAMC 6

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;
}eConfederacion;

void CargarConfederacionesHarcodeadas(eConfederacion confederaciones[], int size);
int ContarConfederacionesCargadas(int* contadorConfederaciones, eConfederacion confederaciones[], int size);
int ValidarConfederacionCargada(eConfederacion confederaciones[], int* contadorConfederaciones, int size);
int buscarIndiceConfederacionPorId(eConfederacion confederaciones[],int id,int sizeConfed);
int MostrarConfederacionPorId(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones, int id);
int ValidarConfederacionCargadaPorId(eConfederacion confederaciones[], int sizeConfed, int id);

#endif /* CONFEDERACIONES_H_ */
