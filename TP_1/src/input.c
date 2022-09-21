/*
 * input.c
 *
 *  Created on: 19 sep. 2022
 *      Author: User
 */
#include "input.h"

int IngresarEnteroValidado(char *mensaje, char *mensajeError, int minimo, int maximo){
	int resultado;

	printf("%s", mensaje);
	scanf("%d", &resultado);
	while(resultado < minimo || resultado > maximo){
		printf("%s", mensajeError);
		scanf("%d", &resultado);
	}

	return resultado;
}

float IngresarFloatValidado(char *mensaje, char *mensajeError, int minimo, int maximo){
	float resultado;

	printf("%s", mensaje);
	///cambiar a utnGetFloat
	scanf("%f", &resultado);
	while(resultado < minimo || resultado > maximo){
		printf("%s", mensajeError);
		printf("%s", mensaje);
		scanf("%f", &resultado);
		//IngresarFloatValidado(mensaje, mensajeError, minimo, maximo);
	}

	return resultado;
}

char ValidarSeguirNoSeguir(char * mensaje, char * mensajeError){
	char letra = 'S';
	char letraNoSeguir = 'N';
	char opcion;

	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &opcion);
		opcion = toupper(opcion);
		if(opcion != letra && opcion != letraNoSeguir){
			printf("%s", mensajeError);
		}
	}while(opcion != letra && opcion != letraNoSeguir);

	return opcion;
}
