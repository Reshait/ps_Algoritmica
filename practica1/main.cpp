#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <cstdlib> // para los systems
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
    
	vector<double> vectorTi, vectorZi, vectorZi_Ti, vectorAs, vectorTe; //vectores usados en ambas opciones
	DatosEntrada Entrada;
	int opcion;

	do{

		cabecera(1);
		cout << "1.- Para realizar el apartado de las matrices." << endl;
		cout << "2.- Para realizar el apartado de fibonacci." << endl;
		cout << "0.- Para Salir." << endl;
		cout << "\tIntroduzca una opción >> ";
		cin >> opcion;
		getchar();

		vectorTi.clear();
		vectorZi.clear();
		vectorZi_Ti.clear();
		vectorAs.clear();
		vectorTe.clear();

		switch(opcion){
			
			case 1:
				cabecera(1);
				
				Entrada.pideDatos();
					// Entrada.imprimeDatos();
				
				for(int i = Entrada.getMin(); i < Entrada.getMax(); i = i + Entrada.getInc()){
					Cronometro.start();
						Matriz matrizMinima(i);
						cout << endl << "Su matriz aleatoria de tamaño " << matrizMinima.getTam() << "x" << matrizMinima.getTam() << " es:" << endl;
						matrizMinima.imprimeMatriz();
						cout << endl << "El determinante es..:\t" << matrizMinima.calculaDeterminante() << endl;
					Cronometro.stop();
						cout << "Han transcurrido..:\t" << Cronometro.elapsed() << " µs" << endl; 
					vectorTi.push_back(Cronometro.elapsed());
					vectorZi.push_back(i);
				}

				cout << endl << "El vector de tiempos registrados es..:" << endl;
				imprimeVectorTiempos(vectorTi);
				cout << endl;

				cout << endl << "El vector de Nis registrados es..:" << endl;
				imprimeVectorTiempos(vectorZi);
				cout << endl;


Cramer2(vectorZi, vectorTi, vectorAs);
cout << endl;
				
				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");

				break;


			case 2:
				cabecera(1);

				cout << endl;
				Entrada.pideDatos();
				cout << endl;

				for(int i = Entrada.getMin(); i <= Entrada.getMax(); i = i + Entrada.getInc()){
					Cronometro.start();
					cout << "El valor resultante a Fibonacci " << i << " es..: " << fibonacci(i) << endl;		
					Cronometro.stop();
					cout << "Han transcurrido..:\t" << Cronometro.elapsed() << " µs" << endl; 

					vectorTi.push_back(Cronometro.elapsed());	//Vector de tiempos registrados
					vectorZi.push_back(pow(2,i));						//Vector que contiene "Zi"s Zi = 2^ni
				}

				cout << endl << "El vector de Zis es..:" << endl;
				imprimeVectorTiempos(vectorZi);
				cout << endl;

				Cramer(vectorZi, vectorTi, vectorAs);

				cout << endl << "El vector de As es..:" << endl;
				imprimeVectorTiempos(vectorAs);
				cout << endl;	

				cout << endl << "El vector de tiempos registrados es..:" << endl;
				imprimeVectorTiempos(vectorTi);
				cout << endl;

				cout << endl << "El vector de Tiempos estimados es..:" << endl;
				for(int	i = 0; i < vectorZi.size(); i++)
					vectorTe.push_back(vectorAs.at(0) + vectorAs.at(1) * vectorZi.at(i));
				imprimeVectorTiempos(vectorTe);
				cout << endl << endl;

				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");

				break;

			case 0:
				system("clear");
				cabecera(1);

				cout << "Saliendo ..." << endl;
				break;	

			default:
				cabecera(1);
				cout << "Opción introducida incorrecta." << endl;
				cout << "Pulse intro para continuar..." << endl;
				system("read");
				break;	
		}

	}while(opcion != 0);	


	return 0;

}
