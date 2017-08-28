#ifndef PILALISTA_CPP
#define PILALISTA_CPP

#include "PilaLista.h"

template <class T>
PilaLista<T>::PilaLista(nat capacidad)
{
	stack = nullptr;
	cantidadElementos = 0;
	this->capacidad = capacidad;
}

template <class T>
PilaLista<T>::PilaLista(Puntero<NodoLista<T>> stack, nat cantidadElementos, nat capacidad)
{
	this->stack = stack;
	this->cantidadElementos = cantidadElementos;
	this->capacidad = capacidad;
}

template <class T>
void PilaLista<T>::Push(const T& e)
{
	Puntero<NodoLista<T>> nodo = new NodoLista<T>{ e,stack };
	stack = nodo;
	cantidadElementos++;
}

template <class T>
const T& PilaLista<T>::Top() const
{
	return stack->_data;
}

template <class T>
void PilaLista<T>::Pop()
{
	Puntero<NodoLista<T>> iter = stack;
	stack = stack->_sig;
	cantidadElementos--;
}

template <class T>
bool PilaLista<T>::EstaLlena() const
{
	return cantidadElementos == capacidad;
}

template <class T>
bool PilaLista<T>::EstaVacia() const
{
	return cantidadElementos == 0;
}

template <class T>
Puntero<Pila<T>> PilaLista<T>::Clon() const
{
	// Copia de la lista
	Puntero<NodoLista<T>> copiaStack = ClonRecursivo(stack);

	// Creo la Pila
	return new PilaLista(copiaStack, cantidadElementos, capacidad);
}

template<class T>
Puntero<NodoLista<T>> PilaLista<T>::ClonRecursivo(const Puntero<NodoLista<T>>& aClonar) const
{
	if (aClonar == nullptr) {
		return nullptr;
	}

	Puntero<NodoLista<T>> nodo = new NodoLista<T>{ aClonar->_data, ClonRecursivo(aClonar->_sig) };

	return nodo;
}


template <class T>
Iterador<T> PilaLista<T>::ObtenerIterador() const
{
	return nullptr;
}
#endif
