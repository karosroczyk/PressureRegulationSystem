/*
 * pid_controller.hpp
 *
 *  Created on: Nov 19, 2019
 *      Author: Szczena
 */

#ifndef PID_CONTROLLER_H_
#define PID_CONTROLLER_H_

#include "constants.h"

class PidController {
public:
	double m_P;
	double m_I;
	double m_sumI;
	double m_D;

	PidController(float p, float i, float sumi, float d);
	PidController(const PidController& obj); // copy constructor
	~PidController();
	double CalculateDiscretePidOutput(float ref, float x);
};

#endif /* PID_CONTROLLER_H_ */
