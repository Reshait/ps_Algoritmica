#include "funcionesGenerales.hpp"
#include "tablero.hpp"

void imprimeError(string const &comparacion, unsigned int const &nReinas){
    system("tput setaf 1");
	cout << "ERROR: El número de reinas debe ser " << comparacion << " que " << nReinas << endl;
    system("tput sgr0");	
}

void pideNumeroDeReinas(int &nReinas){
	do{
		cabecera(6);		
		imprimeEnunciado();

		cout << "Introduzca un número entero de reinas..:  ";
		cin >> nReinas;	

		if(nReinas < 1){

			string comparacion;

			if(nReinas  == 0)
				comparacion = "mayor";

			imprimeError(comparacion, nReinas);

			introParaContinuar();	
		}	

	}while(nReinas < 1);

}

bool Lugar(int fil, vector<int> vReinas){
	for(int i = 0; i < fil; i++){
		if(vReinas[i] == vReinas[fil] || abs(vReinas[i] - vReinas[fil]) == abs(i - fil))
			return false;
	}

	return true;
}

void imprimeTablero(vector <int> vReinas, int nReinas){
	for(int i = 0; i < nReinas; i++){
		cout << "\t"; 
		for(int j = 0; j < nReinas; j++){
			if(vReinas[i] == j+1)
			    cout << "\033[1;32m 1\033[0m" << " ";
			else
				cout << " 0 ";
		}

		cout << endl;
	}

}

void realizarXreinas(){
	vector<int> vReinas (1,0);
	vector<vector<int> > vSolucion;
	int k = 0; //apunto a la primera fila
	int nReinas;

	pideNumeroDeReinas(nReinas);

	while( k >= 0 ){
		vReinas[k]++;

		while( (vReinas[k] <= nReinas) && (Lugar(k, vReinas) == false) )
			vReinas[k]++;

		if(vReinas[k] <= nReinas){
			if( k == nReinas-1){
				imprimeTablero(vReinas, nReinas);
				vSolucion.push_back(vReinas);
			}
			else{
				k++;
				vReinas[k] = 0;
			}
		}
		else
			k++;
	}

}