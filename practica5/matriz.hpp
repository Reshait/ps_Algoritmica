#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include <vector> 

using std::vector;

class Matriz{

	private:
		vector<vector<int> > m_;

	public:
		Matriz(const int &nFil, const int &nCol);

		inline int getColumnas() const;
		inline int getFilas() const;
//		inline vector<int> & operator[](const int indice);
		int& operator()(int posicionI, int posicionJ){
			    return m_[posicionI][posicionJ];
		}

};

#endif