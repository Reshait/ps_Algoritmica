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

	public:
		//Moneda();
		Moneda(string tipo, int valor);

		const int getValor();
		const string getTipo();

		void setValor(const int &valor);
		void setTipo(const string &tipo);

		friend ostream & operator<<(ostream &stream, const Moneda &m);
		friend istream & operator>>(istream &stream, Moneda &m);

};

#endif