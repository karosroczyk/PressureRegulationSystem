/*
 * model.hpp
 *
 *  Created on: Nov 20, 2019
 *      Author: Szczena
 */

#ifndef MODEL_H_
#define MODEL_H_
#include "pid_controller.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

 // model specific
inline Temperature Calculate_T_zm(Temperature _T_0) { return 70 - 2.5 * (_T_0 - 6); }
inline Temperature Calculate_T_zco_ref(Temperature _T_0) { return  55 - 1.75 * _T_0; }


Temperature Deriv_T_pm(int t, Temperature _T_pm);
Temperature Deriv_T_pco(int t, Temperature _T_pco);
Temperature Deriv_T_zco(int t, Temperature _T_zco);
Temperature Deriv_T_r(int t, Temperature _T_r);
Temperature RungeKutta(int x0, Temperature y0, int x, float h, Temperature(*func)(int, Temperature));

#endif /* MODEL_H_ */
