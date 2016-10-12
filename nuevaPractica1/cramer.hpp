#ifndef __CRAMER__
#define __CRAMER__
#include <cmath>

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
				if(i == 0 && j == 0)
					matriz[i][j] = (valorMax - valorMin) / valorInc;
				else
					matriz[i][j] += pow(k, i+j); 
			}
		}
	}
}
#endif
