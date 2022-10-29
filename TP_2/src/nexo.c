/*
 * nexo.c
 *
 *  Created on: 27 oct. 2022
 *      Author: User
 */
#include "nexo.h"

int ContarJugadoresCargados(int* contadorJugadores, eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed){
	int retorno;
	int contadorJugadoresAux = 0;
	int confedJugador;
	retorno = 0;

	if(jugadores != NULL && sizeJugadores > 0 && confederaciones != NULL && sizeConfed > 0 && contadorJugadores != NULL){
		retorno = 1;
		for(int i = 0; i<sizeJugadores; i++){
			confedJugador = buscarIndiceConfederacionPorId(confederaciones, jugadores[i].idConfederacion, sizeConfed);
			if(jugadores[i].isEmpty == CARGADO && confederaciones[confedJugador].isEmpty == CARGADO){
				contadorJugadoresAux++;
			}
		}
		*contadorJugadores = contadorJugadoresAux;
	}

	return retorno;
}

int ValidarJugadorCargado(eJugador jugadores[], int* contadorJugadores, int sizeJugadores, eConfederacion confederaciones[], int sizeConfed){
	int retorno = 0;

	if(ContarJugadoresCargados(contadorJugadores, jugadores, confederaciones, sizeJugadores, sizeConfed)==1){
//	if(ContarJugadoresCargados(contadorJugadores, jugadores, size)==1){
		if(*contadorJugadores > 0){
			retorno = 1;
		}
	}

	return retorno;
}

void CargarJugador(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int* codigoAutoIncremental, int* contadorConfederaciones){
	char seguir;

	if(*codigoAutoIncremental < sizeJugadores){
		do {
			if(AltaJugador(jugadores, confederaciones, sizeJugadores, sizeConfed, *codigoAutoIncremental, contadorConfederaciones) == 1){
				printf("\nSe cargo el jugador correctamente");
				*codigoAutoIncremental = *codigoAutoIncremental+1;
			}else{
				printf("\nNo se pudo realizar la carga");
			}
			seguir = ValidarSeguirNoSeguir("\nIngresar otro jugador? [S|N]", "\nError");
		} while (seguir == 'S' && *codigoAutoIncremental < sizeJugadores);
	}else{
		printf("\nYa estan todos los jugadores cargados");
	}
}

int AltaJugador(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int codigoAutoIncremental, int* contadorConfederaciones){
	int retorno;
	int indiceLibre;
	int reintentos = 2;
	int banderaConfed = 0;

	retorno = -1;
	indiceLibre = BuscarEspacioLibreJugadores(jugadores, sizeJugadores);

	if(ValidarConfederacionCargada(confederaciones, contadorConfederaciones, sizeConfed)==1){
		if(indiceLibre > -1 && indiceLibre < sizeJugadores){
			jugadores[indiceLibre].id = codigoAutoIncremental;
			//Cargar nombre
			if(utn_getNombre(jugadores[indiceLibre].nombre, 51, "\ningrese el nombre del jugador", "\Error", 1)==0){
				ModularNombre(jugadores[indiceLibre].nombre);
				//Cargar posicion
				if(CargarPosicion(jugadores, indiceLibre)==0){
					//Cargar numero camiseta
					if(utn_getShort(&jugadores[indiceLibre].numeroCamiseta, "\nIngrese el numero de camiseta", "\nError", 1, 99, 1)==0){
						//Cargar id confederacion
						if(MostrarDetallesConfederaciones(confederaciones, sizeConfed, contadorConfederaciones)==1){
							do{
								if(utn_getNumero(&jugadores[indiceLibre].idConfederacion, "\nIngrese el numero de la confederacion", "\nError", 100, 105, 1)==0){
									if(ValidarConfederacionCargadaPorId(confederaciones, sizeConfed, jugadores[indiceLibre].idConfederacion)==1){
										banderaConfed = 1;
											//Cargar salario
											if(utn_getNumeroFlotante(&jugadores[indiceLibre].salario, "\ningrese el salario del jugador", "\nError", 1, 999999, 1)==0){
												//Cargar años contrato
												if(utn_getShort(&jugadores[indiceLibre].aniosContrato, "\nIngrese los anios de contrato [1-5]", "\nError de anios de contrato [de 1 a 5 maximo]", 1, 5, 1)==0){
													jugadores[indiceLibre].isEmpty = CARGADO;
													retorno = 1;
												}
											}
//										}
									}else{
										printf("\nConfederacion no cargada");
									}
								}
								reintentos--;
							}while(reintentos >=0 && banderaConfed == 0);
						}
					}
				}
			}else{
				printf("\nNombre cargado sin exito");
			}
		}
	}else{
		printf("\nFalta cargar una confederacion");
	}

	return retorno;
}

void DarDeBajaJugador(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int* contadorJugadores, int codigoAutoIncremental){
	int idBorrar;
	int indice;
	char seguir;
	int maximoIdCargado;

	maximoIdCargado = codigoAutoIncremental-1;

	OrdenarJugadoresPorId(jugadores, sizeJugadores);

	if(MostrarDetallesJugadores(jugadores, confederaciones, sizeJugadores, sizeConfed, contadorJugadores)==1){
		if(utn_getNumero(&idBorrar, "\nIngrese el Id del jugador a dar de baja", "\nError de id", 1, maximoIdCargado, 1) == 0){
			indice = buscarIndicePorIdJugador(jugadores, sizeJugadores, idBorrar);
			if(jugadores[indice].isEmpty == CARGADO){
				seguir = ValidarSeguirNoSeguir("\nEsta seguro que quiere dar de baja al jugador? [S|N]", "\nError, ingrese S o N");
				if(seguir == 'S'){
					jugadores[indice].isEmpty = BAJADO;
					printf("\nEl jugador %s con el id %d fue dado de baja", jugadores[indice].nombre, jugadores[indice].id);
				}else{
					printf("\nNo se dara de baja al jugador");
				}
			}else{
				if(jugadores[indice].isEmpty == BAJADO)
					printf("\n%s ya esta dado de baja", jugadores[indice].nombre);
			}
		}else{
			printf("\nBaja interrumpida");
		}
	}else{
		printf("\nfalta cargar un jugador");
	}
}

void ModificarJugador(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int* contadorJugadores, int* contadorConfederaciones, int codigoAutoIncremental){
	int idModificar;
	int indice;
	int subopcion;
	char seguir;
	int maximoIdCargado;

	maximoIdCargado = codigoAutoIncremental-1;

	OrdenarJugadoresPorId(jugadores, sizeJugadores);

	if(MostrarDetallesJugadores(jugadores, confederaciones, sizeJugadores, sizeConfed, contadorJugadores)==1){
		if(utn_getNumero(&idModificar, "\nElija el id del jugador a modificar", "\nError, no existe ese id", 1, maximoIdCargado, 1)== 0){
			indice = buscarIndicePorIdJugador(jugadores, sizeJugadores, idModificar);
			if(jugadores[indice].isEmpty == CARGADO){
				do {
					MostrarSubmenuModificacion();
					if(utn_getNumero(&subopcion, "\nModificar:", "\nError de opcion", 0, 7, 1) == 0){
						switch (subopcion) {
							case 1://nombre
								if(utn_getNombre(jugadores[indice].nombre, 51, "\nNombre:", "\nError", 1)==0){
									ModularNombre(jugadores[indice].nombre);
									printf("\nnombre cambiado con exito");
								}else{
									printf("\nModificacion interrumpida");
								}
								break;
							case 2://posicion
								if(CargarPosicion(jugadores, indice) == 0){
									printf("\nPosicion cambiada con exito");
								}else{
									printf("\nModificacion interrumpida");
								}
								break;
							case 3://numero
								if(utn_getShort(&jugadores[indice].numeroCamiseta, "\nIngrese el numero de camiseta", "\nError", 1, 99, 1)==0){
									printf("\nNumero de camiseta cambiado con exito");
								}else{
									printf("\nModificacion interrumpida");
								}
								break;
							case 4://idconf
								MostrarDetallesConfederaciones(confederaciones, sizeConfed, contadorConfederaciones);
								if(utn_getNumero(&jugadores[indice].idConfederacion, "\nIngrese el numero de la nueva confederacion", "\nError", 100, 105, 1)==0){
									printf("\nConfederacion cambiada con exito");
								}else{
									printf("\nModificacion interrumpida");
								}
								break;
							case 5://salario
								if(utn_getNumeroFlotante(&jugadores[indice].salario, "\ningrese el nuevo salario del jugador", "\nError", 1, 999999, 1)==0){
									printf("\nSalario cambiado con exito");
								}else{
									printf("\nModificacion interrumpida");
								}
								break;
							case 6://años contrato
								if(utn_getShort(&jugadores[indice].aniosContrato, "\nIngrese los anios de contrato [1-5]", "\nError de anios de contrato [de 1 a 5 maximo]", 1, 5, 1)==0){
									printf("\nAnios de contrato cambiada con exito");
								}else{
									printf("\nModificacion interrumpida");
								}
								break;
							default:
								printf("\nsaliendo del menu de modificaciones");
								break;
						}
					}
					if(subopcion != 7)
						seguir = ValidarSeguirNoSeguir("\nquiere realizar otra modificacion en este jugador? [S|N]", "\nError de opcion");
				}while(subopcion != 7 && seguir == 'S');
			}else{
				if(jugadores[indice].isEmpty == BAJADO)
					printf("\n%s esta dado de baja", jugadores[indice].nombre);
			}
		}else{
			printf("\nModificacion interrumpida");
		}
	}else{
		printf("\nNo hay jugadores cargados");
	}
}

int OrdenarJugadoresPorConfedYNombre(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int* contadorJugadores, int* contadorConfederaciones){
	int retorno;
	int confJugadorUno;
	int confJugadorDos;
	eJugador jugadorAux;

	if(ValidarConfederacionCargada(confederaciones, contadorConfederaciones, sizeConfed)==1){
		if(ValidarJugadorCargado(jugadores, contadorJugadores, sizeJugadores, confederaciones, sizeConfed)==1){
			retorno = 1;
			for(int i = 0; i<sizeJugadores-1;i++){
				for(int j = i+1; j<sizeJugadores;j++){
					confJugadorUno = buscarIndiceConfederacionPorId(confederaciones, jugadores[i].idConfederacion, sizeConfed);
					confJugadorDos = buscarIndiceConfederacionPorId(confederaciones, jugadores[j].idConfederacion, sizeConfed);

					if(strcmpi(confederaciones[confJugadorUno].nombre,confederaciones[confJugadorDos].nombre)>0){
						jugadorAux = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = jugadorAux;
					}else{
						if(jugadores[i].idConfederacion == jugadores[j].idConfederacion){
							if(strcmpi(jugadores[i].nombre,jugadores[j].nombre)>0){
								jugadorAux = jugadores[i];
								jugadores[i] = jugadores[j];
								jugadores[j] = jugadorAux;
							}
						}

					}
				}
			}
		}else{
			printf("\nFalta cargar un jugador");
			retorno = -1;
		}
	}else{
		printf("\nFalta cargar una confederacion");
		retorno = -1;
	}

	return retorno;
}

int AcumularAniosConfed(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int indice/*, int* contadorConfederaciones*/){
	int acumulador;
	acumulador = 0;

	if(confederaciones != NULL && sizeConfed > 0 && jugadores != NULL && sizeJugadores > 0 /*&& ValidarConfederacionCargada(confederaciones, contadorConfederaciones, sizeConfed)==1*/){
		if(confederaciones[indice].isEmpty == CARGADO ){
			for(int j = 0; jugadores[j].isEmpty == LIBRE || j<sizeJugadores; j++){
				if(jugadores[j].idConfederacion == confederaciones[indice].id){
					acumulador = acumulador+jugadores[j].aniosContrato;
				}
			}
		}
	}

	return acumulador;
}

int ObtenerIndiceConfedMasAnios(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones){
	int  acumuladorAuxiliar;
	int mayorAcumulador;
	int banderaMayorAnios =0;
	int indice = -1;

	acumuladorAuxiliar = 0;

	if(confederaciones != NULL && sizeConfed > 0){
		if(ValidarConfederacionCargada(confederaciones, contadorConfederaciones, sizeConfed)==1){
			//funcion
			for(int i = 0; i < sizeConfed; i++){
				if(confederaciones[i].isEmpty == CARGADO){
					acumuladorAuxiliar = AcumularAniosConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, i);
					if(banderaMayorAnios == 0 || acumuladorAuxiliar > mayorAcumulador){
						banderaMayorAnios = 1;
						mayorAcumulador = acumuladorAuxiliar;
						indice = i;
					}
				}
			}
		}
	}
	return indice;
}

int informarConfederacionMasAnios(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones){
	int retorno = -1;
	int indice;

	indice = ObtenerIndiceConfedMasAnios(confederaciones, jugadores, sizeConfed, sizeJugadores, contadorConfederaciones);
	if(indice != -1){
		if(MostrarConfederacionPorId(confederaciones, sizeConfed, contadorConfederaciones, confederaciones[indice].id)==1){
			printf("\n| años: %d |"
					"\n===========", AcumularAniosConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, indice));
		}
	}else{
		printf("\nNo hay confederaciones cargadas");
	}

	return retorno;
}

///ACA VAN LAS FUNCIONES DEL PUNTO 4.5

int ContarJugadoresConfed(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int indice){
	int contador;
	contador = 0;

	if(confederaciones != NULL && sizeConfed > 0 && jugadores != NULL && sizeJugadores > 0){
		if(confederaciones[indice].isEmpty == CARGADO ){
			for(int j = 0; jugadores[j].isEmpty == LIBRE || j<sizeJugadores; j++){
				if(jugadores[j].idConfederacion == confederaciones[indice].id && jugadores[j].isEmpty == CARGADO){
					contador++;
				}
			}
		}
	}

	return contador;
}

int ObtenerIndiceConfedMasJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores){
	int contadorAuxiliar;
	int mayorContador;
	int banderaMayorAnios =0;
	int indice = -1;

	contadorAuxiliar = 0;

	if(confederaciones != NULL && sizeConfed > 0){
		if(ValidarConfederacionCargada(confederaciones, contadorConfederaciones, sizeConfed)==1 && ValidarJugadorCargado(jugadores, contadorJugadores, sizeJugadores, confederaciones, sizeConfed)==1){
			//funcion
			for(int i = 0; i < sizeConfed; i++){
				if(confederaciones[i].isEmpty == CARGADO){
					contadorAuxiliar = ContarJugadoresConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, i);
					if(banderaMayorAnios == 0 || contadorAuxiliar > mayorContador){
						banderaMayorAnios = 1;
						mayorContador = contadorAuxiliar;
						indice = i;
					}
				}
			}
		}
	}
	return indice;
}

void MostrarConfederacionesConMasJugadores(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores){
	int indice;
	int maximoContador;
	int contadorAux;

	contadorAux = 0;

	if((indice = ObtenerIndiceConfedMasJugadores(confederaciones, jugadores, sizeConfed, sizeJugadores, contadorConfederaciones, contadorJugadores)) != -1){
		maximoContador = ContarJugadoresConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, indice);
		printf("\n===========================================================");
		printf("\n|%-15s| %-4s|| %-20s| %-11s|", "Confederacion", "Id", "Nombre Jugador", "Id Jugador");

		for(int i = 0; i< sizeConfed; i++){
			if(confederaciones[i].isEmpty == 1){
				contadorAux = ContarJugadoresConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, i);
				if(contadorAux == maximoContador){
					printf("\n-----------------------------------------------------------");
					printf("\n| %-14s| %-4d||%34c|", confederaciones[i].nombre, confederaciones[i].id, ' ');
					for(int j = 0; j < sizeJugadores; j++){
						if(jugadores[j].idConfederacion == confederaciones[i].id && jugadores[j].isEmpty == CARGADO){
							printf("\n|%43s | %5d      |", jugadores[j].nombre, jugadores[j].id);
						}
					}
				}
			}
		}
	}else{
		printf("\nFaltan cargar jugadores / confederaciones");
	}
	printf("\n===========================================================");
}

float CalcularTotalSalarios(eJugador jugadores[], int sizeJugadores, int* contadorJugadores, eConfederacion confederaciones[], int sizeConfed){
	float acumulador;
	acumulador = 0;

	if(ValidarJugadorCargado(jugadores, contadorJugadores, sizeJugadores, confederaciones, sizeConfed)==1){
		for(int i = 0; jugadores[i].isEmpty == LIBRE || i < sizeJugadores; i++){
			if(jugadores[i].isEmpty == CARGADO){
				acumulador += jugadores[i].salario;
			}
		}
	}
	return acumulador;
}

int CalcularInformeSalarios(eJugador jugadores[], int sizeJugadores, int* contadorJugadores, eConfederacion confederaciones[], int sizeConfed){
	int retorno = -1;
	float acumuladorSalarios;
	float promedioSalarios;
	int contadorJugadoresMayorProm;
	acumuladorSalarios = 0;
	contadorJugadoresMayorProm = 0;

	acumuladorSalarios = CalcularTotalSalarios(jugadores, sizeJugadores, contadorJugadores, confederaciones, sizeConfed);
	promedioSalarios = CalcularPromedio(acumuladorSalarios, *contadorJugadores);

	for(int i = 0; i < sizeJugadores;i++){
		if(jugadores[i].isEmpty == CARGADO && jugadores[i].salario > promedioSalarios){
			contadorJugadoresMayorProm++;
		}
	}

	MostrarInformeSalarios(acumuladorSalarios, promedioSalarios, contadorJugadoresMayorProm);

	return retorno;
}


void InformarPorcentajeJugadoresPorConfed(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores){
	int banderaConfed;
	printf("\n===========================================================");
	printf("\n|%-15s| %-4s|| %-20s| %-11s|", "Confederacion", "Id", "Nombre Jugador", "Id Jugador");

	for(int i = 0; i< sizeConfed; i++){
		banderaConfed = 0;
		if(confederaciones[i].isEmpty == 1){
			printf("\n-----------------------------------------------------------");
			printf("\n| %-14s| %-4d||%34c|", confederaciones[i].nombre, confederaciones[i].id, ' ');
			for(int j = 0; j < sizeJugadores; j++){
				if(jugadores[j].idConfederacion == confederaciones[i].id && jugadores[j].isEmpty == CARGADO){
					if(banderaConfed == 0){
						banderaConfed = 1;
						printf("\n|%50s", "porcentaje: ");
						printf("%%%.2f |", CalcularPorcentajeJugadoresConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, contadorConfederaciones, contadorJugadores, i));
					}
				}else{
					if(ContarJugadoresConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, i) == 0){
						printf("\n| %55s |", "porcentaje: sin jugadores");
						break;
					}
				}
			}
		}
	}
	printf("\n===========================================================");
}

float CalcularPorcentajeJugadoresConfed(eConfederacion confederaciones[], eJugador jugadores[], int sizeConfed, int sizeJugadores, int* contadorConfederaciones, int* contadorJugadores, int indice){
	float porcentaje;
	int contadorJugadoresConfed;

	if(confederaciones != NULL && sizeConfed > 0 && jugadores != NULL && sizeJugadores > 0){
		if(confederaciones[indice].isEmpty == CARGADO ){
			for(int j = 0; jugadores[j].isEmpty == LIBRE || j<sizeJugadores; j++){
				if(jugadores[j].idConfederacion == confederaciones[indice].id && jugadores[j].isEmpty == CARGADO){
					contadorJugadoresConfed = ContarJugadoresConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, indice);
					porcentaje = (float)(contadorJugadoresConfed*100/ *contadorJugadores);
				}
			}
		}
	}

	return porcentaje;
}

void InformarOpciones(eJugador jugadores[], eConfederacion confederaciones[], int sizeJugadores, int sizeConfed, int* contadorJugadores, int* contadorConfederaciones){
	char seguir;
	int opcionInforme;

	if(jugadores != NULL && sizeJugadores > 0 && confederaciones != NULL && sizeConfed >0){
		 if(ValidarConfederacionCargada(confederaciones, contadorConfederaciones, sizeConfed)==1){
			 if(ValidarJugadorCargado(jugadores, contadorJugadores, sizeJugadores, confederaciones, sizeConfed)==1){
				do {
					MostrarMenuInformes();
					if(utn_getNumero(&opcionInforme, "\nOpcion:", "\nError de opcion [1-6]", 1, 7, 1)==0){
						switch(opcionInforme){
							case 1:
								if(OrdenarJugadoresPorConfedYNombre(jugadores, confederaciones, sizeJugadores, sizeConfed, contadorJugadores, contadorConfederaciones)==1){
									MostrarDetallesJugadores(jugadores, confederaciones, sizeJugadores, sizeConfed, contadorJugadores);
								}
								break;
							case 2:
								MostrarConfederacionesConJugadores(confederaciones, jugadores, sizeConfed, sizeJugadores);
								break;
							case 3:
								CalcularInformeSalarios(jugadores, sizeJugadores, contadorJugadores, confederaciones, sizeConfed);
								break;
							case 4:
								informarConfederacionMasAnios(confederaciones, jugadores, sizeConfed, sizeJugadores, contadorConfederaciones);
								break;
							case 5://Informar porcentaje de jugadores por cada confederación.
								InformarPorcentajeJugadoresPorConfed(confederaciones, jugadores, sizeConfed, sizeJugadores, contadorConfederaciones, contadorJugadores);
								break;
							case 6://Informar cual es la región con más jugadores y el listado de los mismos.
								MostrarConfederacionesConMasJugadores(confederaciones, jugadores, sizeConfed, sizeJugadores, contadorConfederaciones, contadorJugadores);
								break;
							default:
								printf("\nError");
								break;
						}
					}
					seguir = ValidarSeguirNoSeguir("\nMostrar otro informe? [S|N]", "\nError..");
				}while(seguir == 'S');
			 }else{
				 printf("\nFalta cargar un jugador");
			 }
		 }else{
			 printf("\nFalta cargar una confederacion");
		 }
	}
}
