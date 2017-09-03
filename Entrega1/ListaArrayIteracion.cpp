#ifndef LISTA_ARRAY_ITERACION_H_
#define LISTA_ARRAY_ITERACION_H_

#include "ListaArrayIteracion.h"

template <class T>
ListaArrayIteracion<T>::ListaArrayIteracion(const ListaArrayImp<T> listaOrd, nat tope)
	:lista(listaOrd)
{
	this->tope = tope;
}

template <class T>
ListaArrayIteracion<T>::ListaArrayIteracion(const ListaArrayImp<T> listaOrd)
:lista(listaOrd)
{
	tope = 0;
}

template <class T>
bool ListaArrayIteracion<T>::HayElemento() const
{
	return lista.Largo() > tope;
}

template <class T>
const T& ListaArrayIteracion<T>::ElementoActual() const
{
	return lista.Obtener(tope);
}

template <class T>
void ListaArrayIteracion<T>::Avanzar()
{
	tope++;
}

template <class T>
void ListaArrayIteracion<T>::Reiniciar()
{
	tope = 0;
}

template <class T>
Puntero<Iteracion<T>> ListaArrayIteracion<T>::Clonar() const
{
	//Puntero<Iteracion<T>> pIt = new ListaArrayIteracion(lista.Clon(), tope);
	//return pIt;
	return new ListaArrayIteracion(*this);
}

#endif
