#ifndef PILAARRAY_CPP
#define PILAARRAY_CPP

#include "PilaArray.h"

template <class T>
PilaArray<T>::PilaArray(Array<T> pila, nat max, nat top)
{
	arreglo = pila;
	maximo = max;
	tope = top;
}

template <class T>
PilaArray<T>::PilaArray()
{
	arreglo = Array<T>(maximo);
	tope = 1;
	maximo = 5;
}

template <class T>
void PilaArray<T>::Push(const T& e)
{
	// Si el tope es igual al Largo -1 entonces hago otro array mas largo
	if (tope == arreglo.Largo - 1)
	{
		maximo = maximo * 2;
		Array<T> nuevoArray = Array<T>(maximo);
		Array<T>::Copiar(arreglo, nuevoArray, 0);

		arreglo = nullptr;
		arreglo = nuevoArray;
	}
	tope++;

	arreglo[tope] = e;
}

template <class T>
const T& PilaArray<T>::Top() const
{
	return arreglo[tope];
}

template <class T>
void PilaArray<T>::Pop()
{
	return arreglo[tope--];
}

template <class T>
bool PilaArray<T>::EstaLlena() const
{
	return tope == arreglo.Largo - 1;
}

template <class T>
bool PilaArray<T>::EstaVacia() const
{
	return tope == -1;
}

template <class T>
Puntero<Pila<T>> PilaArray<T>::Clon() const
{
	Array<T> copia = Array<T>(maximo);
	Array<T>::Copiar(arreglo, copia, 0);

	return new PilaArray(arreglo, maximo, tope);
}


#endif
