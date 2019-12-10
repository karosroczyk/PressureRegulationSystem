/*
 * constants.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: Szczena
 *      Description: This file contains definitions of global extern variables. They are initialized before any other source file.
 */
#include "constants.h"

const Flow F_CO_MAX = 80; // [t/h] max przeplyw zaworu w budynku
const Flow F_ZM_MAX = 150; // [t/h] max wydajnosc pomp cyrkulacyjnych

// stale
const Density RO = 1000; // [kg/m 3] gêstoœc wody
const SpecificHeatCapacity C_W = 4200; // [J/kg/K] cieplo wlasciwe wody
const SpecificHeatCapacity C_B = 1000; // [J/kg/K] cieplo wlasciwe powietrza w budynku
const HeatTransferCoefficient K_W = 250000; // [J/s/K] wspolczynnik przenikania ciepla

// model wymiennika ciepla
const Mass M_M = 3000; //[kg] masa zastepcza wymiennika po stronie pierwotnej
const Mass M_CO = 3000; //[kg] masa zastepcza wymiennika po stronie wtórnej
const SpecificHeatCapacity C_WYM = 2700; // [J/kg/K] zastepcze cieplo wlasciwe wymiennika

// model kaloryferow
const Mass M_H = 3000; //[kg] masy zastepcze kaloryferów
const SpecificHeatCapacity C_H = 2700; //[J/kg/K] zastepcze cieplo wlasciwe kaloryferow
const HeatTransferCoefficient K_H = 12000; //[J/K/s] wspolczynnik przenikania ciepla kaloryfer-pokoj

// model budynku
const Mass M_B = 20000; //[kg] masa powietrza w budynku
const HeatTransferCoefficient K_EXT = 15000; //[J/K/s] wspólczynnik utraty ciepla
