/*
 * operaciones.c
 *
 *  Created on: 23 sep. 2022
 *      Author: User
 */
#include "operaciones.h"

float CalcularSuma(float numeroUno, float numeroDos){
	float suma;

	suma = numeroUno + numeroDos;

	return suma;
}


float CalcularPorcentaje(float valorInicial, int porcentaje){
	float valorPorcentaje;

	valorPorcentaje = (valorInicial * porcentaje) / 100;

	return valorPorcentaje;
}

float CalcularPromedio(int acumulador, int contador){
	float promedio;

	promedio = (float)acumulador / contador;

	return promedio;
}

int ContarConfederaciones(int opcion, int* pUefa, int* pConmebol, int* pConcacaf, int* pAfc, int* pOfc, int* pCaf){
	int retorno = 0;

	if(pUefa != NULL && pConmebol  != NULL &&  pConcacaf != NULL && pAfc != NULL && pOfc != NULL && pCaf != NULL){
		switch (opcion){
			case UEFA:
				*pUefa = * pUefa + 1;
				break;
			case CONMEBOL:
				*pConmebol = *pConmebol + 1;
				break;
			case CONCACAF:
				*pConcacaf = *pConcacaf+1;
				break;
			case AFC:
				*pAfc = *pAfc +1;
				break;
			case OFC:
				*pOfc = *pOfc +1;
				break;
			case CAF:
				*pCaf = *pCaf +1;
				break;
			default:
				printf("\nopcion incorrecta");
				break;
		}
		retorno = 1;
	}
	return retorno;
}



