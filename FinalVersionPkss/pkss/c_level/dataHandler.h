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
	//private:
public:
	std::vector<std::string> simulation_time;
	std::vector<Temperature> orig_data;
	std::vector<History> model_control_data;
};

#endif /* DATAREADER_HPP_ */
