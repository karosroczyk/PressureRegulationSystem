/*
 * DataHandler.hpp
 *
 *  Created on: Dec 1, 2019
 *      Author: Szczena
 */

#ifndef DATAREADER_HPP_
#define DATAREADER_HPP_

#include<vector>
#include <string>

#include "constants.h"

class DataHandler {
public:
	DataHandler();
	virtual ~DataHandler();

	void ReadDataFromCSV();
	void SaveDataToCSV();
	void UpdatePID(std::string filename);
	//private:
public:
	std::vector<std::string> simulation_time;
	std::vector<Temperature> orig_data;
	std::vector<History> model_control_data;
	std::vector<float> PID {0.00031, 0.000003146, 0.000089};
};

#endif /* DATAREADER_HPP_ */
