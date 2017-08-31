#pragma once

#include "ListaOrd.h"
#include "NodoLista.h"

template <class T>
class ListaEncadenadaImp :
	public ListaOrd<T>
{
private:
	Puntero<NodoLista<T>> lista;
	nat cantidadElementos;
	Comparador<T> comparador;

	ListaEncadenadaImp(const Puntero<NodoLista<T>>& aClonar, nat& cantidadElem, Comparador<T> comp);

	// Clona la lista recursivamente
	// PRE:
	// POST: se genera una copia de la lista aClonar en memoria
	typename Puntero<NodoLista<T>> ListaEncadenadaImp<T>::ClonRecursivo(const Puntero<NodoLista<T>>& aClonar, nat& cantidadElem) const;

public:
	~ListaEncadenadaImp() {}

	ListaEncadenadaImp(const Comparador<T>& comp);	

	void InsertarOrdenado(const T& e) override;

	const T& Cabeza() const override;

	void Eliminar(const T& e) override;

	nat Largo() const override;

	const T& Obtener(const nat n) const override;

	bool Pertenece(const T& e) const override;

	bool EstaVacia() const override;

	Puntero<ListaOrd<T>> Clon() const override;

	Iterador<T> ObtenerIterador() const override;	
};

#include "ListaEncadenadaImp.cpp"