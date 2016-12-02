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


void cambio(const int cantidad, vector<Moneda> &vMonetario, vector<vector<int> > &matriz){
	int min;

	for(unsigned int i = 0; i <= vMonetario.size(); i++){
		for(int j = 0; j <= cantidad; j++){
			if(i == 0 && j < vMonetario[i].getValor()){
				matriz[i][j] = INFINITO;
			}

			else{
				if(i == 0){
					matriz[i][j] = 1 + matriz[i][j - vMonetario[0].getValor()];
				}
				else{
					if( j < vMonetario[i].getValor())
						matriz[i][j] = matriz[i-1][j];

					else{
						min = minimo(matriz[i-1][j], 1 + matriz[i][j - vMonetario[i].getValor()]);
						matriz[i][j] = min;
					}					
				}
			}
		}
	}
}


int minimo(const int a, const int b){
    if(a < b)
        return a;
    else
        return b;
};


void realizarCambio(){
	vector<Moneda> vMonetario;

	int centimos;
	introduzcaCantidadAcambiar(centimos);

	leerDelFichero(vMonetario, "candidadesDisponiblesParaCambio.txt");
				
	std::sort(vMonetario.begin(), vMonetario.end(), comparador()); 	// Ordena vector monetario en orden descendente con respecto el valor de los billetes/monedas.
		
//				cambio(centimos, vMonetario, vSolucion); 

	vector <int> vSolucion (vMonetario.size(), 0);
	vector<vector<int> > Matriz(vMonetario.size(), vector<int>(centimos+1));

//	Matriz Mat(vMonetario.size(), centimos+1);

	cambio(centimos+1, vMonetario, Matriz);

//	solucion(centimos+1, vSolucion, Mat, vMonetario);

	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "Su cambio es..:" << endl;
//	imprimeVector(vSolucion);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;		

}
