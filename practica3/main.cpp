#include <iostream>
#include <vector>	
#include <time.h>
#include "conjunto.hpp"
#include "cabecera.hpp"
#include "otrasFunciones.hpp"

using namespace std;



int main()
{
	int nLlamadas = 0, min = 0, max = 0, nElementos, i = 0, j = 0;
	srand(time(NULL));

	cabecera(3);
	
	pideNumeroElementos(nElementos);

	Conjunto<int> ConjuntoEnteros(nElementos);

	ConjuntoEnteros.imprime();

	ConjuntoEnteros.MaximoMinimo(i,j,max,min,nLlamadas);
//	ConjuntoEnteros.eliminaPosicion(3);

//	ConjuntoEnteros.imprime();

//	MaximoMinimo(v, nElementos, 0, nElementos-1, max, min, nLlamadas); 

	cout << "El maximo es " << max << " y el minimo " << min << endl;
	cout << "Se han realiado " << nLlamadas << " llamadas recursivas" << endl;
	

}