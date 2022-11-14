#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

#include "Controller.h"

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete();

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);

/// falta
int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

///-----------------------
/// propias
int selec_getOneSelec(Seleccion* this, int* id, char* pais, char* confederacion, int* convocados);
int selec_printOneSelec(Seleccion* this);
int selec_CompareByConfed(void* unaSelec,void* otraSelec);
int selec_seleccionarConfederacion(char* confederacionOpcion);
int selec_verificarConvocados(LinkedList* pArrayListSeleccion);
int selec_desconvocarPorId(LinkedList* pArrayListSeleccion, int idSeleccion);
void mostrarCabeceraSelecciones(void);

///La uso???
int selec_BuscarIndiceSeleccionPorId(LinkedList* pArrayListSeleccion, int id);

#endif // selec_H_INCLUDED
