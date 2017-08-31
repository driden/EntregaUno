#ifndef LISTAARRAYIMP_CPP
#define LISTAARRAYIMP_CPP

#include "ListaArrayImp.h"

template <class T>
ListaArrayImp<T>::ListaArrayImp(const nat& tamanio, Comparador<T> comp)
{
	this->tamanio = tamanio;
	tope = -1;
	lista = Array<T>(tamanio);
	comparador = comp;
}

template <class T>
void ListaArrayImp<T>::InsertarOrdenado(const T& e)
{
	// recorro el array al reves y voy moviendo los items a la derecha
	tope++;
	int i = tope;
	while (i > 0 && comparador.EsMayor(e, lista[i]))
	{
		lista[i + 1] = lista[i];
		i--;
	}
	lista[i] = e;
}

template <class T>
const T& ListaArrayImp<T>::Cabeza() const
{
	return lista[0];
}

template <class T>
void ListaArrayImp<T>::Eliminar(const T& e)
{
}

template <class T>
const T& ListaArrayImp<T>::Obtener(const nat n) const
{
	return lista[0];
}

template <class T>
nat ListaArrayImp<T>::Largo() const
{
	return tope + 1;
}

template <class T>
bool ListaArrayImp<T>::Pertenece(const T& e) const
{
	return false;
}

template <class T>
bool ListaArrayImp<T>::EstaVacia() const
{
	return tope == -1;
}

template <class T>
Puntero<ListaOrd<T>> ListaArrayImp<T>::Clon() const
{
	return nullptr;
}

template <class T>
Iterador<T> ListaArrayImp<T>::ObtenerIterador() const
{
	return nullptr;
}
#endif
