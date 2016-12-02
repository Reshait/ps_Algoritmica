#include "matriz.hpp"

//Matriz::Matriz() {};
		
int Matriz::getColumnas() const{	
	return m_[0].size(); 
}


int Matriz::getFilas() const{ 
	return m_.size(); 
}


vector<int> & Matriz::operator[](const int indice){ 
	return this->m_[indice]; 
}