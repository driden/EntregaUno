#pragma once

template <class T>
struct NodoLista
{
	T _data;
	Puntero<NodoLista<T>> _sig;
};