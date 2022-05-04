#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "colores.h"
#include "fichas.h"
#include "bolsa.h"
#include "soporte.h"
#include "soportes.h"
#include "jugadas.h"

using namespace std;

bool esEscalera(const tJugada& jugada) {
	tFicha aux = jugada[0];
	int contador = 0;
	bool escalera = true;

	while (!fichaVacia(aux) && escalera) {
		//será escalera hasta que una de las fichas de la jugada muestre lo contrario
		if (jugada[contador + 1].num != -1) {
			if (aux.color != jugada[contador + 1].color || aux.num != jugada[contador + 1].num - 1)
				escalera = false;
		}
		contador++;
		aux = jugada[contador];
	}

	return escalera;
}

bool esSerie(const tJugada& jugada) {
	tFicha aux = jugada[0];
	int contador = 0;
	bool serie = true;

	while (!fichaVacia(aux) && serie) {
		//será serie hasta que una de las fichas de la jugada muestre lo contrario
		if (jugada[contador + 1].num != -1) {
			if (aux.color == jugada[contador + 1].color || aux.num != jugada[contador + 1].num)
				serie = false;
		}
		contador++;
		aux = jugada[contador];
	}

	return serie;
}

void nuevaJugada(tSoporte& soporte, tJugada& jugada, int& jcont) {
	int aux;
	tFicha faux;

	cout << "    Fichas (0 al final): "; //Se recogen e imprimen las posiciones elegidas
	cin >> aux;
	while (aux != 0) {
		cout << aux << " ";
		jugada[jcont] = soporte.fichas[aux - 1];
		jugada[jcont + 1] = { LIBRE, -1 };
		jcont++;
		cin >> aux;
	}
	cout << "0\n";

	cout << "Jugada: "; // Se imprimen las fichas elegidas
	jcont = 0;
	faux = jugada[jcont];
	while (!fichaVacia(faux)) {
		cout << fichaToString(faux) << "  ";
		jcont++;
		faux = jugada[jcont];
	}
}

bool puedePonerFicha(tJugada jugada, tFicha ficha, bool& iniciojugada) {
	tFicha aux = jugada[0];
	tJugada jaux, jaux1;
	int c = 0;
	while (!fichaVacia(aux)) {
		jaux[c] = aux;
		c++;
		aux = jugada[c];
	}
	jaux[c - 1] = ficha;
	jaux[c] = { LIBRE, -1 };
	//Se añade a la jugada una ficha auxiliar y vemos si se mantiene la escalera o la serie

	bool escalera1 = esEscalera(jaux);
	bool serie = esSerie(jaux);

	if (escalera1 || serie)
		return true;
	else {
		c = 1;
		aux = jugada[1];
		jaux1[0] = ficha;
		while (!fichaVacia(aux)) {
			jaux1[c] = aux;
			c++;
			aux = jugada[c];
		}
		jaux[c] = { LIBRE, -1 };
		bool escalera2 = esEscalera(jaux1); //En el caso de escaleras probamos si se puede pone rla fich aal inicio
		if (escalera2) {
			iniciojugada = true;
			return true;
		}
		else
			return false;
	}
}

void ponerFicha(tJugada& jugada, tFicha& ficha, bool iniciojugada) {
	//Se coloca la ficha en la jugada 
	int c = 0, c2 = 0;
	tFicha aux;
	tJugada jaux;
	if (!iniciojugada) {
		aux = jugada[0];
		while (!fichaVacia(aux)) {
			c++;
			aux = jugada[c];
		}
		jugada[c - 1] = ficha;
		jugada[c] = { LIBRE, -1 };
	}
	else {
		jaux[0] = ficha;
		c2++;
		aux = jugada[0];
		while (!fichaVacia(aux)) {
			jaux[c2] = aux;
			c++;
			aux = jugada[c];
		}
		jaux[c] = { LIBRE, -1 };

		aux = jaux[0];
		c = 0;
		while (!fichaVacia(aux)) {
			jugada[c] = jaux[c];
		}
	}

}




