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

//	Entrada.pideDatos();
//	Entrada.imprimeDatos();

//	Matriz M=new Matriz(3); 
	Matriz M(3);
	Matriz M2(3);

	M.imprimeMatriz();
	M2.imprimeMatriz();

}
