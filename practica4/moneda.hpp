#ifndef __MONEDA_HPP__
#define __MONEDA_HPP__

#include <iostream>
#include <cstring>

using std::istream;
using std::ostream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Moneda{
	private:
		string tipo_;
		int valor_;
		int cantidad_;

	public:
		//Moneda();
		Moneda(string tipo, int valor);

		int getValor();
		string getTipo();
		int getCantidad();

		void setValor(const int &valor);
		void setTipo(const string &tipo);
		void setCantidad(const int &cantidad);
		void incrementaCantidad();
		void decrementaCantidad();

		friend ostream &operator<< (ostream &salida, const Moneda &M);
		friend istream & operator>>(istream &stream, Moneda &M);

};

#endif