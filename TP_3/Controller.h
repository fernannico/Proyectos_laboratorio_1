#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "input.h"

/// @brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
/// @param path char* cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL o si no puede abrir el archivo solicitado
/// 					 1 si pudo cargar los jugadores
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

/// @brief Carga los datos de los jugadores desde el archivo generado en modo binario.
/// @param path char* cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL o si no puede abrir el archivo solicitado
/// 					 1 si pudo cargar los jugadores
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/// @brief Alta de jugadores
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL, si no pudo abrir el archivo del id, o si no se ingresaron datos correctos en el alta
/// 					 1 si pudo agregar al jugador
int controller_agregarJugador(LinkedList* pArrayListJugador);

/// @brief Modificar datos del jugador
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL, si no se pudo abrir el archivo de id's o si se ingreso un dato invalido
/// 					 1 si se pudo editar al jugador
int controller_editarJugador(LinkedList* pArrayListJugador);

/// @brief Baja del jugador
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @param pArrayListSeleccion  LinkedList* Puntero a la lista de selecciones
/// @return int retorna -1 si el puntero a la lista de jugadores o selecciones es NULL, si no se pudo abrir el archivo de id's o si se ingreso un dato invalido
/// 					 1 si se pudo remover al jugador
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Listar jugadores
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores o selecciones es NULL o si falla el retorno de la longitud del array
/// 					 1 si pudo listar a los jugadores
int controller_listarJugadores(LinkedList* pArrayListJugador);

/// @brief Ordenar jugadores
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores o selecciones es NULL o si se ingreso un dato invalido
/// 					 1 si se pudo ordenar y listar a los jugadores
/// 					 2 si se decidio por no ordenar jugadores
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/// @brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
/// @param path cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL, si no se pudo abrir el archivo en modo escritura (error de fopen) o si falla el retorno de la longitud del array
/// 					 1 si pudo guardar los jugadores en el archivo csv
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/// @brief Guarda los datos de los jugadores en el archivo binario.
/// @param path cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL, si la funcion fopen devuelve error, si falla el retorno de la longitud del array o si se ingreso una opcion invalida
/// 					 1 si se pudo guardar a los jugadores en el archivo binario
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/// @brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
/// @param path cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayListSeleccion LinkedList* Puntero a la lista de selecciones
/// @return int retorna -1 si el puntero a la lista de selecciones es NULL, si no se pudo abrir el archivo en modo lectura (error de fopen), si falla el retorno de la longitud del array
/// 					 1 si pudo cargar las selecciones desde texto
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/// @brief Modificar datos de seleccion
/// @param pArrayListSeleccion LinkedList* Puntero a la lista  de selecciones
/// @return
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/// @brief Listar selecciones
/// @param pArrayListSeleccion LinkedList* Puntero a la lista  de selecciones
/// @return int retorna -1 si el puntero a la lista de selecciones es NULL o si falla el retorno de la longitud del array
/// 					 1 si pudo listar las selecciones
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/// @brief Ordenar selecciones
/// @param pArrayListSeleccion LinkedList* Puntero a la lista de selecciones
/// @return int retorna -1 si el puntero a la lista de selecciones es NULL, si falla el retorno de la longitud del array o ingreso un dato invalido
/// 					 1 si pudo ordenar y listar las selecciones
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/// @brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
/// @param path cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayListSeleccion LinkedList* Puntero a la lista de selecciones
/// @return int retorna -1 si el puntero a la lista de selecciones es NULL, si no se pudo abrir el archivo en modo escritura (error de fopen) o si falla el retorno de la longitud del array
/// 					 1 si pudo guarda los datos de los selecciones en el archivo
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

///--------------------------------------------------------------
/// propias

/// @brief controller para la opcion de ordenar y listar los jugadores o selecciones segun un criterio ascendente/descendente
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @param pArrayListSeleccion LinkedList* Puntero a la lista de selecciones
/// @return int retorna -1 si el puntero a la lista de selecciones-jugadores es NULL o si se ingreso una dato invalido
/// 					 1 si pudo ordenar y listar los jugadores o selecciones
int controller_ordenarJugadoresYSelecciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief para convocar jugadores a una seleccion
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @param pArrayListSelecc LinkedList* Puntero a la lista de selecciones
/// @return int retorna -1 si el puntero a la lista de jugadores o selecciones es NULL, si no se pudo abrir el archivo de id's o si se ingreso un dato invalido
/// 					 1 si se pudo convocar a un jugador en una seleccion
int controller_Convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief para listar unicamente a los jugadores convocados a una seleccion
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL, si falla el retorno de la longitud del array
/// 					 1 si pudo listar a los jugadores convocados
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador);

/// @brief  para desconvocar jugadores de una seleccion
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @param pArrayListSeleccion LinkedList* Puntero a la lista  de selecciones
/// @return int retorna -1 si el puntero a la lista de jugadores o selecciones es NULL, si el usuario se arrepintio de desconvocar
/// 					 1 si logro desconvocar al jugador de una seleccion
int controller_desconvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief controller para la opcion de convocar - desconvocar jugadores
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @param pArrayListSeleccion LinkedList* Puntero a la lista  de selecciones
/// @return retorna -1 si no pudo convocar o desconvocar
/// 				 1 si pudo
int controller_convocarDesconvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Carga los datos de los jugadores desde el archivo generado en modo binario.
/// @param pathJugadores cadena de caracteres que representa el archivo de jugadores (ruta y el nombre del archivo)
/// @param pathSelecciones cadena de caracteres que representa el archivo de selecciones (ruta y el nombre del archivo)
/// @return int retorna -1 si no se pudo abrir los archivos (error de fopen)
/// 					 1 si pudo carga los jugadores desde el archivo binario
int controller_CargarArchivoBinario(char* pathJugadores, char* pathSelecciones);

//int controller_listarJugadoresConSeleccion(LinkedList* pArrayListJugador/*, LinkedList* pArrayListSeleccion*/);
