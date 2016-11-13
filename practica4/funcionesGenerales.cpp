#include <iostream>
#include "funcionesGenerales.hpp"


void introduzcaCantidadDeCambio(int &centimos){
	cout << "Introduzca la cantidad de euros de su cambio ..:" << endl;
	cin >> centimos;
}

void deCentimosAeuros(const int &centimos, double &euros){
	euros = centimos / 100.0;
}