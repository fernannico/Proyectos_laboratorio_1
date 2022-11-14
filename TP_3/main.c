
#include "Controller.h"


int main()
{
	setbuf(stdout,NULL);
    int option;
//    char seguir;
    int banderaOpcionUno = 0;
    int banderaOpcionOcho = 0;
//    int banderaOpcionDiez = 0;///va aca? porq solo funcionaria 1 vez...

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

//    int cantidadJugadores;
//	Jugador* unJugador;
//    int validarCambios;
//    LinkedList* listaJugadoresSinCambios;
//    LinkedList* listaSeleccionesAux = ll_clone(listaSelecciones);

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
    	utn_getNumero(&option, "\nOpcion", "\nError", 1,12, 1);
        switch(option)
        {
            case 1:
            	if(banderaOpcionUno == 0){
					if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)==1){
						puts("\nCargando jugadores desde el texto...");
					}
					if(controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones)==1){
						puts("\nCargando selecciones desde el texto...");
					}
					banderaOpcionUno = 1;
            	}else{
            		printf("\nLas listas ya fueron cargadas");

            	}
//                listaJugadoresSinCambios = ll_clone(listaJugadores);

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
            	///poner cuando el jugador fue bajado (ahora esta como "no existe") como en desconvocados
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0){
            		controller_editarJugador(listaJugadores);
            	}else{
            		printf("\nLas listas no estan cargadas\n");
            	}
            	break;
            case 4://BAJA
            	///poner cuando el jugador fue bajado (ahora esta como "no existe") como en desconvocados
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
							///poner cuando el jugador fue bajado (ahora esta como "no existe") como en desconvocados
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
            			///habria que validar si esa confederacion tiene convocados y recien ahi crear el archivo
            			/// esto tendria que ser antes de el controller porque al usar dentro el auxiliar, no se muestran los contadores actualizados
            			/// selec_seleccionarConfederacion antes del controller?
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
				///validar con containsAll si hubieron cambios?
				if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores)==1){
					printf("\nGuardando los jugadores en el archivo");
				}
				if(controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones)==1){
					printf("\nGuardando las selecciones en el archivo");
				}

				break;
			case 11:
				///hacer delete de ll...
				/// si sale sin querer guardar cambios.. se tendria que borrar el binario... o al menos desconvocar a todos y guardar...
				/// no dice que tenga que guardar el binario... si el csv.


				/**solo valida si falta un elemento... no si se cambiaron
						validarCambios =ll_containsAll(listaJugadoresSinCambios, listaJugadores);
						if(validarCambios==0){
							printf("\nLas lsitas J difieren");
						}else{
							if(validarCambios ==1){
								printf("\nLas lsitas J no difieren");
							}else{
								if(validarCambios==-1)
								printf("\nNULL");
							}
						}
				 */

				/*lo mismo.. solo valida q esten los elementos, no si se cambiaron
						cantidadJugadores = jug_AsignarIdDesdeTexto("idJugador.csv")-1;
						printf("%d", cantidadJugadores);
						for(int i = 0; i<cantidadJugadores;i++){
							unJugador = (Jugador*)ll_get(listaJugadores, i);
							if(ll_contains(listaJugadoresSinCambios, unJugador)==1){
								printf("\nesta");
							}else{
								printf("\n\nNO ESTA\n\n");
							}
						}
				*/

				printf("\nSaliendo del programa");

//				controller_listarJugadores(listaJugadoresAux);
//				ll_clear(listaJugadores);
//				ll_clear(listaSelecciones);
//				ll_deleteLinkedList(listaJugadores);
//				ll_deleteLinkedList(listaSelecciones);

				break;
			default:

				break;
        }
    }while(option != 12);

    return 0;
}




//					printf("\n%-4s %-25s %-6s %-20s %-17s %-11s","id","nombre Completo", "edad", "posicion", "nacionalidad", "Selecion");
//					printf("\n-------------------------------------------------------------------------------------------");



