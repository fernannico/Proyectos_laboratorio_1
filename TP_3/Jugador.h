
#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#include "LinkedList.h"
#include "Controller.h"

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

/// @brief constructor de jugadores
/// @return retorna un puntero en memoria dinamica del tipo de variable jugador
Jugador* jug_new();

/// @brief constructor de jugador para asignarle valor a sus campos
/// @param idStr string de caracteres para el id
/// @param nombreCompletoStr string de caracteres para el nombre
/// @param edadStr string de caracteres  para la edad
/// @param posicionStr string de caracteres para la posicion
/// @param nacionalidadStr string de caracteres para nacionalidad
/// @param idSeleccionStr string de caracteres para el id de seleccion
/// @return puntero al jugador con los datos cargados en sus campos
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);

/// @brief borra un jugador de memoria dinamica
/// @param this el puntero al jugador a borrar
void jug_delete(Jugador* this);

/// @brief setter para asignarle un id al jugador
/// @param this el puntero al jugador
/// @param id id a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int jug_setId(Jugador* this,int id);

/// @brief getter para obtener el id de un jugador
/// @param this el puntero al jugador
/// @param id puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int jug_getId(Jugador* this,int* id);

/// @brief setter para asignarle un nombre al jugador
/// @param this el puntero al jugador
/// @param nombre a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int jug_setNombreCompleto(Jugador* this,char* nombre);

/// @brief getter para obtener el nombre de un jugador
/// @param this el puntero al jugador
/// @param nombreCompleto puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

/// @brief setter para asignarle una posicion al jugador
/// @param this el puntero al jugador
/// @param posicion a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int jug_setPosicion(Jugador* this,char* posicion);

/// @brief getter para obtener la posicion de un jugador
/// @param this el puntero al jugador
/// @param posicion puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int jug_getPosicion(Jugador* this,char* posicion);

/// @brief setter para asignarle una nacionalidad al jugador
/// @param this el puntero al jugador
/// @param nacionalidad a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int jug_setNacionalidad(Jugador* this,char* nacionalidad);

/// @brief getter para obtener la nacionalidad de un jugador
/// @param this el puntero al jugador
/// @param nacionalidad puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/// @brief setter para asignarle una edad al jugador
/// @param this el puntero al jugador
/// @param edad a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int jug_setEdad(Jugador* this,int edad);

/// @brief getter para obtener la edad de un jugador
/// @param this el puntero al jugador
/// @param edad puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int jug_getEdad(Jugador* this,int* edad);

/// @brief setter para asignarle un id seleccion al jugador
/// @param this el puntero al jugador
/// @param idSeleccion a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/// @brief getter para obtener el id seleccion de un jugador
/// @param this el puntero al jugador
/// @param idSeleccion puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

///----------------------
/// propias

/// @brief para obtener los valores asignados a los campos de un jugador
/// @param unJugador el puntero al jugador que quiero sus datos
/// @param id puntero a la variable donde se guardara el valor
/// @param nombreCompleto puntero a la variable donde se guardara el valor
/// @param edad puntero a la variable donde se guardara el valor
/// @param posicion puntero a la variable donde se guardara el valor
/// @param nacionalidad puntero a la variable donde se guardara el valor
/// @param idSeleccion puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener los valores y 1 si pudo
int jug_getOnePlayer(Jugador* unJugador, int* id, char* nombreCompleto, int* edad, char* posicion, char* nacionalidad, int* idSeleccion);

/// @brief para asignar valores a los campos del jugador a travez de parametros
/// @param unJugador el puntero al jugador
/// @param id
/// @param nombreCompleto
/// @param edad
/// @param posicion
/// @param nacionalidad
/// @param idSeleccion
/// @return retorna -1 si no pudo settear los valores y 1 si pudo
int jug_setOnePlayer(Jugador* unJugador, int id, char* nombreCompleto, int edad, char* posicion, char* nacionalidad, int idSeleccion);

/// @brief para mostrar los datos de un jugador
/// @param unJugador el puntero al jugador
/// @return retorna -1 si no pudo mostrar al jugador y 1 si pudo
int jug_printOnePlayer(Jugador* unJugador);

/// @brief para modificar el nombre del jugador
/// @param this el puntero al jugador
/// @return retorna -1 si no pudo modificar el dato y 1 si pudo
int jug_modificarNombre(Jugador* this);

/// @brief para modificar la edad del jugador
/// @param this el puntero al jugador
/// @return retorna -1 si no pudo modificar el dato y 1 si pudo
int jug_modificarEdad(Jugador* this);

/// @brief para modificar la nacionalidad del jugador
/// @param this el puntero al jugador
/// @return retorna -1 si no pudo modificar el dato y 1 si pudo
int jug_modificarNacionalidad(Jugador* this);

/// @brief para modificar la posicion  del jugador
/// @param this el puntero al jugador
/// @return retorna -1 si no pudo modificar el dato y 1 si pudo
int jug_modificarPosicion(Jugador* this);

/// @brief compara dos jugadores por nombre retornando el ordenamiento
/// @param unJugador
/// @param otroJugador
/// @return retorna el int de la comparacion de la funcion stricmp
int jug_CompareByName(void* unJugador,void* otroJugador);

/// @brief compara dos jugadores por nombre de la nacionalidad retornando el  ordenamiento
/// @param unJugador
/// @param otroJugador
/// @return retorna el int de la comparacion de la funcion stricmp
int jug_CompareByNationality(void* unJugador,void* otroJugador);

/// @brief compara dos jugadores por la edad retornando el ordenamiento
/// @param unJugador
/// @param otroJugador
/// @return retorna 0 si tienen la misma edad, -1 si unJugador es mas joven y 1 si unJugador es mas viejo
int jug_CompareByAge(void* unJugador,void* otroJugador);

/// @brief para recibir el indice en que se encuentra el jugador a traves del id
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @param id id del jugador del que quiero saber el indice
/// @return retorna -1 si el puntero a la lista de jugadores es NULL, si falla el retorno de la longitud del array
/// 				 int del el indice donde se encuentra el jugador
int jug_BuscarIndiceJugadorPorId(LinkedList* pArrayListJugador, int id);

/// @brief para obtener el maximo id disponible desde un archivo de texto
/// @param path cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @return retorna -1 si no puede abrir el archivo solicitado
/// 				int del id maximo
int jug_AsignarIdDesdeTexto(char* path);

/// @brief para ir guardando en el archivo el ultimo id disponible
/// @param id
void jug_actualizarIdModoTexto(int id);

/// @brief para mostrar la cabecera de la lista de jugadores
void mostrarCabeceraJugadores(void);

#endif // jug_H_INCLUDED
