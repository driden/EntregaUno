#ifndef LISTAENCADENADA_CPP
#define LISTAENCADENADA_CPP

#include "ListaEncadenadaImp.h"	
#include "ListaEncadenadaIteracion.h"

template<class T>
ListaEncadenadaImp<T>::ListaEncadenadaImp(const Comparador<T>& comp) :
	lista(nullptr),
	cantidadElementos(0),
	comparador(comp)
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

		// Clean up
		anterior = nullptr;
		iter = nullptr;
	}

	cantidadElementos++;
}

template<class T>
const T & ListaEncadenadaImp<T>::Cabeza() const
{
	return lista->_data;
}

template<class T>
void ListaEncadenadaImp<T>::Eliminar(const T & e)
{
	// Tres casos:
	// Primer Elemento para elminar
	// Elemento del medio
	// Ultimo elemento

	Puntero<NodoLista<T>> iter = lista, anterior = lista;

	while (iter && !comparador.SonIguales(e, iter->_data)) {
		anterior = iter;
		iter = iter->_sig;
	}

	// tengo que borrar iter
	//si son el mismo, es el primero
	if (iter == anterior) {
		lista = iter->_sig;				
	}
	else if (iter->_sig == nullptr){
		// es el ultimo
		anterior->_sig = nullptr;		
	}
	else {
		// caso generico
		anterior->_sig = anterior->_sig->_sig;
	}
	iter = nullptr;
	cantidadElementos--;
}

template<class T>
nat ListaEncadenadaImp<T>::Largo() const
{
	return cantidadElementos;
}

template<class T>
const T & ListaEncadenadaImp<T>::Obtener(const nat n) const
{
	nat pos = 0;
	Puntero<NodoLista<T>> iter = lista;
	while (pos < n) { 
		iter = iter->_sig; 
		pos++;
	}

	return iter->_data;
}

template<class T>
bool ListaEncadenadaImp<T>::Pertenece(const T & e) const
{
	return false;
}

template<class T>
bool ListaEncadenadaImp<T>::EstaVacia() const
{
	return cantidadElementos == 0;
}

template<class T>
Puntero<ListaOrd<T>> ListaEncadenadaImp<T>::Clon() const
{
	return Puntero<ListaOrd<T>>();
}

template<class T>
Iterador<T> ListaEncadenadaImp<T>::ObtenerIterador() const
{
	return new ListaEncadenadaIteracion<T>(*this);
}

#endif