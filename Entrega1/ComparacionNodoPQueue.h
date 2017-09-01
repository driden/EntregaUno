#ifndef COMPARADORNODOPQUEUE_H
#define COMPARADORNODOPQUEUE_H
#include "Comparacion.h"
#include "NodoPQueue.h"
#include "Comparador.h"

template <class T, class P>
class ComparadorNodoPQueue : public Comparacion<NodoPQueue<T, P>>
{
private:
	Comparador<P> comparador;
public:
	~ComparadorNodoPQueue(){}
	ComparadorNodoPQueue(Comparador<P> compPrioridad = Comparador<P>::Default);

	CompRetorno Comparar(const NodoPQueue<T, P>& t1, const NodoPQueue<T, P>& t2) const override;
};

#include "ComparacionNodoPQueue.cpp"
#endif