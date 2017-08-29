#ifndef COLAPRIORIDADLISTA_CPP
#define COLAPRIORIDADLISTA_CPP

#include "ColaPrioridadLista.h"

template <class T, class P>
void ColaPrioridadLista<T, P>::Encolar(const T& e, const P& p)
{
}

template <class T, class P>
const T& ColaPrioridadLista<T, P>::Desencolar()
{
	T t = T();
	return t;
}

template <class T, class P>
const T& ColaPrioridadLista<T, P>::Cabeza() const
{
	T t = T();
	return t;
}

template <class T, class P>
const T& ColaPrioridadLista<T, P>::ObtenerPrioridad(const T& e) const
{
	T t = T();
	return t;
}

template <class T, class P>
bool ColaPrioridadLista<T, P>::Pertenece(const T& e) const
{
	return false;
}

template <class T, class P>
bool ColaPrioridadLista<T, P>::EstaVacia() const
{
	return false;
}

template <class T, class P>
bool ColaPrioridadLista<T, P>::EstaLlena() const
{
	return false;
}

template <class T, class P>
Puntero<ColaPrioridad<T, P>> ColaPrioridadLista<T, P>::Clon() const
{
	return nullptr;	
}

template <class T, class P>
Iterador<T> ColaPrioridadLista<T, P>::ObtenerIterador() const
{
	return nullptr;
}

template <class T, class P>
nat ColaPrioridadLista<T, P>::Largo() const
{
	return 0;
}
#endif
