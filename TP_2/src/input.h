/*
 * input.h
 *
 *  Created on: 18 oct. 2022
 *      Author: User
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/// @brief verifica si la cadena ingresada es numerica
/// @param cadena Cadena de caracteres a ser analizada
/// @param limite el tamanio de la cadena
/// @return retorna -1 si hubo un error, retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
int esNumerica(char * cadena, int limite);

/// @brief Verifica si la cadena ingresada es numerica
/// @param pResultado Puntero al espacio de memoria donde se dejara por referencia el resultado de la funcion
/// @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
int getInt(int * pResultado);

/// @brief Lee de stdin hasta que encuentra un \ n o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
/// @param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
/// @param longitud el tamanio de la cadena
/// @return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
int myGets(char * cadena, int longitud);

/// @brief pide un numero entero al usuario y asigna por referencia tras hacer las verificaciones
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje mensaje que aparecera en consola para pedir el numero
/// @param mensajeError mensaje que aparece si hubo un error
/// @param minimo el minimo numero permitido
/// @param maximo el maximo numero permitido
/// @param reintentos cantidad de reintentos para ingresar el numero
/// @return Retorna 0 (EXITO) si se cumplieron las validaciones y asigno el numero y -1 (ERROR) si no
int utn_getNumero(int * pResultado, char* mensaje, char * mensajeError, int minimo, int maximo, int reintentos);

int getShort(short* pResultado);

int utn_getShort(short* pResultado, char* mensaje, char * mensajeError, short minimo, short maximo, short reintentos);

/// @brief verifica si la cadena ingresada es flotante
/// @param cadena Cadena de caracteres a ser analizada
/// @return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
int esFlotante(char* cadena);

/// @brief Verifica si la cadena ingresada es flotante
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
int getFloat(float* pResultado);

/// @brief pide un numero flotante al usuario y asigna por referencia tras hacer las verificaciones
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje mensaje que aparecera en consola para pedir el flotante
/// @param mensajeError mensaje que aparece si hubo un error
/// @param minimo el minimo flotante permitido
/// @param maximo el maximo flotante permitido
/// @param reintentos cantidad de reintentos para ingresar el numero
/// @return Retorna 0 (EXITO) si se cumplieron las validaciones y asigno el numero y -1 (ERROR) si no
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/// @brief Verifica si la cadena ingresada son solo letras
/// @param cadena Cadena de caracteres a ser analizada
/// @return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
int esSoloLetras(char cadena[],int longitud);

/// @brief Obtiene un string valido como nombre
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
int getNombre(char* pResultado, int longitud);

/// @brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param longitud Es la longitud del array resultado
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param reintentos Cantidad de reintentos
/// @return Retorna 0 si se obtuvo el numero flotante y -1 si no
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

void ModularNombre(char nombre[]);

/// @brief para validar si el usuario quiere seguir o no segun aprete 's' o 'n', sea minuscula o mayuscula
/// @param mensaje mensaje para preguntar al usuario si quiere seguir
/// @param mensajeError mensaje mensaje para avisar al usuario que apreto un char diferente a 's' o 'n'
/// @return retorna 'S' si quiere seguir o 'N' si no quiere seguir
char ValidarSeguirNoSeguir(char * mensaje, char * mensajeError);

float CalcularPromedio(float acumulador, int contador);

#endif /* INPUT_H_ */
