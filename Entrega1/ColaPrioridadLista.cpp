#include "ComparadorNodoPQueue.h"
#ifndef COLAPRIORIDADLISTA_CPP
#define COLAPRIORIDADLISTA_CPP

#include "ColaPrioridadLista.h"
#include "ListaEncadenadaImp.h"

template <class T, class P>
NodoPQueue<T, P>& ColaPrioridadLista<T, P>::Buscar(const T& elem)
{
	Iterador<NodoPQueue<T, P>> iter = pQueue->ObtenerIterador();
	
	while (iter.HayElemento() && compDato.SonDistintos(elem,iter.ElementoActual()))
	{
		iter.Avanzar();
	}

	NodoPQueue<T, P> nodo = iter.ElementoActual();

	return nodo;
}

template <class T, class P>
ColaPrioridadLista<T, P>::ColaPrioridadLista(Puntero<ListaOrd<NodoPQueue<T, P>>> cola, Comparador<T> comparadorDato,nat max)
{
	pQueue = cola;
	compDato = comparadorDato;
	maximaCantidad = max;
}

template <class T, class P>
ColaPrioridadLista<T, P>::ColaPrioridadLista(
	nat max,
	Comparador<P> compPrioridad, 
	Comparador<T> comparadorDato)
{
	Comparador<NodoPQueue<T,P>>c(new ComparadorNodoPQueue<T,P> (compPrioridad));
	
	pQueue = new ListaEncadenadaImp<NodoPQueue<T, P>>(c);

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
	//NodoPQueue<T, P> nodo = Buscar(0);
	//T valor = nodo.GetElemento();
	//pQueue->Eliminar(valor);
	//return valor;
	return T();
}

template <class T, class P>
const T& ColaPrioridadLista<T, P>::Cabeza() const
{
	NodoPQueue<T, P> nodo = (pQueue->Cabeza());
	T valor = nodo.GetElemento();
	return  valor;
}

template <class T, class P>
const T& ColaPrioridadLista<T, P>::ObtenerPrioridad(const T& e) const
{
	/*NodoPQueue<T, P>& nodo = nullptr;
	nodo = Buscar(e);
	T &elem = nodo.GetElemento();
	return elem;*/
	return T();
}

template <class T, class P>
bool ColaPrioridadLista<T, P>::Pertenece(const T& e) const
{
	Iterador<NodoPQueue<T, P>> iter = pQueue->ObtenerIterador();
	
	bool pertenece = false;
	
	while (iter.HayElemento() && !pertenece)
	{
		iter.Avanzar();
		NodoPQueue<T, P> actual = iter.ElementoActual();
		T t = actual.GetElemento();
		pertenece = compDato.SonDistintos(e,t);
	}

	return pertenece;
	
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
	Puntero<ColaPrioridad<T,P>> retorno = new ColaPrioridadLista(cola, compDato, maximaCantidad);
	return retorno;
}

template <class T, class P>
Iterador<T> ColaPrioridadLista<T, P>::ObtenerIterador() const
{
	Puntero<ListaOrd<NodoPQueue<T, P>>> cola = pQueue->Clon();

	return new ColaIteracion<T,P>(cola);
}

template <class T, class P>
nat ColaPrioridadLista<T, P>::Largo() const
{
	return pQueue->Largo();
}
#endif
