#include "funcionesGenerales.hpp"

void introduzcaCantidadAcambiar(int &euros){
	cout << "Introduzca la cantidad de euros de su cambio ..:" << endl;
	cin >> euros;
}


void deEurosAcentimos(const int &euros, int &centimos){
	centimos = euros * 100;
}

void leerDelFichero(vector<Moneda> &vMonetario, string fichero){
	fstream f;
	int valor;
	string tipo;
	Moneda M("",0);

	f.open(fichero.c_str()); 

    while ( f >> tipo >> valor){

		M.setTipo(tipo);
		M.setValor(valor);

		vMonetario.push_back(M);
    } 

    f.close(); 
}

void cambio(int cantidadEnCentimos, vector<Moneda> &vMonetario, vector<int> &solucion){
	int sumaParcial = 0, x = 0, i = 0;

	while( sumaParcial != cantidadEnCentimos){
		x = vMonetario[i].getValor();
		if(x + sumaParcial <= cantidadEnCentimos){
			solucion[i]++;
			sumaParcial += x;
		}
		else
			i++;
	}

}



