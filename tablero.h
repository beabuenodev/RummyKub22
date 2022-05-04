#pragma once

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

//Constantes y tipos
struct tTablero {
	tJugada jugadas[40];
	int contador;
};

//Funciones
bool jugar(tTablero& tablero, tSoporte& soporte); // Recoge, comprueba y coloca las jugadas en el tablero
void mostrar(const tTablero& tablero); // Muestra todas las jugadas del tablero
