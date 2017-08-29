
#ifndef PILAITERACION_CPP
#define PILAITERACION_CPP

#include "PilaIteracion.h"
#include "PilaLista.h"

template <class T>
PilaIteracion<T>::PilaIteracion(const PilaArray<T>& pilaArr)
{
	pila = new PilaArray<T>(pilaArr);
	clon = pila->Clon();
}

template <class T>
PilaIteracion<T>::PilaIteracion(const PilaLista<T>& pilaList)
{
	pila = new PilaLista<T>(pilaList);
	clon = pila->Clon();
}

template <class T>
bool PilaIteracion<T>::HayElemento() const
{
	return !clon->EstaVacia();
}

template <class T>
const T& PilaIteracion<T>::ElementoActual() const
{
	return clon->Top();
}

template <class T>
void PilaIteracion<T>::Avanzar()
{
	return clon->Pop();
}

template <class T>
void PilaIteracion<T>::Reiniciar()
{
	clon = nullptr;
	clon = pila->Clon();
}


#endif
