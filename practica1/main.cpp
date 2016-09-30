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

	for(int i = Entrada.getMin(); i < Entrada.getMax(); i = i + Entrada.getInc()){
		Cronometro.start();
			Matriz matrizMinima(i);
			cout << endl << "Su matriz aleatoria de tamaño " << matrizMinima.getTam() << "x" << matrizMinima.getTam() << " es:" << endl;
			matrizMinima.imprimeMatriz();
			cout << endl << "El determinante es..:\t" << matrizMinima.calculaDeterminante() << endl;
		Cronometro.stop();
			cout << "Han transcurrido..:\t" << Cronometro.elapsed() << " µs" << endl; 
	}


}
