#pragma once

#include "Pila.h"
#include "NodoLista.h"

template <class T>
class PilaLista : public Pila<T>
{
private:
	Puntero < NodoLista<T>> stack;
	nat cantidadElementos, capacidad;
	
	// PRE
	// POS: Crea una nueva instancia de PilaLista que no comparte memoria.
	PilaLista(Puntero<NodoLista<T>> pila, nat elementos, nat max);

	// Clona la lista que modela el stack
	// PRE
	// POS: La nueva lista no comparte memoria con la original
	Puntero<NodoLista<T>> ClonRecursivo(const Puntero<NodoLista<T>>& aClonar) const;
public:
	~PilaLista() {};
	
	// PRE
	// POS: Crea una nueva instancia de PilaLista
	PilaLista(nat capacidad);

	// PRE
	// POS: Crea una nueva instancia de PilaLista
	PilaLista(const PilaLista<T> &pilaLista);
	
	// Coloca el elemento e en el tope
	void Push(const T& e) override;

	// Retorna el tope de la pila
	const T& Top() const override;

	// Borra el tope de la pila
	void Pop() override;

	// PREDICADOS

	// Retorna true si y solo si la lista esta llena
	bool EstaLlena() const override;

	// Retorna true si y solo si la lista esta vacia
	bool EstaVacia() const override;

	//Retorna un clon de la pila que no comparte memoria con ella
	Puntero<Pila<T>> Clon() const override;	

	// PRE
	// POS: Devuelve un iterador de la PilaLista
	Iterador<T> ObtenerIterador() const override;
};
#include "PilaLista.cpp"