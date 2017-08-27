#include "CasoDePrueba.h"
#include "PruebaMemoria.h"
#include "ConductorPrueba.h"
#include "Sistema.h"

#include "ListaEncadenadaImp.h"
#include "ListaEncadenadaIteracion.h"
#include "Comparador.h"

Puntero<Sistema> Inicializar()
{
	return new Sistema();
}

void main()
{
	/*Puntero<ConductorPrueba> cp = new ConductorPrueba();
	Array<Puntero<Prueba>> pruebas = Array<Puntero<Prueba>>(3);
	pruebas[0] = new PruebaMemoria();
	pruebas[1] = new CasoDePrueba(Inicializar);
	pruebas[2] = pruebas[0];
	cp->CorrerPruebas(pruebas.ObtenerIterador());*/

	Comparador<int> comp = Comparador<int>();

	Puntero<ListaOrd<int>> miLista = new ListaEncadenadaImp<int>(comp);
	cout << "Agrego los numeros 5, 4, 6, 3, 2, 1 a la lista" << endl;
	miLista->InsertarOrdenado(5);
	miLista->InsertarOrdenado(4);
	miLista->InsertarOrdenado(6);
	miLista->InsertarOrdenado(3);
	miLista->InsertarOrdenado(2);
	miLista->InsertarOrdenado(1);

	Iterador<int> iter = miLista->ObtenerIterador();
	
	while (iter.HayElemento()) {
		cout << iter.ElementoActual() << ", ";
		iter.Avanzar();
	}

	cout << endl;
	system("pause");
}
