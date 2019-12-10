/*
 * constants.hpp
 *
 *  Created on: Nov 20, 2019
 *      Author: Szczena
 *      Description: This file contains global variable declarations, extern keyword provides variable symbol forwarding
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "definitions.h"

extern const Flow F_CO_MAX; // [t/h] max przeplyw zaworu w budynku
extern const Flow F_ZM_MAX; // [t/h] max wydajnosc pomp cyrkulacyjnych

// stale
extern const Density RO; // [kg/mextern 3] gêstoœc wody
extern const SpecificHeatCapacity C_W; // [J/kg/K] cieplo wlasciwe wody
extern const SpecificHeatCapacity C_B; // [J/kg/K] cieplo wlasciwe powietrza w budynku
extern const HeatTransferCoefficient K_W; // [J/s/K] wspolczynnik przenikania ciepla

// model wymiennika ciepla
extern const Mass M_M; //[kg] masa zastepcza wymiennika po stronie pierwotnej
extern const Mass M_CO; //[kg] masa zastepcza wymiennika po stronie wtórnej
extern const SpecificHeatCapacity C_WYM; // [J/kg/K] zastepcze cieplo wlasciwe wymiennika

// model kaloryferow
extern const Mass M_H; //[kg] masy zastepcze kaloryferów
extern const SpecificHeatCapacity C_H; //[J/kg/K] zastepcze cieplo wlasciwe kaloryferow
extern const HeatTransferCoefficient K_H; //[J/K/s] wspolczynnik przenikania ciepla kaloryfer-pokoj

// model budynku
extern const Mass M_B; //[kg] masa powietrza w budynku
extern const HeatTransferCoefficient K_EXT; //[J/K/s] wspólczynnik utraty ciepla

typedef struct History {
	Temperature T_zad;
	Flow F_zm;

	Temperature T_zm;
	Temperature T_pm;
	Temperature T_pco;
	Temperature T_zco;

	Temperature T_0;

	Flow F_cob0;
	Flow F_cob1;
	Temperature T_r0;
	Temperature T_r1;
} History;

extern History hs[5]; // perform calculations based on 5 previous values
extern History current;
extern History* previous;

#endif /* CONSTANTS_H_ */
