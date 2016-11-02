#include <iostream>
#include <vector>	
#include <time.h>
#include "conjunto.hpp"
#include "cabecera.hpp"
#include "otrasFunciones.hpp"

using namespace std;

int main()
{
	int nLlamadas = 0, min = 0, max = 0, nElementos, opcion;

	do{

		cabecera(3);
		opcion = menu();

		if(opcion){
			cabecera(3);

			pideNumeroElementos(nElementos);

			Conjunto<int> ConjuntoEnteros(nElementos);

			ConjuntoEnteros.imprime();

			ConjuntoEnteros.MaximoMinimo(0, nElementos-1, max, min, nLlamadas);

			cout << "El Maximo es..:\t" << max << endl;
			cout << "El Mínimo es..:\t" << min << endl;
			cout << "Llamadas R ..:\t" << nLlamadas << endl;
				
			introParaContinuar();

		}

		else{	
			system("clear");
			cabecera(3);
			cout << "Saliendo ..." << endl;
		}

	}while(opcion != 0);

}