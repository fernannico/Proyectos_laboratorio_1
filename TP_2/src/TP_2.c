/*
 ============================================================================
 Name        : TP_2.c
 Author      : Nicolas Ivan Fernandez
 Division    : 1K
 Description : Trabajo practico 2 in C
 ============================================================================
 */

#include "nexo.h"
#include "input.h"
#include "output.h"
#include <ctype.h>

//void SwapearChar(char* arrayUno, char* arrayDos);

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int codigoAutoIncremental;
	int contadorJugadores;
	int contadorConfederaciones;
	char salirPrograma;

	eConfederacion confederaciones[TAMC];
	eJugador jugadores[TAMJ];

	codigoAutoIncremental = 7;
	contadorJugadores = 0;
	contadorConfederaciones = 0;

	CargarConfederacionesHarcodeadas(confederaciones, TAMC);
	InicializarEstadoJugadores(jugadores, TAMJ);
	CargarJugadoresHarcodeados(jugadores, TAMJ);
//	ContarConfederacionesCargadas(&contadorConfederaciones, confederaciones, TAMC);
//	ContarJugadoresCargados(&contadorJugadores, jugadores, confederaciones, TAMJ, TAMC);
//
//	printf("%d", contadorJugadores);
//	printf("%d", contadorConfederaciones);

//	if(ValidarConfederacionCargada(confederaciones, &contadorConfederaciones, TAMC) == 1){
//		printf("hay C");
//	}else{
//		printf("no hay C");
//	}

//	if(ValidarConfederacionCargadaPorId(confederaciones, TAMC, 104)==1){
//		printf("\nC cargada");
//	}else{
//		printf("\nC No cargada");
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
				InformarOpciones(jugadores, confederaciones, TAMJ, TAMC, &contadorJugadores, &contadorConfederaciones);
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


