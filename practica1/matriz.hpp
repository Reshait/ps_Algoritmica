#include <cmath>
#include <numeric>

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
					_m[i][j] = (rand() % 20000) - 10000;
					_m[i][j] /= 1000;
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
					cout << _m[i][j] << "\t";
					
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
//    if (getTam() == 2){
        fRet = m[0][0] * m[1][1] - m[1][0] * m[0][1];
//    }
		    
//    else if (getTam() == 1)
//    	fRet = _m[0][0];
/*
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
*/	     
    return fRet;
}

void copiaMatriz(double original[][2], double copia[][2]){
	for(int i= 0; i < 2; i ++)
		for(int j = 0; j < 2; j++)
			copia[i][j] = original[i][j];
}

void Cramer(const vector<double> &vectorNi, const vector<double> &vectorTi, vector<double> &a ){
	double N = vectorNi.size();
	double sumNi = std::accumulate(vectorNi.begin(), vectorNi.end(), 0);
	double sumTi = std::accumulate(vectorTi.begin(), vectorTi.end(), 0);
	double sumNi_Ti;
	double matriz[2][2], matrizAux[2][2];

	matriz[0][0] = N;
	matriz[0][1] = sumNi;
	matriz[1][0] = matriz[0][1];
	matriz[1][1] = pow(matriz[1][0],2);

	vector<double> vectorNi_Ti = vectorNi * vectorTi;
	sumNi_Ti = std::accumulate(vectorNi_Ti.begin(), vectorNi_Ti.end(), 0);

	for(int i = 0; i < 2; i++){
		copiaMatriz(matriz, matrizAux);
		matrizAux[i][0] = sumTi;
		matrizAux[i][1] = sumNi_Ti; 	
		
		a.push_back(calculaDeterminante(matrizAux) / calculaDeterminante(matriz));	
	}

}



#endif