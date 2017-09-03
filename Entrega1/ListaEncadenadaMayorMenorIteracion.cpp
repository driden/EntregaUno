#ifndef  LISTA_ENCADENADA_MAYOR_MENOR_ITERACION_CPP
#define LISTA_ENCADENADA_MAYOR_MENOR_ITERACION_CPP

#include "ListaEncadenadaMayorMenorIteracion.h"


template <class T>
ListaEncadenadaMayorMenorIteracion<T>::ListaEncadenadaMayorMenorIteracion(const ListaOrdMayorAMenor<T> listaAIterar,
	nat posicion)
{
	principioLista = listaAIterar;
	this->posicion = posicion;
}

template <class T>
::ListaEncadenadaMayorMenorIteracion<T>::ListaEncadenadaMayorMenorIteracion(const ListaOrdMayorAMenor<T> listaAiterar)
	:principioLista(listaAiterar)
{
	posicion = 0;
}

template <class T>
bool ListaEncadenadaMayorMenorIteracion<T>::HayElemento() const
{
	return principioLista.Largo() > posicion;
}

template <class T>
const T& ListaEncadenadaMayorMenorIteracion<T>::ElementoActual() const
{
	return principioLista.Obtener(posicion);
}

template <class T>
void ListaEncadenadaMayorMenorIteracion<T>::Avanzar()
{
	posicion++;
}

template <class T>
void ListaEncadenadaMayorMenorIteracion<T>::Reiniciar()
{
	posicion = 0;
}

template <class T>
Puntero<Iteracion<T>> ListaEncadenadaMayorMenorIteracion<T>::Clonar() const
{
	return new ListaEncadenadaMayorMenorIteracion(*this);
}


#endif
