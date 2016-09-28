/*! 
  \file     datosEntrada.hpp
  \brief    Función y Estructura correspondiente para rellenar los datos de entrada.
  \author   Teófilo Rojas Mata
  \date     28/09/2016
*/

#ifndef __DATOS_ENTRADA_HPP__
#define __DATOS_ENTRADA_HPP__

using std::cout;
using std::cin;
using std::endl;

/*! 
  \brief Estructura creada para los datos de entrada a pedir por el teclado.
  \post Ninguna
  \sa stEntrada()
*/
struct stEntrada{
	int min;
	int max;
	int inc;
	/*! 
  	\brief Constructor de inicialización de datos
  	\post Ninguna
  	\sa stEntrada()
	*/
	stEntrada(){
		min = 0;
		max = 0;
		inc = 0;
	}
};

/*! 
  \brief Pide los datos necesarios para comenzar la práctica.
  \post Ninguna
  \sa pideDatos()
  \param Entrada, tipo structura Entrada pasado por referencia.
*/
void pideDatos(stEntrada &Entrada){
	cout << "Introduzca el valor mínimo.: ";
	cin >> Entrada.min;

	do{
		cout << "Introduzca el valor máximo.: ";
		cin >> Entrada.max;	
		if(Entrada.max <= Entrada.min){
			cout << "ERROR. El valor MÁXIMO no puede ser igual o menor que el valor MÍNIMO." << endl;
		}
	}while(Entrada.max <= Entrada.min);

	do{
		cout << "Introduzca el valor incremental.: ";
		cin >> Entrada.inc;
		if(Entrada.inc < 1){
			cout << "ERROR. El valor INCREMENTAL no puede ser menor que 1." << endl;
		}		
	}while(Entrada.inc < 1);

}

/*! 
  \brief Imprime los datos necesarios para comenzar la práctica.
  \post Ninguna
  \sa pideDatos()
  \param Entrada, tipo structura Entrada pasado por referencia.
*/
void imprimeDatos(stEntrada &Entrada){
	cout << "Los valores son:" << endl;
	cout << "Valor min..: " << Entrada.min << endl;
	cout << "Valor max..: " << Entrada.max << endl;
	cout << "Valor inc..: " << Entrada.inc << endl;	
}

#endif