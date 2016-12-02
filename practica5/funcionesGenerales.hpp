#ifndef __FUNCIONES_GENERALES__
#define __FUNCIONES_GENERALES__
#define INFINITO std::numeric_limits<int>::max();

#include <limits>
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>    			// std::sort
#include "moneda.hpp"
#include "matriz.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::fstream;

void introduzcaCantidadAcambiar(int &euros);

void deEurosAcentimos(const int &euros, int &centimos);

void deCentimosAeuro(const int &centimos, int &euros);

void leerDelFichero(vector<Moneda> &vMonetario, string fichero);

bool encuentraValor(int valor, vector<Moneda> &vMonedas);

void cambio(int cantidadEnCentimos, vector<Moneda> &vMonetario, vector<Moneda> &solucion);

struct comparador{ 					// de http://www.cplusplus.com/reference/algorithm/sort/?kw=sort
	bool operator()(Moneda &M1, Moneda &M2){ return M1.getValor() > M2.getValor(); }
};

void imprimeVector(vector<Moneda> &vMonetario);

int minimo(const int a, const int b);

void realizarCambio();


#endif