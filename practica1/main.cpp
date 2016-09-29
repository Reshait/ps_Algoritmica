#include <iostream>
#include <cstdlib>
#include <time.h>
#include "datosEntrada.hpp"
#include "cabecera.hpp"
#include "matriz.hpp"
#include "tiempo.hpp"

//DNI ...1L --> opción del determinante.
using namespace std;

int main(){
	Clock Cronometro;
    srand(time(NULL));

	DatosEntrada Entrada;
	cabecera(1);	

	Entrada.pideDatos();
	Entrada.imprimeDatos();

	Cronometro.start();
		Matriz matrizMinima(Entrada.getMin());
		matrizMinima.imprimeMatriz();
		cout << "El determinante correspondiente es..: " << matrizMinima.calculaDeterminante() << endl;
	Cronometro.stop();
		cout << "Han transcurrido..:\t" << Cronometro.elapsed() << "microsegundos" << endl; 
}
