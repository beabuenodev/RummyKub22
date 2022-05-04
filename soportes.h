#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "colores.h"
#include "fichas.h"
#include "bolsa.h"
#include "soporte.h"

using namespace std;

//constantes y tipos
typedef tSoporte tSoportes[4];

//funciones
void siguienteTurno(int& turno, tSoportes soportes, tAjustes ajustes); //Cambia el n�mero del turno al siguiente jugador
void repartir(tBolsa& bolsa, tSoportes& soportes, const tAjustes& ajustes); //Reparte seg�n el archivo datos.in