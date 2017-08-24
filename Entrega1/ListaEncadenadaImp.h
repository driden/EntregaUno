#pragma once

#include "ListaOrd.h"
#include "NodoLista.h"

template <class T>
class ListaEncadenadaImp :
	public ListaOrd<T>
{

private:
	NodoLista _lista;
	nat _cantidadElmentos;
	Comparador<T> _comparador;

public:
	~ListaEncadenadaImp() {}

	ListaEncadenadaImp(const Comparador<T>& comp);

	void InsertarOrdenado(const T& e) override;

};
#include "ListaEncadenadaImp.cpp"