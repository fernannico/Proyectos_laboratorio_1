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

void MostrarConfederacionesConJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores){
	printf("\n===========================================================");
	printf("\n|%-15s| %-4s|| %-20s| %-11s|", "Confederacion", "Id", "Nombre Jugador", "Id Jugador");

	for(int i = 0; i< sizeConfed; i++){
		if(confederaciones[i].isEmpty == CARGADO){
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

int MostrarConfederacionesBajadas(eConfederacion confederaciones[], int sizeConfed){
	int retorno;

	if(confederaciones != NULL && sizeConfed > 0){
		if(ValidarConfederacionBajada(confederaciones, sizeConfed)==1){
			retorno = 1;
			printf("\n============================================================");
			printf("\n| %-5s| %-9s| %-23s| %-15s|", "ID", "NOMBRE", "REGION", "AÑO CREACION");
			printf("\n============================================================");

			for(int i = 0; i<sizeConfed;i++){
				if(confederaciones[i].isEmpty == BAJADO){
					printf("\n| %-5d| %-9s| %-23s|   %-5d       |", confederaciones[i].id, confederaciones[i].nombre,
																	confederaciones[i].region, confederaciones[i].anioCreacion);
					printf("\n------------------------------------------------------------");
				}
			}
		}else{
			retorno = -1;
		}
	}

	return retorno;
}

int MostrarDetallesJugadores(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int*contadorJugadores){
	int retorno;

	if(ValidarJugadorCargado(jugadores, contadorJugadores, sizeJugadores, confederaciones, sizeConfed)==1){
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

void MostrarConfederacionesConMasJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores){
	int indice;
	int maximoContador;
	int contadorAux;

	contadorAux = 0;

	if((indice = ObtenerIndiceConfedMasJugadores(confederaciones, jugadores, sizeConfed, sizeJugadores, contadorConfederaciones, contadorJugadores)) != -1){
		maximoContador = ContarJugadoresConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, indice);
		printf("\n===========================================================");
		printf("\n|%-15s| %-4s|| %-20s| %-11s|", "Confederacion", "Id", "Nombre Jugador", "Id Jugador");

		for(int i = 0; i< sizeConfed; i++){
			if(confederaciones[i].isEmpty == 1){
				contadorAux = ContarJugadoresConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, i);
				if(contadorAux == maximoContador){
					printf("\n-----------------------------------------------------------");
					printf("\n| %-14s| %-4d||%34c|", confederaciones[i].nombre, confederaciones[i].id, ' ');
					for(int j = 0; j < sizeJugadores; j++){
						if(jugadores[j].idConfederacion == confederaciones[i].id && jugadores[j].isEmpty == CARGADO){
							printf("\n|%43s | %5d      |", jugadores[j].nombre, jugadores[j].id);
						}
					}
				}
			}
		}
	}else{
		printf("\nFaltan cargar jugadores / confederaciones");
	}
	printf("\n===========================================================");
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


void MostrarMenuABMConfed(){
	printf("\n\n==========================="
			"\n| 1 |\tALTA confederacion\n"
			"---------------------------"
			"\n| 2 |\tBAJA confederacion\n"
			"---------------------------"
			"\n| 3 |\tMODIFICACION\n"
			"---------------------------"
			"\n| 4 |\tSALIR\n"
			"===========================\n");
}

void MostrarModificacionConfed(){
	printf("\nMODIFICAR:"
		"\n1- Nombre"
		"\n2- Region"
		"\n3- Años de creacion"
		"\n\n4- Cancelar modificacion");
}
