/*
 * DataHandler.cpp
 *
 *  Created on: Dec 1, 2019
 *      Author: Szczena
 */
#include<fstream>
#include<sstream>
#include<iostream>

#include "dataHandler.h"
using namespace std;

DataHandler::DataHandler() {
	// TODO Auto-generated constructor stub
	simulation_time.reserve(4032);
	orig_data.reserve(4032); // preallocate data
	model_control_data.reserve(4302);
}

DataHandler::~DataHandler() {
	// TODO Auto-generated destructor stub
}

void DataHandler::ReadDataFromCSV() {
	ifstream fin;
	string file_name = "C:\\Users\\Lenovo\\Desktop\\c_level\\Debug\\Temperatura.csv";
	fin.open(file_name.c_str(), ios::in);
	vector<string> row;
	string line, word, temp;
	while (fin >> temp) { // read file
		row.clear();
		getline(fin, line); // read row and save into line
		stringstream s(line); // more advanced container for breaking up the string
		while (getline(s, word, ',')) { // read a 'line' and save each 'word' in 'row' vector
			row.push_back(word);
		}
		simulation_time.push_back(row[0]); // save time of the data in vector
		Temperature temp = stof(row[1]); // interpret the temperature string as float number
		orig_data.push_back(temp);
	}
	fin.close();
}

void DataHandler::SaveDataToCSV() {
	fstream fout;
	string file_name = "C:\\Users\\Lenovo\\Desktop\\FromGitPkss\\pkss\\c_level\\logi.csv";
	fout.open(file_name.c_str(), ios::out);
	int size = model_control_data.size();
	fout << "Time, T_zad, F_zm, T_zm, T_pm, T_pco, T_zco, T_0, F_cob0, F_cob1, T_r0, T_r1\n";
	for (int i = 0; i < size; i++) {
		fout << simulation_time.at(i)
			<< ',' << model_control_data.at(i).T_zad
			<< ',' << model_control_data.at(i).F_zm * F_ZM_MAX
			<< ',' << model_control_data.at(i).T_zm
			<< ',' << model_control_data.at(i).T_pm
			<< ',' << model_control_data.at(i).T_pco
			<< ',' << model_control_data.at(i).T_zco
			<< ',' << model_control_data.at(i).T_0
			<< ',' << model_control_data.at(i).F_cob0 * F_CO_MAX
			<< ',' << model_control_data.at(i).F_cob1 * F_CO_MAX
			<< ',' << model_control_data.at(i).T_r0
			<< ',' << model_control_data.at(i).T_r1 << '\n';
	}
	fout.close();
}

