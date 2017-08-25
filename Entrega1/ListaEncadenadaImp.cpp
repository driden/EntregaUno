#ifndef LISTAENCADENADA_CPP
#define LISTAENCADENADA_CPP

#include "ListaEncadenadaImp.h"	


template<class T>
ListaEncadenadaImp<T>::ListaEncadenadaImp(const Comparador<T>& comp):
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
		Puntero<NodoLista<T>> iter = lista;

		while (iter->_sig != nullptr) {
			iter = iter->_sig;
		}
		
		iter->_sig = nodo;

		//destruyo iter porque no quiero que quede apuntando a nada
		iter = nullptr;
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