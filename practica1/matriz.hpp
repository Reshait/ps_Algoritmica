#include <cmath>
#include <numeric>
#include "tiempo.hpp"  //<-- Quitar antes de entregar
/*! 
  \file     matriz.hpp
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

double calculaDeterminante(const vector<vector<double> > &matriz){
		    double fRet = 0, fProduct = 0;

		    if ( matriz.size() == 2){
		        fRet = matriz[0][0] * matriz[1][1] - matriz[1][0] * matriz[0][1];
		    }
		    
		    else if (matriz.size() == 1)
		    	fRet = matriz[0][0];

		    else {
		        for (int i = 0; i < matriz.size(); i++){
		            //  Multiplicacion de valores verticales de izquierda a derecha...
		            fProduct = 1.0;
		            for (int j = 0; j < matriz.size(); j++)
		                fProduct *= matriz[(i + j) % matriz.size()][j];
		            fRet += fProduct;
		     
		            //  Multiplicacion de valores verticales de derecha a izquierda...
		            fProduct = 1.0;
		            for (int j = 0; j < matriz.size(); j++)
		                fProduct *= matriz[(matriz.size() - 1) - ((i + j) % matriz.size())][j];
		            fRet -= fProduct;
		        }
		    }
		     
		    return fRet;	
}

void copiaMatriz(const vector<vector<double> > &original, vector<vector<double> > &copia){
	for(int i= 0; i < original.size(); i ++)
		for(int j = 0; j < original.size(); j++)
			copia[i][j] = original[i][j];
}

void imprimeMatriz(const vector<vector<double> > &matriz){
	int cuentaIntro = 0;
	for(int i = 0; i < matriz.size(); i++){
		cout << "\t" ;
		for(int j = 0; j < matriz.size(); j++){
			cout << matriz[i][j] << " \t";
			
			cuentaIntro ++;					
			if(cuentaIntro == matriz.size()){
				cout << endl;
				cuentaIntro = 0;
			}
		}
	}
}

double generaTerminoIndependiente(const vector<double> &vNi, const vector<double> &vTi, int valor){
	vector<double> aux;

	if(valor == 0)
		aux = vTi;
	
	else{
		aux = vNi;
		for(int i = 0; i < valor; i++)
			if(i == valor-1)
				aux = aux * vTi;
			else
				aux = aux * vNi;
	}
	return std::accumulate(aux.begin(), aux.end(), 0);
}

double generaTerminosMatriz(const vector<double> &vNi, int valor){
	vector<double> aux;
	double aDevolver;
	aux = vNi;

	if(valor == 0)
		aDevolver = vNi.size();

	else{
		for(int i = 1; i < valor; i++)
				aux = aux * vNi;

		aDevolver = std::accumulate(aux.begin(), aux.end(), 0);		
	}

	return aDevolver;
}

void Cramer(const vector<double> &vectorZi, const vector<double> &vectorTi, vector<double> &a , bool esFibonacci){  //añadir bool esFibonacci
	double N = vectorZi.size();
	double sumZi = std::accumulate(vectorZi.begin(), vectorZi.end(), 0);
	double sumTi = std::accumulate(vectorTi.begin(), vectorTi.end(), 0);
	double sumZi_Ti, sumZi_Zi;

	vector<double> vectorZi_Zi = vectorZi * vectorZi;
	vector<double> vectorZi_Ti = vectorZi * vectorTi;
	sumZi_Ti = std::accumulate(vectorZi_Ti.begin(), vectorZi_Ti.end(), 0);
	sumZi_Zi = std::accumulate(vectorZi_Zi.begin(), vectorZi_Zi.end(), 0);

////Resolucion Fibonacci
	if(esFibonacci == 1){

		vector<vector<double> > matriz (2, vector<double> (2));
		vector<vector<double> > matrizAux (2, vector<double> (2));		
		matriz[0][0] = N;
		matriz[0][1] = sumZi;
		matriz[1][0] = matriz[0][1];
		matriz[1][1] = sumZi_Zi;

		for(int i = 0; i < 2; i++){
			copiaMatriz(matriz, matrizAux);
			//Cambio la columna correspondiente por el término independiente en la Matriz Auxiliar
			matrizAux[0][i] = sumTi;
			matrizAux[1][i] = sumZi_Ti;

			cout << "Determinante de la matriz es..: \t" << calculaDeterminante(matriz) << endl;
			cout << "Determinante de la mAuxiliar es..: \t" << calculaDeterminante(matrizAux) << endl;

			a.push_back(calculaDeterminante(matrizAux) / calculaDeterminante(matriz));	
		}
	}
////Resolución Matrices
	else {
		vector<vector<double> > matriz (4, vector<double> (4));
		vector<vector<double> > matrizAux (4, vector<double> (4));
		vector<double> vectorTerminoIndependiente;

		for(int i=0; i < matriz.size();i++){
			for(int j=0; j < matriz.size(); j++){
				matriz[i][j] = generaTerminosMatriz(vectorZi, i+j);  // en matriz 0,0 se mete N, en matriz 0,1 se mete Zi¹, en matriz 0,2 se mete Zi², en matriz 0,3 se mete Zi³
			}
		}

		for(int i = 0; i < vectorZi.size(); i++)
			vectorTerminoIndependiente.push_back(generaTerminoIndependiente(vectorZi, vectorTi, i));


		//Calculo las As
		for(int i = 0; i < matriz.size(); i++){
			copiaMatriz(matriz, matrizAux);

cout << "MATRIZ" << endl;
imprimeMatriz(matriz);

cout << "MATRIZ AUX COPIADA" << endl;
imprimeMatriz(matrizAux);

			for(int k = 0; k < matrizAux.size(); k++)
				matrizAux[k][i] = vectorTi[k];

cout << "MATRIZ AUX TERMINO IND." << endl;
imprimeMatriz(matrizAux);

cout << calculaDeterminante(matrizAux) << endl;
cout << calculaDeterminante(matriz) << endl;
imprimeMatriz(matriz);

			a.push_back(calculaDeterminante(matrizAux)/calculaDeterminante(matriz));
		}
	
	}
}
#endif