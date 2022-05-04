#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "colores.h"
#include "fichas.h"
#include "bolsa.h"
#include "soporte.h"
#include "soportes.h"

using namespace std;

void repartir(tBolsa& bolsa, tSoportes& soportes, const tAjustes& ajustes) { //Reparte según el archivo datos.in
	tFicha aux;
	int filacolor, num;

	for (int j = 0; j < ajustes.numJugadores; j++) {
		for (int i = 0; i < ajustes.iniFichas; i++) {
			//Sacamos una ficha del archivo
			cin >> filacolor;
			cin >> num;
			aux.num = num + 1;
			inicializarColor(aux, filacolor);

			//La sacamos de la bolsa y la ponemos en el soporte
			soportes[j].fichas[i] = sacarFicha(bolsa, aux, filacolor, ajustes);
			soportes[j].contador++;
		}
	}

}

void siguienteTurno(int& turno, tSoportes soportes, tAjustes ajustes) {
	if (turno != ajustes.numJugadores)
		turno++;
	else //Si el turno es el de el ultimo jugador, se pasa al primero
		turno = 1;

	cout << "Turno para el jugador " << turno << " ...\n";
	mostrar(soportes[turno - 1]);
}


