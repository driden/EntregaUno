#ifndef NODOPQUEUE_H
#define NODOPQUEUE_H

#include "NodoPQueue.h"

template <class T, class P>
NodoPQueue<T, P>::NodoPQueue(const T& elem, const P& prio)	
{
	elemento = elem;
	prioridad = prio;	
}

template <class T, class P>
T& NodoPQueue<T, P>::GetElemento()
{
	return elemento;
}

template <class T, class P>
P& NodoPQueue<T, P>::GetPrioridad()
{
	return prioridad;
}

template <class T, class P>
void NodoPQueue<T, P>::SetElemento(const T& elem)
{
	elemento = elem;
}


template <class T, class P>
void NodoPQueue<T, P>::SetPrioridad(const P& prio)
{
	prioridad = prio;
}


#endif
