#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

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

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

///----------------------
/// propias

int jug_getOnePlayer(Jugador* unJugador, int* id, char* nombreCompleto, int* edad, char* posicion, char* nacionalidad, int* idSeleccion);
int jug_setOnePlayer(Jugador* unJugador, int id, char* nombreCompleto, int edad, char* posicion, char* nacionalidad, int idSeleccion);
int jug_printOnePlayer(Jugador* unJugador);

int jug_modificarNombre(Jugador* this);
int jug_modificarEdad(Jugador* this);
int jug_modificarNacionalidad(Jugador* this);
int jug_modificarPosicion(Jugador* this);

int jug_CompareByName(void* unJugador,void* otroJugador);
int jug_CompareByNationality(void* unJugador,void* otroJugador);
int jug_CompareByAge(void* unJugador,void* otroJugador);
int jug_BuscarIndiceJugadorPorId(LinkedList* pArrayListJugador, int id);

void jug_actualizarIdModoTexto(int id);
int jug_AsignarIdDesdeTexto(char* path);

///la uso--> printfOnePlayer??? falta validar seleccion
int jug_MostrarUnJugadorPorId(LinkedList* pArrayListJugador, int id);

#endif // jug_H_INCLUDED
