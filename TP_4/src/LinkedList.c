#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado */
LinkedList* ll_newLinkedList(void){
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL){
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista */
int ll_len(LinkedList* this){
    int returnAux = -1;

    if(this != NULL){
		returnAux = this->size;
    }

    return returnAux;
}


/** \brief  OBTIENE un nodo de la lista
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                          (pNode) Si funciono correctamente!!! */
static Node* getNode(LinkedList* this, int nodeIndex){

	int cantidad;
	Node* unNodo = NULL;

	if(this != NULL){
		cantidad = ll_len(this);
		if(cantidad != -1 && nodeIndex < cantidad && nodeIndex >=0){
			unNodo = this->pFirstNode;

			while(nodeIndex > 0){
				unNodo = unNodo->pNextNode;
				nodeIndex--;
			}
		}
	}

    return unNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente*/
Node* test_getNode(LinkedList* this, int nodeIndex){

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente*/
static int addNode(LinkedList* this, int nodeIndex,void* pElement){
    int returnAux = -1;
    int cantidad;
    Node* nodoAnterior = NULL;
    Node* nodoAgregado =NULL;

	nodoAgregado = (Node*)malloc(sizeof(Node));

    if(this != NULL)
    cantidad = ll_len(this);

    if(cantidad != -1 && nodoAgregado != NULL && this != NULL && nodeIndex <= cantidad && nodeIndex >=0){

		if(cantidad == 0){
			this->pFirstNode = nodoAgregado;
			nodoAgregado->pNextNode=NULL;
			nodoAgregado->pElement = pElement;
			returnAux = 0;
		}else{
			if(nodeIndex == 0){
				nodoAgregado->pNextNode = this->pFirstNode;
				this->pFirstNode = nodoAgregado;
				nodoAgregado->pElement = pElement;
				returnAux = 0;
			}else{
				nodoAnterior = getNode(this, nodeIndex-1);
				if(nodeIndex == cantidad && nodoAnterior != NULL){
					nodoAnterior->pNextNode = nodoAgregado;
					nodoAgregado->pNextNode = NULL;
					nodoAgregado->pElement = pElement;
					returnAux = 0;

				}else{
					nodoAgregado->pNextNode = nodoAnterior->pNextNode;
					nodoAnterior->pNextNode = nodoAgregado;
					nodoAgregado->pElement = pElement;
					returnAux = 0;
				}
			}
		}
		this->size = this->size+1;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente*/
int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1;
    int ultimoIndice;

    if(this != NULL){
		ultimoIndice = ll_len(this);
		if(ultimoIndice != -1)
		if(addNode(this, ultimoIndice, pElement) == 0)
		returnAux = 0;
    }

    return returnAux;
}

/// @brief Retorna un puntero al elemento que se encuentra en el índice especificado
/// @param this
/// @param index
/// @return void* Retorna NULL Si la verificación falla
/// 			 			   Si tiene éxito retorna el elemento.
void* ll_get(LinkedList* this, int index){
    void* returnAux = NULL;
    int lenLL;
    Node* nodoAux = NULL;

    if(this != NULL)
    lenLL = ll_len(this);

    if(index >=0 && index < lenLL){
    	nodoAux = getNode(this, index);
    	if(nodoAux != NULL){
			returnAux = nodoAux->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente*/
int ll_set(LinkedList* this, int index,void* pElement){
    int returnAux = -1;
    int lenLL;
	Node* nodoAux = NULL;

	if(this != NULL){
		lenLL = ll_len(this);
		if(index >=0 && index < lenLL){
			nodoAux = getNode(this, index);
			if(nodoAux != NULL){
				nodoAux->pElement = pElement;
				returnAux = 0;
			}
		}
	}

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente*/
int ll_remove(LinkedList* this,int index){
    int returnAux = -1;
    int lenLL;
    Node* nodoAux = NULL;
    Node* nodoAnterior = NULL;

    if(this != NULL)
    lenLL = ll_len(this);

    if(lenLL != -1 && index >=0 && index < lenLL){
    	nodoAux = getNode(this, index);
    	if(nodoAux != NULL){
    		if(index == 0){///borro nodo en el indice 0 si hay elementos
    			this->pFirstNode = nodoAux->pNextNode;
    			free(nodoAux);
				returnAux = 0;
			}else{
				nodoAnterior = getNode(this, index-1);
				if(index == lenLL && nodoAnterior != NULL){///borro un nodo en la ultima posicion
					free(nodoAux);
					nodoAnterior->pNextNode = NULL;
					returnAux = 0;
				}else{///borro un nodo en cualquier posicion
					nodoAnterior->pNextNode  = nodoAux->pNextNode;
					free(nodoAux);
					returnAux = 0;
				}
			}
			this->size = this->size-1;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente*/
int ll_clear(LinkedList* this){
    int returnAux = -1;
    int lenLL;
    int i;

    if(this != NULL){
    	lenLL = ll_len(this);
    	if(lenLL != -1){
    		for(i = lenLL; i>=0; i--){
    			if(ll_remove(this, i)==0){
    				returnAux = 0;
    			}
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente*/
int ll_deleteLinkedList(LinkedList* this){
    int returnAux = -1;

    if(this != NULL){
    	if(ll_clear(this)==0){
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente*/
int ll_indexOf(LinkedList* this, void* pElement){
    int returnAux = -1;
    int lenLL;
    int i;
    void* elementoAux =NULL;

    if(this != NULL){
    	lenLL = ll_len(this);
		for(i = 0; i<lenLL; i++){
			elementoAux = ll_get(this, i);
			if(elementoAux == pElement){
				returnAux = i;
				break;
			}
		}

    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia */
int ll_isEmpty(LinkedList* this){
    int returnAux = -1;
    int lenLL;

    if(this != NULL){
    	lenLL = ll_len(this);
    	if(lenLL == 0){
    		returnAux = 1;
    	}else{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente*/
int ll_push(LinkedList* this, int index, void* pElement){
    int returnAux = -1;
    int lenLL;

    if(this != NULL){
		lenLL = ll_len(this);
		if(index >=0 && index<=lenLL){
			if(addNode(this, index, pElement)==0){
				returnAux = 0;
			}
		}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente*/
void* ll_pop(LinkedList* this,int index){
    void* returnAux = NULL;
    int lenLL;

    if(this != NULL){
    	lenLL = ll_len(this);
    	if(index >= 0 && index <= lenLL){
    		returnAux = ll_get(this, index);
    		if(returnAux != NULL){
				if(ll_remove(this, index)==-1){
					returnAux = NULL;
				}
    		}
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento*/
int ll_contains(LinkedList* this, void* pElement){
    int returnAux = -1;

    if(this != NULL){
    	returnAux = 0;
    	if(ll_indexOf(this, pElement) != -1){
    		returnAux = 1;
    	}
    }


    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)*/
int ll_containsAll(LinkedList* this,LinkedList* this2){
    int returnAux = -1;
    int lenLL;
    int lenLLDos;
    int i;
    void* elementoAux;

    if(this != NULL && this2 != NULL){
    	lenLL = ll_len(this);
    	lenLLDos = ll_len(this2);
    	if(lenLL != lenLLDos){
    		returnAux = 0;
    	}else{
			returnAux = 1;
			for(i=0; i < lenLLDos; i++){
				elementoAux = ll_get(this2, i);
				if(ll_contains(this, elementoAux)==0){
					returnAux = 0;
					break;
				}
			}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok*/
LinkedList* ll_subList(LinkedList* this,int from,int to){
    LinkedList* cloneArray = NULL;
    int lenLL;
    int i;
    void* elementosIntermedios;

    if(this != NULL){
    	lenLL = ll_len(this);
    	if(from >= 0 && to <= lenLL && from < to){
    		cloneArray = ll_newLinkedList();
    		if(cloneArray != NULL){
				for(i = from; i<to;i++){
					elementosIntermedios = ll_get(this, i);
					ll_add(cloneArray, elementosIntermedios);
				}
			}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok*/
LinkedList* ll_clone(LinkedList* this){
    LinkedList* cloneArray = NULL;
    int i;
    int lenLL;
    void* elementoAux = NULL;

    if(this != NULL){
    	lenLL = ll_len(this);
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL && lenLL != -1){
    		for(i=0;i<lenLL;i++){
				elementoAux = ll_get(this, i);
				if(elementoAux != NULL){
					ll_add(cloneArray, elementoAux);
				}
			}
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
    int returnAux =-1;
    int lenLL;
    int i, j;
    Node* nodoUno;
    Node* nodoDos;
    void* elementoAux;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0)){
    	lenLL = ll_len(this);

		for(i = 0; i < lenLL-1; i++){
			nodoUno = getNode(this, i);
			for(j = i+1; j < lenLL; j++){
				nodoDos = getNode(this, j);
				if(order == 1){					///ORDEN AScENDENTE
					if(pFunc(nodoUno->pElement, nodoDos->pElement) > 0){
						elementoAux = nodoUno->pElement;
						nodoUno->pElement = nodoDos->pElement;
						nodoDos->pElement = elementoAux;
						returnAux = 0;
					}
				}else{
					if(order == 0){				///ORDEN DESCENDENTE
						if(pFunc(nodoUno->pElement, nodoDos->pElement) < 0){
							elementoAux = nodoUno->pElement;
							nodoUno->pElement = nodoDos->pElement;
							nodoDos->pElement = elementoAux;
							returnAux = 0;
						}
					}
				}
			}
		}
    }

    return returnAux;

}

/// @brief devolverá una nueva linkedlist que contenga alguno de los elementos de la lista original, según algún criterio
/// @param this puntero a la lista a iterar. Se deberá iterar todos los elementos de la lista y pasárselos a la función “pFunc”.
/// @param pFunc puntero a funcion que determina el criterio de filtro. La función “pFunc” devolverá 1 si ese ítem se debe agregar a la lista resultado o 0 si no debe agregarse.
/// @return la función “ll_filter” generará la nueva lista resultado, agregará a la misma los ítems correspondientes y la devolverá
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* element)){
	int lenThis;
	int i;
	void* elementoAux;
	LinkedList* listaFiltrada = NULL;

	if(this != NULL && pFunc != NULL){
		listaFiltrada = ll_newLinkedList();
		if(listaFiltrada != NULL){
			lenThis = ll_len(this);
			for(i = 0; i < lenThis; i++){
				elementoAux = ll_get(this, i);
				if(pFunc(elementoAux) == 1){
					ll_add(listaFiltrada, elementoAux);
				}
			}
		}
	}

	return listaFiltrada;
}

/// @brief
/// @param this
/// @param pFunc
/// @return
LinkedList* ll_map(LinkedList* this, void*(*pFunc)(void* element)){
	///se deberán iterar todos los elementos de la lista y pasárselos a la función “pFunc” que recibirá el elemento y le hara lo que tenga que hacer,
	/// el retorno de “pFunc” se agregará a la lista resultado
	/// Diferencia q hay es que filtro t filtra algo y mapp t agrega un valor a algo q puede ser filtrado o no
	int lenThis;
	int i;
	void* elementoAux;
	LinkedList* listaMapeada = NULL;

	if(this != NULL && *pFunc != NULL){
		lenThis = ll_len(this);
		listaMapeada = ll_newLinkedList();
		if(listaMapeada != NULL){
			for(i = 0; i< lenThis; i++){
				elementoAux = ll_get(this, i);
				if(elementoAux != NULL){
					elementoAux = pFunc(elementoAux);
					if(elementoAux != NULL)
					ll_add(listaMapeada, elementoAux);
				}
			}
		}
	}
	return listaMapeada;
}

/// @brief  Recorre los elementos y acumula un valor.
/// @param  this puntero a la lista a iterar. Se deberá iterar todos los elementos de la lista y pasárselos a la función “pFunc”.
/// @param  pFunc puntero a funcion con el criterio a contar. Devolverá la cantidad que debe contarse.
/// @return Retorna el numero acumulado al finalizar las iteraciones.
int ll_count(LinkedList* this, int (*pFunc)(void*)){
	int acumulador = 0;
	int i;
	int numeroActual; //valor actual de la iteracion
	int lenLL;
	void* pElement; //elemento para iterar.

	if(this != NULL && *pFunc != NULL){
		lenLL = ll_len(this);
		for (i = 0; i < lenLL; i++) {
			pElement = ll_get(this, i); //recorro la lista y voy trayendo los elementos.
			numeroActual = pFunc(pElement);
			if (numeroActual != -1) {
				acumulador = acumulador + numeroActual;
			}
		}
	}
	return acumulador;
}



