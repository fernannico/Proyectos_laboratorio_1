
#include "Jugador.h"

Jugador* jug_new(){
	Jugador* unJugador;

	unJugador = (Jugador*)malloc(sizeof(Jugador));

	return unJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr){
	Jugador* unJugador;

	unJugador = jug_new();

	///falta setter de id
	unJugador->id = atoi(idStr);
	jug_setNombreCompleto(unJugador, nombreCompletoStr);
	jug_setEdad(unJugador, atoi(edadStr));
	jug_setPosicion(unJugador, posicionStr);
	jug_setNacionalidad(unJugador, nacionalidadStr);
	jug_setIdSeleccion(unJugador, atoi(idSeleccionStr));

	return unJugador;
}

void jug_delete(Jugador* this){
	free(this);
}


int jug_setId(Jugador* this,int id){
	int retorno = -1;

	if(this!= NULL){
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int jug_getId(Jugador* this,int* id){
	int retorno = -1;

	if(this != NULL && id != NULL){
		*id=this->id;
		retorno = 0;
	}

	return retorno;
}


int jug_setNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno = -1;

    if(this != NULL && nombreCompleto > 0){
    	strcpy(this->nombreCompleto,nombreCompleto);
        retorno = 0;
    }

	return retorno;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;
    if(this != NULL && nombreCompleto !=NULL){
        strcpy(nombreCompleto, this->nombreCompleto);
        retorno = 0;
    }
	return retorno;
}


int jug_setPosicion(Jugador* this,char* posicion){
	int retorno = -1;

    if(this != NULL && posicion > 0){
    	strcpy(this->posicion,posicion);
        retorno = 0;
    }

	return retorno;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;
    if(this != NULL && posicion !=NULL){
    	strcpy(posicion,this->posicion);
        retorno = 0;
    }

	return retorno;
}


int jug_setNacionalidad(Jugador* this,char* nacionalidad){
	int retorno = -1;

    if(this != NULL && nacionalidad > 0){
    	strcpy(this->nacionalidad, nacionalidad);
        retorno = 0;
    }

	return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

    if(this != NULL && nacionalidad !=NULL){
    	strcpy(nacionalidad, this->nacionalidad);
        retorno = 0;
    }

	return retorno;
}


int jug_setEdad(Jugador* this,int edad){
	int retorno = -1;

    if(this != NULL){
    	this->edad = edad;
        retorno = 0;
    }

	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;

    if(this != NULL && edad !=NULL){
        *edad = this->edad;
        retorno = 0;
    }

	return retorno;
}


int jug_setIdSeleccion(Jugador* this,int idSeleccion){
	int retorno = -1;

    if(this != NULL && idSeleccion >= 0){
    	this->idSeleccion = idSeleccion;
        retorno = 0;
    }

	return retorno;
}
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;

    if(this != NULL && idSeleccion !=NULL){
        *idSeleccion = this->idSeleccion;
        retorno = 0;
    }

	return retorno;
}

int jug_getOnePlayer(Jugador* unJugador, int* id, char* nombreCompleto, int* edad, char* posicion, char* nacionalidad, int* idSeleccion){
	int retorno = -1;

	if(jug_getId(unJugador, id)== 0 && jug_getNombreCompleto(unJugador, nombreCompleto) == 0 && jug_getEdad(unJugador, edad)== 0 &&
			jug_getPosicion(unJugador, posicion)==0 && jug_getNacionalidad(unJugador, nacionalidad)== 0 && jug_getSIdSeleccion(unJugador, idSeleccion)== 0){
		retorno = 1;
	}
	return retorno;
}

int jug_setOnePlayer(Jugador* unJugador, int id, char* nombreCompleto, int edad, char* posicion, char* nacionalidad, int idSeleccion){
	int retorno = -1;

	if( jug_setId(unJugador, id)==0 && jug_setNombreCompleto(unJugador, nombreCompleto)==0 && jug_setEdad(unJugador, edad)==0 &&
		jug_setPosicion(unJugador, posicion)==0 && jug_setNacionalidad(unJugador, nacionalidad)==0 && jug_setIdSeleccion(unJugador, idSeleccion)==0){
		retorno = 1;
	}

	return retorno;
}

int jug_printOnePlayer(Jugador* unJugador){
	int retorno = -1;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	Seleccion* seleccionAux;
	int idSelecAux;
	char pais[30];
	int cantidadSelecciones;

	LinkedList* pArrayListSeleccionAux;
	pArrayListSeleccionAux = ll_newLinkedList();
	controller_cargarSeleccionesDesdeTexto("selecciones.csv", pArrayListSeleccionAux);

	cantidadSelecciones = ll_len(pArrayListSeleccionAux);

	if(jug_getOnePlayer(unJugador, &id, nombreCompleto, &edad, posicion, nacionalidad, &idSeleccion)==1){
		retorno = 1;
		if(idSeleccion==0){
			printf("\n%-4d %-25s %-6d %-20s %-17s %-24s", id, nombreCompleto, edad, posicion, nacionalidad, "No convocado");
		}
		for(int i = 0; i < cantidadSelecciones; i++){
			seleccionAux = (Seleccion*)ll_get(pArrayListSeleccionAux, i);
			if(selec_getId(seleccionAux, &idSelecAux)==0){
				if(idSelecAux == idSeleccion){
					if(selec_getPais(seleccionAux, pais)==0){
						printf("\n%-4d %-25s %-6d %-20s %-17s %-24s", id, nombreCompleto, edad, posicion, nacionalidad, pais);
					}
					break;
				}
			}
		}
	}
	return retorno;
}


int jug_modificarNombre(Jugador* this){
	int retorno = -1;
	char nombreActual[100];
	char nombreNuevo[100];
	char confirmar;

	if(this != NULL){
		jug_getNombreCompleto(this, nombreActual);

		if(utn_getNombre(nombreNuevo, 100, "\nIngrese el nuevo nombre del jugador", "\nError", 1)==0){
			ModularNombre(nombreNuevo);

			printf("\nModificando el nombre del jugador de %s a %s...", nombreActual, nombreNuevo);
			confirmar = ValidarSeguirNoSeguir("\nModificar el nombre del jugador? [S|N]", "\nError");
			if(confirmar == 'S'){
				jug_setNombreCompleto(this, nombreNuevo);
				retorno = 1;
			}
		}else{
			printf("\nModificacion interrumpida");
		}
	}

	return retorno;
}

int jug_modificarEdad(Jugador* this){
	int retorno = -1;
	int edadActual;
	int edadNueva;
	char confirmar;

	if(this != NULL){
		jug_getEdad(this, &edadActual);

		if(utn_getNumero(&edadNueva, "\nIngrese la nueva edad del jugador [16-60]", "\nError", 16, 60, 1)==0){

			printf("\nModificando la edad del jugador de %d a %d años", edadActual, edadNueva);
			confirmar = ValidarSeguirNoSeguir("\nModificar la edad del jugador? [S|N]", "\nError");
			if(confirmar == 'S'){
				jug_setEdad(this, edadNueva);
				retorno = 1;
			}
		}else{
			printf("\nModificacion interrumpida");
		}
	}


	return retorno;
}

///podemos hacer una matriz de 11 posiciones harcodeados y que ingrese el numero--> char posicion[11][30]
int jug_modificarPosicion(Jugador* this){
	int retorno = -1;
	char posicionActual[30];
	char posicionNueva[30];
	char confirmar;

	if(this != NULL){
		jug_getPosicion(this, posicionActual);

		printf("\nIngrese la nueva posicion del jugador");
		fflush(stdin);
		scanf("%[^\n]s", posicionNueva);
//		utn_getNumero(&posicionNueva, "\nIngrese la nueva posicion del jugador", "\nError", 16, 60, 1);

		printf("\nModificando la posicion del jugador de %s a %s", posicionActual, posicionNueva);
		confirmar = ValidarSeguirNoSeguir("\nModificar la posicion del jugador? [S|N]", "\nError");
		if(confirmar == 'S'){
			jug_setPosicion(this, posicionNueva);
			retorno = 1;
		}
	}

	return retorno;
}

///podemos hacer una matriz de 32 paises harcodeados y que ingrese el numero--> char nacionalidad[32][30]
int jug_modificarNacionalidad(Jugador* this){
	int retorno = -1;
	char nacionalidadActual[30];
	char nacionalidadNueva[30];
	char confirmar;

	if(this != NULL){
		jug_getNacionalidad(this, nacionalidadActual);

//		utn_getNumero(&nacionalidadNueva, "\nIngrese la nueva edad del jugador [16-60]", "\nError", 16, 60, 1);
		printf("\nIngrese la nueva nacionalidad del jugador");
		fflush(stdin);
		scanf("%[^\n]s", nacionalidadNueva);

		printf("\nModificando la nacionalidad del jugador de %s a %s", nacionalidadActual, nacionalidadNueva);
		confirmar = ValidarSeguirNoSeguir("\nModificar la nacionalidad del jugador? [S|N]", "\nError");
		if(confirmar == 'S'){
			jug_setNacionalidad(this, nacionalidadNueva);
			retorno = 1;
		}
	}


	return retorno;
}

int jug_CompareByName(void* unJugador,void* otroJugador){
	Jugador* jugadorUno;
	Jugador* jugadorDos;

	int compara = 0;

	jugadorUno = (Jugador*)unJugador;
	jugadorDos = (Jugador*)otroJugador;

	compara = stricmp(jugadorUno->nombreCompleto, jugadorDos->nombreCompleto);

	if(compara > 0){
		compara = 1;
	}else{
		if(compara < 0){
			compara = -1;
		}
	}

	return compara;
}

int jug_CompareByNationality(void* unJugador,void* otroJugador){
	Jugador* jugadorUno;
	Jugador* jugadorDos;

	int compara;

	jugadorUno = (Jugador*)unJugador;
	jugadorDos = (Jugador*)otroJugador;

	compara = strcmpi(jugadorUno->nacionalidad, jugadorDos->nacionalidad);

	return compara;
}

int jug_CompareByAge(void* unJugador,void* otroJugador){
	int compara = 0;

	Jugador* jugadorUno;
	Jugador* jugadorDos;

	jugadorUno = (Jugador*)unJugador;
	jugadorDos = (Jugador*)otroJugador;

	if(jugadorUno->edad > jugadorDos->edad){
		compara = 1;
	}else{
		if(jugadorUno->edad < jugadorDos->edad){
			compara = -1;
		}
	}

	return compara;
}

int jug_BuscarIndiceJugadorPorId(LinkedList* pArrayListJugador, int id){
	int indice = -1;
	int cantidad;
	int idAux;
	Jugador* unJugador;

	cantidad = ll_len(pArrayListJugador);

	for(int i = 0; i<cantidad; i++){
		unJugador = ll_get(pArrayListJugador, i);

		if(jug_getId(unJugador, &idAux)==0 && idAux == id){
			indice = ll_indexOf(pArrayListJugador, unJugador);
			///recien agregado
			break;
		}
	}

	return indice;
}

/*
int jug_MostrarUnJugadorPorId(LinkedList* pArrayListJugador, int id){
	int retorno = 0;
	int indice = -1;
	int cantidad;
	Jugador* jugadorAux;

	indice = jug_BuscarIndiceJugadorPorId(pArrayListJugador, id);
	cantidad = ll_len(pArrayListJugador);

	if(indice != -1){
		for(int i=0;i<cantidad;i++){
			jugadorAux = (Jugador*)ll_get(pArrayListJugador, indice);
			jug_printOnePlayer(jugadorAux);
			retorno = 1;
			break;
		}
	}

	return retorno;
}
*/
void jug_actualizarIdModoTexto(int id){
	FILE* pArchivo;

	pArchivo = fopen("idJugador.csv", "w");

	fprintf(pArchivo, "%d\n", id);

	fclose(pArchivo);
}

int jug_AsignarIdDesdeTexto(char* path){
	FILE* pArchivo = NULL;
	char idTexto[5];
	int id;

	pArchivo = fopen(path, "r");

	if(pArchivo!=NULL){
		while(feof(pArchivo)==0){
			fscanf(pArchivo, "%[^\n]\n", idTexto);
		}
	}

	id = atoi(idTexto) +1;

	fclose(pArchivo);

	return id;
}
