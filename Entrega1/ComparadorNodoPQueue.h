#pragma once
#include "Comparacion.h"
#include "NodoPQueue.h"
#include "Comparador.h"

template <class T, class P>
class ComparadorNodoPQueue : Comparacion<NodoPQueue<T, P>>
{
private:
	Comparador<P> comparador;
public:
	~ComparadorNodoPQueue(){}
	explicit ComparadorNodoPQueue(Comparador<P> compPrioridad);

	CompRetorno Comparar(const NodoPQueue<T, P>& t1, const NodoPQueue<T, P>& t2) const override;
};


#include "ComparadorNodoPQueue.cpp"
