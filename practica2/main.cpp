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
	double valorN, sumatorio;
	int opcion, desde = 0, hasta = 0;

	//Hanoi
	vector<int> vOrigen, vDestino, vAux;
	unsigned int cuentaMovimientos = 0;

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

		switch(opcion){
			
			case 1:


				cabecera(2);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ COMBINATORIO - Recursividad Cnk = Cn-1,k-1 + Cn-1,k ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;	
				
				pideDatos(desde, hasta);

				for(int i = desde; i < hasta; i++){
					sumatorio = 0;
					for(int j = 0; j <= i; j++){
						sumatorio = combinatorioRecursivo(i,j);
						cout << combinatorioRecursivo(i, j) << endl;
					}	
					vTiemposObservados.push_back(sumatorio = sumatorio/((desde-hasta)+2));
				}

				imprimeVector(vTiemposObservados);
				
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
//				cout << combinatorioRecursivo(valorN, valorK, vEstructuras) << endl;
//				system("./ejemplo_gnuplot.sh");

				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				cin.ignore().get();

				break;
				
			case 3:
				cabecera(2);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ COMBINATORIO - Algoritmo NO recursivo ┃" << endl;	
				cout << "\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;	

				pideDatos(desde, hasta);
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
//				imprimeVector(vOrigen);
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
