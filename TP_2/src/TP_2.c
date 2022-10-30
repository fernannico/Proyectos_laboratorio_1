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

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int codigoAutoIncremental;
	int idAutoIncrementalConfed;
	int contadorJugadores;
	int contadorConfederaciones;
	char salirPrograma;

	eConfederacion confederaciones[TAMC];
	eJugador jugadores[TAMJ];

	codigoAutoIncremental = 1;
	contadorJugadores = 0;
	idAutoIncrementalConfed = 106;
	contadorConfederaciones = 0;

	InicializarEstadoConfederaciones(confederaciones, TAMC);
	CargarConfederacionesHarcodeadas(confederaciones, TAMC);
	InicializarEstadoJugadores(jugadores, TAMJ);
//	CargarJugadoresHarcodeados(jugadores, TAMJ);

	do {
		MostrarMenuPrincipal();
		utn_getNumero(&opcion, "\ningrese una opcion del menu [1-6]", "\nError", 1, 6, 1);

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
				AccederABMConfed(confederaciones, TAMC, &contadorConfederaciones, idAutoIncrementalConfed);
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

