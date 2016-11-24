#include "cabecera.hpp"
#include "funcionesGenerales.hpp"
#include "moneda.hpp"

using namespace std;

int main(){
	int opcion, centimos;
	//int euros;
	cabecera(4);
	vector<Moneda> vMonetario, vSolucion;

	do{
		vMonetario.clear();
		vSolucion.clear();

		opcion = menu();

		switch(opcion){

				
			case 1:
				cabecera(4);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ Cambio de Monedas ┃" << endl;
				cout << "\t┗━━━━━━━━━━━━━━━━━━━┛" << endl;	

				introduzcaCantidadAcambiar(centimos);

				leerDelFichero(vMonetario, "candidadesDisponiblesParaCambio.txt");
				
				std::sort(vMonetario.begin(), vMonetario.end(), comparador()); 	// Ordena vector monetario en orden descendente con respecto el valor de los billetes/monedas.
		
				cambio(centimos, vMonetario, vSolucion); 

				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "Su cambio es..:" << endl;
				imprimeVector(vSolucion);
				cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;				

				introParaContinuar();

			break;


			case 0:
				cabecera(4);
				cout << "Saliendo ..." << endl;
			break;	


			default:
				cabecera(4);
				cout << "Opción introducida incorrecta." << endl;
				introParaContinuar();
			break;	
		}

	}while(opcion != 0);

}