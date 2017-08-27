#pragma once

#include "ListaOrd.h"

template <class T>
class ListaEncadenadaImp :
	public ListaOrd<T>
{
	template <class T>
	struct NodoLista
	{
		T _data;
		Puntero<NodoLista<T>> _sig;
	};
private:
	Puntero<NodoLista<T>> lista;
	nat cantidadElementos;
	Comparador<T> comparador;

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