#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <fstream>
#include "cabecera.hpp"
#include "funcionesGenerales.hpp"
#include "cramer.hpp"
#include "tiempo.hpp"
#include "combinatorio.hpp"
#include "hanoi.hpp"

using namespace std;

int main(){
	std::ofstream fo;
	Clock Cronometro;
	vector<stTabla> vEstructuras;

	vector<double> vTiemposObservados, vTiemposEstimados, vAs;
	double valorN, sumTiempo;
	int opcion, desde = 0, hasta = 0;

	//Hanoi
	vector<string> vOrigen, vDestino, vAux;
	int cuentaMovimientos = 0;

	do{

		cabecera(2);
		cout << "1.- Para realizar COMBINATORIO - Recursividad Cnk = Cn-1,k-1 + Cn-1,k." << endl;
		cout << "2.- Para realizar COMBINATORIO - Recursividad con tabla." << endl;
		cout << "3.- Para realizar COMBINATORIO - Algoritmo NO recursivo." << endl;
		cout << "4.- Para realizar HANOI." << endl;
		cout << "0.- Para Salir." << endl;
		cout << "\tIntroduzca una opción >> ";
		cin >> opcion;
		getchar();

		vTiemposObservados.clear();
		vTiemposEstimados.clear();
		vAs.clear();
		vOrigen.clear();
		vDestino.clear();
		vAux.clear();

		vOrigen.push_back("Orig..:");
		vDestino.push_back("Dest..:");
		vAux.push_back("Auxi..:");

///1uitar
double error;

		switch(opcion){
			
			case 1:

				cabecera(2);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ COMBINATORIO - Recursividad Cnk = Cn-1,k-1 + Cn-1,k ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;	
				
				pideDatos(desde, hasta);

				for(int i = desde; i <= hasta; i++){
					sumTiempo = 0;

					for(int j = 0; j <= i; j++){
						Cronometro.start();
						cout << combinatorioRecursivo(i, j) << endl;
						Cronometro.stop();	
						sumTiempo += Cronometro.elapsed();
					}
					vTiemposObservados.push_back(sumTiempo/(hasta-desde + 1));						
//					vTiemposObservados.push_back(sumTiempo/(i + 1));						
				}



				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				cramer(1, desde, hasta, 1, 2, vTiemposObservados, vAs);

				cout << "Los tiempos estimados son..: " << endl;
				for(int i = desde; i <= hasta; i ++){
					vTiemposEstimados.push_back( std::abs(vAs[0] + vAs[1] * pow(2,i)) );
					cout << std::abs(vAs[0] + vAs[1] * pow(2,i)) << "\t";
				}		
				cout << endl;		
//quitar	-->				
	//for(unsigned int i = 0; i < vTiemposObservados.size(); i++)
	//	error += std::abs(vTiemposObservados[i] - vTiemposEstimados[i]);
	//error = error / vTiemposObservados.size();
	//cout << "EL error abs. medio es..: " << error << endl;
//hasta aquí <--

//				system("./ejemplo_gnuplot.sh");

				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				cin.ignore().get();

				break;


			case 2:
				cabecera(2);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ COMBINATORIO - Recursividad con tabla ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;	

				pideDatos(desde, hasta);

				for(int i = desde; i <= hasta; i++){
					sumTiempo = 0;

					for(int j = 0; j <= i; j++){
						Cronometro.start();
						cout << combinatorioRecursivo(i, j, vEstructuras) << endl;
						Cronometro.stop();	
						sumTiempo += Cronometro.elapsed();
					}
					vTiemposObservados.push_back(sumTiempo/(hasta-desde + 1));						
//					vTiemposObservados.push_back(sumTiempo/(i + 1));						
				}		

				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				cramer(0, desde, hasta, 1, 4, vTiemposObservados, vAs);

				cout << "Los tiempos estimados son..: " << endl;
				for(int i = desde; i <= hasta; i ++)
					vTiemposEstimados.push_back(tiempoEstimado(vAs, i));
				imprimeVector(vTiemposEstimados);		

//				system("./ejemplo_gnuplot.sh");

				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				cin.ignore().get();

				break;
				
			case 3:
				cabecera(2);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ COMBINATORIO - Algoritmo Iterativo ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;	

				pideDatos(desde, hasta);

				for(int n = desde; n <= hasta; n++){
					sumTiempo = 0;

					for(int k = 0; k <= n; k++){
						Cronometro.start();		
						cout << combinatorioIterativo(n,k) << endl;
						Cronometro.stop();	
						sumTiempo += Cronometro.elapsed();						
					}
					vTiemposObservados.push_back(sumTiempo/(hasta-desde + 1));											
				}

				cout << "El vector de tiempos observados es..: " << endl;
				imprimeVector(vTiemposObservados);

				cramer(0, desde, hasta, 1, 4, vTiemposObservados, vAs);

				cout << "Los tiempos estimados son..: " << endl;
				for(int i = desde; i <= hasta; i ++)
					vTiemposEstimados.push_back(tiempoEstimado(vAs, i));
				imprimeVector(vTiemposEstimados);

//				system("./ejemplo_gnuplot.sh");

				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				cin.ignore().get();

				break;				

			case 4:
				cabecera(2);
				cout << "\t┏━━━━━━━┓" << endl;
				cout << "\t┃ HANOI ┃" << endl;	
				cout << "\t┗━━━━━━━┛" << endl;	

				pideDatos(valorN);

				rellenaVectorOrigen(valorN, vOrigen);

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << endl;
				cout << "Se parte de las siguientes Torres..:" << endl;
				imprime(vOrigen,vAux,vDestino);
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

				hanoi(vOrigen, vDestino, vAux, vOrigen.size());

//				system("./ejemplo_gnuplot.sh");

				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				cin.ignore().get();

				break;	

			case 0:
				system("clear");
				cabecera(2);

				cout << "Saliendo ..." << endl;
				break;	

			default:
				cabecera(2);
				cout << "Opción introducida incorrecta." << endl;
				cout << "Pulse intro para continuar..." << endl;
				cin.ignore().get();
				break;	
		}

	}while(opcion != 0);	

	return 0;

}
