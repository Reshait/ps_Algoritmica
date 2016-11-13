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

		int getValor();
		string getTipo();

		void setValor(const int &valor);
		void setTipo(const string &tipo);

		friend ostream &operator<< (ostream &salida, const Moneda &M){
			salida << M.tipo_ << "\t" << M.valor_ << endl;
			//salida << M.valor_;
			return salida;			
		}
		//friend istream & operator>>(istream &stream, Moneda &M);

};

#endif