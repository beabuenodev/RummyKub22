#ifndef bolsa_h
#define bolsa_h

//FP2 - RummyKub V.2
//Nombre y Apellidos: Beatriz Bueno Almagro 1ºB

#include "fichas.h"
#include "ajustes.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//constantes y tipos
typedef tFichaPtr tBolsa[8][13];

//funciones
void inicializarBolsa(tBolsa& bolsa, tAjustes ajustes); // Inicializa la bolsa con las fichas iniciales
void mostrar(const tBolsa& bolsa, tAjustes ajustes); // Muestra la bolsa
tFicha sacarFicha(tBolsa& bolsa, const tAjustes& ajustes); // Saca una ficha concreta de la bolsa
bool fichaVacia(const tBolsa& bolsa, const tFicha& ficha, int f); // Indica si una ficha en la bolsa está vacía.
int numAleatorioFila();
int numAleatorioColumna(tAjustes ajustes);
void delBolsa(tBolsa bolsa, tAjustes ajustes);
#endif