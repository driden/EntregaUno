#pragma once
#include "ListaOrd.h"

template <class T>
class ListaEncadenadaImp :
	public ListaOrd<T>
{
private:
	struct Nodo
	{
		T data;
		Puntero<Nodo> _sig;
	};
public:
	~ListaEncadenadaImp() {}
};


