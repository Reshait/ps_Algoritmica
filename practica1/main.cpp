#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <fstream>
#include "cabecera.hpp"
#include "funcionesGenerales.hpp"
#include "cramer.hpp"
#include "tiempo.hpp"


//DNI ...1L --> opción del determinante.
using namespace std;

int main(){
//	std::ofstream fo;
	Clock Cronometro;
	srand(time(NULL));
	
	vector<double> vTiemposObservados, vTiemposEstimados, vAs;
	int valorMin, valorMax, valorInc, opcion;

	do{

		cabecera(1);

		opcion = menu();

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

				rellenaTiemposObservados(1, valorMin,valorMax,valorInc,vTiemposObservados);

				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				cramer(0, valorMin, valorMax, valorInc, 4, vTiemposObservados, vAs);

				calculaTiemposEstimados(valorMin, valorMax, valorInc, vTiemposEstimados, vAs);

				cout << "El vector de tiempos estimados es..: " << endl;
				imprimeVector(vTiemposEstimados);

				imprimeResultadosEnFichero(valorMin, valorInc, vTiemposObservados, vTiemposEstimados);

				system("./gnuplot.sh");

				introParaContinuar();

				break;


			case 2:
				cabecera(1);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ APARTADO DE FIBONACCI ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

				pideDatos(valorMin, valorMax, valorInc);

				rellenaTiemposObservados(2, valorMin,valorMax,valorInc,vTiemposObservados);

				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				cramer(1,  valorMin, valorMax, valorInc, 2, vTiemposObservados, vAs);

				cout << "Los tiempos estimados son..: " << endl;
				for(int i = valorMin; i <= valorMax; i += valorInc){
					vTiemposEstimados.push_back( vAs[0] + vAs[1] * pow(2,i) );
				}

//				calculaTiemposEstimados(pow(2,valorMin), pow(2,valorMax), valorInc, vTiemposEstimados, vAs);

				imprimeVector(vTiemposEstimados);

				imprimeResultadosEnFichero(valorMin, valorInc, vTiemposObservados, vTiemposEstimados);

				system("./gnuplot.sh");

				introParaContinuar();

				break;

			case 0:
				cabecera(1);

				cout << "Saliendo ..." << endl;
				break;	

			default:
				cabecera(1);
				cout << "Opción introducida incorrecta." << endl;
				introParaContinuar();
				break;	
		}

	}while(opcion != 0);	

	return 0;

}
