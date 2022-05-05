#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "soporte.h"
#include "jugadas.h"

using namespace std;

void inicializarSoporte(tSoporte soporte) {
	soporte.fichas = new tFicha[8];
	soporte.capacidad = 8;
	soporte.contador = 0;
}

void nuevaFicha(tSoporte& soporte, tFicha ficha) {
	if (soporte.contador == soporte.capacidad)
		ampliarCapacidad(soporte);
	soporte.fichas[soporte.contador] = ficha;
	soporte.contador++;
}

void eliminarFicha(tSoporte& soporte, tFicha ficha) {
	if (soporte.capacidad - soporte.contador - 1 == 8)
		disminuirCapacidad(soporte);
	tSoporte aux;
	aux.contador = 0;
	aux.capacidad = soporte.capacidad;
	aux.fichas = new tFicha[aux.capacidad];
	for (int i = 0; i < soporte.contador; i++) {
		if (!(soporte.fichas[i] == ficha)) {
			aux.fichas[aux.contador] = soporte.fichas[i];
			aux.contador++;
		}
	}
	soporte = aux;
}

void ampliarCapacidad(tSoporte& soporte) {
	tFichaPtr aux = nullptr;
	aux = new tFicha[2 * soporte.capacidad];
	for (int i = 0; i < soporte.contador; i++)
		aux[i] = soporte.fichas[i];
	delete[] soporte.fichas; 
	soporte.fichas = aux;
	soporte.capacidad = soporte.capacidad * 2;
	aux = nullptr;
}

void disminuirCapacidad(tSoporte& soporte) {
	tFichaPtr aux = nullptr;
	aux = new tFicha[soporte.capacidad - 4];
	for (int i = 0; i < soporte.contador; i++)
		aux[i] = soporte.fichas[i];
	delete[] soporte.fichas;
	soporte.capacidad = soporte.capacidad - 4;
	aux = nullptr;
}

void mostrar(const tSoporte& soporte) {
	cout << "Soporte:      ";
	for (int f = 0; f < soporte.contador; f++) {
		cout << fichaToString(soporte.fichas[f]) << "       ";
	}
	colorTexto(LIBRE);
	cout << "\n";
}

void ordenarPorNum(tSoporte& soporte) {
	bool inter = true;
	int i = 0;
	while ((i < soporte.contador - 1) && inter) {
		inter = false;
		for (int j = soporte.contador - 1; j > i; j--) {
			if (soporte.fichas[j].num < soporte.fichas[j - 1].num) { //Usando m�todo de la burbuja
				tFicha tmp;
				tmp = soporte.fichas[j];
				soporte.fichas[j] = soporte.fichas[j - 1];
				soporte.fichas[j - 1] = tmp;
				inter = true;
			}
			if (soporte.fichas[j].num == soporte.fichas[j - 1].num) {
				if (soporte.fichas[j].color < soporte.fichas[j - 1].color) {
					tFicha tmp;
					tmp = soporte.fichas[j];
					soporte.fichas[j] = soporte.fichas[j - 1];
					soporte.fichas[j - 1] = tmp;
					inter = true;
				}
			}
		}
		if (inter) {
			i++;
		}
	}
}

void ordenarPorColor(tSoporte& soporte) {
	bool inter = true;
	int i = 0;
	while ((i < soporte.contador - 1) && inter) {
		inter = false;
		for (int j = soporte.contador - 1; j > i; j--) {
			if (soporte.fichas[j].color < soporte.fichas[j - 1].color) { //Usando m�todo de la burbuja
				tFicha tmp;
				tmp = soporte.fichas[j];
				soporte.fichas[j] = soporte.fichas[j - 1];
				soporte.fichas[j - 1] = tmp;
				inter = true;
			}
			if (soporte.fichas[j].color == soporte.fichas[j - 1].color) {
				if (soporte.fichas[j].num < soporte.fichas[j - 1].num) {
					tFicha tmp;
					tmp = soporte.fichas[j];
					soporte.fichas[j] = soporte.fichas[j - 1];
					soporte.fichas[j - 1] = tmp;
					inter = true;
				}
			}
		}
		if (inter) {
			i++;
		}
	}
}

void robar(tBolsa& bolsa, tSoporte& soporte, const tAjustes& ajustes) {
	nuevaFicha(soporte, sacarFicha(bolsa, ajustes)); // Se saca la ficha de la bolsa aleatoriamente
}

void mostrarEscaleras(tSoporte& soporte) {
	tJugada escalera;
	int pos = 0, posesc = 0;
	bool siguienteNum = false;

	ordenarPorColor(soporte); //Se ordena por color para facilitar encontrar escaleras

	while (pos <= soporte.contador - 3) {
		posesc = 0;
		escalera[0] = soporte.fichas[pos];
		escalera[1] = { LIBRE, -1 };
		posesc++;

		while ((pos < soporte.contador) && (soporte.fichas[pos].color == soporte.fichas[pos + 1].color)
			&& (soporte.fichas[pos + 1].num == escalera[posesc - 1].num + 1 || soporte.fichas[pos + 1].num == escalera[posesc - 1].num)) {
			//Si los colores son iguales y el numero es el sucesivo o el mismo:
			siguienteNum = false;

			if (soporte.fichas[pos + 1].num == escalera[posesc - 1].num + 1)
				siguienteNum = true;

			if (siguienteNum) { //Si el numero es el el sucesivo se a�ade a la escalera
				escalera[posesc] = soporte.fichas[pos + 1];
				posesc++;
				escalera[posesc + 1] = { LIBRE, -1 };

			}
			pos++;
		}
		if (posesc >= 3) { //Si la escalera tiene 3 o mas fichas es valida
			int auxpos = 0;
			tFicha aux = escalera[auxpos];
			while (!fichaVacia(aux)) { //Se imprime la escalera
				cout << fichaToString(aux) << "  ";
				auxpos++;
				aux = escalera[auxpos];
			}
			cout << "\n";
		}
		pos++;

	}
}

void mostrarSeries(tSoporte& soporte) {

	tJugada serie;
	int pos = 0, posser = 0;
	bool siguienteColor = false;

	ordenarPorNum(soporte); //Se oredna por numero para facilitar encontrar series

	while (pos <= soporte.contador - 3) {
		posser = 0;
		serie[0] = soporte.fichas[pos];
		serie[1] = { LIBRE, -1 };
		posser++;

		while ((pos < soporte.contador) && (soporte.fichas[pos].num == soporte.fichas[pos + 1].num) &&
			(soporte.fichas[pos + 1].color == serie[posser - 1].color + 1 || soporte.fichas[pos + 1].color == serie[posser - 1].color)) {
			//Si el color es el sucesivo y el numero es el mismo
			siguienteColor = false;

			if (soporte.fichas[pos + 1].color == serie[posser - 1].color + 1)
				siguienteColor = true;

			if (siguienteColor) { //Si el color es el siguiente se a�ade a la serie
				serie[posser] = soporte.fichas[pos + 1];
				posser++;
				serie[posser + 1] = { LIBRE, -1 };
			}

			pos++;

		}
		if (posser >= 3) { //Si la serie tiene 3 o mas fichas es valida
			int auxpos = 0;
			tFicha aux = serie[auxpos];
			while (!fichaVacia(aux)) {
				cout << fichaToString(aux) << "  ";
				auxpos++;
				aux = serie[auxpos];
			}
			cout << "\n";
		}
		pos++;
	}
}

void sugerir(tSoporte& soporte) {
	mostrarSeries(soporte);
	mostrarEscaleras(soporte);
}