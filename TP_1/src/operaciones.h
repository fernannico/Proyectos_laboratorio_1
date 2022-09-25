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

/// @brief calcula la suma de dos numeros flotantes
/// @param numeroUno el primer sumando
/// @param numeroDos el segundo sumando
/// @return retorna la suma de ambos sumandos
float CalcularSuma(float numeroUno, float numeroDos);

/// @brief calcula el promedio
/// @param acumulador el numerador, la variable que contiene el grupo de numeros
/// @param contador el divisor, la variable que tiene como valor el recuento de esos numeros
/// @return retorna el promedio del conjunto de valores
float CalcularPromedio(int acumulador, int contador);

/// @brief calcula el porcentaje de aumento o descuento de un monto inicial
/// @param valorInicial el monto sobre el cual se va a calcular el porcentaje
/// @param porcentaje el porcentaje de descuento o aumento a aplicar
/// @return retorna el monto a aumentar o a descontar
float CalcularPorcentaje(float valorInicial, int porcentaje);

/// @brief va contando la cantidad de jugadores en cada confederacion
/// @param opcion el entero que determina a que confederacion se le agregara un jugador
/// @param uefa puntero de referencia a la direccion de memoria de la variable "acumulador de jugadores de la UEFA"
/// @param conmebol puntero de referencia a la direccion de memoria de la variable "acumulador de jugadores de la CONMEBOL"
/// @param concacaf puntero de referencia a la direccion de memoria de la variable "acumulador de jugadores de la CONCACAF"
/// @param afc puntero de referencia a la direccion de memoria de la variable "acumulador de jugadores de la AFC"
/// @param ofc puntero de referencia a la direccion de memoria de la variable "acumulador de jugadores de la OFC"
/// @param caf puntero de referencia a la direccion de memoria de la variable "acumulador de jugadores de la CAF"
/// @return retorna 1 si la carga fue correcta o 0 si no pudo realizar la carga
int ContarConfederaciones(int opcion, int* uefa, int* conmebol, int* concacaf, int* afc, int* ofc, int* caf);


#endif /* OPERACIONES_H_ */
