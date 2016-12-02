#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include <vector> 

using std::vector;

class Matriz{

	private:
		vector<vector<int> > m_;

	public:
		Matriz() {};

		inline int getColumnas() const;
		inline int getFilas() const;
		inline vector<int> & operator[](const int indice);

};

#endif