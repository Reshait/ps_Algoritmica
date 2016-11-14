#include "moneda.hpp"


Moneda::Moneda(string tipo, int valor){
	setTipo(tipo);
	setValor(valor);
	setCantidad(1);
}

int Moneda::getValor(){
	return valor_;
}

string Moneda::getTipo(){
	return tipo_;
}

int Moneda::getCantidad(){
	return cantidad_;
}

void Moneda::incrementaCantidad(){
	cantidad_++;
}
void Moneda::decrementaCantidad(){
	cantidad_--;
}

void Moneda::setValor(const int &valor){
	valor_ = valor;
}

void Moneda::setTipo(const string &tipo){
	tipo_.assign(tipo);
}

void Moneda::setCantidad(const int &cantidad){
	cantidad_ = cantidad;
}

ostream &operator<< (ostream &salida, const Moneda &M){
	salida << M.tipo_ << "\t" << M.valor_ << endl;
	return salida;
}

istream & operator>>(istream &stream, Moneda &M){
	int valor;
	string tipo;

	cout << endl << "Introduzca el tipo [billete/moneda] ..:" << endl;
	stream >> tipo;
	M.setTipo(tipo);

	cout << endl << "Introduzca el valor del/la billete/moneda ..:" << endl;
	stream >> valor;
	M.setValor(valor);

	return stream;
}

