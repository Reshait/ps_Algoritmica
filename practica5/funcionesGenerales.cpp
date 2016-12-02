#include "funcionesGenerales.hpp"

void introduzcaCantidadAcambiar(int &euros){
	cout << "Introduzca la cantidad en céntimos (ej 1€ = 100, 20€ = 2000) de su cambio ..:" << endl;
	cin >> euros;
}


void deEurosAcentimos(const int &euros, int &centimos){
	centimos = euros * 100;
}

void deCentimosAeuro(const int &centimos, int &euros){
	euros = centimos / 100;
}

void leerDelFichero(vector<Moneda> &vMonetario, string fichero){
	fstream f;
	int valor;
	string tipo;
	Moneda M("",0);
	f.open(fichero.c_str());

	if(f){
	    while ( f >> tipo >> valor){

			M.setTipo(tipo);
			M.setValor(valor);

			vMonetario.push_back(M);
	    } 

	    f.close(); 		
	}
	else
		cout << "Error. El fichero no existe" << endl;
}


bool encuentraValor(int valor, vector<Moneda> &vMonedas){
	bool encontrado = false;

	for(unsigned int i = 0; i < vMonedas.size(); i++)
		if(valor == vMonedas[i].getValor())
			encontrado = true;

	return encontrado;
}

/*
void cambio(int cantidadEnCentimos, vector<Moneda> &vMonetario, vector<Moneda> &vSolucion){
	int sumaParcial = 0, i = 0;
	Moneda mAux("",0);

	while( sumaParcial != cantidadEnCentimos){
		if(vMonetario[i].getValor() + sumaParcial <= cantidadEnCentimos){

			if(encuentraValor(vMonetario[i].getValor(), vSolucion)){			// Si el billete/moneda ya estaba en la solución, incrementa su cantidad de billetes/monedas

				for(unsigned int j = 0; j < vSolucion.size(); j++){ 			//revisar esto.
					if(vSolucion[j].getValor() == vMonetario[i].getValor())
						vSolucion[j].incrementaCantidad();
				}				
			}
			else{																// Si no, añade el nuevo tipo de billete/moneda con cantidad 1.
				mAux = vMonetario[i];
				mAux.setCantidad(1);
				vSolucion.push_back(mAux);
			}

			sumaParcial += vMonetario[i].getValor();

		}
		else
			i++;
	}

}
*/
