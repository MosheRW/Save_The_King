#pragma once
#include "Location.h"
#include "Globals.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>


class RawData
{
public:
	RawData(int level = 1);//opens and read the level.
	~RawData();
	
	Location get(Value val, int i = 0)const;
	int time();
	int getLen(Value val)const;
	
	Value getValue(Location cell) const;
	Value getValue(int x, int y) const;


private:
	bool isFileExist();
	void readFile();
	
	int m_level;
	std::string m_name = std::string(std::to_string(m_level) + ".txt");
	std::fstream m_file;
	
	std::vector < std::vector<Location>> arr;
	
};

