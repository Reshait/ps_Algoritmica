#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <fstream>
#include "cabecera.hpp"
#include "funcionesGenerales.hpp"
#include "cramer.hpp"
#include "tiempo.hpp"
#include "estadisticos.hpp"


//DNI ...1L --> opción del determinante.
using namespace std;

int main(){
//	std::ofstream fo;
	Clock Cronometro;
	srand(time(NULL));
	
	vector<double> vTiemposObservados, vTiemposEstimados, vAs;
	int valorMin, valorMax, valorInc, opcion, apartado;

	do{

		cabecera(1);

		opcion = menu();

		vTiemposObservados.clear();
		vTiemposEstimados.clear();
		vAs.clear();

		switch(opcion){
			
			case 1:
				apartado = 1;
				cabecera(1);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ APARTADO DE MATRICES ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━┛" << endl;	
				
				pideDatos(valorMin, valorMax, valorInc);

				rellenaTiemposObservados(apartado, valorMin,valorMax,valorInc,vTiemposObservados);

				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				cramer(apartado, valorMin, valorMax, valorInc, 4, vTiemposObservados, vAs);

				calculaTiemposEstimados(apartado, valorMin, valorMax, valorInc, vTiemposEstimados, vAs);				

				cout << "El vector de tiempos estimados es..: " << endl;
				imprimeVector(vTiemposEstimados);

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "El coeficiente de determinación es..:" << endl;
				cout << coeficienteDeterminacion(vTiemposEstimados, vTiemposObservados) << endl;
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				imprimeResultadosEnFichero(valorMin, valorInc, vTiemposObservados, vTiemposEstimados);

				system("./gnuplot.sh");

				prediccion(apartado, vAs);

				introParaContinuar();

				break;


			case 2:
				apartado = 2;
				cabecera(1);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ APARTADO DE FIBONACCI ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

				pideDatos(valorMin, valorMax, valorInc);

				rellenaTiemposObservados(apartado, valorMin,valorMax,valorInc,vTiemposObservados);

				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				cramer(apartado,  valorMin, valorMax, valorInc, 2, vTiemposObservados, vAs);

				calculaTiemposEstimados(apartado, valorMin, valorMax, valorInc, vTiemposEstimados, vAs);				
				cout << "Los tiempos estimados son..: " << endl;
				imprimeVector(vTiemposEstimados);

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "El coeficiente de determinación es..:" << endl;
				cout << coeficienteDeterminacion(vTiemposEstimados, vTiemposObservados) << endl;
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				imprimeResultadosEnFichero(valorMin, valorInc, vTiemposObservados, vTiemposEstimados);

				system("./gnuplot.sh");

				prediccion(apartado, vAs);

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
