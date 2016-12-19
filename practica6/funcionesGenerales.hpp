#ifndef __FUNCIONES_GENERALES__
#define __FUNCIONES_GENERALES__

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

#include "cabecera.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::abs;

bool Lugar (int fila, vector<int> vReinas);

void imprimirTablero (vector<int> vReinas, int nReinas);

void realizarXreinas ();

void imprimeError(string const &comparacion, int const &nReinas);

void pideNumeroDeReinas(int &nReinas);

bool pideDibujarTableros();

void imprimeInfoSoluciones(vector < vector<int> > const &vSolucion, int nReinas);

#endif