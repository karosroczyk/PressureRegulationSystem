/*
 * pid_controller.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: Szczena
 */
#include "pid_controller.h"

PidController::PidController(float p, float i, float sumi, float d) : m_P(p), m_I(i), m_sumI(sumi), m_D(d) {}

PidController::PidController(const PidController& obj) { // copy constructor
	m_P = obj.m_P;
	m_I = obj.m_I;
	m_sumI = obj.m_sumI;
	m_D = obj.m_D;
}
PidController::~PidController() {}
double PidController::CalculateDiscretePidOutput(float ref, float x) {
	float diff = ref - x;
	m_sumI += diff;
	m_sumI = m_sumI < -1000 ? -1000 :
		m_sumI > 1000 ? 1000 : m_sumI; // check if sumI is between -1000 and 1000
	double u = (m_P * diff) + (m_I * m_sumI) + (m_D * diff); // TODO SPRAWDZIC
	return u;
}
