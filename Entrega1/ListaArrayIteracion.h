#pragma once

#include "Iteracion.h"
#include "ListaArrayImp.h"

template <class T>
class ListaArrayIteracion :
	public Iteracion<T>
{
private:
	const ListaArrayImp<T> lista;
	nat tope;

	ListaArrayIteracion(const ListaArrayImp<T> listaOrd, nat tope);
public:
	~ListaArrayIteracion(){}
	ListaArrayIteracion(const ListaArrayImp<T> listaOrd);
	ListaArrayIteracion();

	// PRE:
	// POS: retorna true si hay un elemento para iterar.
	bool HayElemento() const override;

	// PRE:
	// POS: Devuelve el elemento sobre el cual se itera.
	const T& ElementoActual() const override;

	// PRE:
	// POS: avanza el iterador.
	void Avanzar() override;

	// PRE:
	// POS: reinicia el iterador
	void Reiniciar() override;

	// PRE:
	// POS: clona la iteracion sin compartir memoria.
	Puntero<Iteracion<T>> Clonar() const override;
};

#include "ListaArrayIteracion.cpp"

