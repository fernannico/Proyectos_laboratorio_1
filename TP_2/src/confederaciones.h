/*
 * confederaciones.h
 *
 *  Created on: 18 oct. 2022
 *      Author: User
 */

#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_
#include <stdio.h>
#include <stdlib.h>

#define LIBRE 0
#define CARGADO 1
#define BAJADO 2
#define TAMC 10

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;
}eConfederacion;

/// \brief para cargar un array de estructuras de confederaciones
/// \param confederaciones dato del tipo estructura para cargar los campos de las confederaciones
/// \param size tamaño del array de estructuras confederaciones
void CargarConfederacionesHarcodeadas(eConfederacion confederaciones[], int size);

/// \brief para validar la existencia de al menos una confederacion dada de baja
/// \param confederaciones estructura de control para corroborar la existencia de una confederacion dada de baja
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \return retorna 1 si hay una baja y 0 si no la hay
int ValidarConfederacionBajada(eConfederacion confederaciones[], int sizeConfed);

/// \brief para inicializar el campo estado del array de jugadores en LIBRES
/// \param confederaciones dato del tipo estructura cuyos campos estado seran asignados como LIBRES en el array
/// \param sizeConfed tamaño del array de estructuras confederaciones
void InicializarEstadoConfederaciones(eConfederacion confederaciones[], int sizeConfed);

/// \brief para buscar el primer espacio libre del array
/// \param confederaciones dato del tipo estructura donde se buscara el estado LIBRE
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \return retorna el primer indice del array cuyo elemento tiene el estado libre
int BuscarEspacioLibreConfed(eConfederacion confederaciones[], int sizeConfed);

/// \brief para dar de alta una confederacion cuyo campo "estado" (isEmpty) esta dado de baja
/// \param confederaciones dato del tipo estructura donde se buscara el estado BAJADO
/// \param sizeConfed tamaño del array de estructuras confederaciones
void CargarConfederacionesBajadas(eConfederacion confederaciones[], int sizeConfed);

/// \brief  para dar de alta una nueva confederacion con los valores de los campos dados por el usuario
/// \param confederaciones dato del tipo estructura que se dara de alta
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \param idAutoIncrementalConfed id que se asigna automaticamente de forma incremental
/// \return retorna 1 si pudo cargar la confederacion y -1 si no fue posible
int CargarNuevaConfederacion(eConfederacion confederaciones[], int sizeConfed, int idAutoIncrementalConfed);

/// \brief para dar una baja logica a una confederacion del array
/// \param confederaciones tipo de dato estructura donde se efectua la baja
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \param contadorConfederaciones puntero al espacio de memoria donde se encuentra el contador de confederaciones
void DarDeBajaConfederacion(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones);

/// \brief para modificar una confederacion del array
/// \param confederaciones tipo de dato estructura donde se efectua la modificacion
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \param contadorConfederaciones puntero al espacio de memoria donde se encuentra el contador de confederaciones
void ModificarConfederacion(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones);

/// \brief para contar la cantidad de confederaciones cargadas
/// \param contadorConfederaciones puntero al espacio de memoria donde se dejara por referencia el resultado del conteo
/// \param confederaciones tipo de dato estructura donde realizara el conteo segun su campo estado
/// \param size tamaño del array de estructuras confederaciones
/// \return retorna 1 si fue posible realizar el conteo y 0 si no
int ContarConfederacionesCargadas(int* contadorConfederaciones, eConfederacion confederaciones[], int size);

/// \brief para validar que haya al menos una confederacion cargada
/// \param confederaciones  tipo de dato estructura donde se realiza la validacion
/// \param contadorConfederaciones puntero al espacio de memoria donde se encuentra el contador de confederaciones
/// \param size tamaño del array de estructuras confederaciones
/// \return retorna 1 si existe una confederacion cargada y 0 si no
int ValidarConfederacionCargada(eConfederacion confederaciones[], int* contadorConfederaciones, int size);

/// \brief dado un id de una confederacion, nos retorna el indice del array donde se encuentra
/// \param confederaciones dato del tipo estructura donde buscara el indice
/// \param id el ID de la confederacion usado como referencia para obtener el indice
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \return retorna el indice donde se encuentra la confederacion con el respectivo id
int buscarIndiceConfederacionPorId(eConfederacion confederaciones[],int id,int sizeConfed);

/// \brief para validar que una confederacion encuentra su campo estado CARGADO segun el id
/// \param confederaciones  dato del tipo estructura que se usara para determinar el estado de su campo
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \param id el ID de la confederacion usado como referencia para verificar su estado
/// \return retorna 1 si la confederacion con el ID respectivo tiene su estado CARGADO y -1 si no
int ValidarConfederacionCargadaPorId(eConfederacion confederaciones[], int sizeConfed, int id);

/// \brief para ingresar a la opcion de ABM de confederaciones con sus respectivas subopciones
/// \param confederaciones  dato del tipo estructura que se usara como ABM
/// \param sizeConfed tamaño del array de estructuras confederaciones
/// \param contadorConfederaciones puntero al espacio de memoria donde se encuentra el contador de confederaciones
/// \param idAutoIncrementalConfed id que se asigna automaticamente de forma incremental
void AccederABMConfed(eConfederacion confederaciones[], int sizeConfed, int* contadorConfederaciones, int idAutoIncrementalConfed);

#endif /* CONFEDERACIONES_H_ */
