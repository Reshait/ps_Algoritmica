#include "funcionesGenerales.hpp"
#include "tablero.hpp"

void imprimeError(string const &comparacion, unsigned int const &nReinas){
    system("tput setaf 1");
	cout << "ERROR: El número de reinas debe ser " << comparacion << " que " << nReinas << endl;
    system("tput sgr0");	
}

void pideNumeroDeReinas(unsigned int &nReinas){
	do{
		cabecera(6);		
		imprimeEnunciado();

		cout << "Introduzca un número entero de reinas..:  ";
		cin >> nReinas;	

		if(nReinas > 8 || nReinas < 1){

			string comparacion;

			if(nReinas > 8)
				comparacion = "menor";

			else if(nReinas  == 0)
				comparacion = "mayor";

			imprimeError(comparacion, nReinas);

			introParaContinuar();	
		}	

	}while(nReinas > 8 || nReinas < 1);

}

bool realizarXreinas(){
	unsigned int nReinas;

	pideNumeroDeReinas(nReinas);

	Tablero Tablero((int)nReinas);

	if( Tablero.resolverNreinas(0) == false){
	    system("tput setaf 1");
		cout << "La solución a este tablero no existe" << endl;
	    system("tput sgr0");
		return false;
	}

	cout << "La solución a su tablero es la siguiente:" << endl;
	Tablero.imprimeTablero();
	return true;
}