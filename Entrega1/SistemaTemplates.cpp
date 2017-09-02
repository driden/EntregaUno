#include "PilaLista.h"
#include "PilaArray.h"
#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"

template <class T>
void Sistema::MergeSort(Array<T> &arr, int low, int high, Comparador<T> comp)
{
	if (low >= high)
		return;
	else {
		int mid = (low + high) / 2;
		MergeSort(arr, low, mid,comp);
		MergeSort(arr, mid + 1, high,comp);
		Merge(arr, low, mid, mid + 1, high,comp);
	}
}
template <class T>
void Sistema::Merge(Array<T> &arr, int left_low, int left_high, int right_low, int right_high, Comparador<T> comp)
{
	int length = right_high - left_low + 1;
	Array<T> temp(length);
	int left = left_low;
	int right = right_low;

	for (int i = 0; i < length; ++i) {
		
		if (left > left_high)
			temp[i] = arr[right++];
		
		else if (right > right_high)
			temp[i] = arr[left++];
		
		else if (comp.EsMenor(arr[left] ,arr[right]) || comp.SonIguales(arr[left], arr[right]))
			temp[i] = arr[left++];
		
		else
			temp[i] = arr[right++];
	}

	for (int i = 0; i< length; ++i)
		arr[left_low++] = temp[i];
}

// Ejercicio 1: ordenamiento
template <class T>
void Sistema::Ordenar(Array<T>& elementos, const Comparador<T>& comp)
{
	// Use un mergesort
	// se subdivide el array en 2, high y low y se ordena cada subarray
	// luego se mergean los resultados
	
	MergeSort(elementos, 0, elementos.Largo - 1, comp);
}

///////////////////////////////////////////////////////////////////////////
template<class T>
int Sistema::BusquedaBinaria(const Array<T>& elementos, int min, int max, const T& elem, const Comparador<T>& comp)
{
	if (min > max) return -1;
	int medio = (min + max) / 2;

	if (comp.EsMenor(elementos[medio],elem))
	{
		//busco a la der
		return BusquedaBinaria(elementos, medio + 1, max, elem, comp);

	}else if (comp.EsMenor(elem, elementos[medio]))
	{
		//busco a la izq
		return BusquedaBinaria(elementos, min, medio-1, elem, comp);

	}else if (comp.SonIguales(elem, elementos[medio]))
	{
		return medio;
	}
	return -1;
}
// Operación 2: Búsqueda
template <class T>
int Sistema::Busqueda(const Array<T>& elementos, const T& elem, const Comparador<T>& comp)
{
	return BusquedaBinaria(elementos, 0, elementos.Largo, elem, comp);
}

// Operación 3: TAD Pila
template <class T>
Puntero<Pila<T>> Sistema::CrearPilaSimplementeEncadenada(nat tamano)
{
	return new PilaLista<T>(tamano);
}

template <class T>
Puntero<Pila<T>> Sistema::CrearPilaArray(nat tamano)
{
	return new PilaArray<T>(tamano);
}

template <class T>
bool Sistema::Iguales(const Puntero<Pila<T>>& pila1, const Puntero<Pila<T>>& pila2, const Comparador<T>& comp)
{
	Iterador<T> itPila1 = pila1->ObtenerIterador();
	Iterador<T> itPila2 = pila2->ObtenerIterador();

	while(itPila1.HayElemento())
	{
		if (!itPila2.HayElemento())
			return false;

		if (!comp.SonIguales(itPila1.ElementoActual(), itPila2.ElementoActual()))
			return false;

		itPila1.Avanzar();
		itPila2.Avanzar();
	}
	
	if (!itPila1.HayElemento() && itPila2.HayElemento())
		return false;
	
	return true;
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