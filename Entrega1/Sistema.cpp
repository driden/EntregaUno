#ifndef SISTEMA_CPP
#define SISTEMA_CPP

#include "Sistema.h"

Sistema::Sistema()
{
}
Sistema::~Sistema()
{
}

// Ejercicio 1: ordenamiento
void Sistema::OrdenarEnteros(Array<int>& elementos)
{
	//Como el arreglo es de enteros pares, entonces puedo crear otro arreglo con el siguiente formato
	// n, [# ocurrencias de n], n*2, [# de ocurrencias de n*2]
	// luego puedo volver a elementos dejarlo ordenado

	Array<int> arr(6002, 0);

	// recorro elementos y voy populando 'arr' con los valores
	foreach(int elem, elementos.ObtenerIterador())
	{
		//Aumento en uno el "contador" de ocurrencias de elem en elementos
		arr[elem + 1] += 1;
	}

	// Recorro los impares y se cuantas veces aparecio el par "anterior"
	// el numero "i" ocurrio arr[i-1] veces
	//Itero en los impares
	int arrLargo = arr.Largo;
	int iterElementos = 0;
	for (int i = 1; i < arrLargo; i += 2)
	{
		//std::cout << "cantidad de veces que aparece " << i - 1 << ":  " << arr[i] << endl;
		// cantidad es la cantidad de veces que esta el i-1
		for (int cantidad = 0; cantidad < arr[i]; cantidad++)
		{
			elementos[iterElementos + cantidad] = i - 1;
			
		}
		
		// recalculo el offset para la siguiente pasada
		if(arr[i] > 0)
			iterElementos += arr[i];		
	}
}

// Operación 2: Búsqueda
bool Sistema::ExisteSuma(const Array<int>& elementos, int suma)
{
	// Copio el array de entrada porque elementos es constante
	Array<int> copia(elementos.Largo);
	Array<int>::Copiar(elementos, copia);

	// Ordeno el array
	Ordenar<int>(copia, Comparador<int>::Default);

	int largoCopia = copia.Largo;
	for (int i = 0; i < largoCopia;i++)
	{
		Array<int> copiaSinI(copia.Largo - 1);
		Array<int>::Copiar(copia, 0, i, copiaSinI, 0);
		Array<int>::Copiar(copia, i+1, copiaSinI, i);

		int aBuscar = suma - copia[i];
		int res = Busqueda<int>(copiaSinI, aBuscar, Comparador<int>::Default);

		if (res != -1) return true;
	}
	return false;
}

// Operacion 4: Cadenas
Array<Cadena> Sistema::Split(const Cadena& origen, char delimiter)
{
	return Array<Cadena>();
}
Cadena Sistema::Reverso(const Cadena& origen)
{
	return Cadena("");
}

#endif