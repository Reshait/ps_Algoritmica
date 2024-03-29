#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <fstream>

#include "cabecera.hpp"
#include "cramer.hpp"
#include "funcionesGenerales.hpp"
#include "estadisticos.hpp"
#include "hanoi.hpp"
#include "funcionesGenerales.hpp"

using namespace std;

int main(){
	vector<double> vTiemposObservados, vTiemposEstimados, vAs;
	int opcion, desde = 0, hasta = 0, apartado;

	do{

		opcion = menu();

		inicializaVectores(vTiemposObservados, vTiemposEstimados, vAs);

		switch(opcion){
			
			case 1:
				apartado = 1;
				cabecera(2);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ COMBINATORIO - Recursividad Cnk = Cn-1,k-1 + Cn-1,k ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;	
				
				pideDatos(desde, hasta);

				rellenaTiemposObservados(apartado, desde, hasta, vTiemposObservados);

				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				matrizParaCramer(2, desde, hasta, 1, 2, vTiemposObservados, vAs);

				calculaTiemposEstimados(2, desde, hasta, vTiemposEstimados, vAs);	//2 para exponencial
				cout << "Los tiempos estimados son..: " << endl;

				imprimeVector(vTiemposEstimados);

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "El coeficiente de determinación es..:" << endl;
				cout << coeficienteDeterminacion(vTiemposEstimados, vTiemposObservados) << endl;
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				imprimeResultadosEnFichero(desde, vTiemposObservados, vTiemposEstimados);

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "La ecuación de ajuste utilizada es..:" << endl;
				imprimeEcuacionAjuste(apartado, vAs);
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				system("./gnuplot.sh");

				prediccion(2, vAs);													//2 para exponencial

				introParaContinuar();

				break;


			case 2:
				apartado = 2;			
				cabecera(2);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ COMBINATORIO - Recursividad con tabla ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;	

				pideDatos(desde, hasta);

				rellenaTiemposObservados(apartado, desde, hasta, vTiemposObservados);

				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				matrizParaCramer(1, desde, hasta, 1, 3, vTiemposObservados, vAs);	//1 sin cambio de variable

				calculaTiemposEstimados(1, desde, hasta, vTiemposEstimados, vAs);	//1 sin cambio de variable
				cout << "Los tiempos estimados son..: " << endl;
				imprimeVector(vTiemposEstimados);		

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "El coeficiente de determinación es..:" << endl;
				cout << coeficienteDeterminacion(vTiemposEstimados, vTiemposObservados) << endl;
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				imprimeResultadosEnFichero(desde, vTiemposObservados, vTiemposEstimados);

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "La ecuación de ajuste utilizada es..:" << endl;
				imprimeEcuacionAjuste(apartado, vAs);
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				system("./gnuplot.sh");

				prediccion(1, vAs);													//1 sin cambio de variable

				introParaContinuar();

				break;
				
			case 3:
				apartado = 3;
				cabecera(2);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ COMBINATORIO - Algoritmo Iterativo ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;	

				pideDatos(desde, hasta);

				rellenaTiemposObservados(apartado, desde, hasta, vTiemposObservados);

				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				matrizParaCramer(1, desde, hasta, 1, 3, vTiemposObservados, vAs);	//1 sin cambio de variable

				calculaTiemposEstimados(1, desde, hasta, vTiemposEstimados, vAs);	//1 sin cambio de variable
				cout << "Los tiempos estimados son..: " << endl;
				imprimeVector(vTiemposEstimados);

				imprimeResultadosEnFichero(desde, vTiemposObservados, vTiemposEstimados);

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "El coeficiente de determinación es..:" << endl;
				cout << coeficienteDeterminacion(vTiemposEstimados, vTiemposObservados) << endl;
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "La ecuación de ajuste utilizada es..:" << endl;
				imprimeEcuacionAjuste(apartado, vAs);
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				system("./gnuplot.sh");

				prediccion(1, vAs);													//1 sin cambio de variable

				introParaContinuar();

				break;				

			case 4:
				apartado = 4;
				cabecera(2);
				cout << "\t┏━━━━━━━┓" << endl;
				cout << "\t┃ HANOI ┃" << endl;	
				cout << "\t┗━━━━━━━┛" << endl;	

				desde = 3;
				pideDatos(hasta);

				rellenaTiemposObservados(apartado, desde, hasta, vTiemposObservados);				

				cout << "==========================================" << endl;
				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				matrizParaCramer(2, desde, hasta, 1, 4, vTiemposObservados, vAs);	//2 para ajuste exponencial

				calculaTiemposEstimados(2, desde, hasta, vTiemposEstimados, vAs);	//2 para ajuste exponencial
				cout << "Los tiempos estimados son..: " << endl;
				imprimeVector(vTiemposEstimados);

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "El coeficiente de determinación es..:" << endl;
				cout << coeficienteDeterminacion(vTiemposEstimados, vTiemposObservados) << endl;
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				imprimeResultadosEnFichero(desde, vTiemposObservados, vTiemposEstimados);

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "La ecuación de ajuste utilizada es..:" << endl;
				imprimeEcuacionAjuste(apartado, vAs);
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				system("./gnuplot.sh");

				prediccion(2, vAs);													//2 para ajuste exponencial

				introParaContinuar();

				break;	

			case 0:
				cabecera(2);

				cout << "Saliendo ..." << endl;
				break;	

			default:
				cabecera(2);
				cout << "Opción introducida incorrecta." << endl;
				introParaContinuar();
				break;	
		}

	}while(opcion != 0);	

	return 0;

}
