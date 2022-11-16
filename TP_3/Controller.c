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
		if(id != -1 && utn_getNombre(nombreCompleto, 100, "\nIngrese el nombre del jugador: ", "\nError", 1)==0){
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

//	ll_deleteLinkedList(pArrayListSeleccionAux);
//	free(unJugador);
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
					///aca tendria que ir el do para editar datos del mismo jugador
					if(unJugador!=NULL){
						jug_printOnePlayer(unJugador);
						printf("\n\nModificar:"
								"\n1- Nombre"
								"\n2- Edad"
								"\n3- Posicion"
								"\n4- Nacionalidad");
						if(utn_getNumero(&opcion, "\nOpcion: ", "\nError", 1, 4, 1)==0){
							switch (opcion) {
								case 1:
									if(jug_modificarNombre(unJugador)==1){
										printf("\nNombre modificado");
										retorno = 1;
									}else{
										printf("\nModificacion no realizada");
									}

									break;
								case 2:
									if(jug_modificarEdad(unJugador)==1){
										printf("\nEdad modificada");
										retorno = 1;
									}else{
										printf("\nModificacion no realizada");
									}
									break;
								case 3:
									if(jug_modificarPosicion(unJugador)==1){
										printf("\nPosicion modificada");
										retorno = 1;
									}else{
										printf("\nModificacion no realizada");
									}
									break;
								case 4:
									if(jug_modificarNacionalidad(unJugador)==1){
										printf("\nNacionalidad modificada");
										retorno = 1;
									}else{
										printf("\nModificacion no realizada");
									}
									break;
								default:
									break;
							}
						///preguntar si quiere modificarle algo mas a este jugador... afuera de la fx?
	//					confirmar = ValidarSeguirNoSeguir("\nModificar este jugador? [S|N]", "\nError");
						}else{
							printf("\nModificacion interrumpida");
						}
					}
				}else{
					printf("\nEl jugador no existe");
//					intentos--;
				}
			}
//		}while(/*validaExistencia == 0 ||*/ intentos >0);
	}

//	free(unJugador);

    return retorno;
}

int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int retorno = -1;
	int id;
	int indice;
	int idMaximo;
	char seguir;
	Jugador* unJugador;
	int idSeleccion;
	int indiceSelec;
	int contador;
	Seleccion* unaSeleccion = NULL;

	idMaximo = jug_AsignarIdDesdeTexto("idJugador.csv");

	if(controller_listarJugadores(pArrayListJugador)==1){;
		if(utn_getNumero(&id, "\nIngrese el id del jugador a dar de baja: ", "\nError", 1, idMaximo, 1)==0){
			indice = jug_BuscarIndiceJugadorPorId(pArrayListJugador, id);
			if(indice != -1){
				unJugador = ll_get(pArrayListJugador, indice);
				if(unJugador != NULL){
					printf("\nJugador a borrar: ");
					mostrarCabeceraJugadores();
					jug_printOnePlayer(unJugador);
					seguir = ValidarSeguirNoSeguir("\nSeguro que quiere borrar al jugador? [S|N]", "\nError");
					if(seguir == 'S'){
						jug_getSIdSeleccion(unJugador, &idSeleccion);
						if(idSeleccion != 0){
							indiceSelec = selec_BuscarIndiceSeleccionPorId(pArrayListSeleccion, idSeleccion);
							unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indiceSelec);
							if(unaSeleccion != NULL){
								selec_getConvocados(unaSeleccion, &contador);
								contador--;
								selec_setConvocados(unaSeleccion, contador);
							}
						}
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
	}
    return retorno;
}


int controller_listarJugadores(LinkedList* pArrayListJugador){
	int cantidad;
	int retorno = -1;
	Jugador* jugadorAux;

	if(pArrayListJugador != NULL){
		cantidad = ll_len(pArrayListJugador);
		if(cantidad != -1){
			mostrarCabeceraJugadores();
			for(int i=0;i<cantidad;i++){
				jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
				if(jugadorAux != NULL){
					if(jug_printOnePlayer(jugadorAux)==1){
						retorno = 1;
					}
				}
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
			if(criterio != -1){
				if(criterio==1){
					printf("\n");
				}else{
					if(criterio==2){
						controller_ordenarSelecciones(seleccionesAux);
					}
				}
				retorno = 1;
			}
			seguir= ValidarSeguirNoSeguir("\nDesea ordenar y listar en otro formato? [S|N]\n", "\nError");
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
			switch (opcion) {
				case 1:
					if(utn_getNumero(&orden,"\n0- Orden descendente"
										 "\n1- Orden ascendente"
										 "\nOpcion:", "\nError", 0, 1, 1)==0)
					{
						ll_sort(pArrayListJugador, jug_CompareByNationality, orden);
						if(controller_listarJugadores(pArrayListJugador)==1){
							retorno = 1;
						}
					}
					break;
				case 3:
					if(utn_getNumero(&orden,"\n0- Orden descendente"
										 "\n1- Orden ascendente"
										 "\nOpcion:", "\nError", 0, 1, 1)==0)
					{
						ll_sort(pArrayListJugador, jug_CompareByAge, orden);
						if(controller_listarJugadores(pArrayListJugador)==1){
							retorno = 1;
						}
					}
					break;
				case 4:
					if(utn_getNumero(&orden,"\n0- Orden descendente"
										 "\n1- Orden ascendente"
										"\nOpcion:", "\nError", 0, 1, 1)==0)
					{
						ll_sort(pArrayListJugador, jug_CompareByName, orden);
						if(controller_listarJugadores(pArrayListJugador)==1){
							retorno = 1;
						}
					}
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


int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador){
	int retorno = -1;
	int cantidad;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	Jugador* unJugador = NULL;

	FILE* pArchivo;

	if(path != NULL && pArrayListJugador != NULL){
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL){
			cantidad = ll_len(pArrayListJugador);
			if(cantidad != -1){
				fprintf(pArchivo, "%s,%s,%s,%s,%s,%s\n", "id","nombreCompleto","edad","posicion","nacionalidad","idSelecion");
				for(int i = 0; i < cantidad; i++){
					unJugador = (Jugador*)ll_get(pArrayListJugador, i);
					if(unJugador != NULL){
						if(jug_getOnePlayer(unJugador, &id, nombreCompleto, &edad, posicion, nacionalidad, &idSeleccion)==1){
							fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n", id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
							retorno = 1;
						}
					}
				}
			}
		}
		fclose(pArchivo);
	}

    return retorno;
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
			pFileBin = fopen(path, "wb");
			cantidadJugad = ll_len(pArrayListJugador);
			cantidadSelec = ll_len(pArrayListSeleccionAux);

			if(cantidadJugad != -1 && cantidadSelec != -1){
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


int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion){
	int retorno = -1;
    FILE* pArchivo;

    if(path != NULL && pArrayListSeleccion != NULL){
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL){
			if(parser_SeleccionFromText(pArchivo, pArrayListSeleccion)==1){
				retorno = 1;
			}
		}
		fclose(pArchivo);
    }

    return retorno;
}


int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{

    return 1;
}


int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int cantidad;
	int retorno = -1;
	Seleccion* seleccionAux = NULL;

	cantidad = ll_len(pArrayListSeleccion) +1;
	if(cantidad != -1){
		mostrarCabeceraSelecciones();
		for(int i=0;i<cantidad;i++){
			seleccionAux = (Seleccion*)ll_get(pArrayListSeleccion, i);
			if(seleccionAux != NULL){
				if(selec_printOneSelec(seleccionAux)==1){
					retorno = 1;
				}
			}
		}
	}

//	free(seleccionAux);
    return retorno;
}


int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion){
	int retorno = -1;
	int orden;

	if(utn_getNumero(&orden,"\n0- Orden descendente"
						 "\n1- Orden ascendente"
						 "\nOpcion:", "\nError", 0, 1, 1)==0){
		mostrarCabeceraSelecciones();
		if(ll_sort(pArrayListSeleccion, selec_CompareByConfed, orden)==0){
			controller_listarSelecciones(pArrayListSeleccion);
			retorno = 1;
		}
	}

    return retorno;
}


int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion){
	int retorno = -1;
	int cantidad;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	Seleccion* unaSeleccion = NULL;

	FILE* pArchivo;

	if(path != NULL && pArrayListSeleccion != NULL){
		pArchivo = fopen(path, "w");
		if(pArchivo!= NULL){
			cantidad = ll_len(pArrayListSeleccion);
			if(cantidad != -1){
				fprintf(pArchivo, "%s,%s,%s,%s\n", "id","pais","confederacion","convocados");
				for(int i = 0; i<cantidad; i++){
					unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
					if(unaSeleccion != NULL){
						if(selec_getOneSelec(unaSeleccion, &id, pais, confederacion, &convocados)==1){
							fprintf(pArchivo, "%d,%s,%s,%d\n", id,pais,confederacion,convocados);
							retorno = 1;
						}
					}
				}
			}
		}
		fclose(pArchivo);
	}

    return retorno;
}


int controller_Convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int retorno = -1;
    int indiceJugador;
    int idJugador;
    int idMaximo;
    int cantidadSelec;
    int idSeleccion;
    int idSeleccionJugador;
    int indiceSeleccion;
    int convocados;/**Actual;
    int convocadosAhora;*/
	Jugador* unJugador = NULL;
	Seleccion* unaSeleccion = NULL;

	idMaximo = jug_AsignarIdDesdeTexto("idJugador.csv");

												///por que este +1?
	cantidadSelec = ll_len(pArrayListSeleccion)+1;

	if(controller_listarJugadores(pArrayListJugador)==1){
		if(utn_getNumero(&idJugador, "\nIngrese Id del jugador a convocar: ", "\nError", 1, idMaximo, 1)==0){
			indiceJugador = jug_BuscarIndiceJugadorPorId(pArrayListJugador, idJugador);
			if(indiceJugador != -1){
				unJugador = (Jugador*)ll_get(pArrayListJugador, indiceJugador);
				if(unJugador != NULL){
					jug_getSIdSeleccion(unJugador, &idSeleccionJugador);
					if(idSeleccionJugador == 0){
						printf("\nJugador a convocar:");
						mostrarCabeceraJugadores();
						if(jug_printOnePlayer(unJugador)==1){
							printf("\n==========================================================================================================\n");
							mostrarCabeceraSelecciones();
							controller_listarSelecciones(pArrayListSeleccion);
							if(utn_getNumero(&idSeleccion, "\nSeleccion a la que convocar:", "\nError", 1, cantidadSelec, 1)==0){
								///verificar que la seleccion elegida no tenga ya 22 convocados
								indiceSeleccion = selec_BuscarIndiceSeleccionPorId(pArrayListSeleccion, idSeleccion);
								unaSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, indiceSeleccion);
								if(unaSeleccion != NULL){
									selec_getConvocados(unaSeleccion, &convocados/*Actual*/);
									if(convocados/*Actual*/ < 22){
										if(jug_setIdSeleccion(unJugador, idSeleccion)==0){
											///contar convocados por seleccion:
											convocados/*Ahora*/ = convocados/*Actual*/+1;
											selec_setConvocados(unaSeleccion, convocados/*Ahora*/);
											printf("\nDatos del Jugador convocado:");
											printf("\n----------------------------");
											mostrarCabeceraJugadores();
											jug_printOnePlayer(unJugador);
											printf("\n==========================================================================================================\n");
											printf("\nDatos de la seleccion a la que fue convocado:");
											printf("\n---------------------------------------------");
											mostrarCabeceraSelecciones();
											selec_printOneSelec(unaSeleccion);
											printf("\n=====================================================\n");
											retorno = 1;
										}
									}else{
										printf("\nLa seleccion ya cuenta con todos sus jugadores convocados");
									}
								}
							}
						}
					}else{
						printf("\nel jugador ya esta convocado en una seleccion");
					}
				}else{
					printf("\nEl jugador no existe");
				}
			}
		}
	}else{
		printf("no entra");
	}

	return retorno;
}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador){
	int retorno = -1;

	int cantidadJugadores;
	int idSeleccJug;
	Jugador* jugadorAux;

	cantidadJugadores = ll_len(pArrayListJugador);

	if(cantidadJugadores != -1){
		printf("\nMostrando todos los jugadores convocados:");
		printf("\n-----------------------------------------");
		mostrarCabeceraJugadores();

		for(int i = 0; i < cantidadJugadores; i++){
			jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
			if(jug_getSIdSeleccion(jugadorAux, &idSeleccJug)==0){
				if(idSeleccJug != 0){
					jug_printOnePlayer(jugadorAux);
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

int controller_desconvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int retorno = -1;
	int idMaximo;
	int idJugAux;
	int indiceJugAux;
	int jugIdSeleccion;
	char seguir;
//	int validarDesconvocado = 0;
	char nombreCompleto[100];
	Jugador* unJugador = NULL;
//	int indiceSelecc;
//	int convocados;
	Seleccion* unaSeleccion = NULL;

	idMaximo = jug_AsignarIdDesdeTexto("idJugador.csv")-1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		if(controller_listarJugadoresConvocados(pArrayListJugador)==1){
			printf("\nSeleccione el jugador a desconvocar: ");
			if(utn_getNumero(&idJugAux, "\nOpcion: ", "\nEl jugador no existe", 1, idMaximo, 1)==0){
				indiceJugAux = jug_BuscarIndiceJugadorPorId(pArrayListJugador, idJugAux);
				unJugador = (Jugador*)ll_get(pArrayListJugador, indiceJugAux);
				jug_getSIdSeleccion(unJugador, &jugIdSeleccion);
				if(unJugador != NULL){
					if(jugIdSeleccion != 0){
						jug_printOnePlayer(unJugador);
						seguir = ValidarSeguirNoSeguir("\nDesconvocar a este jugador? [S|N]", "\nError");
						if(seguir == 'S'){
							if(selec_desconvocarPorId(pArrayListSeleccion, jugIdSeleccion)==1){
								selec_printOneSelec(unaSeleccion);
								jug_setIdSeleccion(unJugador, 0);
								retorno = 1;
							}
						}else{
							printf("\nEl jugador no fue desconvocado");
						}
					}else{
						jug_getNombreCompleto(unJugador, nombreCompleto);
						printf("\nEl jugador %s no esta convocado a ninguna seleccion", nombreCompleto);
					}
				}else{
					printf("\nEl jugador fue bajado");
				}
			}else{
				printf("\nDesconvocatoria interrumpida");
			}
		}
	}

	return retorno;
}

///preguntar si puedo hacer esto por ds
int controller_CargarArchivoBinario(char* pathJugadores, char* pathSelecciones){
	int retorno = -1;

	if(pathJugadores != NULL && pathSelecciones != NULL){
		LinkedList* jugadoresAuxiliar;
		LinkedList* seleccionesAux;
		jugadoresAuxiliar = ll_newLinkedList();
		seleccionesAux = ll_newLinkedList();

		if(seleccionesAux != NULL && jugadoresAuxiliar != NULL){
			if(controller_cargarJugadoresDesdeBinario(pathJugadores, jugadoresAuxiliar)==1 &&
					controller_cargarSeleccionesDesdeTexto(pathSelecciones, seleccionesAux)==1){
				controller_listarJugadoresConvocados(jugadoresAuxiliar);
				retorno = 1;
			}
		}

		///que onda con la fx clear?
		ll_clear(jugadoresAuxiliar);
		ll_deleteLinkedList(jugadoresAuxiliar);
	}
	return retorno;
}
