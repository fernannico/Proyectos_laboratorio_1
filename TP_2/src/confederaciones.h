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
#define TAMC 10

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;
}eConfederacion;

void CargarConfederacionesHarcodeadas(eConfederacion confederaciones[], int size);
int ValidarConfederacionBajada(eConfederacion confederaciones[], int sizeConfed);
void InicializarEstadoConfederaciones(eConfederacion confederaciones[], int sizeConfed);
int BuscarEspacioLibreConfed(eConfederacion confederaciones[], int sizeConfed);
int CargarNuevaConfederacion(eConfederacion confederaciones[], int sizeConfed, int idAutoIncrementalConfed, int* contadorConfederaciones);
void CargarConfederacionesBajadas(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones);

void DarDeBajaConfederacion(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones);
void ModificarConfederacion(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones);
int ContarConfederacionesCargadas(int* contadorConfederaciones, eConfederacion confederaciones[], int size);
int ValidarConfederacionCargada(eConfederacion confederaciones[], int* contadorConfederaciones, int size);
int buscarIndiceConfederacionPorId(eConfederacion confederaciones[],int id,int sizeConfed);
int ValidarConfederacionCargadaPorId(eConfederacion confederaciones[], int sizeConfed, int id);
void AccederABMConfed(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones, int idAutoIncrementalConfed);

#endif /* CONFEDERACIONES_H_ */
