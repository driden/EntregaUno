#pragma once

#include "Iteracion.h"
#include "Pila.h"
#include "PilaLista.h"
#include "PilaArray.h"

template <class T>
class PilaIteracion :
	public Iteracion<T>
{
private:
	Puntero<Pila<T>> pila, clon;
public:
	~PilaIteracion(){}

	// PRE:
	// POS: crea una instancia de PilaIteracion
	PilaIteracion(const PilaArray<T>& pilaArr);

	// PRE:
	// POS: crea una instancia de PilaIteracion
	PilaIteracion(const PilaLista<T>& pilaList);

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
	Puntero<Iteracion<T>> Clonar() const override { return nullptr; }
};

#include "PilaIteracion.cpp"