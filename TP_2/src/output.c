/*
 * output.c
 *
 *  Created on: 19 oct. 2022
 *      Author: User
 */

#include "output.h"
#include "nexo.h"

void MostrarMenuPrincipal(){
	printf("\n\n==========================="
			"\n| 1 |\tALTA\n"
			"---------------------------"
			"\n| 2 |\tBAJA\n"
			"---------------------------"
			"\n| 3 |\tMODIFICACION\n"
			"---------------------------"
			"\n| 4 |\tINFORMES\n"
			"---------------------------"
			"\n| 5 |\tABM CONFEDERACION\n"
			"==========================="
			"\n| 6 |\tSALIR\n"
			"===========================");
}

void MostrarSubmenuPosicion(){
	printf("\nPosicion:"
		"\n1- Arquero"
		"\n2- Defensor"
		"\n3- Mediocampo"
		"\n4- Delantero");
}

void MostrarSubmenuModificacion(){
	printf("\nMODIFICAR:"
		"\n1- Nombre"
		"\n2- Posicion"
		"\n3- Numero de camiseta"
		"\n4- Confederacion"
		"\n5- Salario"
		"\n6- Anios de contrato"
		"\n\n7- Cancelar modificacion");
}

int MostrarDetallesConfederaciones(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones){
	int retorno = -1;
	if(ValidarConfederacionCargada(confederaciones, contadorConfederaciones, sizeConfed)==1){
		retorno = 1;
		printf("\n============================================================");
		printf("\n| %-5s| %-9s| %-23s| %-15s|", "ID", "NOMBRE", "REGION", "AÑO CREACION");
		printf("\n------------------------------------------------------------");

		for(int i = 0; i< sizeConfed; i++){
			if(confederaciones[i].isEmpty == 1)
				printf("\n| %-5d| %-9s| %-23s|   %-5d       |", confederaciones[i].id, confederaciones[i].nombre,
																confederaciones[i].region, confederaciones[i].anioCreacion);
		}
		printf("\n============================================================");
	}
	return retorno;
}

void MostrarConfederacionesConJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores){
	printf("\n===========================================================");
	printf("\n|%-15s| %-4s|| %-20s| %-11s|", "Confederacion", "Id", "Nombre Jugador", "Id Jugador");

	for(int i = 0; i< sizeConfed; i++){
		if(confederaciones[i].isEmpty == 1){
			printf("\n-----------------------------------------------------------");
			printf("\n| %-14s| %-4d||%34c|", confederaciones[i].nombre, confederaciones[i].id, ' ');
			for(int j = 0; j < sizeJugadores; j++){
				if(jugadores[j].idConfederacion == confederaciones[i].id && jugadores[j].isEmpty == CARGADO){
					printf("\n|%43s | %5d      |", jugadores[j].nombre, jugadores[j].id);
				}else{
					if(ContarJugadoresConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, i) == 0){
						printf("\n| %55s |", "Confederacion sin jugadores");
						break;
					}
				}
			}
		}
	}
	printf("\n===========================================================");
}

int MostrarDetallesJugadores(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int*contadorJugadores){
	int retorno;

	if(ValidarJugadorCargado(jugadores, contadorJugadores, sizeJugadores)==1){
		retorno = 1;
		printf("\n============================================================================================================");
		printf("\n| %-3s| %-25s| %-11s| %-13s| %-11s| %-14s| %-18s|", "ID", "NOMBRE", "POSICION", "N° CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");
		printf("\n------------------------------------------------------------------------------------------------------------");

		for(int i = 0; i< sizeJugadores; i++){
			if(jugadores[i].isEmpty == CARGADO){
				for(int j = 0; j < sizeConfed;j++){
					if(jugadores[i].idConfederacion == confederaciones[j].id)
						printf("\n| %-3d| %-25s| %-11s|%7d      |%11.2f | %-14s|     %-13d|", jugadores[i].id, jugadores[i].nombre, jugadores[i].posicion, jugadores[i].numeroCamiseta, jugadores[i].salario, confederaciones[j].nombre, jugadores[i].aniosContrato);
				}
			}
		}
		printf("\n============================================================================================================");
	}else{
		retorno = 0;
	}

	return retorno;
}

void MostrarMenuInformes(){
	printf( "\n1- Listado de jugadores por nombre de confederacion"
			"\n2- Listado de confederaciones con sus jugadores"
			"\n3- Informe de salarios"
			"\n4- Confederación con mayor cantidad de años de contratos total"
			"\n5- Porcentaje de jugadores por cada confederación"
			"\n6- Region con mas jugadores y listado de ellos");
}

void MostrarInformeSalarios(float acumuladorSalarios, float promedioSalarios, int contadorJugadoresMayorProm){
	printf("\nTotal de salarios: %.2f"
			"\nPromedio de salarios: %.2f"
			"\nCantidad de jugadores que superan el promedio: %d",acumuladorSalarios, promedioSalarios, contadorJugadoresMayorProm);
}
