#ifndef __CRAMER__
#define __CRAMER__
#include <cmath>
#include "funcionesGenerales.hpp"

using std::cout;
using std::cin;
using std::vector;

void cramer(bool esFibonacci, const int &valorMin,const int &valorMax,const int &valorInc,const int tam, const vector<double> &vTiemposObservados, vector<double> &vAs){
	vector<vector<double> > matriz (tam, vector<double> (tam));
	//Generando la matriz original para cramer
	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			matriz[i][j] = 0; 				//inicializando a 0 por el sumatorio siguiente
			for(int k = valorMin; k <= valorMax; k += valorInc){
				if(i == 0 && j == 0)		//Si es el primer valor, mete N
					matriz[i][j] = 1 + ((valorMax - valorMin) / valorInc);
				else{						//Si no, mete su sumatorio elevado a la potencia que corresponda
					if(esFibonacci == false)
						matriz[i][j] += pow(k, i+j); 
					else
						matriz[i][j] += pow(pow(2, k),i+j); 

				}
			}
		}
	}

	//Cálculo de los As correspondientes
	vector<vector<double> > matrizAux (tam, vector<double> (tam));
//cout << endl; imprimeMatriz(matriz); cout << endl; 
//cout << "CUYO DETERMINANTE ES..:\t" << calculaDeterminante(matriz) << endl;

	for(int i = 0; i < tam; i++){			//Genera las matrices auxiliares correspondientes con el término indep insertado en cada una de sus columnas
		copiaMatriz(matriz, matrizAux);
		for(int j = 0; j < tam; j++){
			matrizAux[j][i] = 0;  //<-- El fallo está aquí joder!!
			for(unsigned int k = 0, z = valorMin; k < vTiemposObservados.size(); k ++, z += valorInc)
				if(esFibonacci == false)
					matrizAux[j][i] += (vTiemposObservados[k] * pow(z, j));
				else
					matrizAux[j][i] += vTiemposObservados[k] * pow(pow(2, z), j);
		}

//cout << endl; imprimeMatriz(matrizAux); cout << endl; 
//cout << "CUYO DETERMINANTE ES..:\t" << calculaDeterminante(matrizAux) << endl;

		vAs.push_back(calculaDeterminante(matrizAux)/calculaDeterminante(matriz));
	}
}

/*
double tiempoEstimado(const vector<double> &vAs, const int &Ni){
	double tiempoEstimado = 0.0;

	for(unsigned int i = 0; i < vAs.size(); i++)
		tiempoEstimado += vAs[i] * pow(Ni,i);

	return tiempoEstimado;
}
*/

int fibonacci(int n){
    if(n == 0 || n == 1)
       return n;
    else
       return fibonacci(n - 2) + fibonacci(n - 1);
}

#endif
