﻿#pragma once

#include "Pila.h"
#include "Array.h"

template <class T>
class PilaArray : public Pila<T>
{
private:
	Array<T> arreglo;
	nat maximo, tope;

	PilaArray(Array<T> pila, nat max, nat tope);
public:
	~PilaArray() {}
	PilaArray();

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
};

#include "PilaArray.cpp"
