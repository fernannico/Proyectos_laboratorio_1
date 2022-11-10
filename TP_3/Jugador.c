
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

	LinkedList* pArrayListSeleccion;
	pArrayListSeleccion = ll_newLinkedList();
	controller_cargarSeleccionesDesdeTexto("selecciones.csv", pArrayListSeleccion);

	cantidadSelecciones = ll_len(pArrayListSeleccion);

	if(jug_getOnePlayer(unJugador, &id, nombreCompleto, &edad, posicion, nacionalidad, &idSeleccion)==1){
		retorno = 1;
		if(idSeleccion==0){
			printf("\n%-4d %-25s %-6d %-20s %-17s %-24s", id, nombreCompleto, edad, posicion, nacionalidad, "No convocado");
		}
		for(int i = 0; i < cantidadSelecciones; i++){
			seleccionAux = (Seleccion*)ll_get(pArrayListSeleccion, i);
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

int jug_MostrarUnJugadorPorId(LinkedList* pArrayListJugador, int id){
	int retorno = 0;
	int indice = -1;
	int cantidad;
	Jugador* jugadorAux;

	indice = jug_BuscarIndiceJugadorPorId(pArrayListJugador, id);
	cantidad = ll_len(pArrayListJugador);

	for(int i=0;i<cantidad;i++){
		jugadorAux = (Jugador*)ll_get(pArrayListJugador, indice);
		jug_printOnePlayer(jugadorAux);
		retorno = 1;
		break;
	}

	return retorno;
}

