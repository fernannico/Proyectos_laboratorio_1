
#include "Controller.h"


int main()
{
	setbuf(stdout,NULL);
    int option;
//    char seguir;
    int banderaOpcionOcho = 0;
    int banderaOpcionUno = 0;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do{
    	printf( "\n\n|=============================|"
    			"\n|            MENU             |\n|=============================|"
    			"\n| 1 | CARGA DE ARCHIVOS       |\n|-----------------------------|"
    			"\n| 2 | ALTA DE JUGADOR         |\n|-----------------------------|"
    			"\n| 3 | MODIFICACION DE JUGADOR |\n|-----------------------------|"
    			"\n| 4 | BAJA DE JUGADOR         |\n|-----------------------------|"
    			"\n| 5 | LISTADOS                |\n|-----------------------------|"
    			"\n| 6 | CONVOCAR JUGADOR        |\n|-----------------------------|"
    			"\n| 7 | ORDENAR Y LISTAR        |\n|-----------------------------|"
    			"\n| 8 | GENERAR ARCHIVO BINARIO |\n|-----------------------------|"
    			"\n| 9 | CARGAR ARCHIVO BINARIO  |\n|-----------------------------|"
    			"\n| 10 | GUARDAR ARCHIVO CSV    |\n|-----------------------------|"
    			"\n| 11 | SALIR                  |\n|=============================|");
    	utn_getNumero(&option, "\nOpcion", "\nError", 1,11, 1);
        switch(option)
        {
            case 1:
            	if(banderaOpcionUno == 0){
					puts("\nCargando jugadores desde el texto...");
					controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);

					puts("\nCargando selecciones desde el texto...");
					controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);
					banderaOpcionUno = 1;
            	}else{
            		printf("\nLas listas ya fueron cargadas");

            	}
                break;
            case 2://ALTA
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0){
            		if(controller_agregarJugador(listaJugadores)==1){
						printf("\nJugador cargado");
            		}else{
						printf("\nAlta interrumpida");
            		}
            	}else{
            		printf("\nLas listas no estan cargadas\n");
            	}
            	break;
            case 3://MODIFICACION
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0){
            		controller_editarJugador(listaJugadores);
            	}else{
            		printf("\nLas listas no estan cargadas\n");
            	}
            	break;
            case 4://BAJA
            	///si se da de baja un jugador convocado hay que reducir el contador de seleccion
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0){
            		controller_removerJugador(listaJugadores, listaSelecciones);
            	}else{
            		printf("\nLas listas no estan cargadas\n");
            	}
            	break;
            case 5:
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0){
					printf("LISTADOS:\n"
					"1- TODOS LOS JUGADORES.\n"
					"2- TODAS LAS SELECCIONES.\n"
					"3- JUGADORES CONVOCADOS (únicamente)\n");
					if(utn_getNumero(&option, "\nopcion: ", "\nError!", 1, 3, 1)==0){
						switch (option) {
							case 1:
								controller_listarJugadores(listaJugadores);
								break;
							case 2:
								controller_listarSelecciones(listaSelecciones);
								break;
							case 3:
								if(selec_verificarConvocados(listaSelecciones)==1){
									controller_listarJugadoresConvocados(listaJugadores);
								}else{
									printf("\nNo hay convocados en ninguna seleccion");
								}
								break;
							default:
								printf("\nError");
								break;
						}
					}
            	}else{
            		printf("\nLas listas no estan cargadas\n");
            	}
            	break;
            case 6://CONVOCAR-desconvocar JUGADORES
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0){
//					do {
						printf("\n1- CONVOCAR"
								"\n2- QUITAR DE LA SELECCION\n");
						utn_getNumero(&option, "\nOpcion", "\nError", 1, 2, 1);
						if(option == 1){
							///Hacerle las verificaciones.
							controller_Convocar(listaJugadores, listaSelecciones);
						}else{
							if(option == 2 && selec_verificarConvocados(listaSelecciones)==1){
								if(controller_desconvocar(listaJugadores, listaSelecciones)==1){
									printf("\nJugador desconvocado");
								}

							}else{
								printf("\nNo hay convocados en ninguna seleccion");
							}
						}
//						seguir = ValidarSeguirNoSeguir("\nConvocar/desConvocar otro jugador? [S|N]", "\nError");
//					} while (seguir != 'N');
				}else{
					printf("\nLas listas no estan cargadas\n");
				}
				break;
            case 7:
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0){
            		controller_ordenarJugadoresYSelecciones(listaJugadores, listaSelecciones);
            	}else{
            		printf("\nLas listas no estan cargadas\n");
            	}
            	break;
			case 8://8. GENERAR ARCHIVO BINARIO: Generar y guardar en binario una nueva lista que contenga los jugadores convocados de una confederación ingresada por el usuario.
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0){
            		if(selec_verificarConvocados(listaSelecciones)==1){
						if(controller_guardarJugadoresModoBinario("convocados.dat", listaJugadores)==1){
							printf("\nLa lista fue creada \n");
							banderaOpcionOcho = 1;
						}
            		}else{
                		printf("\nNo hay nadie convocado en ninguna seleccion\n");
                	}
            	}else{
            		printf("\nLas listas no estan cargadas\n");
            	}
				break;
			case 9://9. CARGAR ARCHIVO BINARIO: Se deberá leer e imprimir los datos del archivo generado en el punto 8.
				if(banderaOpcionOcho == 1){
					controller_CargarArchivoBinario("convocados.dat", "selecciones.csv");
				}
				break;
			case 10://GUARDAR ARCHIVOS .CSV
				///validar con containsAll?

//				printf("id de selecc:");
//				scanf("%d", &id);
//				indice = selec_BuscarIndiceSeleccionPorId(listaSelecciones, id);
//				unaSelecAux = ll_get(listaSelecciones, indice);
//				selec_printOneSelec(unaSelecAux);
//				controller_listarJugadoresConSeleccion(listaJugadores/*, listaSelecciones*/);


				break;
			case 11:
				///hacer delete de ll...
				/// si sale sin querer guardar cambios.. se tendria que borrar el binario... o al menos desconvocar a todos y guardar...
				/// no dice que tenga que guardar el binario... si el csv.

				printf("\nSaliendo del programa");

				ll_clear(listaJugadores);
				ll_clear(listaSelecciones);
				ll_deleteLinkedList(listaJugadores);
				ll_deleteLinkedList(listaSelecciones);

				break;
			default:

				break;
        }
    }while(option != 11);

    return 0;
}




//					printf("\n%-4s %-25s %-6s %-20s %-17s %-11s","id","nombre Completo", "edad", "posicion", "nacionalidad", "Selecion");
//					printf("\n-------------------------------------------------------------------------------------------");



