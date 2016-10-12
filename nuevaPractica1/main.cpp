#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "cabecera.hpp"
#include "funcionesGenerales.hpp"
#include "tiempo.hpp"


//DNI ...1L --> opción del determinante.
using namespace std;

int main(){
	Clock Cronometro;
	srand(time(NULL));
	
	vector<double> vTiemposObservados, vTiemposEstimados, vAs;
	int valorMin, valorMax, valorInc, tamCramer, opcion;
    
	do{

		cabecera(1);
		cout << "1.- Para realizar el apartado de las matrices." << endl;
		cout << "2.- Para realizar el apartado de fibonacci." << endl;
		cout << "0.- Para Salir." << endl;
		cout << "\tIntroduzca una opción >> ";
		cin >> opcion;
		getchar();

		vTiemposObservados.clear();
		vTiemposEstimados.clear();
		vAs.clear();


		switch(opcion){
			
			case 1:
				cabecera(1);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ APARTADO DE MATRICES ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━┛" << endl;	
				
				pideDatos(valorMin, valorMax, valorInc);

				for(int i = valorMin; i <= valorMax; i += valorInc){
					Cronometro.start();
					generaMatrizValoresAleatorios(i);
					Cronometro.stop();					
					
					cout << "Han transcurrido..:\t" << Cronometro.elapsed() << " µs" << endl;
					
					vTiemposEstimados.push_back(Cronometro.elapsed());		
					cout << endl;
				}

				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposEstimados);

				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				cin.ignore().get();

				break;


			case 2:
				cabecera(1);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ APARTADO DE FIBONACCI ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
				
				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				cin.ignore().get();

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
				cin.ignore().get();
				break;	
		}

	}while(opcion != 0);	


	return 0;

}
