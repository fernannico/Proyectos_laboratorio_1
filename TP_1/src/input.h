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


float IngresarFloatValidado(char *mensaje, char *mensajeError, int minimo, int maximo);
char ValidarSeguirNoSeguir(char * mensaje, char * mensajeError);

int IngresarEnteroValidado(char *mensaje, char *mensajeError, int minimo, int maximo);

#endif /* INPUT_H_ */
