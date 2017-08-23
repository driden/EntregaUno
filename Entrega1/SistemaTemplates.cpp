#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"

// Ejercicio 1: ordenamiento
template <class T>
void Sistema::Ordenar(Array<T>& elementos, const Comparador<T>& comp)
{
}

// Operación 2: Búsqueda
template <class T>
int Sistema::Busqueda(const Array<T>& elementos, const T& elem, const Comparador<T>& comp)
{
	return -1;
}

// Operación 3: TAD Pila
template <class T>
Puntero<Pila<T>> Sistema::CrearPilaSimplementeEncadenada(nat tamano)
{
	return nullptr;
}

template <class T>
Puntero<Pila<T>> Sistema::CrearPilaArray(nat tamano)
{
	return nullptr;
}

template <class T>
bool Sistema::Iguales(const Puntero<Pila<T>>& pila1, const Puntero<Pila<T>>& pila2, const Comparador<T>& comp)
{
	return false;
}

// Operación 5: Lista Ordenada
template<class T>
Puntero<ListaOrd<T>> Sistema::CrearListaOrdenadaEncadenada(const Comparador<T>& comp)
{
	return nullptr;
}

template <class T>
Puntero<ListaOrd<T>> Sistema::CrearListaOrdenadaConArray(const Comparador<T>& comp)
{
	return nullptr;
}

template <class T>
bool Sistema::ListasSonIguales(const Puntero<ListaOrd<T>>& lista1, const Puntero<ListaOrd<T>>& lista2, const Comparador<T>& comp)
{
	return false;
}

// Operación 6: Tad Cola de Prioridad
template<class T, class P>
Puntero<ColaPrioridad<T, P>> Sistema::CrearColaPrioridad(nat tamano)
{
	return nullptr;
}


// Operación 7: Ejercicio con Cola de Prioridad
template <class T>
Array<T> Sistema::MayoresN(Array<Array<T>> datos, const Comparador<T>& comp, nat n)
{
	return Array<T>();
}

#endif