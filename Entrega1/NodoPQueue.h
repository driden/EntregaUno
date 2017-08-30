#pragma once
template <class T, class P>
class NodoPQueue
{
private:
	T elemento;
	P prioridad;
public:
	~NodoPQueue(){};
	NodoPQueue(const T &elem, const P &prioridad);

	T& GetElemento();
	P& GetPrioridad();
	void SetElemento(const T &elem);
	void SetPrioridad(const P &prio);
};

#include "NodoPQueue.cpp"

