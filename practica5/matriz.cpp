#include "matriz.hpp"

//Matriz::Matriz() {};

Matriz::Matriz(const int &nFil, const int &nCol){
	vector<int> filaCompleta;
	for(int i = 0; i < nCol; i++)				// relleno una fila con tantos 0 como celdas 
		filaCompleta.push_back(0);
	for(int i = 0; i < nFil; i++)				// inserto esa fila, todas las veces(filas) q debe haber
		m_.push_back(filaCompleta);
}
		
int Matriz::getColumnas() const{	
	return m_[0].size(); 
}


int Matriz::getFilas() const{ 
	return m_.size(); 
}

/*
vector<int> & Matriz::operator[](const int indice){ 
	return this->m_[indice]; 
}
*/

