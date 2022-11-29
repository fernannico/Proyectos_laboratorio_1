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
    void* pElement;                 ///puntero generico al elemento (persona, empleado, jugadores, seleccionesetc.)
     	 	 	 	 	 	 	 		///cuando le pasaba el ll_add, aca se guaraba la referencia del jugador que le mandaba.
     	 	 	 	 	 	 	 		/// por eso LL es generico, porq guarda estructuras genericas en una direccion de memoria, guarda info de donde estan esos datos en md.
     	 	 	 	 	 	 	 		/// ll no almacena datos, almacena direcciones de memoria.
    struct Node* pNextNode;         ///PUNTERO AL PROXIMO NODO. es como las Fx recursivas. Es como una cadena porque cada nodo va a llamar al proximo nodo.
     	 	 	 	 	 	 	 	 ///ver que cuando voy agregando nodos (ponele q pasa el usuario el 51 como elemento) en cuando al pNextNode lo tengo que apuntar a null yo (pNextNode-> NULL) para que haya un final en el tren
     	 	 	 	 	 	 	 	 ///
}typedef Node;

///tiene la estructura de arriba guardada adentro de la estructura linkedlist.
struct LinkedList
{
    Node* pFirstNode;				///aca tenemos el firstNode que es un puntero a nodo (siendo nodo un puntero a un elemento y otro nodo). O sea que la cabecera del LL tiene el puntero que apunta al primer nodo [el del indice 0 por asi decir]. Como el primer nodo es un nodo, tambien es un elemento y apunta a otro nodo (el 1000 en el trencito, el 2do vagon tambien tiene el 1000)
     	 	 	 	 	 	 	 	///Este 2do elemetnto (el 21) tiene otra direccion de memoria que va a ser la que apunta el 3er nodo y asi.
    int size;                       ///cada vez que agrego o elimino un elemento size++/--.. es decir, guarda la cantidad de elementos
}typedef LinkedList;				///
#endif

///EN RESUMEN. linkedlist (q es un nodo) guarda el tamaño y apunta al primer nodo (el del elemento 21) y guarda la direccion de memoria del proximo nodo.
/// se sabe que el ultimo nodo va a estar apuntando a NULL, por lo que se corta la cadena. O sea, si apunta a null, es que es el ultimo, pero no quiere decir que este vacio.
/// el ultimo vagon tiene un puntero a elemento (51), pero no tiene siguiente vagon, asiq apunta a null.
///ESTO SE DIFERENCIA MUCHO DE LOS ARRAYS, ¿Como recorremos esto? de uno en uno viendo la direccion del otro.. no es como los arrays. No puedo ir al ultimo elemento de una con el linkedlist. Tengo que recorrer tod0 el tren desde el principio:
/// es decir: Empezando del principio (pFirstNode), el primero apunta a mil. ¿Como se cual es el que le sigue? Porque el de mil apunta al de la posicion 2000. ¿como se cual le sigue? Porq 2000 guarda el dato del siguiente. Y ¿como se que termino en el 3er vagon? Porq apunta a null
/// es como estar en una fila sin saber quien esta atras de tod0, tengo que preguntarle al q me sigue y el q me sigue va a saber al q le sigue y asi hasta el final que le van a preguntar si es el ultimo y va a confirmar porq no tiene a nadie detras. Entonces tengo que ir uno en uno obteniendolo.
/// 	(si nosotros tenemos un array de 5 elementos y queremos acceder a la ultima posicion seria array[4}.)
///
/// con LL no tengo el problema de arrays donde tienen que ser continuos. LL guarda direcciones de memoria,  no trabaja con el dato de por si, sino el puntero al elemento
/// 	el arrayList reserva espacio en memoria para esos elementos en el heap. Entonces como no tiene que ser continuo donde se guardan, no va a tener el error de que no hay
/// 	memoria para la cantidad nueva. AMBAS LABURA CON EL HEAP, el tema es q con arrays cuando realoco, tiene q ser contiguo y si no hay memoria seria NULL. Con LL no.
//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);                                       //devuelve el valor del campo int size
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);                           //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* element));
LinkedList* ll_map(LinkedList* this, void*(*pFunc)(void* element));
