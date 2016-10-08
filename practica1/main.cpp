#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "datosEntrada.hpp"
#include "cabecera.hpp"
#include "matriz.hpp"
#include "fibonacci.hpp"
#include "tiempo.hpp"

//DNI ...1L --> opción del determinante.
using namespace std;
	
int main(){
	Clock Cronometro;
    srand(time(NULL));
    
	std::vector<double> tiemposEstimados, vectorTi, vectorNi, vectorNi_Ti, vectorAs;
	DatosEntrada Entrada;
	cabecera(1);	

//	Entrada.pideDatos();
	// Entrada.imprimeDatos();

/*
	for(int i = Entrada.getMin(); i < Entrada.getMax(); i = i + Entrada.getInc()){
		Cronometro.start();
			Matriz matrizMinima(i);
			cout << endl << "Su matriz aleatoria de tamaño " << matrizMinima.getTam() << "x" << matrizMinima.getTam() << " es:" << endl;
			matrizMinima.imprimeMatriz();
			cout << endl << "El determinante es..:\t" << matrizMinima.calculaDeterminante() << endl;
		Cronometro.stop();
			cout << "Han transcurrido..:\t" << Cronometro.elapsed() << " µs" << endl; 
		tiemposRegistrados.push_back(Cronometro.elapsed());
	}

	cout << endl << "El vector de tiempos registrados es..:" << endl;
	imprimeVectorTiempos(tiemposRegistrados);
	cout << endl;
*/
	cout << endl;
	Entrada.pideFibonacci();
	cout << endl;

	for(int i = 0; i <= Entrada.getFib(); i++){
		Cronometro.start();
		cout << "El valor resultante a Fibonacci " << i << " es..: " << fibonacci(i) << endl;		
		Cronometro.stop();
		cout << "Han transcurrido..:\t" << Cronometro.elapsed() << " µs" << endl; 

		vectorTi.push_back(Cronometro.elapsed());	//Vector de tiempos registrados
		vectorNi.push_back(i);						//Vector que contiene "ni"s
	}

	cout << endl << "El vector de tiempos registrados es..:" << endl;
	imprimeVectorTiempos(vectorTi);
	cout << endl;

	cout << endl << "El vector de nis es..:" << endl;
	imprimeVectorTiempos(vectorNi);
	cout << endl;

	Cramer(vectorNi, vectorTi, vectorAs);

	cout << endl << "El vector de As es..:" << endl;
	imprimeVectorTiempos(vectorAs);
	cout << endl;	

}
