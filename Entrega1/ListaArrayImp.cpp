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
ListaArrayImp<T>::ListaArrayImp(const Comparador<T>& comp)
{
	tamanio = 10;
	lista = Array<T>(tamanio);
	comparador = comp;
	tope = -1;
}

template <class T>
void ListaArrayImp<T>::InsertarOrdenado(const T& e)
{
	if (tope == lista.Largo - 1)
	{
		tamanio *= 2;
		Array<T> nuevoArray = Array<T>(lista);
		Array<T>::Copiar(lista, nuevoArray, 0);

		lista = nuevoArray;
	}

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
	int indiceE = -1;
	for(nat i = 0; i < lista.Largo;i++)
	{
		if (comparador.SonIguales(lista[i], e))
			indiceE = i;
	}

	for (nat j = static_cast<nat>(indiceE); j < lista.Largo  ; j--)
	{
		lista[j] = lista[j + 1];
	}
	tope--;
}

template <class T>
const T& ListaArrayImp<T>::Obtener(const nat n) const
{
	return lista[n];
}

template <class T>
nat ListaArrayImp<T>::Largo() const
{
	return tope + 1;
}

template <class T>
bool ListaArrayImp<T>::Pertenece(const T& e) const
{
	return IndexOf(e) != -1;
}

template <class T>
bool ListaArrayImp<T>::EstaVacia() const
{
	return tope == -1;
}

template <class T>
Puntero<ListaOrd<T>> ListaArrayImp<T>::Clon() const
{
	return new ListaArrayImp(tamanio, lista, tope, comparador);
}

template <class T>
ListaArrayImp<T>::ListaArrayImp(nat size, Array<T> arr, int tope, const Comparador<T> comp)
{
	this->tamanio = size;
	this->comparador = comp;
	this->tope = tope;
	this->lista = arr;
}

template <class T>
Iterador<T> ListaArrayImp<T>::ObtenerIterador() const
{
	return nullptr;
}
template <class T>
int ListaArrayImp<T>::IndexOf(const T& e) const
{
	int indiceE = -1;
	for (nat i = 0; i< lista.Largo; i++)
	{
		if (comparador.SonIguales(lista[i], e))
			indiceE = i;
	}
	return indiceE;
}

#endif
