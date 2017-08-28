#pragma once

#include "Puntero.h"
template <class T>
struct NodoLista
{
	T _data;
	Puntero<NodoLista<T>> _sig;
};