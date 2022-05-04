#pragma once

#include "fichas.h"
#include <iostream>
#include <string>

using namespace std;

//constantes y tipos

enum tColor { ROJO, VERD, AZUL, AMAR, LIBRE };
const int NUM_COLORES = 4;

//cabeceras

void inicializarColor(tFicha& ficha, int f); // Inicializa un color para la ficha dependiendo del número de la fila de la Bolsa