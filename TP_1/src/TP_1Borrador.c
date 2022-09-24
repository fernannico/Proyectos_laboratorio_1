/*
 ============================================================================

Dicho plantel contara con un costo de mantenimiento, que va a estar compuesto por:
Gastos de Transporte, Hospedaje y Comida. El usuario deberá cargar todos los gastos.

 ============================================================================
 */

/**
 * biblioteca para logica y otra para pedido de datos (input)
 * test commit
 * */

#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include "input.h"

#define TAM 22
#define UEFA 1
#define CONMEBOL 2
#define CONCACAF 3
#define AFC 4
#define OFC 5
#define CAF 6

float CalcularPromedio(int numerador, int divisor);

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int subopcion;
	int subopcionConfederacion;
	char seguir;
	float costoHospedaje;
	float costoComida;
	float costoTransporte;
	float acumuladorCostoHospedaje;
	float acumuladorCostoComida;
	float acumuladorCostoTransporte;
	float costoMantenimiento;
	float montoAumentadoAlMantenimiento;
	float costoMantenimientoAumentado;
	int numeroCamiseta;
	int contadorArqueros;
	int contadorDefensores;
	int contadorMediocampistas;
	int contadorDelanteros;
	int cantidadJugadores;
	int contadorUefa;
	int contadorConmebol;
	int contadorConcacaf;
	int contadorAfc;
	int contadorOfc;
	int contadorCaf;
	float promedioUefa;
	float promedioConmebol;
	float promedioConcacaf;
	float promedioAfc;
	float promedioOfc;
	float promedioCaf;
	int banderaOpcion1;
	int banderaOpcion2;
	int banderaOpcion3;

	acumuladorCostoHospedaje = 0;
	acumuladorCostoComida = 0;
	acumuladorCostoTransporte = 0;
	contadorArqueros = 0;
	contadorDefensores = 0;
	contadorMediocampistas = 0;
	contadorDelanteros = 0;
	cantidadJugadores = 0;
	contadorUefa = 0;
	contadorConmebol = 0;
	contadorConcacaf = 0;
	contadorAfc = 0;
	contadorOfc = 0;
	contadorCaf = 0;
	banderaOpcion1 = 0;
	banderaOpcion2 = 0;
	banderaOpcion3 = 0;

	do {
		ImprimirMenu(acumuladorCostoHospedaje, acumuladorCostoComida, acumuladorCostoTransporte, contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);
		opcion = IngresarEnteroValidado("\nopcion:", "\nIngresar una opcion entre 1 - 5", 1, 5);
		switch (opcion) {
			case 1:
				do{
					ImprimirSubmenuMantenimiento(acumuladorCostoHospedaje, acumuladorCostoComida, acumuladorCostoTransporte);
					subopcion = IngresarEnteroValidado("\nelegir qué gasto desea ingresar [1 - 2 - 3]", "\nerror de opcion [1-2-3]", 1, 3);
					switch (subopcion) {
						case 1:
							costoHospedaje = IngresarFloatValidado("\ningresar costo de hospedaje: ", "\nNo ingreso un valor valido", 1, 99999999);
							acumuladorCostoHospedaje += costoHospedaje;
							printf("Costo hospédaje %.2f\n", acumuladorCostoHospedaje);
							break;
						case 2:
							costoComida = IngresarFloatValidado("\ningresar costo de comida: ", "\nNo ingreso un valor valido", 1, 99999999);
							acumuladorCostoComida += costoComida;
							printf("Costo comida %.2f\n", acumuladorCostoComida);
							break;
						case 3:
							costoTransporte = IngresarFloatValidado("\ningresar costo de transporte: ", "\nNo ingreso un valor valido", 1, 99999999);
							acumuladorCostoTransporte += costoTransporte;
							printf("Costo transporte %.2f\n", acumuladorCostoTransporte);
							break;
						default:
							printf("\nerror de opcion");
							break;
					}
					if(acumuladorCostoComida > 0 && acumuladorCostoHospedaje > 0 && acumuladorCostoTransporte > 0){
						banderaOpcion1 = 1;
					}
					seguir = ValidarSeguirNoSeguir("\ningresar otro costo de mantenimiento? [S|N]", "\nerror de opcion");
				}while(seguir == 'S');

				break;
			case 2:
				if(cantidadJugadores < TAM){
					do{
						ImprimirCantidadJugadores(contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);
						subopcion = IngresarEnteroValidado("\nIngrese un jugador segun la posicion [1-2-3-4]", "\Error de opcion, reintente [1-2-3-4]", 1, 4);

						switch (subopcion){
							case 1:
								//preguntar si esta seguro de los datos ingresados, sino reintentar
								if(contadorArqueros < 2){
									numeroCamiseta = IngresarEnteroValidado("\nIngresar número de camiseta de 1 a 99: ", "Error,  ingresar una camiseta valida de 1 a 99", 1, 99);
									printf("Se ingreso la camiseta numero %d\n", numeroCamiseta);

									ImprimirSubmenuConfederaciones(contadorUefa, contadorConmebol, contadorConcacaf, contadorAfc, contadorOfc, contadorCaf);

									subopcionConfederacion = IngresarEnteroValidado("\nIngrese la confederacion del jugador [1-2-3-4-5-6]", "\Error de opcion, reintente [1-2-3-4-5-6]", UEFA, CAF);
									if(ContarConfederaciones(subopcionConfederacion, &contadorUefa, &contadorConmebol, &contadorConcacaf, &contadorAfc, &contadorOfc, &contadorCaf)){
										printf("\nse ingresaron correctamente los datos");
									}else{
										printf("\nerror");
									}

									contadorArqueros++;
								}else{
									printf("\nYa se ingresaron todos los jugadores para esta posicion");
								}
								break;
							case 2:
								if(contadorDefensores < 8){
									numeroCamiseta = IngresarEnteroValidado("\nIngresar número de camiseta de 1 a 99: ", "Error,  ingresar una camiseta valida de 1 a 99", 1, 99);

									ImprimirSubmenuConfederaciones(contadorUefa, contadorConmebol, contadorConcacaf, contadorAfc, contadorOfc, contadorCaf);

									subopcionConfederacion = IngresarEnteroValidado("\nIngrese la confederacion del jugador [1-2-3-4-5-6]", "\Error de opcion, reintente [1-2-3-4-5-6]", UEFA, CAF);
									if(ContarConfederaciones(subopcionConfederacion, &contadorUefa, &contadorConmebol, &contadorConcacaf, &contadorAfc, &contadorOfc, &contadorCaf)){
										printf("\nse ingresaron correctamente los datos");
									}else{
										printf("\nerror");
									}
									contadorDefensores++;
								}else{
									printf("\nYa se ingresaron todos los jugadores para esta posicion");
								}
								break;
							case 3:
								if(contadorMediocampistas < 8){
									numeroCamiseta = IngresarEnteroValidado("\nIngresar número de camiseta de 1 a 99: ", "Error,  ingresar una camiseta valida de 1 a 99", 1, 99);

									ImprimirSubmenuConfederaciones(contadorUefa, contadorConmebol, contadorConcacaf, contadorAfc, contadorOfc, contadorCaf);

									subopcionConfederacion = IngresarEnteroValidado("\nIngrese la confederacion del jugador [1-2-3-4-5-6]", "\Error de opcion, reintente [1-2-3-4-5-6]", UEFA, CAF);
									if(ContarConfederaciones(subopcionConfederacion, &contadorUefa, &contadorConmebol, &contadorConcacaf, &contadorAfc, &contadorOfc, &contadorCaf)){
										printf("\nse ingresaron correctamente los datos");
									}else{
										printf("\nerror");
									}
									contadorMediocampistas++;
								}else{
									printf("\nYa se ingresaron todos los jugadores para esta posicion");
								}
								break;
							case 4:
								if(contadorDelanteros < 4){
									numeroCamiseta = IngresarEnteroValidado("\nIngresar número de camiseta de 1 a 99: ", "Error,  ingresar una camiseta valida de 1 a 99", 1, 99);

									ImprimirSubmenuConfederaciones(contadorUefa, contadorConmebol, contadorConcacaf, contadorAfc, contadorOfc, contadorCaf);

									subopcionConfederacion = IngresarEnteroValidado("\nIngrese la confederacion del jugador [1-2-3-4-5-6]", "\Error de opcion, reintente [1-2-3-4-5-6]", UEFA, CAF);
									if(ContarConfederaciones(subopcionConfederacion, &contadorUefa, &contadorConmebol, &contadorConcacaf, &contadorAfc, &contadorOfc, &contadorCaf)){
										printf("\nse ingresaron correctamente los datos");
									}else{
										printf("\nerror");
									}
									contadorDelanteros++;
								}else{
									printf("\nYa se ingresaron todos los jugadores para esta posicion");
								}
								break;
							default:
								printf("\nError de opcion, reintente [1-2-3-4]");
								break;
						}
						cantidadJugadores++;
						banderaOpcion2 = 1;
						seguir = ValidarSeguirNoSeguir("\nIngresar otro jugador? [S|N]", "\nError de opcion");
					}while(seguir == 'S');
				}
				break;
			case 3:
				if(banderaOpcion1 == 0 || banderaOpcion2 == 0){
					printf("\nFaltan ingresar valores en la opcion 1 y 2");///hacer que me diga qué falta
				}else{
//					a. Calcular el promedio de jugadores de cada mercado.
					promedioUefa = CalcularPromedio(contadorUefa, cantidadJugadores);
					promedioConmebol = CalcularPromedio(contadorConmebol, cantidadJugadores);
					promedioConcacaf = CalcularPromedio(contadorConcacaf, cantidadJugadores);
					promedioAfc = CalcularPromedio(contadorAfc, cantidadJugadores);
					promedioOfc = CalcularPromedio(contadorOfc, cantidadJugadores);
					promedioCaf = CalcularPromedio(contadorCaf, cantidadJugadores);

//					b. Calcular el costo de mantenimiento.
					costoMantenimiento = acumuladorCostoComida + acumuladorCostoHospedaje + acumuladorCostoTransporte;

//					c. Si la mayoría del plantel está compuesta por jugadores de la confederación europea el costo de mantenimiento recibe un aumento del 35%.
					if(promedioUefa > 0.5){
						montoAumentadoAlMantenimiento = costoMantenimiento * 0.35;
						costoMantenimientoAumentado = costoMantenimiento + montoAumentadoAlMantenimiento;
					}else{
						costoMantenimientoAumentado = costoMantenimiento;
					}

					//					solo informar que se realizaron correctamente los siguientes caculos:
					printf( "\n\t-------------------------------------"
							"\n\tSe han realizado los calculos!"
							"\n\t-------------------------------------");
					banderaOpcion3 = 1;
				}
				break;
			case 4:
				if(banderaOpcion1 == 0 || banderaOpcion2 == 0 || banderaOpcion3 == 0){
					printf("\nFaltan ingresar valores en la opcion 1 y 2 y no se han realizado los calculos");
				}else{
					if(promedioUefa > 0.5){
						ImprimirResultados(promedioUefa, promedioConmebol, promedioConcacaf, promedioAfc, promedioOfc, promedioCaf);
						printf( "\nel costo de mantenimiento era de %.2f y recibio un aunento de %.2f, su nuevo valor es de: %.2f\n", costoMantenimiento, montoAumentadoAlMantenimiento, costoMantenimientoAumentado);
					}else{
						ImprimirResultados(promedioUefa, promedioConmebol, promedioConcacaf, promedioAfc, promedioOfc, promedioCaf);
						printf(	"\nel costo de mantenimiento es de %.2f y no se aplico aumento\n", costoMantenimiento);
					}
				}
				break;
			case 5:
				printf("\nsaliendo del programa");
				break;
			default:
				printf("\nOpcion invalida");
				break;
		}
	} while (opcion != 5);

	return EXIT_SUCCESS;
}

float CalcularPromedio(int numerador, int divisor){
	float promedio;

	promedio = (float)numerador / divisor;

	return promedio;
}




