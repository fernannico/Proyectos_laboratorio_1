/*
 * output.c
 *
 *  Created on: 17 sep. 2022
 *      Author: User
 */

#include "output.h"


void ImprimirMenu(int costosHospedaje, int costosComida, int costosTransporte, int contadorArqueros, int contadorDefensores, int contadorMediocampistas, int contadorDelanteros){
	printf( "\n--------------------------------------------"
			"\n1. Ingreso de los costos de Mantenimiento."
				"\n Costo de hospedaje -> $%d"
				"\n Costo de comida -> $%d"
				"\n Costo de transporte -> $%d"
			"\n2. Carga de jugadores:"
				"\n Arqueros -> %d"
				"\n Defensores -> %d"
				"\n Mediocampistas -> %d"
				"\n Delanteros -> %d"
			"\n3. Realizar todos los cálculos."
			"\n4. Informar todos los resultados."
			"\n5. Salir.", costosHospedaje, costosComida, costosTransporte, contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);
}

void ImprimirSubmenuMantenimiento(int costosHospedaje, int costosComida, int costosTransporte){
	printf( "\n1. Costo de hospedaje -> $%d"
			"\n2. Costo de comida -> $%d"
			"\n3. Costo de transporte -> $%d", costosHospedaje, costosComida, costosTransporte);
}

void ImprimirCantidadJugadores(int contadorArqueros, int contadorDefensores, int contadorMediocampistas, int contadorDelanteros){
	printf( "\ncantidad de jugadores en cada posición cargados hasta el momento:"
			"\n1. Arqueros -> %d"
			"\n2. Defensores -> %d"
			"\n3. Mediocampistas -> %d"
			"\n4. Delanteros -> %d", contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);
}

void ImprimirSubmenuConfederaciones(int uefa, int conmebol, int concacaf, int afc, int ofc, int caf){

	printf( "\nelegir una de las siguientes confederaciones: "
			"\n1. UEFA en Europa -> %d"
			"\n2. CONMEBOL en Sudamérica -> %d"
			"\n3. CONCACAF en zona del Norte -> %d"
			"\n4. AFC en Asia -> %d"
			"\n5. OFC en Oceanía -> %d"
			"\n6. CAF en África -> %d", uefa, conmebol, concacaf, afc, ofc, caf);
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

void ImprimirResultados(float promedioUefa, float promedioConmebol, float promedioConcacaf, float promedioAfc, float promedioOfc, float promedioCaf){
	printf( "\nPromedio Uefa %.2f"
			"\nPromedio Conmebol %.2f"
			"\nPromedio Concacaf %.2f"
			"\nPromedio Afc %.2f"
			"\nPromedio Ofc %.2f"
			"\nPromedio Caf %.2f", promedioUefa, promedioConmebol, promedioConcacaf, promedioAfc, promedioOfc, promedioCaf);
}







