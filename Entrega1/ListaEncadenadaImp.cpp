#pragma once
#include "ListaEncadenadaImp.h"	

template<class T>
ListaEncadenadaImp<T>::ListaEncadenadaImp(const Comparador<T>& comp)
{
	_lista = nullptr;
	_cantidadElementos = 0;
	_comparador = comp;
}

template<class T>
void ListaEncadenadaImp<T>::InsertarOrdenado(const T & e)
{
	NodoLista nodo = new NodoLista{
		e, // _data
		nullptr; // _sig
	};
	
	if (_lista == nullptr) {
		_lista = nodo
	}
	else {
		NodoLista iter = this->_lista;

		while (iter->_sig != nullptr) {
			iter = iter->_sig;
		}
		
		iter->_sig = nodo;
	}

	this._cantidadElementos++;
};