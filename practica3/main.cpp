#include <iostream>
#include <vector>	
#include <time.h>
#include "conjunto.hpp"
#include "cabecera.hpp"
#include "otrasFunciones.hpp"

using namespace std;

int main()
{
	int nComparaciones = 0, min = 0, max = 0, nElementos, opcion;

	do{

		cabecera(3);
		opcion = menu();

		if(opcion){
			cabecera(3);

			pideNumeroElementos(nElementos);

			Conjunto<int> ConjuntoEnteros(nElementos);

			ConjuntoEnteros.imprime();

			ConjuntoEnteros.MaximoMinimo(0, nElementos-1, max, min, nComparaciones);

			cout << "El Maximo es..:\t" << max << endl;
			cout << "El Mínimo es..:\t" << min << endl;
			cout << "Comparacions..:\t" << nComparaciones << endl;

			if(ConjuntoEnteros.compruebaMaximoEsMaximo(max)){
				system("tput setaf 2");	
				cout << "Se confirma que el máximo escogido es el máximo del conjunto" << endl;
				system("tput sgr0");
			}
			else{
            	system("tput setaf 1");				
				cout << "El máximo escogido NO es el máximo del conjunto" << endl;
				system("tput sgr0");
			}


			if(ConjuntoEnteros.compruebaMinimoEsMinimo(min)){
				system("tput setaf 2");	
				cout << "Se confirma que el minimo escogido es el minimo del conjunto" << endl;
				system("tput sgr0");
			}
			else{
				system("tput setaf 1");
				cout << "El mínimo escogido NO es el mínimo del conjunto" << endl;
				system("tput sgr0");
			}							
			introParaContinuar();

		}

		else{	
			system("clear");
			cabecera(3);
			cout << "Saliendo ..." << endl;
		}

	}while(opcion != 0);

}