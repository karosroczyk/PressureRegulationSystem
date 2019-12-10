/*
 * model.cpp
 *
 *  Created on: Nov 21, 2019
 *      Author: Szczena
 */

#include "model.h"

Temperature Deriv_T_pm(int t, Temperature _T_pm) {
	Temperature derivativeT_pm = (hs[t].F_zm * RO * C_W * (hs[t].T_zm - hs[t].T_pm) - K_W * (_T_pm - hs[t].T_zco)) / (M_M * C_WYM);
	return derivativeT_pm;

}

Temperature Deriv_T_pco(int t, Temperature _T_pco) {
	Temperature derivativeT_pco = ((hs[t].F_cob0 + hs[t].F_cob1) * RO * C_W * (hs[t].T_zco - _T_pco) - K_H * (_T_pco - hs[t].T_r0)) / (M_H * C_H);
	return derivativeT_pco;
	// TODO check T_r0 and 1
}

Temperature Deriv_T_zco(int t, Temperature _T_zco) {
	Temperature derivativeT_zco = (K_W * (hs[t].T_pm - _T_zco) - (hs[t].F_cob0 + hs[t].F_cob1) * RO * C_W * (_T_zco - hs[t].T_pco)) / (M_CO * C_WYM);
	return derivativeT_zco;
}

Temperature Deriv_T_r(int t, Temperature _T_r) {
	Temperature derivativeT_r = (K_H * (hs[t].T_pco - _T_r) - K_EXT * (_T_r - hs[t].T_0)) / (M_B * C_B);
	return derivativeT_r;
}

Temperature RungeKutta(int x0, Temperature y0, int x, float h, Temperature(*func)(int t, Temperature _y)) {
	{
		// Count number of iterations using step size or
		// step height h
		int n = (int)((x - x0) / h);

		float k1, k2, k3, k4;

		// Iterate for number of iterations
		float y = y0;
		for (int i = 1; i <= n; i++)
		{
			// Apply Runge Kutta Formulas to find
			// next value of y
			k1 = h * func(x0, y);
			k2 = h * func(x0 + 0.5 * h, y + 0.5 * k1);
			k3 = h * func(x0 + 0.5 * h, y + 0.5 * k2);
			k4 = h * func(x0 + h, y + k3);

			// Update next value of y
			y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);

			// Update next value of x
			x0 = x0 + h;
		}

		return y;
	}
}
