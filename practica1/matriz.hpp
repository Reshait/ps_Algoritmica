#include <cmath>

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

#endif