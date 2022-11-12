#include "Controller.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
    FILE* pArchivo;

    if(path != NULL && pArrayListJugador != NULL){
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL){
			if(parser_JugadorFromText(pArchivo, pArrayListJugador)==1){
				retorno = 1;
			}
		}
		fclose(pArchivo);
    }
    return retorno;
}


int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path != NULL && pArrayListJugador != NULL){
		pArchivo = fopen(path, "rb");
		if(pArchivo != NULL){
			if(parser_JugadorFromBinary(pArchivo, pArrayListJugador) == 1){
				retorno = 1;
			}
		}
		fclose(pArchivo);
	}

    return retorno;
}


int controller_agregarJugador(LinkedList* pArrayListJugador){
	int retorno = -1;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	Jugador* unJugador = NULL;

	LinkedList* pArrayListSeleccionAux;
	pArrayListSeleccionAux = ll_newLinkedList();
	controller_cargarSeleccionesDesdeTexto("selecciones.csv", pArrayListSeleccionAux);

	if(pArrayListJugador != NULL){
		id= jug_AsignarIdDesdeTexto("idJugador.csv");
		if(utn_getNombre(nombreCompleto, 100, "\nIngrese el nombre del jugador: ", "\nError", 1)==0){
			ModularNombre(nombreCompleto);
			if(utn_getNumero(&edad, "\nIngrese la edad del jugador: [15-55]", "\nError", 15, 55, 1)==0){
				if(utn_getNombre(posicion, 30, "\nIngrese la posicion del jugador: ", "\nError", 1)==0){
					if(utn_getNombre(nacionalidad, 30, "\nIngrese la nacionalidad del jugador: ", "\nError", 1)==0)
					{
						unJugador = jug_new();
						if(jug_setOnePlayer(unJugador, id, nombreCompleto, edad, posicion, nacionalidad, 0)==1){
							if(unJugador != NULL){
								ll_add(pArrayListJugador, unJugador);
								jug_actualizarIdModoTexto(id);
								retorno = 1;
							}
						}
					}
				}
			}
		}
	}

	ll_deleteLinkedList(pArrayListSeleccionAux);
	free(unJugador);
    return retorno;
}

int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int idMaximo;
	int idJugAux;
	int indiceJugAux;
//	int validaExistencia = 0;
//	int intentos = 2;
	int opcion;
//	char confirmar;
	Jugador* unJugador = NULL;

	idMaximo = jug_AsignarIdDesdeTexto("idJugador.csv");

	if(pArrayListJugador != NULL /*&& cantidadJugadores > 0*/){
//		do{
			controller_listarJugadores(pArrayListJugador);
			if(utn_getNumero(&idJugAux, "\nIngrese el ID del jugador a modificar: ", "\nError", 1, idMaximo, 1)==0){
				indiceJugAux = jug_BuscarIndiceJugadorPorId(pArrayListJugador, idJugAux);
				if(indiceJugAux != -1){
//					validaExistencia = 1;
//					intentos = 0;
					unJugador = (Jugador*)ll_get(pArrayListJugador, indiceJugAux);
					if(unJugador!=NULL){
						jug_printOnePlayer(unJugador);
						printf("\n\nModificar:"
								"\n1- Nombre"
								"\n2- Edad"
								"\n3- Posicion"
								"\n4- Nacionalidad");
						utn_getNumero(&opcion, "\nOpcion: ", "\nError", 1, 4, 1);
						switch (opcion) {
							case 1:
								if(jug_modificarNombre(unJugador)==1){
									printf("\nNombre modificado");
								}else{
									printf("\nModificacion no realizada");
								}

								break;
							case 2:
								if(jug_modificarEdad(unJugador)==1){
									printf("\nEdad modificada");
								}else{
									printf("\nModificacion no realizada");
								}
								break;
							case 3:
								if(jug_modificarPosicion(unJugador)==1){
									printf("\nPosicion modificada");
								}else{
									printf("\nModificacion no realizada");
								}
								break;
							case 4:
								if(jug_modificarNacionalidad(unJugador)==1){
									printf("\nNacionalidad modificada");
								}else{
									printf("\nModificacion no realizada");
								}
								break;
							default:
								break;
						}
						///preguntar si quiere modificarle algo mas a este jugador
	//					confirmar = ValidarSeguirNoSeguir("\nModificar este jugador? [S|N]", "\nError");
					}
				}else{
					printf("\nEl jugador no existe");
//					intentos--;
				}
			}
//		}while(/*validaExistencia == 0 ||*/ intentos >0);
	}

	free(unJugador);

    return retorno;
}

int controller_removerJugador(LinkedList* pArrayListJugador){
	int retorno = -1;
	int id;
	int indice;
	int idMaximo;
	char seguir;
	Jugador* unJugador;

	idMaximo = jug_AsignarIdDesdeTexto("idJugador.csv");

	if(controller_listarJugadores(pArrayListJugador)==1){
		if(utn_getNumero(&id, "\nIngrese el id del jugador a dar de baja: ", "\nError", 1, idMaximo, 1)==0){
			indice = jug_BuscarIndiceJugadorPorId(pArrayListJugador, id);
			if(indice != -1){
				unJugador = ll_get(pArrayListJugador, indice);
				if(unJugador != NULL){
					printf("\nJugador a borrar: "
							"\n%-4s %-25s %-6s %-20s %-17s %-11s","id","nombre Completo", "edad", "posicion", "nacionalidad", "idSelecion");
					jug_printOnePlayer(unJugador);
//					controller_listarJugadoresConSeleccion(pArrayListJugador, pArrayListSeleccion);
					seguir = ValidarSeguirNoSeguir("\nSeguro que quiere borrar al jugador? [S|N]", "\nError");
					if(seguir == 'S'){
						ll_remove(pArrayListJugador, indice);
						jug_delete(unJugador);
						printf("\nJugador borrado");
						retorno = 1;
					}else{
						printf("\nNo se borrara al jugador");
					}
				}
			}else{
				printf("\nEl jugador no existe");
			}
		}else{
			printf("\nInterrumpiendo opcion");
		}
	}else{
		printf("\nno entra");
	}
    return retorno;
}


int controller_listarJugadores(LinkedList* pArrayListJugador){
	int cantidad;
	int retorno = 0;
	Jugador* jugadorAux;

	if(pArrayListJugador != NULL){
		cantidad = ll_len(pArrayListJugador);
		printf("\n%-4s %-25s %-6s %-20s %-17s %-11s","id","nombre Completo", "edad", "posicion", "nacionalidad", "idSelecion");
		printf("\n----------------------------------------------------------------------------------------");

		for(int i=0;i<cantidad;i++){
			jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
			if(jug_printOnePlayer(jugadorAux)==1){
				retorno = 1;
			}
		}
	}
    return retorno;
}

int controller_ordenarJugadoresYSelecciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int retorno = -1;
	char seguir;
	int criterio;

	LinkedList* jugadoresAux = NULL;
	LinkedList* seleccionesAux = NULL;

	jugadoresAux = ll_clone(pArrayListJugador);
	seleccionesAux = ll_clone(pArrayListSeleccion);

	if(jugadoresAux != NULL && seleccionesAux != NULL){
		do {
			printf("ORDENAR Y LISTAR\n"
				"1) JUGADORES POR NACIONALIDAD.\n"
				"2) SELECCIONES POR CONFEDERACIÓN.\n"
				"3) JUGADORES POR EDAD\n"
				"4) JUGADORES POR NOMBRE.\n");

			criterio = controller_ordenarJugadores(jugadoresAux);
			if(criterio==1){
				printf("\n");
			}else{
				if(criterio==2){
					controller_ordenarSelecciones(seleccionesAux);
				}
			}
			seguir= ValidarSeguirNoSeguir("\nDesea ordenar y listar en otro formato?\n", "\nError");
		} while (seguir != 'N');
	}

	return retorno;
}

int controller_ordenarJugadores(LinkedList* pArrayListJugador){
    int orden;
    int opcion;
    int retorno = -1;

	if(utn_getNumero(&opcion, "\nOpcion", "\nError", 1, 4, 1)==0){
		if(opcion != 2){
			retorno = 1;
			switch (opcion) {
				case 1:
					utn_getNumero(&orden,"\n0- Orden descendente"
										 "\n1- Orden ascendente"
										 "\nOpcion:", "\nError", 0, 1, 1);
					ll_sort(pArrayListJugador, jug_CompareByNationality, orden);
					controller_listarJugadores(pArrayListJugador);
					break;
				case 3:
					utn_getNumero(&orden,"\n0- Orden descendente"
										 "\n1- Orden ascendente"
										 "\nOpcion:", "\nError", 0, 1, 1);
					ll_sort(pArrayListJugador, jug_CompareByAge, orden);
					controller_listarJugadores(pArrayListJugador);
					break;
				case 4:
					utn_getNumero(&orden,"\n0- Orden descendente"
										 "\n1- Orden ascendente"
										"\nOpcion:", "\nError", 0, 1, 1);
					ll_sort(pArrayListJugador, jug_CompareByName, orden);
					controller_listarJugadores(pArrayListJugador);
					break;
				default:
					printf("\nError");
					break;
			}
		}else{
			if(opcion == 2){
				retorno = 2;
			}
		}
	}else{
		printf("\nOpcion interrumpida");
	}

    return retorno;
}


int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}


int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador){
	int retorno = -1;
	int cantidadJugad;
	int cantidadSelec;
	int idSelecJugAux;
	int idSelecAux;
	char confederacionAux[30];
	char confederacionOpcion[30];
	FILE* pFileBin;

	Jugador* jugadorAux;
	Seleccion* seleccionAux;

	LinkedList* pArrayListSeleccionAux;
	pArrayListSeleccionAux = ll_newLinkedList();
	controller_cargarSeleccionesDesdeTexto("selecciones.csv", pArrayListSeleccionAux);

	if(path != NULL && pArrayListJugador != NULL && pArrayListSeleccionAux != NULL){
		if(selec_seleccionarConfederacion(confederacionOpcion)==1){
			///habria que validar si esa confederacion tiene convocados y recien ahi crear el archivo
			pFileBin = fopen(path, "wb");
			cantidadJugad = ll_len(pArrayListJugador);
			cantidadSelec = ll_len(pArrayListSeleccionAux);

			for(int i = 0; i<cantidadJugad; i++){
				jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
				if(jug_getSIdSeleccion(jugadorAux, &idSelecJugAux)==0){
					if(idSelecJugAux != 0){
						for(int j = 0; j<cantidadSelec; j++){
							seleccionAux = (Seleccion*)ll_get(pArrayListSeleccionAux, j);
							if(selec_getId(seleccionAux, &idSelecAux)==0 && selec_getConfederacion(seleccionAux, confederacionAux)==0){
								if(strcmp(confederacionAux, confederacionOpcion)==0 && idSelecAux == idSelecJugAux){
									fwrite(jugadorAux, sizeof(Jugador), 1, pFileBin);
									retorno = 1;
								}
							}
						}
					}
				}
			}

			fclose(pFileBin);
			ll_clear(pArrayListSeleccionAux);
			ll_deleteLinkedList(pArrayListSeleccionAux);
			free(jugadorAux);
			free(seleccionAux);
		}else{
			printf("\nOpcion interrumpida...");
		}
	}

    return retorno;
}


int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
    FILE* pArchivoS;
    pArchivoS = fopen(path, "r");

    if(pArchivoS != NULL){
		parser_SeleccionFromText(pArchivoS, pArrayListSeleccion);
    }
	fclose(pArchivoS);

    return 1;
}


int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{

    return 1;
}


int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	Seleccion* seleccionAux;
	int cantidad;
	cantidad = ll_len(pArrayListSeleccion);

	for(int i=0;i<cantidad;i++){
		seleccionAux = (Seleccion*)ll_get(pArrayListSeleccion, i);
		selec_printOneSelec(seleccionAux);
	}

    return 1;
}


int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int orden;

	utn_getNumero(&orden,"\n0- Orden descendente"
						 "\n1- Orden ascendente"
						 "\nOpcion:", "\nError", 0, 1, 1);
	ll_sort(pArrayListSeleccion, selec_CompareByConfed, orden);

	controller_listarSelecciones(pArrayListSeleccion);

    return 1;
}


int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


///el maximo de jugadores se puede asi?
int controller_Convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSelecc){
	int retorno = -1;
    int indice;
    int id;
    int seleccion;
    int idMaximo;
    int cantidadSelec;
	Jugador* unJugador;

	idMaximo = jug_AsignarIdDesdeTexto("idJugador.csv");
//	cantidad = ll_len(pArrayListJugador);
	cantidadSelec = ll_len(pArrayListSelecc);

	if(controller_listarJugadores(pArrayListJugador)==1){
		if(utn_getNumero(&id, "\nIngrese Id del jugador a convocar: ", "\nError", 1, idMaximo, 1)==0){
			indice = jug_BuscarIndiceJugadorPorId(pArrayListJugador, id);
			if(indice != -1){
				unJugador = (Jugador*)ll_get(pArrayListJugador, indice);
				printf("\nJugador a convocar:");
				if(jug_printOnePlayer(unJugador)==1){
	//				printf("\n");
					controller_listarSelecciones(pArrayListSelecc);
					if(utn_getNumero(&seleccion, "\nSeleccion a la que convocar:", "\nError", 1, cantidadSelec, 1)==0){
						if(jug_setIdSeleccion(unJugador, seleccion)==0){
							jug_printOnePlayer(unJugador);
							retorno = 1;
						}
					}
				}
			}else{
				printf("\nEl jugador no existe");
			}
		}
	}
	return retorno;
}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador){
	int retorno = -1;

	int cantidadJugadores;
	int idSeleccJug;
	Jugador* jugadorAux;

	cantidadJugadores = ll_len(pArrayListJugador);

	printf("\n%-4s %-25s %-6s %-20s %-17s %-11s","id","nombre Completo", "edad", "posicion", "nacionalidad", "Selecion");
	printf("\n-------------------------------------------------------------------------------------------");

	for(int i = 0; i < cantidadJugadores; i++){
		jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
		if(jug_getSIdSeleccion(jugadorAux, &idSeleccJug)==0){
			if(idSeleccJug != 0){
				jug_printOnePlayer(jugadorAux);
				retorno = 1;
			}
		}
	}

	return retorno;
}

///preguntar si puedo hacer esto por ds
int controller_CargarArchivoBinario(char* pathJugadores, char* pathSelecciones){
	int retorno = -1;

	LinkedList* jugadoresAuxiliar;
	LinkedList* seleccionesAux;
	jugadoresAuxiliar = ll_newLinkedList();
	seleccionesAux = ll_newLinkedList();

	controller_cargarJugadoresDesdeBinario(pathJugadores, jugadoresAuxiliar);
	controller_cargarSeleccionesDesdeTexto(pathSelecciones, seleccionesAux);

	controller_listarJugadoresConvocados(jugadoresAuxiliar/*, seleccionesAux*/);

	///que onda con la fx clear?
	ll_clear(jugadoresAuxiliar);
	ll_deleteLinkedList(jugadoresAuxiliar);
	return retorno;
}
