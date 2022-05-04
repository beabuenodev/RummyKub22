#include "colores.h"
#include "fichas.h"
#include "bolsa.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void inicializarBolsa(tBolsa& bolsa, tAjustes ajustes) {
	tFicha aux;

	for (int f = 0; f < 8; f++) {
		for (int c = 0; c < ajustes.numFichas; c++) { //inicializamos fichas para cada posición de la bolsa
			aux.num = c + 1;
			inicializarColor(aux, f);
			bolsa[f][c] = aux;
		}
	}
}

void mostrar(const tBolsa& bolsa, tAjustes ajustes) {
	cout << "Bolsa...\n";
	for (int f = 0; f < 8; f++) {
		for (int c = 0; c < ajustes.numFichas; c++) {
			if (c == ajustes.numFichas - 1) {
				cout << fichaToString(bolsa[f][c]) << "\n";
			}
			else {
				cout << fichaToString(bolsa[f][c]) << "  ";
			}
		}
	}
	cout << "\n";
}

tFicha sacarFicha(tBolsa& bolsa, tFicha ficha, int faux, const tAjustes& ajustes) {
	//faux nos indica la fila de la bolsa en la que está la ficha

	bool encontrado = false;
	int cf = 0, c, f; //cf es un contador de las fichas recorridas, para no pasarnos ed 8

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

	if (fichaVacia(bolsa, ficha, faux)) { //Si la posicion en bolsa está vacia
		while (!encontrado && c < ajustes.numFichas && cf < NUM_COLORES * 2) { //Recorremos toda la bolsa hasta encontrar una ficha que no está vacía
			if (!fichaVacia(bolsa, bolsa[f][c], f)) { //Si la ficha en la que estamos no está vacía, la sacamos
				aux = bolsa[f][c];
				bolsa[f][c] = { LIBRE, -1 };
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
		bolsa[faux][ficha.num - 1] = { LIBRE, -1 };
	}

	return aux;
}

bool fichaVacia(const tBolsa& bolsa, const tFicha& ficha, int f) { //funcion para ver si una ficha está vacía en la bolsa
	tFicha fichavacia = { LIBRE, -1 };

	if (bolsa[f][ficha.num - 1] == fichavacia || ficha.num == -1)
		return true;
	else
		return false;
}