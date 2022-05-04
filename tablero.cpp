#include "tablero.h"
#include "jugadas.h"

using namespace std;

bool jugar(tTablero& tablero, tSoporte& soporte) {

	mostrar(soporte);
	char espacio = ' '; //Se imprime el soporte con los numeros de las posiciones
	int numespaciosiniciales = 9, numespacioscolor = 6;
	cout << setw(numespaciosiniciales) << setfill(espacio) << " ";
	for (int f = 1; f < soporte.contador + 1; f++) {
		cout << setw(numespacioscolor) << setfill(espacio) << f << "  ";
	}
	cout << "\n";

	tJugada jugada;
	int jcont = 0;

	cout << "\n";
	nuevaJugada(soporte, jugada, jcont); //Se crea una nueva jugada

	if (jcont >= 3) { //Si la jugada tiene 3 o mas fichas es una jugada nueva
		bool escalera = esEscalera(jugada); //Se recoge si la jugada es una escalera o serie
		bool serie = esSerie(jugada);
		if (escalera || serie) {
			for (int f = 0; f < jcont; f++) { //Se añade la jugada al tablero y se elimina del soporte
				tablero.jugadas[tablero.contador][f] = jugada[f];
				eliminarFicha(soporte, jugada[f]);
			}
			tablero.jugadas[tablero.contador][jcont] = { LIBRE, -1 }; //Se coloca el centinela
			tablero.contador++;

			if (escalera)
				cout << "  " << "- Escalera correcta!\n";
			if (serie)
				cout << "  " << "- Serie correcta!\n";
			return true;
		}
	}
	else if (jcont == 1) { //Si la jugada tiene 1 ficha es una ficha a añadir a una jugada existente
		cout << "\n";
		tFicha ficha = jugada[0], aux;
		tJugada jaux;
		int c = 0, d = 0, cjug = 0, posjug = -1, posfich = 0;
		bool iniciojugada = false;

		for (int j = 0; j < tablero.contador; j++) { //Se recogen todas las jugadas a las que se le puede meter una ficha 
			aux = tablero.jugadas[j][0];
			while (!fichaVacia(aux)) {
				jaux[c] = tablero.jugadas[j][d];
				d++; c++;
				aux = tablero.jugadas[j][d];
			}
			jaux[c + 1] = { LIBRE, -1 };
			if (puedePonerFicha(jaux, ficha, iniciojugada)) {
				cjug++;
				posjug = j;
			}
			c = 0; d = 0;
		}

		if (posjug != -1) { //Si se ha encontrado al menos una jugada en la que se puede colocar la ficha
			if (cjug == 1 && !iniciojugada) { //Si es solo una jugada y no es a su inicio (caso de escaleras) se coloca la ficha 
				cout << "Jugadas del tablero donde poner la ficha: " << posjug + 1;
				aux = tablero.jugadas[posjug][0];
				while (!fichaVacia(aux)) {
					posfich++;
					aux = tablero.jugadas[posjug][posfich];
				}
				tablero.jugadas[posjug][posfich] = ficha;
				tablero.jugadas[posjug][posfich + 1] = { LIBRE, -1 }; //Se coloca el centinela
				eliminarFicha(soporte, ficha);
				cout << "   -> Colocada!\n";
				return true;
			}
			else if (cjug == 1 && iniciojugada) { //Si es solo una jugada, y es a su inicio (caso de escaleras) se coloca la ficha
				cout << "Jugadas del tablero donde poner la ficha: " << posjug + 1;
				c = 1;
				aux = jugada[1];
				jaux[0] = ficha;
				while (!fichaVacia(aux)) {
					jaux[c] = aux;
					c++;
					aux = jugada[c];
				}
				jaux[c + 1] = { LIBRE, -1 }; //Se coloca el centinela
				eliminarFicha(soporte, ficha);
				cout << "   -> Colocada!\n";
				return true;
			}
			else if (cjug > 1) { //Si es mas de una jugada, se deja al jugador ponerla en una de las jugadas
				cout << "Jugadas del tablero donde poner la ficha: ";
				cin >> posjug;
				aux = tablero.jugadas[posjug][0];
				while (!fichaVacia(aux)) {
					posfich++;
					aux = tablero.jugadas[posjug][posfich];
				}
				tablero.jugadas[posjug][posfich] = ficha;
				tablero.jugadas[posjug][posfich + 1] = { LIBRE, -1 };
				eliminarFicha(soporte, ficha);
				cout << "-> Colocada!\n";
				return true;
			}
		}
		else {
			cout << "   - No es una jugada correcta! Prueba de nuevo...\n";
			return false;
		}

	}
	else {
		cout << "    - No es una jugada correcta! Prueba de nuevo...\n";
	}

	return false;
}

void mostrar(const tTablero& tablero) {
	cout << "Tablero:\n";
	tFicha aux;
	int c = 0;
	for (int j = 0; j < tablero.contador; j++) {
		cout << " " << j + 1 << ": ";
		aux = tablero.jugadas[j][0];
		while (!fichaVacia(aux)) {
			cout << fichaToString(aux) << "  ";
			c++;
			aux = tablero.jugadas[j][c];
		}
		c = 0;
		cout << "\n";
	}
	colorTexto(LIBRE);
}