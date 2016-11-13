#include "cabecera.hpp"
#include "funcionesGenerales.hpp"
#include "moneda.hpp"

using namespace std;

int main(){
	int opcion, euros, centimos;
	cabecera(4);
	//Moneda M("hola", 5);
	vector<Moneda> vMonetario;

	do{
		opcion = menu();

		switch(opcion){

				
			case 1:
				cabecera(4);
				cout << "\t┏━━━━━━━━━━━━━━━━━━━┓" << endl;
				cout << "\t┃ Cambio de Monedas ┃" << endl;
				cout << "\t┗━━━━━━━━━━━━━━━━━━━┛" << endl;	

				introduzcaCantidadAcambiar(euros);

				deEurosAcentimos(euros, centimos);

				leerDelFichero(vMonetario, "cantidadesDisponiblesParaCambio.txt");

				std::sort(vMonetario.begin(), vMonetario.end(), comparador()); 	// Ordena vector monetario en orden descendente(valor).

				//cambio(centimos, vMonetario, vSolucion); a Moneda tengo que añadirle otro valor que sea cantidad.



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