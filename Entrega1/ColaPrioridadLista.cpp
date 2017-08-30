#ifndef COLAPRIORIDADLISTA_CPP
#define COLAPRIORIDADLISTA_CPP

#include "ColaPrioridadLista.h"
#include "ListaEncadenadaImp.h"

template <class T, class P>
NodoPQueue<T, P> ColaPrioridadLista<T, P>::Buscar(const T& elem)
{
	Iterador<ListaOrd<NodoPQueue<T, P>>> iter = pQueue->ObtenerIterador();
	
	while (iter.HayElemento() && compDato.SonDistintos(elem,iter.ElementoActual()))
	{
		iter.Avanzar();
	}

	return iter.ElementoActual();
}

template <class T, class P>
ColaPrioridadLista<T, P>::ColaPrioridadLista(Puntero<ListaOrd<NodoPQueue<T, P>>> cola, Comparador<T> comparadorDato,
	nat max)
{
	pQueue = cola;
	compDato = comparadorDato;
	maximaCantidad = max;
}

template <class T, class P>
ColaPrioridadLista<T, P>::ColaPrioridadLista(const Comparador<P> &compPrioridad, const Comparador<T> comparadorDato, nat max)	
{
	pQueue = new ListaEncadenadaImp<NodoPQueue<T, P>>(compPrioridad);
	compDato = comparadorDato;
	maximaCantidad = max;
}


template <class T, class P>
void ColaPrioridadLista<T, P>::Encolar(const T& e, const P& p)
{
	NodoPQueue<T, P> nodo(e, p);
	pQueue->InsertarOrdenado(nodo);
}

template <class T, class P>
const T& ColaPrioridadLista<T, P>::Desencolar()
{
	NodoPQueue<T, P> nodo = pQueue->Obtener(0);
	T valor = nodo.GetElemento();
	pQueue->Eliminar(valor);
	return valor;
}

template <class T, class P>
const T& ColaPrioridadLista<T, P>::Cabeza() const
{
	return pQueue->Cabeza();
}

template <class T, class P>
const T& ColaPrioridadLista<T, P>::ObtenerPrioridad(const T& e) const
{
	NodoPQueue<T, P> nodo = Buscar(e);
	T prioridad = nodo.GetPrioridad();
	return prioridad;
}

template <class T, class P>
bool ColaPrioridadLista<T, P>::Pertenece(const T& e) const
{
	return pQueue->Pertenece(e);
}

template <class T, class P>
bool ColaPrioridadLista<T, P>::EstaVacia() const
{
	return pQueue->EstaVacia();
}

template <class T, class P>
bool ColaPrioridadLista<T, P>::EstaLlena() const
{
	return pQueue->Largo() == maximaCantidad;
}

template <class T, class P>
Puntero<ColaPrioridad<T, P>> ColaPrioridadLista<T, P>::Clon() const
{
	Puntero<ListaOrd<NodoPQueue<T, P>>> cola = pQueue->Clon();
	return new ColaPrioridadLista(cola,compDato,maximaCantidad);
}

template <class T, class P>
Iterador<T> ColaPrioridadLista<T, P>::ObtenerIterador() const
{
	return nullptr;
}

template <class T, class P>
nat ColaPrioridadLista<T, P>::Largo() const
{
	return pQueue->Largo();
}
#endif
