#pragma once
#include "ListaOrd.h"
#include "Array.h"

template <class T>
class ListaArrayImp : public ListaOrd<T>
{
private: 
	nat tamanio;
	Array<T> lista;
	int tope;
	Comparador<T> comparador;

	// PRE: el elemento e se encuentra en la lista
	// POS: devuelve el indice en el que se encuentra e o -1 si no se encuentra
	int IndexOf(const T& e) const;
	
	// PRE: -
	// POS: Crea una nueva listaArray con el tamanio, un arreglo, el tope, y el comparador 
	ListaArrayImp(nat size, Array<T> arr, int tope, const Comparador<T> comp);
public:
	~ListaArrayImp(){}
	
	// PRE: -
	// POS: Crea una nueva instancia de ListaArrayImp con un tamanio y un comparador dado	
	ListaArrayImp(const nat &tamanio, Comparador<T> comparador);
	
	// PRE: -
	// POS: Crea una nueva instancia de ListaArrayImp con comparador dado, se asume un maximo internamente
	ListaArrayImp(const Comparador<T>& comp);
	
	// PRE: Est� ordenada
	// POS: e pertenece a la lista. La lista est� ordenada y contiene todos los elementos que hab�a en la lista antes de la inserci�n
	void InsertarOrdenado(const T& e) override;

	// PRE: La lista no est� vac�a
	// POS: Retorna el primer elemento de la lista
	const T& Cabeza() const override;

	// PRE: -
	// POS: Elimina una ocurrencia del elemento de la lista si existe. De no existir no tiene acci�n.
	void Eliminar(const T& e) override;

	// PRE: -
	// POS: Retorna el largo de la lista
	nat Largo() const override;

	// PRE: La lista tiene un elemento en la posici�n n. 
	// POS: Retorna el elemento que est� en esa posici�n de la lista. El primer elemento empieza en 0.
	const T& Obtener(const nat n) const override;

	// PRE: -
	// POS: Retorna true si y solo si el elemento e pertenece a la lista.
	bool Pertenece(const T& e) const override;

	// PRE: -
	// POS: Retorna true si y solo si la lista esta vacia
	bool EstaVacia() const override;

	// PRE: -
	// POS: Retorna un clon de la lista que no comparte memoria con ella
	Puntero<ListaOrd<T>> Clon() const override;

	// PRE:
	// POS: Retorna un iterador de la lista
	Iterador<T> ObtenerIterador() const override;	
};
#include "ListaArrayImp.cpp"
