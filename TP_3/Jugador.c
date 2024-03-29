
#include "Jugador.h"

Jugador* jug_new(){
	Jugador* unJugador;

	unJugador = (Jugador*)malloc(sizeof(Jugador));

	return unJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr){
	Jugador* unJugador;

	unJugador = jug_new();

	jug_setId(unJugador, atoi(idStr));
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


int jug_setNombreCompleto(Jugador* this,char* nombre){
	int retorno = -1;

    if(this != NULL && nombre != NULL){
    	strcpy(this->nombreCompleto,nombre);
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

    if(this != NULL && posicion != NULL){
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

    if(this != NULL && nacionalidad != NULL){
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

    if(this != NULL){
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
	if(controller_cargarSeleccionesDesdeTexto("selecciones.csv", pArrayListSeleccionAux)==1){
		cantidadSelecciones = ll_len(pArrayListSeleccionAux);

		if(jug_getOnePlayer(unJugador, &id, nombreCompleto, &edad, posicion, nacionalidad, &idSeleccion)==1 && cantidadSelecciones != -1){
			retorno = 1;
			if(idSeleccion==0){
				printf("\n| %-4d | %-25s | %-6d | %-20s | %-17s | %-15s |", id, nombreCompleto, edad, posicion, nacionalidad, "No convocado");
			}
			for(int i = 0; i < cantidadSelecciones; i++){
				seleccionAux = (Seleccion*)ll_get(pArrayListSeleccionAux, i);
				if(selec_getId(seleccionAux, &idSelecAux)==0){
					if(idSelecAux == idSeleccion){
						if(selec_getPais(seleccionAux, pais)==0){
							printf("\n| %-4d | %-25s | %-6d | %-20s | %-17s | %-15s |", id, nombreCompleto, edad, posicion, nacionalidad, pais);
						}
						break;
					}
				}
			}
		}
	}


	ll_deleteLinkedList(pArrayListSeleccionAux);

	return retorno;
}


int jug_modificarNombre(Jugador* this){
	int retorno = -1;
	char nombreActual[100];
	char nombreNuevo[100];
	char confirmar;

	if(this != NULL){
		if(jug_getNombreCompleto(this, nombreActual)==0){
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

int jug_modificarPosicion(Jugador* this){
	int retorno = -1;
	char posicionActual[30];
	char posicionNueva[30];
	char confirmar;

	if(this != NULL){
		jug_getPosicion(this, posicionActual);

		if(utn_getNombre(posicionNueva, 30, "\nIngrese la nueva posicion del jugador: ", "\nError, intente de nuevo", 1)==0){
			printf("\nModificando la posicion del jugador de %s a %s", posicionActual, posicionNueva);
			confirmar = ValidarSeguirNoSeguir("\nModificar la posicion del jugador? [S|N]", "\nError");
			if(confirmar == 'S'){
				jug_setPosicion(this, posicionNueva);
				retorno = 1;
			}
		}

	}

	return retorno;
}

int jug_modificarNacionalidad(Jugador* this){
	int retorno = -1;
	char nacionalidadActual[30];
	char nacionalidadNueva[30];
	char confirmar;

	if(this != NULL){
		jug_getNacionalidad(this, nacionalidadActual);

		if(utn_getNombre(nacionalidadNueva, 30, "\nIngrese la nueva nacionalidad del jugador: ", "\nError, intente de nuevo", 1)==0){
			ModularNombre(nacionalidadNueva);
			printf("\nModificando la nacionalidad del jugador de %s a %s", nacionalidadActual, nacionalidadNueva);
			confirmar = ValidarSeguirNoSeguir("\nModificar la nacionalidad del jugador? [S|N]", "\nError");
			if(confirmar == 'S'){
				jug_setNacionalidad(this, nacionalidadNueva);
				retorno = 1;
			}
		}

	}


	return retorno;
}

int jug_CompareByName(void* unJugador,void* otroJugador){
	Jugador* jugadorUno = NULL;
	Jugador* jugadorDos = NULL;
	char nombreJugadorUno[100];
	char nombreJugadorDos[100];
	int compara = 0;

	jugadorUno = (Jugador*)unJugador;
	jugadorDos = (Jugador*)otroJugador;

	if(jugadorUno != NULL && jugadorDos != NULL){
		if(jug_getNombreCompleto(jugadorUno, nombreJugadorUno)==0 &&
				jug_getNombreCompleto(jugadorDos, nombreJugadorDos)==0){
			compara = stricmp(nombreJugadorUno, nombreJugadorDos);

			if(compara > 0){
				compara = 1;
			}else{
				if(compara < 0){
					compara = -1;
				}
			}
		}
	}
	return compara;
}

int jug_CompareByNationality(void* unJugador,void* otroJugador){
	Jugador* jugadorUno = NULL;
	Jugador* jugadorDos = NULL;
	char nacionalidadJugUno[30];
	char nacionalidadJugDos[30];

	int compara;

	jugadorUno = (Jugador*)unJugador;
	jugadorDos = (Jugador*)otroJugador;

	if(jugadorUno != NULL && jugadorDos != NULL){
		if(jug_getNacionalidad(jugadorUno, nacionalidadJugUno)==0 &&
				jug_getNacionalidad(jugadorDos, nacionalidadJugDos)==0){
			compara = strcmpi(nacionalidadJugUno, nacionalidadJugDos);
		}
	}

	return compara;
}

int jug_CompareByAge(void* unJugador,void* otroJugador){
	int compara = 0;
	Jugador* jugadorUno = NULL;
	Jugador* jugadorDos = NULL;
	int edadJugUno;
	int edadJugDos;

	jugadorUno = (Jugador*)unJugador;
	jugadorDos = (Jugador*)otroJugador;

	if(jugadorUno != NULL && jugadorDos != NULL){
		if(jug_getEdad(jugadorUno, &edadJugUno)==0 &&
				jug_getEdad(jugadorDos, &edadJugDos)==0){
			if(edadJugUno > edadJugDos){
				compara = 1;
			}else{
				if(edadJugUno < edadJugDos){
					compara = -1;
				}
			}
		}
	}


	return compara;
}

int jug_BuscarIndiceJugadorPorId(LinkedList* pArrayListJugador, int id){
	int indice = -1;
	int cantidad;
	int idAux;
	Jugador* unJugador;

	if(pArrayListJugador != NULL){
		cantidad = ll_len(pArrayListJugador);
		if(cantidad != -1){
			for(int i = 0; i<cantidad; i++){
				unJugador = ll_get(pArrayListJugador, i);

				if(jug_getId(unJugador, &idAux)==0 && idAux == id){
					indice = ll_indexOf(pArrayListJugador, unJugador);
					break;
				}
			}
		}
	}

	return indice;
}

void jug_actualizarIdModoTexto(int id){
	FILE* pArchivo;

	pArchivo = fopen("idJugador.csv", "w");

	if(pArchivo != NULL){
		fprintf(pArchivo, "%d\n", id);
	}

	fclose(pArchivo);
}

int jug_AsignarIdDesdeTexto(char* path){
	FILE* pArchivo = NULL;
	char idTexto[5];
	int id = -1;

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

void mostrarCabeceraJugadores(void){
	printf("\n| %-4s | %-25s | %-6s | %-20s | %-17s | %-15s |","id","nombre Completo", "edad", "posicion", "nacionalidad", "Selecion");
	printf("\n----------------------------------------------------------------------------------------------------------");
}
