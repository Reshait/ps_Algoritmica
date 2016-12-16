#ifndef __TABLERO_HPP__
#define __TABLERO_HPP__

#include <iostream>
#include <cstring>
#include <vector>

using std::istream;
using std::ostream;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Tablero{
	private:
		vector<vector<bool> > _tab;

	public:
		Tablero(const int &tamanio);

		void setTamanio(const int &tamanio);

		void imprimeTablero();

		bool esCeldaUtil(int fil, int col);

		bool resolverNreinas(int col);

};

#endif