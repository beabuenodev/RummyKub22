#ifndef bolsa_h
#define bolsa_h

//FP2 - RummyKub V.2
//Nombre y Apellidos: Beatriz Bueno Almagro 1�B

#include "fichas.h"
#include "ajustes.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//constantes y tipos
const int NUM_FILAS = 8, MAX_COLUMNAS = 13;
typedef tFichaPtr tBolsa[NUM_FILAS][MAX_COLUMNAS];

//funciones
void inicializarBolsa(tBolsa& bolsa, tAjustes ajustes); // Inicializa la bolsa con las fichas iniciales
void mostrar(const tBolsa& bolsa, tAjustes ajustes); // Muestra la bolsa
tFicha sacarFicha(tBolsa& bolsa, const tAjustes& ajustes); // Saca una ficha concreta de la bolsa
int numAleatorioFila();
int numAleatorioColumna(tAjustes ajustes);
void delBolsa(tBolsa bolsa, tAjustes ajustes);
#endif