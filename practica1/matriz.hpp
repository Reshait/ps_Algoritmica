/*! 
  \file     mamtriz.hpp
  \brief    Función y Estructura correspondiente para rellenar los datos de entrada.
  \author   Teófilo Rojas Mata
  \date     28/09/2016
*/

#ifndef __MATRIZ_HPP__
#define __MATRIZ_HPP__

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
					_m[i][j] = (rand() % 10) - 10;
				}
			}
		}

		inline const int getTam(){ return _tam; }
		inline void setTam(int tam){ _tam = tam; }


		void imprimeMatriz(){
			int cuentaIntro = 0;

			for(int i = 0; i < getTam(); i++){
				for(int j = 0; j < getTam(); j++){
					cout << _m[i][j] << "  ";
					
					cuentaIntro ++;					
					if(cuentaIntro == getTam()){
						cout << endl;
						cuentaIntro = 0;
					}
				}
			}
		}
	
};

#endif