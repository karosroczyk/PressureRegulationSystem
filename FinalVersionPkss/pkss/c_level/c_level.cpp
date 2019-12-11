#include <iostream>
#include <stdio.h>

#include "dataHandler.h"
#include "model.h"



void FillHistory(History* hs, History& current) {
	hs[0].T_zad = 20;
	hs[0].F_zm = 0.1;
	hs[0].T_zm = 80;
	hs[0].T_pm = 70;
	hs[0].T_pco = 20;
	hs[0].T_zco = 50;
	hs[0].T_0 = 0;
	hs[0].F_cob0 = 0.1;
	hs[0].F_cob1 = 0.1;
	hs[0].T_r0 = 15;
	hs[0].T_r1 = 15;

	for (int i = 1; i < 5; i++) {
		hs[i] = hs[0];
	}
	current = hs[1];
}
History hs[5]; // perform calculations based on 5 previous values
History current;
History* previous = &hs[4];
int main() {
	// zmienne
	FillHistory(hs, current);
	//PID values copied from the model
	DataHandler dh;
	PidController regulatorUm;
	PidController regulatorUb0;
	PidController regulatorUb1;
	regulatorUm.UpdatePIDclass("C:\\Users\\Lenovo\\Desktop\\c_level\\Debug\\PIDwymiennika.csv");
	regulatorUb0.UpdatePIDclass("C:\\Users\\Lenovo\\Desktop\\c_level\\Debug\\PIDbudynku1.csv");
	regulatorUb1.UpdatePIDclass("C:\\Users\\Lenovo\\Desktop\\c_level\\Debug\\PIDbudynku2.csv");
	Temperature T_pcob0 = 25;
	Temperature T_pcob1 = 25;
	dh.ReadDataFromCSV();

		std::cout << regulatorUm.PID[0] <<" "<< regulatorUm.PID[1] << " " << regulatorUm.PID[2] << std::endl;
		std::cout << regulatorUb0.PID[0] << " " << regulatorUb0.PID[1] << " " << regulatorUb0.PID[2] << std::endl;
		std::cout << regulatorUb1.PID[0] << " " << regulatorUb1.PID[1] << " " << regulatorUb1.PID[2] << std::endl;

	Temperature T_zco_ref = Calculate_T_zco_ref(previous->T_0);

	for (int i = 0; i < 4000; i++) {
		if (i > 1500 && i < 2500) {
			current.T_zad = 15;
		}
		else current.T_zad = 20;
		current.T_0 = previous->T_0 = dh.orig_data.at(i);
		previous->T_zm = Calculate_T_zm(previous->T_0);
		// TODO boundary check?
		current.T_zm = previous->T_zm;
		previous->F_zm = regulatorUm.CalculateDiscretePidOutput(T_zco_ref, previous->T_zco);
		previous->F_zm = previous->F_zm < 0 ?
			0 : previous->F_zm > 1.5 ?
			1.5 : previous->F_zm;
		current.F_zm = previous->F_zm;

		previous->F_cob0 = regulatorUb0.CalculateDiscretePidOutput(previous->T_zad, previous->T_r0);
		previous->F_cob0 = previous->F_cob0 < 0 ?
			0 : previous->F_cob0 > 0.8 ?
			0.8 : previous->F_cob0;
		current.F_cob0 = previous->F_cob0;

		previous->F_cob1 = regulatorUb1.CalculateDiscretePidOutput(previous->T_zad, previous->T_r1);
		previous->F_cob1 = previous->F_cob1 < 0 ?
			0 : previous->F_cob1 > F_CO_MAX - previous->F_cob0 ?
			F_CO_MAX - previous->F_cob0 : previous->F_cob1;
		current.F_cob1 = previous->F_cob1;

		current.T_pm = RungeKutta(0, previous->T_pm, 4, 2, &Deriv_T_pm);
		current.T_pco = RungeKutta(0, previous->T_pco, 4, 2, &Deriv_T_pco);
		current.T_zco = RungeKutta(0, previous->T_zco, 4, 2, &Deriv_T_zco);
		current.T_r0 = RungeKutta(0, previous->T_r0, 4, 2, &Deriv_T_r);
		current.T_r1 = RungeKutta(0, previous->T_r1, 4, 2, &Deriv_T_r);

		//TODO finish the equations
				// save the data and move the circular buffer
		for (int i = 0; i < 4; i++) {
			hs[i] = hs[i + 1];
		}
		hs[4] = current;
		dh.model_control_data.push_back(current);
	}
	dh.SaveDataToCSV();
	return 0;
}
