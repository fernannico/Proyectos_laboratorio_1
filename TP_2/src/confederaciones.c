/*
 * confederaciones.c
 *
 *  Created on: 18 oct. 2022
 *      Author: User
 */
#include "nexo.h"

void CargarConfederacionesHarcodeadas(eConfederacion confederaciones[], int size){
	eConfederacion auxiliar[] = { {100, "CONMEBOL", "SUDAMERICA", 1916, CARGADO}, {101, "UEFA", "EUROPA", 1954, CARGADO}, {102, "AFC", "ASIA", 1954, CARGADO},
					{103, "CAF", "AFRICA", 1957, CARGADO}, {104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, CARGADO}, {105, "OFC", "OCEANIA", 1966, CARGADO}};

	for(int i = 0; i<size; i++){
		confederaciones[i] = auxiliar[i];
	}
}


void InicializarEstadoConfederaciones(eConfederacion confederaciones[], int sizeConfed){
	for(int i = 0; i<sizeConfed; i++){
		confederaciones[i].isEmpty = LIBRE;
	}
}

int BuscarEspacioLibreConfed(eConfederacion confederaciones[], int sizeConfed){
	int indiceLibre = -1;

	for(int i = 0; i < sizeConfed; i++){
		if(confederaciones[i].isEmpty == LIBRE){
			indiceLibre = i;
			break;
		}
	}
	return indiceLibre;
}

void CargarConfederacionesBajadas(eConfederacion confederaciones[], int sizeConfed){
	int idBajado;
	int indiceBajado;

	if(confederaciones != NULL && sizeConfed > 0){
		if(MostrarConfederacionesBajadas(confederaciones, TAMC)==1){
			if(utn_getNumero(&idBajado, "\nIngrese el id de la confederacion a re-cargar: ", "Error", 100, 110, 1)==0){
				indiceBajado = buscarIndiceConfederacionPorId(confederaciones, idBajado, sizeConfed);
				if(confederaciones[indiceBajado].isEmpty == BAJADO){
					confederaciones[indiceBajado].isEmpty = CARGADO;
					printf("\nConfederacion cargada");
				}else{
					if(confederaciones[indiceBajado].isEmpty == CARGADO){
						printf("\nConfederacion ya esta dada de alta");
					}else{
						if(confederaciones[indiceBajado].isEmpty == LIBRE){
							printf("\nEse id esta libre");
						}
					}
				}
			}
		}else{
			printf("\nNo hay confederaciones dadas de baja");
		}
	}
}

int CargarNuevaConfederacion(eConfederacion confederaciones[], int sizeConfed, int idAutoIncrementalConfed){
	int retorno;
	int indiceLibre;

	retorno = -1;
	indiceLibre = BuscarEspacioLibreConfed(confederaciones, sizeConfed);

	if(indiceLibre > -1 && indiceLibre < sizeConfed){
		confederaciones[indiceLibre].id = idAutoIncrementalConfed;
		retorno = 1;
		if(utn_getNombre(confederaciones[indiceLibre].nombre, 51, "\ningrese el nombre de la confederacion", "\Error", 1)==0){
			strupr(confederaciones[indiceLibre].nombre);
			if(utn_getNombre(confederaciones[indiceLibre].region, 51, "\ningrese la region de la confederacion", "\Error", 1)==0){
				strupr(confederaciones[indiceLibre].nombre);
				if(utn_getNumero(&confederaciones[indiceLibre].anioCreacion, "\nIngrese el año de creacion", "\nError", 1916, 2022, 1)==0){
					confederaciones[indiceLibre].isEmpty = CARGADO;
				}
			}else{
				printf("\nRegion cargada sin exito");
			}
		}else{
			printf("\nNombre cargado sin exito");
		}
	}
	return retorno;
}

int ValidarConfederacionBajada(eConfederacion confederaciones[], int sizeConfed){
	int retorno;

	for(int i = 0; i < sizeConfed; i++){
		if(confederaciones[i].isEmpty == BAJADO){
			retorno = 1;
			break;
		}else{
			retorno = 0;
		}
	}

	return retorno;
}

void DarDeBajaConfederacion(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones){
	int idBorrar;
	int indice;
	char seguir;

	if(MostrarDetallesConfederaciones(confederaciones, sizeConfed, contadorConfederaciones)==1){
		if(utn_getNumero(&idBorrar, "\nIngrese el Id de la confederacion a dar de baja", "\nError de id", 100, 110, 1) == 0){
			indice = buscarIndiceConfederacionPorId(confederaciones, idBorrar, sizeConfed);
			if(confederaciones[indice].isEmpty == CARGADO){
				seguir = ValidarSeguirNoSeguir("\nEsta seguro que quiere dar de baja esta confederacion? [S|N]", "\nError, ingrese S o N");
				if(seguir == 'S'){
					confederaciones[indice].isEmpty = BAJADO;
					printf("\nLa confederacion %s con el id %d fue dada de baja", confederaciones[indice].nombre, confederaciones[indice].id);
				}else{
					printf("\nNo se dara de baja a la confederacion");
				}
			}else{
				if(confederaciones[indice].isEmpty == BAJADO)
					printf("\nLa %s ya esta dada de baja", confederaciones[indice].nombre);
			}
		}else{
			printf("\nBaja interrumpida");
		}
	}else{
		printf("\nfalta cargar una confederacion");
	}
}

void ModificarConfederacion(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones){
	int idModificar;
	int indice;
	int subopcion;
	char seguir;

	if(MostrarDetallesConfederaciones(confederaciones, sizeConfed, contadorConfederaciones)==1){
		if(utn_getNumero(&idModificar, "\nElija el id de la confederacion a modificar", "\nError, no existe ese id", 100, 110, 1)== 0){
			indice = buscarIndiceConfederacionPorId(confederaciones, idModificar, sizeConfed);
			if(confederaciones[indice].isEmpty == CARGADO){
				do {
					MostrarModificacionConfed();
					if(utn_getNumero(&subopcion, "\nModificar:", "\nError de opcion", 0, 7, 1) == 0){
						switch (subopcion) {
							case 1://nombre char
								if(utn_getNombre(confederaciones[indice].nombre, 51, "\nNombre:", "\nError", 1)==0){
									strupr(confederaciones[indice].nombre);
									printf("\nnombre cambiado con exito");
								}else{
									printf("\nModificacion interrumpida");
								}
								break;
							case 2://region char
								if(utn_getNombre(confederaciones[indice].region, 51, "\nRegion:", "\nError", 1)==0){
									strupr(confederaciones[indice].region);
									printf("\nRegion cambiada con exito");
								}else{
									printf("\nModificacion interrumpida");
								}
								break;
							case 3://año creacion int
								if(utn_getNumero(&confederaciones[indice].anioCreacion, "\nIngrese el año de creacion", "\nError", 1916, 2022, 1)==0){
									printf("\nAño de creacion cambiado con exito");
								}else{
									printf("\nModificacion interrumpida");
								}
								break;
							default:
								printf("\nsaliendo del menu de modificaciones");
								break;
						}
					}
					if(subopcion != 4)
						seguir = ValidarSeguirNoSeguir("\nquiere realizar otra modificacion en esta confederacion? [S|N]", "\nError de opcion");
				}while(subopcion != 4 && seguir == 'S');
			}else{
				if(confederaciones[indice].isEmpty == BAJADO)
					printf("\n%s esta dada de baja", confederaciones[indice].nombre);
			}
		}else{
			printf("\nModificacion interrumpida");
		}
	}else{
		printf("\nNo hay confederaciones cargados");
	}
}

int ContarConfederacionesCargadas(int* contadorConfederaciones, eConfederacion confederaciones[], int size){
	int retorno;
	int contadorConfedAux = 0;
	retorno = 0;

	if(contadorConfederaciones != NULL && size > 0){
		retorno = 1;
		for(int i = 0; i<size; i++){
			if(confederaciones[i].isEmpty == CARGADO){
				contadorConfedAux++;
			}
		}
		*contadorConfederaciones = contadorConfedAux;
	}

	return retorno;
}

int ValidarConfederacionCargada(eConfederacion confederaciones[], int* contadorConfederaciones, int size){
	int retorno = 0;

	if(ContarConfederacionesCargadas(contadorConfederaciones, confederaciones, size)== 1){
		if(*contadorConfederaciones > 0){
			retorno = 1;
		}
	}

	return retorno;
}

int buscarIndiceConfederacionPorId(eConfederacion confederaciones[],int id,int sizeConfed){
	int indice = -1;

	if(confederaciones != NULL && sizeConfed > 0){
		for(int i=0; i<sizeConfed; i++){
			if(confederaciones[i].id == id){
				indice = i;
				break;
			}
		}
	}

	return indice;
}


int ValidarConfederacionCargadaPorId(eConfederacion confederaciones[], int sizeConfed, int id){
	int retorno = -1;

	if(confederaciones != NULL && sizeConfed > 0){
		for(int c = 0; c<sizeConfed;c++){
			if(confederaciones[c].isEmpty == CARGADO && confederaciones[c].id == id){
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

void AccederABMConfed(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones, int idAutoIncrementalConfed){
	int opcionABMConfed;
	int subOpcionAltaConfed;
	char seguirABMConfed;

	do {
		MostrarMenuABMConfed();
		if(utn_getNumero(&opcionABMConfed, "\nOpcion: ", "\nError", 1, 4, 1)==0){
			switch (opcionABMConfed) {
				case 1://Alta
					printf("\n1- Cargar una confederacion dada de baja"
							"\n2- Cargar una nueva confederacion");
					if(utn_getNumero(&subOpcionAltaConfed, "\nOpcion", "\nError", 1, 2, 1)==0){
						switch (subOpcionAltaConfed) {
							case 1:
								CargarConfederacionesBajadas(confederaciones, sizeConfed);
								break;
							case 2:
								if(CargarNuevaConfederacion(confederaciones, sizeConfed, idAutoIncrementalConfed)==1){
									printf("\nConfederacion cargada con exito");
								}else{
									printf("\nConfederacion cargada sin exito");
								}
								break;
							default:
								printf("\nerror");
								break;
						}
					}else{
						printf("\nAlta interrumpida");
					}
					break;
				case 2:
					DarDeBajaConfederacion(confederaciones, sizeConfed, contadorConfederaciones);
					break;
				case 3:
					ModificarConfederacion(confederaciones, sizeConfed, contadorConfederaciones);
					break;
				case 4:
					printf("\nEligio salir del ABM confederaciones...");
					break;
				default:
					printf("\nError");
					break;
			}
		}
		if(opcionABMConfed != 4)
			seguirABMConfed = ValidarSeguirNoSeguir("\nSeguir en el ABM confed? [S|N]", "Error");
	} while (opcionABMConfed != 4 && seguirABMConfed == 'S');

}
