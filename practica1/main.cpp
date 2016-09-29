#include <iostream>
#include <cstdlib>
#include <time.h>
#include "datosEntrada.hpp"
#include "cabecera.hpp"
#include "matriz.hpp"

//DNI ...1L --> opción del determinante.

int main(){
    srand(time(NULL));

	DatosEntrada Entrada;
	cabecera(1);	

	Entrada.pideDatos();
	Entrada.imprimeDatos();

	Matriz matrizMinima(Entrada.getMin());
	matrizMinima.imprimeMatriz();
	cout << "El determinante correspondiente es..: " << matrizMinima.calculaDeterminante() << endl;
	
}
