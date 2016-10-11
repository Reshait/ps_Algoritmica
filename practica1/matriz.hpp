#include <cmath>
#include <numeric>
#include "tiempo.hpp"  //<-- Quitar antes de entregar
/*! 
  \file     mamtriz.hpp
  \brief    Función y Estructura correspondiente para rellenar los datos de entrada.
  \author   Teófilo Rojas Mata
  \date     28/09/2016
*/

#ifndef ___mHPP__
#define ___mHPP__

using std::cout;
using std::cin;
using std::endl;
using std::vector;

/*! 
  \brief Definición clase Matriz creada para los datos de entrada a pedir por el teclado.
  \post Ninguna
*/

// Sacado de:
// http://www.cplusplus.com/forum/general/97018/#msg524064
class Matriz
{
	private:
		double** _m;
		int _tam;

	public:
		Matriz(int tam){
			setTam(tam);

			_m = new double*[getTam()];
			for(int i = 0; i < getTam(); i++){
			
				_m[i] = new double[getTam()];
			
				for(int j = 0; j < getTam(); j++){
					//_m[i][j] = (rand() % 20000) - 10000;
					//_m[i][j] /= 1000;
					_m[i][j] = -10+((double)rand() /RAND_MAX) * (20);
				}
			}
		}
		~Matriz(void){
			//cout << "Destrucción completada" << endl;
		};

		inline const int getTam(){ return _tam; }
		inline void setTam(int tam){ _tam = tam; }


		void imprimeMatriz(){
			int cuentaIntro = 0;
			for(int i = 0; i < getTam(); i++){
				cout << "\t" ;
				for(int j = 0; j < getTam(); j++){
					cout << _m[i][j] << " \t";
					
					cuentaIntro ++;					
					if(cuentaIntro == getTam()){
						cout << endl;
						cuentaIntro = 0;
					}
				}
			}
		}


		double calculaDeterminante(){
		    double fRet = 0, fProduct = 0;

		    if (getTam() == 2){
		        fRet = _m[0][0] * _m[1][1] - _m[1][0] * _m[0][1];
		    }
		    
		    else if (getTam() == 1)
		    	fRet = _m[0][0];

		    else {
		        for (int i = 0; i < getTam(); i++){
		            //  Multiplicacion de valores verticales de izquierda a derecha...
		            fProduct = 1.0;
		            for (int j = 0; j < getTam(); j++)
		                fProduct *= _m[(i + j) % getTam()][j];
		            fRet += fProduct;
		     
		            //  Multiplicacion de valores verticales de derecha a izquierda...
		            fProduct = 1.0;
		            for (int j = 0; j < getTam(); j++)
		                fProduct *= _m[(getTam() - 1) - ((i + j) % getTam())][j];
		            fRet -= fProduct;
		        }
		    }
		     
		    return fRet;
		}		
	
};


vector<double> operator*(const vector<double> &a, const vector<double> &b){
	vector<double> total;
	for(int i = 0; i < a.size(); i++)
		total.push_back(a.at(i) * b.at(i));

	return total;
}

double calculaDeterminante(double m[][2]){
    double fRet = 0, fProduct = 0;

    fRet = (m[0][0] * m[1][1]) - (m[1][0] * m[0][1]);
 
    return fRet;
}

double calculaDeterminante(double m[][3]){
    double fRet = 0, fProduct = 0;

    for (int i = 0; i < 3; i++){
    //  Multiplicacion de valores verticales de izquierda a derecha...
        fProduct = 1.0;
        for (int j = 0; j < 3; j++)
            fProduct *= m[(i + j) % 3][j];
 	        fRet += fProduct;
		     
		            //  Multiplicacion de valores verticales de derecha a izquierda...
		    fProduct = 1.0;
		    for (int j = 0; j < 3; j++)
		        fProduct *= m[(3 - 1) - ((i + j) % 3)][j];
		    fRet -= fProduct;
 	}
    return fRet;
}

void copiaMatriz(double original[][2], double copia[][2]){
	for(int i= 0; i < 2; i ++)
		for(int j = 0; j < 2; j++)
			copia[i][j] = original[i][j];
}

void copiaMatriz(double original[][3], double copia[][3]){
	for(int i= 0; i < 3; i ++)
		for(int j = 3; j < 3; j++)
			copia[i][j] = original[i][j];
}

void Cramer(const vector<double> &vectorZi, const vector<double> &vectorTi, vector<double> &a ){  //añadir bool esFibonacci
	double N = vectorZi.size();
	double sumZi = std::accumulate(vectorZi.begin(), vectorZi.end(), 0);
	double sumTi = std::accumulate(vectorTi.begin(), vectorTi.end(), 0);
	double sumZi_Ti, sumZi_Zi;

	vector<double> vectorZi_Zi = vectorZi * vectorZi;
	vector<double> vectorZi_Ti = vectorZi * vectorTi;
	sumZi_Ti = std::accumulate(vectorZi_Ti.begin(), vectorZi_Ti.end(), 0);
	sumZi_Zi = std::accumulate(vectorZi_Zi.begin(), vectorZi_Zi.end(), 0);

////Resolucion Fibonacci
	double matriz[2][2], matrizAux[2][2];
	matriz[0][0] = N;
	matriz[0][1] = sumZi;
	matriz[1][0] = matriz[0][1];
	matriz[1][1] = sumZi_Zi;

	for(int i = 0; i < 2; i++){
		copiaMatriz(matriz, matrizAux);
		matrizAux[i][0] = sumTi;
		matrizAux[1][i] = sumZi_Ti; 	
		
		cout << "Determinante de la matriz es..: \t" << calculaDeterminante(matriz) << endl;
		cout << "Determinante de la mAuxiliar es..: \t" << calculaDeterminante(matrizAux) << endl;

		a.push_back(calculaDeterminante(matrizAux) / calculaDeterminante(matriz));	
	}

}

vector<double> elevarVectorAlValorPorSumTi(const vector<double> &vNi, const vector<double> &vTi, int valor){
	vector<double> aux;
	aux = vNi;

	for(int i = 0; i < valor; i++)
		if(i == valor-1)
			aux = aux * vTi;
		else
			aux = aux * vNi;

	return aux;
}


void Cramer2(const vector<double> &vectorZi, const vector<double> &vectorTi, vector<double> &a ){  //Cramer para las matrices
	double N = vectorZi.size();
	double sumZi = std::accumulate(vectorZi.begin(), vectorZi.end(), 0);
	double sumTi = std::accumulate(vectorTi.begin(), vectorTi.end(), 0);
	double sumZi_Ti, sumZi_Zi;

	vector<double> vectorZi_Zi = vectorZi * vectorZi;
	vector<double> vectorZi_Ti = vectorZi * vectorTi;
	sumZi_Ti = std::accumulate(vectorZi_Ti.begin(), vectorZi_Ti.end(), 0);
	sumZi_Zi = std::accumulate(vectorZi_Zi.begin(), vectorZi_Zi.end(), 0);

////Resolucion Matrices
	vector<double> vAux;
	double matriz[3][3], matrizAux[3][3];

	for(int i=0; i < 3;i++){
		for(int j=0; j < 3; j++){
			if(i == 0 && j == 0)
				matriz[i][j] = N;

			else{
				vAux = elevarVectorAlValorPorSumTi(vectorZi, vectorTi, i+j); // en matriz 0,1 se mete Zi¹, en matriz 0,2 se mete Zi², en matriz 0,3 se mete Zi³
				matriz[i][j] = std::accumulate(vAux.begin(), vAux.end(), 0);

			}
		}
	}

	vAux.clear();

	vector<double> vectorTerminoIndependiente;
	for(int i = 0; i < vectorZi.size(); i++){
		if(i == 0)
			vectorTerminoIndependiente.push_back(sumTi);

		else{
			vAux = elevarVectorAlValorPorSumTi(vectorZi, vectorTi, i);

			vectorTerminoIndependiente.push_back(std::accumulate(vAux.begin(), vAux.end(), 0));
		}
	}

	//imprimeVectorTiempos(vectorTerminoIndependiente);

	for(int i = 0; i < 3; i++){
		copiaMatriz(matriz, matrizAux);
		for(int k = 0; k < 3; k++)
			matrizAux[k][0] = vectorTerminoIndependiente.at(k);

		a.push_back(calculaDeterminante(matrizAux)/calculaDeterminante(matriz));
	}
}


#endif