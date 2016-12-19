#include "funcionesGenerales.hpp"
#include "cabecera.hpp"

using namespace std;

int main(){
	int opcion;
	cabecera(6);

	do{

		opcion = menu();

		switch(opcion){

				
			case 1:
				cabecera(6);
				imprimeEnunciado();

				realizarXreinas();

				introParaContinuar();

			break;


			case 0:
				cabecera(6);
				cout << "Saliendo ..." << endl;
			break;	


			default:
				cabecera(6);
				cout << "Opción introducida incorrecta." << endl;
				introParaContinuar();
			break;	
		}

	}while(opcion != 0);

}





































