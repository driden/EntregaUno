#pragma once
#pragma once

#include "Iterable.h"
#include "ListaOrdMayorAMenor.h"

template <class T>
class ListaEncadenadaMayorMenorIteracion: public Iteracion<T>
{
private:
	const ListaOrdMayorAMenor<T> principioLista;
	nat posicion;

	/// PRE: -
	/// POS: Crea una nueva instancia de ListaEncadenadaMayorMenorIteracion
	ListaEncadenadaMayorMenorIteracion(const ListaOrdMayorAMenor<T> listaAIterar, nat posicion);
public:
	~ListaEncadenadaMayorMenorIteracion(){}
	/// PRE: -
	/// POS: Crea una nueva instancia de ListaEncadenadaMayorMenorIteracion
	ListaEncadenadaMayorMenorIteracion(const ListaOrdMayorAMenor<T> listaAiterar);

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

#include "ListaEncadenadaMayorMenorIteracion.cpp"
