
#ifndef PARSER_H_
#define PARSER_H_
#include "Controller.h"

/// @brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
/// @param path char*
/// @param pArrayListJugador LinkedList*
/// @return int
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/// @brief Parsea los datos de los jugadores desde el archivo binario.
/// @param pFile
/// @param pArrayListJugador LinkedList*
/// @return int
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/// @brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
/// @param pFile
/// @param pArrayListSeleccion LinkedList*
/// @return int
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);


#endif /* PARSER_H_ */
