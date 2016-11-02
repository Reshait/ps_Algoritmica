#ifndef __OTRAS_FUNCIONES_HPP__
#define __OTRAS_FUNCIONES_HPP__

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void pideNumeroElementos(int &nElementos){
	do{
		cout << "Introduzca el número de nElementos del vector" << endl;
		cin >> nElementos;

		if(nElementos <= 1)
			cout << "Error numero de nElementos" << endl;

	}while(nElementos <= 1);
}


#endif