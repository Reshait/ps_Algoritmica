#ifndef __CRAMER__
#define __CRAMER__
#include <cmath>
#include "funcionesGenerales.hpp"

using std::cout;
using std::cin;
using std::vector;


void cramer(int apartado, const int &valorMin, const int &valorMax, const int &valorInc, vector<vector<double> > matriz, const vector<double> &vTiemposObservados, vector<double> &vAs){
	vector<vector<double> > matrizAux (matriz.size(), vector<double> (matriz.size()));

	for(unsigned int i = 0; i < matriz.size(); i++){			//Genera las matrices auxiliares correspondientes con el término indep insertado en cada una de sus columnas
		copiaMatriz(matriz, matrizAux);
		for(unsigned int j = 0; j < matriz.size(); j++){
			matrizAux[j][i] = 0;  
			for(unsigned int k = 0, z = valorMin; k < vTiemposObservados.size(); k ++, z += valorInc)
				if(apartado == 1)
					matrizAux[j][i] += (vTiemposObservados[k] * pow(z, j));
				else if(apartado == 2)
					matrizAux[j][i] += vTiemposObservados[k] * pow(pow(2, z), j);
		}

		vAs.push_back(calculaDeterminante(matrizAux)/calculaDeterminante(matriz));
	}
}


void matrizParaCramer(int apartado, const int &valorMin, const int &valorMax, const int &valorInc, const int tam, const vector<double> &vTiemposObservados, vector<double> &vAs){
	vector<vector<double> > matriz (tam, vector<double> (tam));
	//Generando la matriz original para cramer
	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			matriz[i][j] = 0; 				//inicializando a 0 por el sumatorio siguiente
			for(int k = valorMin; k <= valorMax; k += valorInc){
				if(i == 0 && j == 0)		//Si es el primer valor, mete N
					matriz[i][j] = 1 + ((valorMax - valorMin) / valorInc);
				else{						//Si no, mete su sumatorio elevado a la potencia que corresponda
					if(apartado == 1)
						matriz[i][j] += pow(k, i+j); 
					else if(apartado == 2)
						matriz[i][j] += pow(pow(2, k),i+j); 

				}
			}
		}
	}

	cramer(apartado, valorMin, valorMax, valorInc, matriz, vTiemposObservados, vAs);
}


#endif
