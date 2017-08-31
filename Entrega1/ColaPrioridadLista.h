#pragma once
#include "ColaPrioridad.h"
#include "ListaOrd.h"
#include "NodoPQueue.h"

template <class T, class P>
class ColaPrioridadLista : public ColaPrioridad<T,P>
{
private:
	Puntero<ListaOrd<NodoPQueue<T, P>>> pQueue;
	Comparador<T> compDato;
	nat maximaCantidad;

	NodoPQueue<T, P>& Buscar(const T &elem);
	ColaPrioridadLista(Puntero<ListaOrd<NodoPQueue<T, P>>> cola, Comparador<T> comparadorDato, nat max);
public:
	~ColaPrioridadLista(){}
	ColaPrioridadLista(nat max,
		Comparador<P> compPrioridad = Comparador<P>::Default,
		Comparador<T> comparadorDato = Comparador<T>::Default);

	// PRE: -
	// POS: Encola el elemento e con prioridad p
	void Encolar(const T& e, const P& p) override;

	// PRE: La cola no está vacía
	// POS: Retorna el elemento de mayor prioridad en la cola eliminándolo
	const T& Desencolar() override;

	// PRE: La cola no está vacía
	// POS: Retorna el elemento de mayor prioridad en la cola sin eliminarlo
	const T& Cabeza() const override;

	// PRE: -
	// POS: Retorna el largo de la cola
	nat Largo() const override;

	// PRE: El elemento e está en la cola
	// POS: Retorna la instancia del elemento de mayor prioridad dentro de la cola.
	const T& ObtenerPrioridad(const T& e) const override;

	// PRE: -
	// POS: Retorna true si y solo si el elemento e pertenece a la cola.
	bool Pertenece(const T& e) const override;

	// PRE: -
	// POS: Retorna true si y solo si la cola esta vacia
	bool EstaVacia() const override;

	// PRE: -
	// POS: Retorna true si y solo si la cola esta llena
	bool EstaLlena() const override;

	// PRE: -
	// POS: Retorna un clon de la cola que no comparte memoria con ella
	Puntero<ColaPrioridad<T, P>> Clon() const override;

	// Retorna un nuevo iterador sobre la estructura
	// Postcondición: El iterador se encuentra reiniciado
	Iterador<T> ObtenerIterador() const override;
};

#include "ColaPrioridadLista.cpp"
