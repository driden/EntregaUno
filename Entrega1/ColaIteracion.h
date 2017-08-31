#pragma once
#include "Iteracion.h"
#include "ColaPrioridadLista.h"
#include "NodoPQueue.h"

template <class T,class P>
class ColaIteracion : public Iteracion<T>
{
private:
	Puntero<ListaOrd<NodoPQueue<T, P>>> pQueue;
	Iterador<NodoPQueue<T, P>> colaIter;
public:
	~ColaIteracion(){}
	ColaIteracion(const Puntero<ListaOrd<NodoPQueue<T, P>>> &pqueue);

	bool HayElemento() const override;
	const T& ElementoActual() const override;
	void Avanzar() override;
	void Reiniciar() override;

	Puntero<Iteracion<T>> Clonar() const override{ return nullptr; }
};
#include "ColaIteracion.cpp"
