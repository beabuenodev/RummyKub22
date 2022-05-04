#pragma once

#include "colores.h"
#include "fichas.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//constantes y tipos
typedef tFicha tBolsa[8][13];

//funciones
void inicializarBolsa(tBolsa& bolsa, tAjustes ajustes); // Inicializa la bolsa con las fichas iniciales
void mostrar(const tBolsa& bolsa, tAjustes ajustes); // Muestra la bolsa
tFicha sacarFicha(tBolsa& bolsa, tFicha ficha, int faux, const tAjustes& ajustes); // Saca una ficha concreta de la bolsa
bool fichaVacia(const tBolsa& bolsa, const tFicha& ficha, int f); // Indica si una ficha en la bolsa está vacía.
