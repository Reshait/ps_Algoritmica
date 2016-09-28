#include <iostream>
#include <cstdlib>
#include "datosEntrada.hpp"
#include "cabecera.hpp"

//DNI ...1L --> opción del determinante.

int main(){
	DatosEntrada Entrada;
	cabecera(1);	

	Entrada.pideDatos();
	Entrada.imprimeDatos();
}
