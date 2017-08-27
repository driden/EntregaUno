#ifndef LISTAENCADENADA_CPP
#define LISTAENCADENADA_CPP

#include "ListaEncadenadaImp.h"	


template<class T>
ListaEncadenadaImp<T>::ListaEncadenadaImp(const Comparador<T>& comp) :
	lista(nullptr),
	cantidadElementos(0),
	comparador(comp),
	unValor(T())
{
}

template<class T>
void ListaEncadenadaImp<T>::InsertarOrdenado(const T & e)
{
	Puntero<NodoLista<T>> nodo = new NodoLista<T>{ e, nullptr };

	if (lista == nullptr) {
		lista = nodo;
	}
	else {
		// Hay al menos un nodo en la lista
		Puntero<NodoLista<T>> iter = lista, anterior = lista;

		// Busco hasta que encuentro un elemento menor al que tengo		
		while (iter->_sig != nullptr && comparador.EsMayor(e, iter->_data)) {
			anterior = iter;
			iter = iter->_sig;
		}

		// Discrimino el caso de que tenga que ir al principio
		if (iter == anterior) { // Comparacion de punteros
			lista = nodo;
			nodo->_sig = iter;
		}
		else if (iter->_sig == nullptr && comparador.EsMayor(e, iter->_data)) {
		
			// Si iter es el ultimo y 'e' es Mayor que data en iter
			// entonces 'e' va despues de iter
			iter->_sig = nodo;
		}		
		else if (iter->_sig == nullptr) {
			// Si el ultimo es menor que 'e' entonces 'e' va al final
			// Inserto entre el anterior y el siguiente		
			anterior->_sig = nodo;
			nodo->_sig = iter;
		}
	}

	cantidadElementos++;
}

template<class T>
const T & ListaEncadenadaImp<T>::Cabeza() const
{
	return unValor;
}

template<class T>
void ListaEncadenadaImp<T>::Eliminar(const T & e)
{
}

template<class T>
nat ListaEncadenadaImp<T>::Largo() const
{
	return 0;
}

template<class T>
const T & ListaEncadenadaImp<T>::Obtener(const nat n) const
{
	// TODO: insert return statement here
	return unValor;
}

template<class T>
bool ListaEncadenadaImp<T>::Pertenece(const T & e) const
{
	return false;
}

template<class T>
bool ListaEncadenadaImp<T>::EstaVacia() const
{
	return false;
}

template<class T>
Puntero<ListaOrd<T>> ListaEncadenadaImp<T>::Clon() const
{
	return Puntero<ListaOrd<T>>();
}

template<class T>
Iterador<T> ListaEncadenadaImp<T>::ObtenerIterador() const
{
	return Iterador<T>();
}

#endif