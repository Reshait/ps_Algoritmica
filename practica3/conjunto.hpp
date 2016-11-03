#ifndef __CONJUNTO_HPP__
#define __CONJUNTO_HPP__

#include <vector>
#include <cstdlib>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

template <class T> 
class Conjunto{
	private:
		vector<T> _v;
		unsigned int _nEle;
		
	public:
		Conjunto(int nElementos){
			if(nElementos <= 0)
				cout << "Error: el conjunto debe tener al menos un elemento" << endl;

			else{
				setNumEle(nElementos);
				_v.clear();

				for(int i = 0; i < nElementos; i++){
					T a = rand()%9999 + 1;
					_v.push_back(a);	
				}					
			}	

		}

		void meteElementoAlFinal(T const&);
		void sacaUltimoElemento();
		T ultimoElemento();
		inline bool vacia() const{ return _v.empty();}
//		inline unsigned int tamanio(){ return _v.size(); }
		inline int tamanio(){ return _nEle; }		
		void imprime();

		T Maximo (const T numero1, const T numero2);
		T Minimo (const T numero1, const T numero2);
		inline void setNumEle(int nEle){ _nEle = nEle;}

		void eliminaPosicion(int posicion){
			if(posicion < 0)
				cout << "Error: la posición a eliminar debe ser 0 o mayor" << endl;

			else if(posicion > this->tamanio)
				cout << "Error: la posición a eliminar debe ser menor que" << this->tamanio()-1 << endl;

			else{
				for(int i = posicion; i < this->tamanio(); i++){
					_v[i-1] = _v[i];
				}
				_nEle--;
				this->sacaUltimoElemento();
			}
		}
		T posicion(int posicion){
			return _v[posicion];
		}

		void MaximoMinimo(int i, int j, int &maximo, int &minimo, int &llamadas_recursivas);

		bool compruebaMaximoEsMaximo(T const &maximo){
			for(int i = 0; i < this->tamanio(); i++){
				if(maximo < _v[i])
					return false;					
			}
			return true;
		}
		bool compruebaMinimoEsMinimo(T const &minimo){
			for(int i = 0; i < this->tamanio(); i++){
				if(minimo > _v[i])
					return false;					
			}
			return true;
		}		
};


template <class T>
void Conjunto<T>::meteElementoAlFinal(T const& elem){ _v.push_back(elem); }


template <class T>
void Conjunto<T>::sacaUltimoElemento(){
	if(this->vacia())
		cout << "ERROR. El conjunto de elementos está vacío" << endl;
	else
		_v.pop_back();
}


template <class T>
T Conjunto<T>::ultimoElemento(){
	if(this->vacia())
		cout << "ERROR. El conjunto de elementos está vacío" << endl;
	else
		return _v.back();
}


template <class T>
void Conjunto<T>::imprime(){
	cout << "Su conjunto de elementos es..:" << endl;
	
	for(int i = 0; i < this->tamanio(); i++)
		cout << this->_v[i] << "\t"; 
	cout << endl;     
}


template <class T>
T Conjunto<T>::Minimo(const T a, const T b){
	if(a < b)
		return a;
	else
		return b;
}


template <class T>
T Conjunto<T>::Maximo(const T a, const T b){
	if(a > b)
		return a;
	else
		return b;
}


template <class T>
void Conjunto<T>::MaximoMinimo(int i, int j, int &maximo, int &minimo, int &llamadas_recursivas){
	
	int maximo1,maximo2,minimo1,minimo2;

	if(i == j){
		maximo = this->posicion(i); 
		minimo = maximo;
	}

	else {
		if(i == j-1){
			if(this->posicion(i) < this->posicion(j)){
				maximo = this->posicion(j);
				minimo = this->posicion(i);
			}
			
			else{
				maximo = this->posicion(i);
				minimo = this->posicion(j);
			}
		}

		else{
			int mitad = (i+j)/2;

			llamadas_recursivas++;
			MaximoMinimo(i,mitad,maximo1,minimo1,llamadas_recursivas);
			llamadas_recursivas++;
			MaximoMinimo(mitad+1,j,maximo2,minimo2,llamadas_recursivas);

			maximo = Maximo(maximo1,maximo2);
			minimo = Minimo(minimo1,minimo2);
		}
	}
}


#endif