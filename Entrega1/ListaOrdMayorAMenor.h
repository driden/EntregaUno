#pragma once
#include "ListaOrd.h"
#include "NodoLista.h"

template <class T>
class ListaOrdMayorAMenor: public ListaOrd<T>
{
private:
	Puntero<NodoLista<T>> lista;
	nat cantidadElementos;
	Comparador<T> comparador;
	ListaOrdMayorAMenor(const Puntero<NodoLista<T>>& aClonar, nat& cantidadElem, Comparador<T> comp);

	Puntero<NodoLista<T>> ClonRecursivo(const Puntero<NodoLista<T>>& aClonar, nat& cantidadElem) const;
	public:
	~ListaOrdMayorAMenor(){}
	
	ListaOrdMayorAMenor(Comparador<T> comp = Comparador<T>::Default);

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

#include "ListaOrdMayorAMenor.cpp"