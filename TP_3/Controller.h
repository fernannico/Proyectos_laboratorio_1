#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "input.h"

/// @brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
/// @param path char*
/// @param pArrayListJugador LinkedList*
/// @return int
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

/// @brief Carga los datos de los jugadores desde el archivo generado en modo binario.
/// @param path char*
/// @param pArrayListJugador LinkedList*
/// @return int
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/// @brief Alta de jugadores
/// @param pArrayListJugador LinkedList*
/// @return int
int controller_agregarJugador(LinkedList* pArrayListJugador);

/// @brief Modificar datos del jugador
/// @param pArrayListJugador
/// @return
int controller_editarJugador(LinkedList* pArrayListJugador);

/// @brief Baja del jugador
/// @param pArrayListJugador
/// @return
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Listar jugadores
/// @param pArrayListJugador
/// @return
int controller_listarJugadores(LinkedList* pArrayListJugador);

/// @brief Ordenar jugadores
/// @param pArrayListJugador
/// @return
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/// @brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
/// @param path
/// @param pArrayListJugador
/// @return
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/// @brief Guarda los datos de los jugadores en el archivo binario.
/// @param path
/// @param pArrayListJugador
/// @return
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/// @brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
/// @param path
/// @param pArrayListSeleccion
/// @return
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/// @brief Modificar datos de seleccion
/// @param pArrayListSeleccion
/// @return
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/// @brief Listar selecciones
/// @param pArrayListSeleccion
/// @return
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/// @brief Ordenar selecciones
/// @param pArrayListSeleccion
/// @return
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/// @brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
/// @param path
/// @param pArrayListSeleccion
/// @return
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

///--------------------------------------------------------------
/// propias

int controller_ordenarJugadoresYSelecciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int controller_Convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSelecc);

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador);

int controller_desconvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int controller_CargarArchivoBinario(char* pathJugadores, char* pathSelecciones);

//int controller_listarJugadoresConSeleccion(LinkedList* pArrayListJugador/*, LinkedList* pArrayListSeleccion*/);
