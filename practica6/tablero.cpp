#include "tablero.hpp"
#define GREEN "\e[32m"   //!< GREEN
#define WHITE "\e[37m"   //!< WHITE


Tablero::Tablero(const int &tamanio){
	setTamanio(tamanio);
}


void Tablero::setTamanio(const int &tamanio){
	vector<bool> aux (tamanio, 0);

	for(int i = 0; i < tamanio; i++)
		_tab.push_back(aux);
}

/*
void Tablero::imprimeTablero(){
	for(int i = 0; i < (int)_tab.size(); i++){
		for(int j = 0; j < (int)_tab.size(); j++)
			cout << " " << _tab[i][j] << " ";
		cout << endl;
	}

}
*/

void Tablero::imprimeTablero(){
	for(int i = 0; i < (int)_tab.size(); i++){
		cout << "\t"; 
		for(int j = 0; j < (int)_tab.size(); j++){
			if(_tab[i][j] == true)	//Para Imprimir los 1s en color
			cout << " " << "\x1b[" << _tab[i][j] << " ";

			cout << " " << _tab[i][j] << " ";
			
			if(_tab[i][j] == 1)	//Para Imprimir los 1s en color	
			    WHITE;			
		}

		cout << endl;
	}

}


bool Tablero::esCeldaUtil(int fil, int col){
	for(int i = 0; i < col; i++)
		if(_tab[fil][i])			//compruebo que no hay colisión izqda
			return false;

	for(int i = fil, j = col; i >= 0 && j>=0; i--, j--)
		if(_tab[i][j])			//compruebo que no hay colisión diagonal iqda superior
			return false;

	for(int i = fil, j = col; j >= 0 && i < (int)_tab.size(); i++, j--)
		if(_tab[i][j])			//compruebo que no hay colisión diagonal iqda inferior
			return false;

	return true;
}

bool Tablero::resolverNreinas(int col){
	if(col >= (int)_tab.size())		//si todas las reinas estan puestas devuelvo true (para recursivo)
		return true;

	for(int i = 0; i < (int)_tab.size(); i++){
		if(esCeldaUtil(i, col)){	//pone reina en celda util
			_tab[i][col] = 1;

			if( resolverNreinas(col + 1))
				return true;		//recursivo con la siguiente columna

			_tab[i][col] = 0;		//si ponerlo en la tabla[i][col] no permite una solución, borro la reina que tenía puesta actual, para el Backtrack
		}
	}
									//si la reina no se puede poner en ninguna celda de la columna col, devuelve falso
	return false;
}

