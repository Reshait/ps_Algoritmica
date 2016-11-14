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
	int valor, cantidad;
	string tipo;
	Moneda M("",0);

	f.open(fichero.c_str()); 

    while ( f >> tipo >> valor >> cantidad){

		M.setTipo(tipo);
		M.setValor(valor);
		M.setCantidad(cantidad);

		vMonetario.push_back(M);
    } 

    f.close(); 
}

void cambio(int cantidadEnCentimos, vector<Moneda> &vMonetario, vector<Moneda> &vSolucion){
	int sumaParcial = 0, i = 0;

	while( sumaParcial != cantidadEnCentimos){
		if(vMonetario[i].getValor() + sumaParcial <= cantidadEnCentimos){

			vSolucion[i].incrementaCantidad();
			vSolucion[i].setValor(vMonetario[i].getValor());
			vSolucion[i].setTipo(vMonetario[i].getTipo());
			sumaParcial += vMonetario[i].getValor();

		}
		else
			i++;
	}

}

void imprimeVector(vector<Moneda> &vMonetario){
    for(unsigned int i = 0; i < vMonetario.size(); i++)
        cout << vMonetario[i].getCantidad() << " " << vMonetario[i].getTipo() << " de " << vMonetario[i].getValor() << endl; 
    cout << endl;     
}



