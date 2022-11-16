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

/// @brief constructor de jugadores
/// @return retorna un puntero en memoria dinamica del tipo de variable seleccion
Seleccion* selec_new();

/// @brief constructor de seleccion para asignarle valor a sus campos
/// @param idStr string de caracteres para el id
/// @param paisStr string de caracteres para el pais
/// @param confederacionStr string de caracteres para la confederacion
/// @param convocadosStr string de caracteres para los convocados
/// @return puntero a la seleccion con los datos cargados en sus campos
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

/// @brief borra una seleccion de memoria dinamica
void selec_delete();

/// @brief getter para obtener el id de una seleccion
/// @param this el puntero a la seleccion
/// @param id puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int selec_getId(Seleccion* this,int* id);

/// @brief getter para obtener el pais de una seleccion
/// @param this el puntero a la seleccion
/// @param pais puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int selec_getPais(Seleccion* this,char* pais);

/// @brief getter para obtener la confederacion de una seleccion
/// @param this el puntero a la seleccion
/// @param confederacion puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int selec_getConfederacion(Seleccion* this,char* confederacion);

/// @brief setter para asignar el valor de convocados a una seleccion
/// @param this el puntero a la seleccion
/// @param convocados parametro que se le va a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int selec_setConvocados(Seleccion* this,int convocados);

/// @brief getter para obtener los convocados de una seleccion
/// @param this el puntero a la seleccion
/// @param convocados puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int selec_getConvocados(Seleccion* this,int* convocados);

///-----------------------
/// propias

/// @brief para obtener los valores asignados a los campos de una seleccion
/// @param this el puntero a la seleccion que quiero sus datos
/// @param id puntero a la variable donde se guardara el valor
/// @param pais puntero a la variable donde se guardara el valor
/// @param confederacion puntero a la variable donde se guardara el valor
/// @param convocados puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener los valores y 1 si pudo
int selec_getOneSelec(Seleccion* this, int* id, char* pais, char* confederacion, int* convocados);

/// @brief para mostrar los datos de una seleccion
/// @param this el puntero a la seleccion
/// @return retorna -1 si no pudo mostrar a la seleccion y 1 si pudo
int selec_printOneSelec(Seleccion* this);

/// @brief compara dos selecciones por confederacion retornando el ordenamiento
/// @param unaSelec
/// @param otraSelec
/// @return retorna el int de la comparacion de la funcion stricmp
int selec_CompareByConfed(void* unaSelec,void* otraSelec);

/// @brief muestra las 5 confederaciones disponibles y carga la opcion elegida en el puntero a la confederacion
/// @param confederacionOpcion puntero a la confederacion donde quiero que se guarde la cadena
/// @return -1 si no funciono, 1 si funciono
int selec_seleccionarConfederacion(char* confederacionOpcion);

/// @brief para verificar que exista al menos un convocado en alguna seleccion
/// @param pArrayListSeleccion  LinkedList* Puntero a la lista de selecciones
/// @return retorna -1 si no hay ningun convocado
/// 				1 si existe al menos 1 convocado
int selec_verificarConvocados(LinkedList* pArrayListSeleccion);

/// @brief para disminuir en 1 el campo de convocados de una seleccion segun su id
/// @param pArrayListSeleccion LinkedList* Puntero a la lista de selecciones
/// @param idSeleccion id de la seleccion de la que quiero desconvocar
/// @return retorna -1 si el puntero a la lista de selecciones es NULL y si ingreso un dato invaldio
/// 				 1 si pudo desconvocar
int selec_desconvocarPorId(LinkedList* pArrayListSeleccion, int idSeleccion);

/// @brief para mostrar la cabecera de la lista de selecciones
void mostrarCabeceraSelecciones(void);

/// @brief para recibir el indice en que se encuentra la seleccion a traves del id
/// @param pArrayListSeleccion LinkedList* Puntero a la lista de selecciones
/// @param id  id de la seleccion del que quiero saber el indice
/// @return retorna -1 si el puntero a la lista de selecciones es NULL, si falla el retorno de la longitud del array
/// 				 int del el indice donde se encuentra la seleccion
int selec_BuscarIndiceSeleccionPorId(LinkedList* pArrayListSeleccion, int id);

#endif // selec_H_INCLUDED
