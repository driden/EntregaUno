#pragma once

#include "Array.h"
#include "Pila.h"

template <class T>
class PilaArray : public Pila<T>
{
private:
	Array<T> arreglo;
	nat maximo;
	int tope;

	/// PRE:
	/// POS: Crea una nueva instancia de PilaArray, usado para cloanr la clase
	PilaArray(Array<T> pila, nat max, int tope);	
public:
	~PilaArray() {}
	
	/// PRE:
	/// POS: Crea una nueva instancia de PilaArray
	PilaArray();
	
	/// PRE:
	/// POS: Crea una nueva instancia de PilaArray
	PilaArray(const PilaArray<T> &pilaArray);
	
	/// PRE:
	/// POS: Crea una nueva instancia de PilaArray
	PilaArray(nat max);
	
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

	/// PRE: -
	/// POS: Obtiene un iterador de PilaArray
	Iterador<T> ObtenerIterador() const override;
};

#include "PilaArray.cpp"

