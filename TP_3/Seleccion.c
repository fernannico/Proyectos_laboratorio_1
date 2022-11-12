
#include "Seleccion.h"

Seleccion* selec_new(){
	Seleccion* unaSeleccion;

	unaSeleccion = (Seleccion*)malloc(sizeof(Seleccion));

	return unaSeleccion;
}


Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion* unaSeleccion;
	unaSeleccion = selec_new();

	unaSeleccion->id = atoi(idStr);
	strcpy(unaSeleccion->pais, paisStr);
	strcpy(unaSeleccion->confederacion, confederacionStr);
	unaSeleccion->convocados= atoi(convocadosStr);

	return unaSeleccion;
}


int selec_getId(Seleccion* this,int* id){
	int retorno = -1;

	if(this != NULL && id != NULL){
		*id=this->id;
		retorno = 0;
	}

	return retorno;
}

int selec_getPais(Seleccion* this,char* pais){
	int retorno = -1;

	if(this != NULL && pais != NULL){
		strcpy(pais, this->pais);
		retorno = 0;
	}

	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion){
	int retorno = -1;

	if(this != NULL && confederacion != NULL){
		strcpy(confederacion, this->confederacion);
		retorno = 0;
	}

	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados){
	int retorno = -1;

	return retorno;
}

int selec_getConvocados(Seleccion* this,int* convocados){
	int retorno = -1;
	if(this != NULL && convocados != NULL){
		*convocados = this->convocados;
		retorno = 0;
	}

	return retorno;
}

int selec_getOneSelec(Seleccion* unaSeleccion, int* id, char* pais, char* confederacion, int* convocados){
	int retorno = -1;

	if(unaSeleccion != NULL && id != NULL && pais != NULL && confederacion != NULL && confederacion != NULL){
		if( selec_getId(unaSeleccion, id) == 0 && selec_getPais(unaSeleccion, pais) == 0 &&
			selec_getConfederacion(unaSeleccion, confederacion) == 0 && selec_getConvocados(unaSeleccion, convocados) == 0){
			retorno = 1;
		}
	}

	return retorno;
}


int selec_printOneSelec(Seleccion* unaSeleccion){
	int retorno = -1;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	if(selec_getOneSelec(unaSeleccion, &id, pais, confederacion, &convocados)== 1){
		printf("\n| %-2d | %-15s | %-9s | %-2d |", id, pais, confederacion, convocados);
		retorno = 1;
	}
	return retorno;
}

int selec_CompareByConfed(void* unaSelec,void* otraSelec){
	int compara;

	Seleccion* selecUno;
	Seleccion* selecDos;

	selecUno = (Seleccion*)unaSelec;
	selecDos = (Seleccion*)otraSelec;

	compara = strcmpi(selecUno->confederacion, selecDos->confederacion);

	return compara;
}

int selec_seleccionarConfederacion(char* confederacionOpcion){
	int retorno = -1;
	int opcion;

	if(utn_getNumero(&opcion,	"\n1- AFC"
								"\n2- CAF"
								"\n3- CONCACAF"
								"\n4- CONMEBOL"
								"\n5- UEFA", "\nError", 1, 5, 1)==0){
		retorno = 1;
		switch (opcion) {
			case 1:
				strcpy(confederacionOpcion,"AFC");
				break;
			case 2:
				strcpy(confederacionOpcion,"CAF");
				break;
			case 3:
				strcpy(confederacionOpcion,"CONCACAF");
				break;
			case 4:
				strcpy(confederacionOpcion,"CONMEBOL");
				break;
			case 5:
				strcpy(confederacionOpcion,"UEFA");
				break;
			default:
				break;
		}
	}
	return retorno;
}

///La uso???
int selec_BuscarIndiceSeleccionPorId(LinkedList* pArrayListSeleccion, int id){
	int indice = -1;
	int cantidad;
	int idAux;
	Seleccion* seleccionAux;

	cantidad = ll_len(pArrayListSeleccion);

	for(int i = 0; i<cantidad; i++){
		seleccionAux = ll_get(pArrayListSeleccion, i);
		if(selec_getId(seleccionAux, &idAux)==0){
			if(idAux == id){
				indice = ll_indexOf(pArrayListSeleccion, seleccionAux);
				break;
			}
		}
	}

	return indice;
}


