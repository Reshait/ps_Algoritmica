#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <fstream>
#include "cabecera.hpp"
#include "cramer.hpp"
//#include "combinatorio.hpp"
#include "hanoi.hpp"
#include "funcionesGenerales.hpp"

using namespace std;

int main(){
//Eliminar al final
	std::ofstream fo;
	Clock Cronometro;
	vector<stTabla> vEstructuras;
//
	vector<double> vTiemposObservados, vTiemposEstimados, vAs;
	double valorN, sumTiempo;
	int opcion, desde = 0, hasta = 0, apartado;

	//Hanoi
	vector<string> vOrigen, vDestino, vAux;
	bool quiereImprimir = false;

	do{

		opcion = menu();

		inicializaVectoresYTorres(vTiemposObservados, vTiemposEstimados, vAs);
		inicializaTorres(vOrigen, vDestino, vAux);

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

				cramer(1, desde, hasta, 1, 2, vTiemposObservados, vAs);

				calculaTiemposEstimados(2, desde, hasta, vTiemposEstimados, vAs);	//2 para exponencial
				cout << "Los tiempos estimados son..: " << endl;

				imprimeVector(vTiemposEstimados);

				imprimeResultadosEnFichero(desde, vTiemposObservados, vTiemposEstimados);

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

				cramer(0, desde, hasta, 1, 4, vTiemposObservados, vAs);

				calculaTiemposEstimados(1, desde, hasta, vTiemposEstimados, vAs);	//1 para polinómico
				cout << "Los tiempos estimados son..: " << endl;
				imprimeVector(vTiemposEstimados);		

				imprimeResultadosEnFichero(desde, vTiemposObservados, vTiemposEstimados);

				system("./gnuplot.sh");

				prediccion(1, vAs);													//1 para ajuste polinómico

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

				cramer(0, desde, hasta, 1, 4, vTiemposObservados, vAs);	

				calculaTiemposEstimados(1, desde, hasta, vTiemposEstimados, vAs);	//1 para polinómico
				cout << "Los tiempos estimados son..: " << endl;
				imprimeVector(vTiemposEstimados);

				imprimeResultadosEnFichero(desde, vTiemposObservados, vTiemposEstimados);

				system("./gnuplot.sh");

				prediccion(1, vAs);													//1 para ajuste polinómico

				introParaContinuar();

				break;				

			case 4:
				apartado = 4;
				cabecera(2);
				cout << "\t┏━━━━━━━┓" << endl;
				cout << "\t┃ HANOI ┃" << endl;	
				cout << "\t┗━━━━━━━┛" << endl;	

				pideDatos(valorN);

				cout << "¿Quiere observar la representación por pantalla? " << endl;
				cout << "0.- NO" << endl;
				cout << "1.- SI" << endl;
				cin >> quiereImprimir;

				for(int i = 3; i <= valorN; i++){
					//Inicializando los vectores
/*					vOrigen.clear();
					vDestino.clear();
					vAux.clear();

					vOrigen.push_back("Orig..:");
					vDestino.push_back("Dest..:");
					vAux.push_back("Auxi..:");	
*/
					inicializaTorres(vOrigen, vDestino, vAux);

					//Terminada la inicialización

					rellenaVectorOrigen(i, vOrigen);

					if(quiereImprimir){
						cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
						cout << endl;
						cout << "Se parte de las siguientes Torres..:" << endl;
						imprime(vOrigen,vAux,vDestino);
						cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
					}

					Cronometro.start();
					hanoi(vOrigen, vDestino, vAux, vOrigen.size(), quiereImprimir);
					Cronometro.stop();
					vTiemposObservados.push_back(Cronometro.elapsed());											
				}

				cout << "==========================================" << endl;
				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				cramer(0, 3, valorN, 1, 4, vTiemposObservados, vAs);

				cout << "Los tiempos estimados son..: " << endl;
				for(int i = 3; i <= valorN; i ++)
					vTiemposEstimados.push_back(tiempoEstimado(vAs, i));
				imprimeVector(vTiemposEstimados);

				//Imprimiendo en Datos.txt los resultados
				fo.open("Datos.txt"); 
				for(unsigned int i = 0, ni = 3; i < vTiemposObservados.size(); i++, ni ++)
					fo << ni << " " << vTiemposObservados[i] << " " << vTiemposEstimados[i] << "\n";
				fo.close();
				system("./gnuplot.sh");

				prediccion(vAs);

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
