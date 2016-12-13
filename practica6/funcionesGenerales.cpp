#include "funcionesGenerales.hpp"

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

void realizarXreinas(){
	unsigned int nReinas;

	pideNumeroDeReinas(nReinas);
}