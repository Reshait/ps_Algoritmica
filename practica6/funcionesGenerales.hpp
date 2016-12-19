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


void imprimeError(string const &comparacion, unsigned int const &nReinas);

void pideNumeroDeReinas(int &nReinas);

bool Lugar(int fil, vector<int> vReinas);

void imprimeTablero(vector <int> vReinas, int nReinas);

void realizarXreinas();

#endif