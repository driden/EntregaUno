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

	// PRE: -
	// POS: crea una ListaArrauIteracion conociendo la lista a iterar y el tope que tiene
	//		Usado para clonar el iterador
	ListaArrayIteracion(const ListaArrayImp<T> listaOrd, nat tope);
public:
	~ListaArrayIteracion(){}
	
	// PRE: 
	// POS: Crea una nueva instancia de ListaArrayIteracion pasando la ListaArrayImp a iterar
	ListaArrayIteracion(const ListaArrayImp<T> listaOrd);	

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

