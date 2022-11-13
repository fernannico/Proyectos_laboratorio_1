
#include "parser.h"


int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* unJugador = NULL;
	char id[10];
	char nombreCompleto[100];
	char edad[4];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[10];

	if(pFile != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);//lectura fantasma

		while(feof(pFile)==0){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			unJugador = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			if(unJugador!=NULL)
			ll_add(pArrayListJugador, unJugador);
		}
	}

//	free(unJugador);

    return 1;
}


int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* jugadorAux;

	if(pFile !=NULL && pArrayListJugador != NULL){
		while(feof(pFile)==0){
			jugadorAux = jug_new();
			if(jugadorAux != NULL){
				fread(jugadorAux,sizeof(Jugador), 1, pFile);

				if(feof(pFile)){
					free(jugadorAux);
					break;//para que el ultimo q se lee y agrega en MD no se guarde en el ll
				}
				ll_add(pArrayListJugador, jugadorAux);
			}
		}
	}

    return 1;
}


int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	Seleccion* unaSeleccion;
	char id[10];
	char pais[100];
	char confederacion[100];
	char convocados[10];

	if(pFile != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);//lectura fantasma

		while(feof(pFile)==0){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);
			unaSeleccion = selec_newParametros(id, pais, confederacion, convocados);

			ll_add(pArrayListSeleccion, unaSeleccion);
		}
	}


    return 1;
}

