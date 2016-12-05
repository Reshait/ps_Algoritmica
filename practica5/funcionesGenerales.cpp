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
	int n = (int)matriz.size();
	int N = (int)matriz[0].size();

    for (int i = 0; i < n; i++)
        matriz[i][0] = 0;	

  	for(int i = 0; i < n; i++){
  		for(int j = 0; j < N; j++){

			if( i == 0 && j < vMonetario[i].getValor() ) 
				matriz[i][j] = INFINITO;				

			else{
				if( i == 0)
					matriz[i][j] = 1 + matriz[i][j - vMonetario[i].getValor()];

				else{
					if( j > vMonetario[i].getValor()){
						int x = matriz[i-1][j];
						int y = 1 + matriz[i][j - vMonetario[i].getValor()];
						matriz[i][j] = min(x,y);						
					}
					else {
							matriz[i][j] = matriz[i-1][j];
					}
				}
			}

    	}
    }
}


// sacado de http://www.aprenderaprogramar.com/foros/index.php?topic=2069.0
void solucion(vector<Moneda> &vMonetario, const int cantidad, vector<vector<unsigned int> > &matriz, vector<int> &vSolucion){

        int i = (int)matriz.size()-1;       
        int j = (int)matriz[0].size()-1;        

        while(j>1){										//porque mi primera columna es inservible (todo infinito)
            if(i>1 && matriz[i][j]==matriz[i-1][j]){
                i--;
            }
            else{
                vSolucion[i]++;
                j = j - vMonetario[i].getValor();
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
				
	std::sort(vMonetario.begin(), vMonetario.end(), comparador()); 								// Ordena vector monetario en orden ascendente con respecto el valor de los billetes/monedas.

	vector<vector<unsigned int> > Matriz(vMonetario.size(), vector<unsigned int>(centimos+2));	// Normalmente sería +1 para tener la columna 0, pero como no puedo eliminar que me meta en la primera columna el infinito, por eso es +2

	cambio(vMonetario, centimos, Matriz);

	vector <int> vSolucion (vMonetario.size(), 0);

	solucion(vMonetario, centimos, Matriz, vSolucion);

	cout << "La tabla de ilustración del procedimiento del cambio queda:" << endl;
	imprimeMatriz(Matriz);

	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "Su cambio es..:" << endl;
	muestraCambio(vSolucion, vMonetario);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;		
}


void imprimeVectorMonedas(vector<Moneda> Vec){
	for(unsigned int i = 0; i < Vec.size(); i++)
		cout << Vec[i] << " " ;
	cout << endl;	
}

template <typename T>
void imprimeVector(vector<T> Vec){
	for(unsigned int i = 0; i < Vec.size(); i++)
		cout << Vec[i] << " " ;
	cout << endl;		
}

void muestraCambio(vector<int> vSolucion, vector<Moneda> vMonetario){
	for(int i = 0; i < (int)vSolucion.size(); i++){
		cout << vSolucion[i] << " " << vMonetario[i].getTipo() << " de ";

		if(vMonetario[i].getValor() > 50)
			cout << vMonetario[i].getValor()/100 << " €" << endl;

		else
			cout << vMonetario[i].getValor() << " cts" << endl;
	}
}
