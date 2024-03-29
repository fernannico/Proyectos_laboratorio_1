/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas

/// \brief Crea y retorna un nuevo LinkedList.
/// \return retorna la nueva LinkedList.
LinkedList* ll_newLinkedList(void);

/// \brief Retorna el tamaño del LinkedList.
/// \param this LinkedList* Puntero a la lista
/// \return Si la verificación falla la función retorna (-1) y si tiene éxito retorna la longitud del array.
int ll_len(LinkedList* this);

/// @brief Retorna un puntero al nodo que se encuentra en el índice especificado.
/// @param this LinkedList* Puntero a la lista
/// @param nodeIndex Indice del nodo a obtener.
/// @return Retorna  (NULL) Error: si el puntero a la lista es NULL o si el indice es menor a 0 o mayor al len de la lista
/// 				 (pElement) Si funciono correctamente
Node* test_getNode(LinkedList* this, int nodeIndex);

/// @brief Permite realizar el test de la funcion addNode la cual es privad
/// @param this LinkedList* Puntero a la lista
/// @param nodeIndex Ubicacion donde se agregara el nuevo nodo
/// @param pElement Puntero al elemento a ser contenido por el nuevo nodo
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL o si el indice es menor a 0 o mayor al len de la lista
///  				 ( 0) Si funciono correctamente
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/// @brief Agrega un elemento a la lista
/// @param this LinkedList* Puntero a la lista
/// @param pElement void* Puntero al elemento a ser agregado
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
/// 			     ( 0) Si funciono correctamente.
int ll_add(LinkedList* this, void* pElement);

/// @brief Permite realizar el test de la funcion addNode la cual es privada
/// @param this LinkedList* Puntero a la lista
/// @param index Ubicacion del elemento a obtener
void* ll_get(LinkedList* this, int index);

/// @brief Modifica un elemento de la lista
/// @param this LinkedList* Puntero a la lista
/// @param index Ubicacion del elemento a modificar
/// @param pElement void* Puntero al nuevo elemento
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL si el indice es menor a 0 o mayor al len de la lista
/// 			 	 ( 0) Si funciono correctamente. *
int ll_set(LinkedList* this, int index,void* pElement);

/// @brief Elimina un elemento del LinkedList, en el índice especificado
/// @param this LinkedList* Puntero a la lista
/// @param index Ubicacion del elemento a eliminar
/// @return retorna (-1) Error: si el puntero a la lista es NULL si el indice es menor a 0 o mayor al len de la lista
/// 		   		( 0) Si funciono correctamente.
int ll_remove(LinkedList* this,int index);

/// @brief Elimina todos los elementos de la lista
/// @param this LinkedList* Puntero a la lista
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
/// 				 ( 0) Si funciono correctamente.
int ll_clear(LinkedList* this);

/// @brief Elimina todos los elementos de la lista y la lista
/// @param this LinkedList* Puntero a la lista
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
/// 				 ( 0) Si funciono correctamente.
int ll_deleteLinkedList(LinkedList* this);

/// @brief el indice de la primer ocurrencia del elemento pasado como parametro.
/// @param this LinkedList* Puntero a la lista
/// @param pElement void* Puntero al elemento
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
/// 				 (indice del elemento) Si funciono correctamente
int ll_indexOf(LinkedList* this, void* pElement);

/// @brief Indica si la lista esta o no vacia
/// @param this LinkedList* Puntero a la lista
/// @return Retorna  (-1) Error: si el puntero a la lista es NULL
/// 				 ( 0) Si la lista NO esta vacia
int ll_isEmpty(LinkedList* this);

/// @brief Inserta un nuevo elemento en la lista en la posicion indicada
/// @param this LinkedList* Puntero a la lista
/// @param index Ubicacion donde se agregara el nuevo elemento
/// @param pElement void* Puntero al nuevo elemento
/// @return retorna (-1) Error: si el puntero a la lista es NULL si el indice es menor a 0 o mayor al len de la lista
///		  			( 0) Si funciono correctamente
int ll_push(LinkedList* this, int index, void* pElement);

/// @brief Elimina el elemento de la posicion indicada y retorna su puntero
/// @param this LinkedList* Puntero a la lista
/// @param index Ubicacion del elemento eliminar
void* ll_pop(LinkedList* this,int index);

/// @brief Determina si la lista contiene o no el elemento pasado como parametro
/// @param this LinkedList* Puntero a la lista
/// @param pElement void* Puntero del elemento a verificar
/// @return retorna (-1) Error: si el puntero a la lista es NULL
/// 	 		    ( 1) Si contiene el elemento
/// 		   		( 0) si No contiene el elemento
int ll_contains(LinkedList* this, void* pElement);

/// @brief Determina si todos los elementos de la lista (this2) estan contenidos en la lista (this)
/// @param this LinkedList* Puntero a la lista
/// @param this2 LinkedList* Puntero a la lista
/// @return Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
///                  ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
///                  ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
int ll_containsAll(LinkedList* this,LinkedList* this2);

/// @brief Crea y retorna una nueva lista con los elementos indicados
/// @param this LinkedList* Puntero a la lista
/// @param from Indice desde el cual se copian los elementos en la nueva lista
/// @param to Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
/// @return Retorna  (NULL) Error: si el puntero a la listas es NULL si el indice from es menor a 0 o mayor al len de la lista
///                                								   o si el indice to es menor o igual a from o mayor al len de la lista
///                  (puntero a la nueva lista) Si ok
LinkedList* ll_subList(LinkedList* this,int from,int to);

/// @brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
/// @param this LinkedList* Puntero a la lista
/// @return Retorna  (NULL) Error: si el puntero a la listas es NULL
///                  (puntero a la nueva lista) Si ok
LinkedList* ll_clone(LinkedList* this);

/// @brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
/// @param this LinkedList* Puntero a la lista
/// @param pFunc (*pFunc) Puntero a la funcion criterio
/// @param order int [1] Indica orden ascendente - [0] Indica orden descendente
/// @return Retorna (-1) Error: si el puntero a la listas es NULL
///                 ( 0) Si ok
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
