/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//#include "confederaciones.h"
//#include "jugadores.h"
#include "nexo.h"
#include "input.h"
#include "output.h"
#include <ctype.h>

//void SwapearChar(char* arrayUno, char* arrayDos);
//int informarRegionMasJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores);


int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int codigoAutoIncremental;
	int contadorJugadores;
	int contadorConfederaciones;
	char salirPrograma;
	char seguir;
	int opcionInforme;
	int indice;

	eConfederacion confederaciones[TAMC];
	eJugador jugadores[TAMJ];

	contadorJugadores = 0;
	codigoAutoIncremental = 5;
	contadorConfederaciones = 0;

	CargarConfederacionesHarcodeadas(confederaciones, TAMC);
	InicializarEstadoJugadores(jugadores, TAMJ);
	CargarJugadoresHarcodeados(jugadores, TAMJ);
	ContarConfederacionesCargadas(&contadorConfederaciones, confederaciones, TAMC);
	ContarJugadoresCargados(&contadorJugadores, jugadores, TAMJ);
//
//	printf("%d", contadorJugadores);
//	printf("%d", contadorConfederaciones);

//	if(ValidarConfederacionCargada(confederaciones, &contadorConfederaciones, TAMC) == 1){
//		printf("hay C");
//	}else{
//		printf("no hay C");
//	}


	do {
//		if(ValidarJugadorCargado(jugadores, &contadorJugadores, TAMJ)==1){
//				printf("hay J");
//			}else{
//				printf("no hay J");
//			}
		MostrarMenuPrincipal();
		utn_getNumero(&opcion, "\ningrese una opcion del menu [1-6]", "\nError", 1, 6, 1);

		///en las opciones, hacer de devuelvan 1 o 0 segun confirme lo que hace
		switch (opcion) {
			case 1:
				CargarJugador(jugadores, confederaciones, TAMJ, TAMC, &codigoAutoIncremental, &contadorConfederaciones);
				break;
			case 2:
				DarDeBajaJugador(jugadores, confederaciones, TAMJ, TAMC, &contadorJugadores, codigoAutoIncremental);
				printf("\ncontador jugadores: %d", contadorJugadores);
				break;
			case 3:
				ModificarJugador(jugadores, confederaciones, TAMJ, TAMC, &contadorJugadores, &contadorConfederaciones, codigoAutoIncremental);
				break;
			case 4:
				 if(ValidarConfederacionCargada(confederaciones, &contadorConfederaciones, TAMC)==1){
					 if(ValidarJugadorCargado(jugadores, &contadorJugadores, TAMJ)==1){
						do {
							MostrarMenuInformes();
							if(utn_getNumero(&opcionInforme, "\nOpcion:", "\nError de opcion [1-6]", 1, 7, 1)==0){
								switch(opcionInforme){
									case 1:
										if(OrdenarJugadoresPorConfedYNombre(jugadores, confederaciones, TAMJ, TAMC, &contadorJugadores, &contadorConfederaciones)==1){
											MostrarDetallesJugadores(jugadores, confederaciones, TAMJ, TAMC, &contadorJugadores);
										}
										break;
									case 2:
										MostrarConfederacionesConJugadores(confederaciones, jugadores, TAMC, TAMJ);
										break;
									case 3:
										CalcularInformeSalarios(jugadores, TAMJ, &contadorJugadores);
										break;
									case 4:
										informarConfederacionMasAnios(confederaciones, jugadores, TAMC, TAMJ, &contadorConfederaciones);
										break;
									case 5://Informar porcentaje de jugadores por cada confederación.

										break;
									case 6://Informar cual es la región con más jugadores y el listado de los mismos.
										MostrarConfederacionesConMasJugadores(confederaciones, jugadores, TAMC, TAMJ, &contadorConfederaciones, &contadorJugadores);
										break;
									default:
										break;
								}
							}
							seguir = ValidarSeguirNoSeguir("\nMostrar otro informe? [S|N]", "\nError..");
						}while(seguir == 'S');
					 }else{
						 printf("\nFalta cargar un jugador");
					 }
				 }else{
					 printf("\nFalta cargar una confederacion");
				 }
				break;
			case 5:
				///ABM CONFEDERACIONES
				break;
			case 6:
				printf("\nEligio salir del programa...");
				salirPrograma = ValidarSeguirNoSeguir("\nEsta seguro que quiere salir del programa? [S|N]", "\nError");
				break;
			default:
				printf("\nError");
				break;
		}

	}while(salirPrograma != 'S');

	return EXIT_SUCCESS;
}







/*
int informarRegionMasJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores){
	int retorno = -1;
	int indice;

	indice = ObtenerIndiceConfedMasJugadores(confederaciones, jugadores, sizeConfed, sizeJugadores, contadorConfederaciones, contadorJugadores);
	if(indice != -1){
		printf("\n============================"
				"\n| Region con mas jugadores |");
		if(MostrarConfederacionPorId(confederaciones, sizeConfed, contadorConfederaciones, confederaciones[indice].id)==1){
					///hacer que ==== sea un for con strlen del tamaño de chars de la region
		}
	}else{
		printf("\nNo hay confederaciones cargadas");
	}

	return retorno;
}
*/
