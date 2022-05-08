#ifndef tablero_h
#define tablero_h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "soporte.h"
#include "jugadas.h"

using namespace std;

//Constantes y tipos
typedef tJugada tArrayTablero[NUM_FILAS*2];

struct tTablero {
	tArrayTablero jugadas;
	int contador;
};

//Funciones
bool jugar(tTablero& tablero, tSoporte& soporte, tAjustes ajustes); // Recoge, comprueba y coloca las jugadas en el tablero
void mostrar(const tTablero& tablero); // Muestra todas las jugadas del tablero
void delJugadas(tTablero tablero);
#endif