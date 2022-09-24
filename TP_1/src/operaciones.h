/*
 * operaciones.h
 *
 *  Created on: 23 sep. 2022
 *      Author: User
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include <stdio.h>
#include <stdlib.h>
#define UEFA 1
#define CONMEBOL 2
#define CONCACAF 3
#define AFC 4
#define OFC 5
#define CAF 6

float CalcularSuma(float num1, float num2);
float CaclcularCostoMantenimiento(float costoComida, float costoHospedaje, float costoTransporte);
float CalcularPromedio(int numerador, int divisor);
int ContarConfederaciones(int opcion, int* uefa, int* conmebol, int* concacaf, int* afc, int* ofc, int* caf);

#endif /* OPERACIONES_H_ */
