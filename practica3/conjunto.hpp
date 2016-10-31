#ifndef __CONJUNTO_HPP__
#define __CONJUNTO_HPP__

#include <vector>
#include <cstdlib>
#include <iostream>

template <class T> class Conjunto{
	private:
		vector<T> _v;
		int _nEle;
		
	public:
		Conjunto(int nElementos){
			setNumEle(nElementos);
			_v.clear();

			for(int i = 0; i < nElementos; i++){
				T a = rand()%9999 + 1;
				_v.push_back(a);	
			}				

		}

		T Maximo (const T numero1, const T numero2);
		T Minimo (const T numero1, const T numero2);
		inline void setNumEle(int nEle){ _nEle = nEle};
};
/*! 
	\fn    		void MaximoMinimo(const std::vector<int> &v, int n, int i, int j, int &maximo, int &minimo, int &llamadas_recursivas);
	\brief     	Función que calcula el maximo y el minimo elemento de un vector v, implementado usando 'divide y vencerás'
	\param     	v Vector de elementos
	\param     	nElementos Elementos del vector
	\param     	i indice inferior
	\param     	j indice superior
	\param     	maximo[ref] minimo elemento del vector v desde i hasta j
	\param     	minimo[ref] maximo elemento del vector v desde i hasta j
	\param		llamadas_recursivas[ref] numero de llamadas recursivas que genera la función recursiva

*/
void MaximoMinimo(const std::vector<int> &v, int nElementos, int indiceInferior, int indiceSuperior, int &maximo, int &minimo, int &llamadas_recursivas);

int Maximo (const int numero1, const int numero2);
int Minimo (const int numero1, const int numero2);

#endif