//FP2 - RummyKub V.2
//Nombre y Apellidos: Beatriz Bueno Almagro 1ºB
#include "bolsa.h"

using namespace std;

void inicializarBolsa(tBolsa& bolsa, tAjustes ajustes) {
	for (int f = 0; f < 8; f++) {
		for (int c = 0; c < ajustes.numFichas; c++) { //inicializamos fichas para cada posición de la bolsa
			bolsa[f][c] = new tFicha{ inicializarColor(f), c + 1 };
		}
	}
}

void mostrar(const tBolsa& bolsa, tAjustes ajustes) {
	cout << "Bolsa...\n";
	for (int f = 0; f < 8; f++) {
		for (int c = 0; c < ajustes.numFichas; c++) {
			if (bolsa[f][c] != NULL) {
				if (c == ajustes.numFichas - 1) {
					cout << fichaToString(*bolsa[f][c]);
				}
				else {
					cout << fichaToString(*bolsa[f][c]) << "  ";
				}
			}
		}
		cout << "\n";
	}
	colorTexto(LIBRE);
	cout << "\n";
}

tFicha sacarFicha(tBolsa& bolsa, const tAjustes& ajustes) {
	//faux nos indica la fila de la bolsa en la que está la ficha

	bool encontrado = false;
	int cf = 0, c, f; //cf es un contador de las fichas recorridas, para no pasarnos ed 8
	int faux = numAleatorioFila();
	tFicha ficha;
	ficha.color = inicializarColor(faux);
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

	if (bolsa[faux][ficha.num] == NULL) { //Si la posicion en bolsa está vacia
		while (!encontrado && c < ajustes.numFichas && cf < NUM_COLORES * 2) { //Recorremos toda la bolsa hasta encontrar una ficha que no está vacía
			if (bolsa[f][c] != NULL) { //Si la ficha en la que estamos no está vacía, la sacamos
				aux = *bolsa[f][c];
				delete bolsa[f][c];
				bolsa[f][c] = NULL;
				encontrado = true;
			}
			if (c == ajustes.numFichas - 1) { // Ajustes de índices si se acaban las columnas
				if (f == (NUM_COLORES * 2) - 1) //Si esta fila es la 8 (última) se pasa a la primera
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
	else { //Si la pos no está vacía, simplemente se coge esa ficha
		aux = ficha;
		delete bolsa[faux][ficha.num - 1];
		bolsa[faux][ficha.num - 1] = NULL;
	}

	return aux;
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

void delBolsa(tBolsa bolsa, tAjustes ajustes) {
	for (int f = 0; f < NUM_COLORES; f++) {
		for (int c = 0; c < ajustes.numFichas; c++) {
			if (bolsa[f][c] != NULL)
				delete bolsa[f][c];
		}
	}
}