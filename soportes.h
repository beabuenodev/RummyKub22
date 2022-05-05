#ifndef soportes_h
#define soportes_h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "ajustes.h"
#include "soporte.h"

using namespace std;

//constantes y tipos
typedef tSoporte tSoportes[4];

//funciones
void siguienteTurno(int& turno, tSoportes soportes, tAjustes ajustes); //Cambia el número del turno al siguiente jugador
void repartir(tBolsa& bolsa, tSoportes& soportes, const tAjustes& ajustes); //Reparte según el archivo datos.in
void delSoportes(tSoportes& soportes, tAjustes ajustes);
#endif