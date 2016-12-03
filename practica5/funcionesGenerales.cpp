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


void cambio(vector<Moneda> &vMonetario, const int cantidad, vector<vector<unsigned int> > &matriz){

	for(unsigned int i = 0; i < vMonetario.size(); i++){
			matriz[i][0] = 0;
	}

	for(unsigned int i = 1; i < vMonetario.size(); i++){
		for(int j = 1; j <= cantidad; j++){
			if ( j < vMonetario[i].getValor() ) 
				if( i == 1)
					matriz[i][j] = INFINITO;
				else
					matriz[i][j] = matriz[i-1][j]; 
            else
            	matriz[i][j] = min(matriz[i-1][j], 1 + matriz[i][j - vMonetario[i].getValor()]);
		}
	}
//cout << matriz[vMonetario.size()-1][cantidad-1] << endl;
}



void solucion(vector<Moneda> &vMonetario, const int cantidad, vector<vector<unsigned int> > &matriz, vector<int> &vSolucion){

	for(int i = (int)vMonetario.size(), j = cantidad; i >= 1; i--){
		if(j >= 1){
			if(i == 1)
				vSolucion[i-1] = matriz[i][j];

			else if(matriz[i][j] < matriz[i-1][j]){
				vSolucion[i-1]++;
				j -= vMonetario[i].getValor();
			}			
		}

	}

	
}


void imprimeMatriz(const vector<vector<unsigned int> > &matriz){
	for(unsigned int i = 0; i < matriz.size(); i ++){
		for(unsigned int j = 0; j < matriz[i].size(); j++){
			if( matriz[i][j] == INFINITO)
				cout << "∞" << " ";
			else
				cout << matriz[i][j] << " " ;
		}
		cout << endl;
	}
}


void realizarCambio(){
	vector<Moneda> vMonetario;

	int centimos;
	introduzcaCantidadAcambiar(centimos);

	leerDelFichero(vMonetario, "candidadesDisponiblesParaCambio.txt");
				
	std::sort(vMonetario.begin(), vMonetario.end(), comparador()); 	// Ordena vector monetario en orden descendente con respecto el valor de los billetes/monedas.
		
	vector<vector<unsigned int> > Matriz(vMonetario.size(), vector<unsigned int>(centimos + 1));

	cambio(vMonetario, centimos, Matriz);

	vector <int> vSolucion (vMonetario.size(), 0);

	cout << "Imprimiendo vSolucion:" << endl;
	for(unsigned int i = 0; i < vSolucion.size(); i++)
		cout << vSolucion[i] << " " ;

	solucion(vMonetario, centimos, Matriz, vSolucion);

	cout << "Imprimiendo vSolucion:" << endl;
	for(unsigned int i = 0; i < vSolucion.size(); i++)
		cout << vSolucion[i] << " " ;

	imprimeMatriz(Matriz);

	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "Su cambio es..:" << endl;
//	imprimeVector(vSolucion);
	for(unsigned int i = 0; i<vSolucion.size(); i++)	
	{

		cout << vSolucion[i] <<" "<< vMonetario[i].getTipo() << " de ";

		if(vMonetario[i].getValor() > 50)
			cout << vMonetario[i].getValor()/100 << " €"<< endl;
		else
			cout << vMonetario[i].getValor() << " cts"<<endl;

	}
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;		

}
