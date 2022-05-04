//FP2 - RummyKub V.2
//Nombre y Apellidos: Beatriz Bueno Almagro 1�B
#include "bolsa.h"

using namespace std;

void inicializarBolsa(tBolsa& bolsa, tAjustes ajustes) {
	tFichaPtr aux;

	for (int f = 0; f < 8; f++) {
		for (int c = 0; c < ajustes.numFichas; c++) { //inicializamos fichas para cada posici�n de la bolsa
			aux->num = c + 1;
			inicializarColor(*aux, f);
			bolsa[f][c] = aux;
		}
	}
}

void mostrar(const tBolsa& bolsa, tAjustes ajustes) {
	cout << "Bolsa...\n";
	for (int f = 0; f < 8; f++) {
		for (int c = 0; c < ajustes.numFichas; c++) {
			if (c == ajustes.numFichas - 1) {
				cout << fichaToString(*bolsa[f][c]) << "\n";
			}
			else {
				cout << fichaToString(*bolsa[f][c]) << "  ";
			}
		}
	}
	colorTexto(LIBRE);
	cout << "\n";
}

tFicha sacarFicha(tBolsa& bolsa, const tAjustes& ajustes) {
	//faux nos indica la fila de la bolsa en la que est� la ficha

	bool encontrado = false;
	int cf = 0, c, f; //cf es un contador de las fichas recorridas, para no pasarnos ed 8
	int faux = numAleatorioFila();
	tFicha ficha;
	inicializarColor(ficha, faux);
	ficha.num = numAleatorioColumna(ajustes) + 1;

	if (ficha.num >= ajustes.numFichas) { // Ajuste de fila/columna inicial, si la columna es la ultima
		c = 0; // Se pasa al inicio de la siguiente fila 
		if (faux + 1 >= NUM_COLORES * 2) //Si la fila es la ultima se inicializa con la primera
			f = 0;
		else
			f = faux + 1;
		cf++;
	}
	else { //Si no hay casos especiales se inicializa normal
		cf = 0; c = ficha.num, f = faux;
	}

	tFicha aux;

	if (fichaVacia(bolsa, ficha, faux)) { //Si la posicion en bolsa est� vacia
		while (!encontrado && c < ajustes.numFichas && cf < NUM_COLORES * 2) { //Recorremos toda la bolsa hasta encontrar una ficha que no est� vac�a
			if (!fichaVacia(bolsa, *bolsa[f][c], f)) { //Si la ficha en la que estamos no est� vac�a, la sacamos
				aux = *bolsa[f][c];
				delete bolsa[f][c];
				encontrado = true;
			}
			if (c == ajustes.numFichas - 1) { // Ajustes de �ndices si se acaban las columnas
				if (f == (NUM_COLORES * 2) - 1) //Si esta fila es la 8 (�ltima) se pasa a la primera
					f = 0;
				else
					f++;
				cf++;
				c = 0;
			}
			else {
				c++;
			}
		}
	}
	else { //Si la pos no est� vac�a, simplemente se coge esa ficha
		aux = ficha;
		delete bolsa[faux][ficha.num - 1];
	}

	return aux;
}

bool fichaVacia(const tBolsa& bolsa, const tFicha& ficha, int f) { //funcion para ver si una ficha est� vac�a en la bolsa
	tFicha fichavacia = { LIBRE, -1 };

	if (bolsa[f][ficha.num - 1] == fichavacia || ficha.num == -1)
		return true;
	else
		return false;
}

int numAleatorioFila() {
	int numero;
	numero = rand() % NUM_COLORES * 2;
	return numero;
}

int numAleatorioColumna(tAjustes ajustes) {
	int numero;
	numero = rand() % ajustes.numFichas;
	return numero;
}