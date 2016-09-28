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
  \brief Definición clase DatosEntrada creada para los datos de entrada a pedir por el teclado.
  \post Ninguna
*/
class DatosEntrada{
	private:
        //! \name Atributos privados de la clase DatosEntrada
		int _min;
		int _max;
		int _inc;

    //! \name Métodos públicos de la clase DatosEntrada     	
	public:
		DatosEntrada(){
			setMin(0);
			setMax(0);
			setInc(0);
		}
		inline const int getMin(){ return _min; }
		inline const int getMax(){ return _max; }
		inline const int getInc(){ return _inc; }
		void setMin(int min){ _min = min; }
		void setMax(int max){ _max = max; }
		void setInc(int inc){ _inc = inc; }

		/*! 
		  \brief Pide los datos necesarios para comenzar la práctica.
		  \post Ninguna
		  \sa pideDatos()
		  \param niguno
		*/
		void pideDatos(){
			int valor;

			cout << "Introduzca el valor mínimo.: ";
			cin >> valor;
			setMin(valor);

			do{
				cout << "Introduzca el valor máximo.: ";
				cin >> valor;
				setMax(valor);

				if(getMax() <= getMin()){
					cout << "ERROR. El valor MÁXIMO no puede ser igual o menor que el valor MÍNIMO." << endl;
				}
			}while(getMax() <= getMin());

			do{
				cout << "Introduzca el valor incremental.: ";
				cin >> valor;
				setInc(valor);

				if(getInc() < 1){
					cout << "ERROR. El valor INCREMENTAL no puede ser menor que 1." << endl;
				}		
			}while(getInc() < 1);

		}
		/*! 
		  \brief Imprime los datos necesarios para comenzar la práctica.
		  \post Ninguna
		  \sa pideDatos()
		  \param ninguno
		*/
		const void imprimeDatos(){
			cout << "Los valores son:" << endl;
			cout << "Valor min..: " << getMin() << endl;
			cout << "Valor max..: " << getMax() << endl;
			cout << "Valor inc..: " << getInc() << endl;	
		}
};

#endif