/*
 * output.h
 *
 *  Created on: 17 sep. 2022
 *      Author: User
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_
#include <stdio.h>
#include <stdlib.h>



void ImprimirMenu(int costosHospedaje, int costosComida, int costosTransporte, int contadorArqueros, int contadorDefensores, int contadorMediocampistas, int contadorDelanteros);
void ImprimirSubmenuMantenimiento(int costosHospedaje, int costosComida, int costosTransporte);
void ImprimirCantidadJugadores(int contadorArqueros, int contadorDefensores, int contadorMediocampistas, int contadorDelanteros);

void ImprimirSubmenuConfederaciones(int uefa, int conmebol, int concacaf, int afc, int ofc, int caf);

void ImprimirResultados(float promedioUefa, float promedioConmebol, float promedioConcacaf, float promedioAfc, float promedioOfc, float promedioCaf);
#endif /* OUTPUT_H_ */
