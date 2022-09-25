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
	char seguir;
	float costoHospedaje;
	float costoComida;
	float costoTransporte;
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
	float costoMantenimiento;
	float montoAumentadoAlMantenimiento;
	float costoMantenimientoAumentado;
	int banderaOpcionUno;
	int banderaOpcionDos;
	int banderaOpcionTres;

	costoHospedaje = 0;
	costoComida = 0;
	costoTransporte = 0;
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
	banderaOpcionUno = 0;
	banderaOpcionDos = 0;
	banderaOpcionTres = 0;

	do {
		ImprimirMenu(costoHospedaje, costoComida, costoTransporte, contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);
		if(utn_getNumero(&opcion, "\nIngresar una opcion del menu [1 a 5]", "\nError de opcion", 1, 5, 1) ==0){
			switch (opcion) {
				case 1:
					do{
						ImprimirSubmenuMantenimiento(costoHospedaje, costoComida, costoTransporte);
						if(utn_getNumero(&subopcion, "\nelegir qué gasto desea ingresar [1 - 2 - 3]", "\nError de opcion", 1, 3, 1) ==0)
						{
							switch (subopcion) {
								case 1:
									if(utn_getNumeroFlotante(&costoHospedaje, "\ningresar costo de hospedaje: ", "\nNo ingreso un valor valido", 1, 99999999, 1)== 0){
										printf("\nMonto cargado correctamente");
									}
									break;
								case 2:
									if(utn_getNumeroFlotante(&costoComida, "\ningresar costo de comida: ", "\nNo ingreso un valor valido", 1, 99999999, 1)== 0){
										printf("\nMonto cargado correctamente");
									}
									break;
								case 3:
									if(utn_getNumeroFlotante(&costoTransporte, "\ningresar costo de transporte: ", "\nNo ingreso un valor valido", 1, 99999999, 1)== 0){
										printf("\nMonto cargado correctamente");
									}
									break;
								default:
									printf("\nerror de opcion");
									break;
							}
							if(costoHospedaje > 0 && costoComida > 0 && costoTransporte > 0){
								banderaOpcionUno = 1;
							}
						}
						seguir = ValidarSeguirNoSeguir("\ningresar otro costo de mantenimiento? [S|N]", "\nerror de opcion");
					}while(seguir == 'S');

					break;
				case 2:
					if(contadorJugadores < TAM){
						do{
							ImprimirCantidadJugadores(contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);
							if(utn_getNumero(&subopcion,"\nIngrese un jugador segun la posicion [1-2-3-4]", "\Error de opcion, reintente [1-2-3-4]", 1, 4, 1)==0)
							{
								switch (subopcion){
									case 1:
										if(contadorArqueros < 2)
										{
											CargarUnJugador(&numeroCamiseta, &acumuladorUefa, &acumuladorConmebol, &acumuladorConcacaf, &acumuladorAfc, &acumuladorOfc, &acumuladorCaf);
											contadorArqueros++;
										}else{
											printf("\nYa se ingresaron todos los jugadores para esta posicion");
										}
										break;
									case 2:
										if(contadorDefensores < 8)
										{
											CargarUnJugador(&numeroCamiseta, &acumuladorUefa, &acumuladorConmebol, &acumuladorConcacaf, &acumuladorAfc, &acumuladorOfc, &acumuladorCaf);
											contadorDefensores++;
										}else{
											printf("\nYa se ingresaron todos los jugadores para esta posicion");
										}
										break;
									case 3:
										if(contadorMediocampistas < 8)
										{
											CargarUnJugador(&numeroCamiseta, &acumuladorUefa, &acumuladorConmebol, &acumuladorConcacaf, &acumuladorAfc, &acumuladorOfc, &acumuladorCaf);
											contadorMediocampistas++;
										}else{
											printf("\nYa se ingresaron todos los jugadores para esta posicion");
										}
										break;
									case 4:
										if(contadorDelanteros < 4)
										{
											CargarUnJugador(&numeroCamiseta, &acumuladorUefa, &acumuladorConmebol, &acumuladorConcacaf, &acumuladorAfc, &acumuladorOfc, &acumuladorCaf);
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
								banderaOpcionDos = 1;
							}
							seguir = ValidarSeguirNoSeguir("\nIngresar otro jugador? [S|N]", "\nError de opcion");
							if(seguir == 'S' && contadorJugadores > 21){
								printf("\nSe han ingresado todos los jugadores");
							}
						}while(seguir == 'S' && contadorJugadores < TAM);
					}
					break;
				case 3:
					if(ValidarIngresosDeDatos(banderaOpcionUno, banderaOpcionDos)){
	//					a. Calcular el promedio de jugadores de cada mercado.
						promedioUefa = CalcularPromedio(acumuladorUefa, contadorJugadores);
						promedioConmebol = CalcularPromedio(acumuladorConmebol, contadorJugadores);
						promedioConcacaf = CalcularPromedio(acumuladorConcacaf, contadorJugadores);
						promedioAfc = CalcularPromedio(acumuladorAfc, contadorJugadores);
						promedioOfc = CalcularPromedio(acumuladorOfc, contadorJugadores);
						promedioCaf = CalcularPromedio(acumuladorCaf, contadorJugadores);

	//					b. Calcular el costo de mantenimiento.
						costoMantenimiento = CalcularSuma(costoHospedaje, costoComida);
						costoMantenimiento = CalcularSuma(costoMantenimiento, costoTransporte);

	//					c. Si la mayoría del plantel está compuesta por jugadores de la confederación europea el costo de mantenimiento recibe un aumento del 35%.
						if(acumuladorUefa > acumuladorConmebol && acumuladorUefa > acumuladorConcacaf && acumuladorUefa > acumuladorAfc && acumuladorUefa > acumuladorOfc && acumuladorUefa > acumuladorCaf){
							montoAumentadoAlMantenimiento = CalcularPorcentaje(costoMantenimiento, 35);
							costoMantenimientoAumentado = CalcularSuma(costoMantenimiento, montoAumentadoAlMantenimiento);
						}else{
							costoMantenimientoAumentado = costoMantenimiento;
						}

						printf( "\n\t-------------------------------------"
								"\n\tSe han realizado los calculos!"
								"\n\t-------------------------------------");
						banderaOpcionTres = 1;
					}
					break;
				case 4:
					if(ValidarIngresosDeDatos(banderaOpcionUno, banderaOpcionDos) == 0 || banderaOpcionTres == 0){
						printf("\nno se han realizado los calculos");
					}else{
						ImprimirResultados(promedioUefa, promedioConmebol, promedioConcacaf, promedioAfc, promedioOfc, promedioCaf);
						if(acumuladorUefa > acumuladorConmebol && acumuladorUefa > acumuladorConcacaf && acumuladorUefa > acumuladorAfc && acumuladorUefa > acumuladorOfc && acumuladorUefa > acumuladorCaf){
							printf( "\nel costo de mantenimiento era de %.2f y recibio un aunento de %.2f"
									"\nsu nuevo valor es de: %.2f\n", costoMantenimiento, montoAumentadoAlMantenimiento, costoMantenimientoAumentado);
						}else{
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
		}
	} while (opcion != 5);

	return EXIT_SUCCESS;
}



