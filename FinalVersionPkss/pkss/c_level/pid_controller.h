/*
 * pid_controller.hpp
 *
 *  Created on: Nov 19, 2019
 *      Author: Szczena
 */

#ifndef PID_CONTROLLER_H_
#define PID_CONTROLLER_H_

#include "constants.h"
#include<iostream>
#include<vector>

class PidController {
public:
	double m_P;
	double m_I;
	double m_sumI;
	double m_D;
	std::vector<float> PID{ 0.00031, 0.000003146, 0.000089 };

	PidController(float sumi = 0);
	PidController(float p, float i, float sumi, float d);
	PidController(const PidController& obj); // copy constructor
	~PidController();
	double CalculateDiscretePidOutput(float ref, float x);
	void UpdatePIDclass(std::string filename);
};

#endif /* PID_CONTROLLER_H_ */
