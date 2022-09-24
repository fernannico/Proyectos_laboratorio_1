/*
 Alumno: Nicolas Ivan Fernandez
 Division: K
*/

#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include "input.h"
#include "operaciones.h"

#define TAM 22

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
	int contadorJugadores;
	int acumuladorUefa;
	int acumuladorConmebol;
	int acumuladorConcacaf;
	int acumuladorAfc;
	int acumuladorOfc;
	int acumuladorCaf;
	float promedioUefa;
	float promedioConmebol;
	float promedioConcacaf;
	float promedioAfc;
	float promedioOfc;
	float promedioCaf;
	int banderaOpcion1;
	int banderaOpcion2;
	int banderaOpcion3;

	acumuladorCostoHospedaje = 0;				///cambiar a 0
	acumuladorCostoComida = 0;					///cambiar a 0
	acumuladorCostoTransporte = 0;
	contadorArqueros = 0;
	contadorDefensores = 0;
	contadorMediocampistas = 0;
	contadorDelanteros = 0;
	contadorJugadores = 0;
	acumuladorUefa = 0;
	acumuladorConmebol = 0;
	acumuladorConcacaf = 0;
	acumuladorAfc = 0;
	acumuladorOfc = 0;
	acumuladorCaf = 0;
	banderaOpcion1 = 0;
	banderaOpcion2 = 0;
	banderaOpcion3 = 0;

	do {
		ImprimirMenu(acumuladorCostoHospedaje, acumuladorCostoComida, acumuladorCostoTransporte, contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);
		opcion = IngresarEnteroValidado("\nopcion:", "\nIngresar una opcion entre 1 - 5", 1, 5);
		//fflush(stdin);
		switch (opcion) {
			case 1:
				do{
					ImprimirSubmenuMantenimiento(acumuladorCostoHospedaje, acumuladorCostoComida, acumuladorCostoTransporte);
					subopcion = IngresarEnteroValidado("\nelegir qué gasto desea ingresar [1 - 2 - 3]", "\nerror de opcion [1-2-3]", 1, 3);
					switch (subopcion) {
						case 1:
							costoHospedaje = IngresarFloatValidado("\ningresar costo de hospedaje: ", "\nNo ingreso un valor valido", 1, 99999999);
							acumuladorCostoHospedaje += costoHospedaje;
							break;
						case 2:
							costoComida = IngresarFloatValidado("\ningresar costo de comida: ", "\nNo ingreso un valor valido", 1, 99999999);
							acumuladorCostoComida += costoComida;
							break;
						case 3:
							costoTransporte = IngresarFloatValidado("\ningresar costo de transporte: ", "\nNo ingreso un valor valido", 1, 99999999);
							acumuladorCostoTransporte += costoTransporte;
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
				if(contadorJugadores < TAM){
					do{
						ImprimirCantidadJugadores(contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);
						subopcion = IngresarEnteroValidado("\nIngrese un jugador segun la posicion [1-2-3-4]", "\Error de opcion, reintente [1-2-3-4]", 1, 4);

						switch (subopcion){
							case 1:
								//preguntar si esta seguro de los datos ingresados, sino reintentar
								if(contadorArqueros < 2){
									numeroCamiseta = IngresarEnteroValidado("\nIngresar número de camiseta de 1 a 99: ", "Error,  ingresar una camiseta valida de 1 a 99", 1, 99);
									printf("Se ingreso la camiseta numero %d\n", numeroCamiseta);

									ImprimirSubmenuConfederaciones(acumuladorUefa, acumuladorConmebol, acumuladorConcacaf, acumuladorAfc, acumuladorOfc, acumuladorCaf);

									subopcionConfederacion = IngresarEnteroValidado("\nIngrese la confederacion del jugador [1-2-3-4-5-6]", "\Error de opcion, reintente [1-2-3-4-5-6]", UEFA, CAF);
									if(ContarConfederaciones(subopcionConfederacion, &acumuladorUefa, &acumuladorConmebol, &acumuladorConcacaf, &acumuladorAfc, &acumuladorOfc, &acumuladorCaf)){
										printf("\nSe ingreso correctamente al jugador");
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

									ImprimirSubmenuConfederaciones(acumuladorUefa, acumuladorConmebol, acumuladorConcacaf, acumuladorAfc, acumuladorOfc, acumuladorCaf);

									subopcionConfederacion = IngresarEnteroValidado("\nIngrese la confederacion del jugador [1-2-3-4-5-6]", "\Error de opcion, reintente [1-2-3-4-5-6]", UEFA, CAF);
									if(ContarConfederaciones(subopcionConfederacion, &acumuladorUefa, &acumuladorConmebol, &acumuladorConcacaf, &acumuladorAfc, &acumuladorOfc, &acumuladorCaf)){
										printf("\nSe ingreso correctamente al jugador");
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

									ImprimirSubmenuConfederaciones(acumuladorUefa, acumuladorConmebol, acumuladorConcacaf, acumuladorAfc, acumuladorOfc, acumuladorCaf);

									subopcionConfederacion = IngresarEnteroValidado("\nIngrese la confederacion del jugador [1-2-3-4-5-6]", "\Error de opcion, reintente [1-2-3-4-5-6]", UEFA, CAF);
									if(ContarConfederaciones(subopcionConfederacion, &acumuladorUefa, &acumuladorConmebol, &acumuladorConcacaf, &acumuladorAfc, &acumuladorOfc, &acumuladorCaf)){
										printf("\nSe ingreso correctamente al jugador");
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

									ImprimirSubmenuConfederaciones(acumuladorUefa, acumuladorConmebol, acumuladorConcacaf, acumuladorAfc, acumuladorOfc, acumuladorCaf);

									subopcionConfederacion = IngresarEnteroValidado("\nIngrese la confederacion del jugador [1-2-3-4-5-6]", "\Error de opcion, reintente [1-2-3-4-5-6]", UEFA, CAF);
									if(ContarConfederaciones(subopcionConfederacion, &acumuladorUefa, &acumuladorConmebol, &acumuladorConcacaf, &acumuladorAfc, &acumuladorOfc, &acumuladorCaf)){
										printf("\nSe ingreso correctamente al jugador");
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
						contadorJugadores++;
						banderaOpcion2 = 1;

						seguir = ValidarSeguirNoSeguir("\nIngresar otro jugador? [S|N]", "\nError de opcion");
						if(seguir == 'S' && contadorJugadores > 21){
							printf("\nSe han ingresado todos los jugadores");
						}
					}while(seguir == 'S' && contadorJugadores < TAM);
				}else{
					printf("\nSe han ingresado todos los jugadores");
				}
				break;
			case 3:
				if(ValidarIngresosDeDatos(banderaOpcion1, banderaOpcion2)){
//					a. Calcular el promedio de jugadores de cada mercado.
					promedioUefa = CalcularPromedio(acumuladorUefa, contadorJugadores);
					promedioConmebol = CalcularPromedio(acumuladorConmebol, contadorJugadores);
					promedioConcacaf = CalcularPromedio(acumuladorConcacaf, contadorJugadores);
					promedioAfc = CalcularPromedio(acumuladorAfc, contadorJugadores);
					promedioOfc = CalcularPromedio(acumuladorOfc, contadorJugadores);
					promedioCaf = CalcularPromedio(acumuladorCaf, contadorJugadores);

//					b. Calcular el costo de mantenimiento.
					costoMantenimiento = CalcularSuma(acumuladorCostoHospedaje, acumuladorCostoComida);
					costoMantenimiento = CalcularSuma(costoMantenimiento, acumuladorCostoTransporte);

//					c. Si la mayoría del plantel está compuesta por jugadores de la confederación europea el costo de mantenimiento recibe un aumento del 35%.
					if(promedioUefa > 0.5){
						montoAumentadoAlMantenimiento = CalcularPorcentaje(costoMantenimiento, 35);
						costoMantenimientoAumentado = CalcularSuma(costoMantenimiento, montoAumentadoAlMantenimiento);
					}else{
						costoMantenimientoAumentado = costoMantenimiento;
					}

					printf( "\n\t-------------------------------------"
							"\n\tSe han realizado los calculos!"
							"\n\t-------------------------------------");
					banderaOpcion3 = 1;
				}
				break;
			case 4:
				if(ValidarIngresosDeDatos(banderaOpcion1, banderaOpcion2) == 0 || banderaOpcion3 == 0){
					printf("\nno se han realizado los calculos");
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










