#include <iostream>
#include <vector>	
#include <time.h>
#include "conjunto.hpp"
#include "cabecera.hpp"

using namespace std;



int main()
{
	int nLlamadas = 0, min, max, nElementos;
	srand(time(NULL));

	cabecera(3);
	
	do{
		cout << "Introduzca el número de nElementos del vector" << endl;
		cin >> nElementos;

		if(nElementos <= 1)
			cout << "Error numero de nElementos" << endl;

	}while(nElementos <= 1);


//	MaximoMinimo(v, nElementos, 0, nElementos-1, max, min, nLlamadas); 

	cout << "El maximo es " << max << " y el minimo " << min << endl;
	cout << "Se han realiado " << nLlamadas << " llamadas recursivas" << endl;
	

}