#ifndef __CRAMER__
#define __CRAMER__
#include <cmath>
#include "funcionesGenerales.hpp"

using std::cout;
using std::cin;
using std::vector;

void cramer(const int &valorMin,const int &valorMax,const int &valorInc,const int tam, const vector<double> &vTiemposObservados, vector<double> &vAs){
	vector<vector<double> > matriz (tam, vector<double> (tam));
	//Generando la matriz original para de cramer
	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			matriz[i][j] = 0; 				//inicializando a 0 por el sumatorio siguiente
			for(int k = valorMin; k <= valorMax; k += valorInc){
				if(i == 0 && j == 0)		//Si es el primer valor, mete N
					matriz[i][j] = 1 + ((valorMax - valorMin) / valorInc);
				else						//Si no, mete su sumatorio elevado a la potencia que corresponda
					matriz[i][j] += pow(k, i+j); 
			}
		}
	}
	cout << "=============================" << endl;
	imprimeVector(vTiemposObservados);
	imprimeMatriz(matriz);
	//Cálculo de los As correspondientes
	vector<vector<double> > matrizAux (tam, vector<double> (tam));
	for(int i = 0; i < tam; i++){			//Genera las matrices auxiliares correspondientes
		copiaMatriz(matriz, matrizAux);
// aquí está el problema
		for(int j = 0; j < tam; j++){
			matrizAux[j][i] = 0;
			for(int k = 0; k < vTiemposObservados.size(); k ++)
				matrizAux[j][i] += (vTiemposObservados[k] * pow(k, i+j));
		}
//
		imprimeMatriz(matrizAux);
	}
}
#endif
