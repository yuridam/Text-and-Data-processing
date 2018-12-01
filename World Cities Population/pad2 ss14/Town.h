#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <functional>
#include <iomanip> 
#include <algorithm>
#include <set>


class Town
{
public:
	Town();
	~Town();


	void setStadt(std::string);
	void setEinwohner(std::string);
	void setLand(std::string);
	void setKontinent(std::string);

	void addTown(std::string stadt, std::string einwohner, std::string land, std::string kontinent);
	void addTown2(std::string stadt2, std::string einwohner2, std::string land2, std::string kontinent2);

	std::string getStadt();
	std::string getEinwohner();
	std::string getLand();
	std::string getKontinent();

	void sortTownsAndLand();
	void readTowns();
	void showTowns();
	void showTowns3();
	
	void sortTownsByEinwohner();
	void sumEinwohnerProLand();

	std::vector <Town*> myTown;
	std::vector <Town*> myTownSorted;
	std::set <std::string> sortedLand;
	std::set <std::string> sortedStadt;
	std::vector <int> sortedEinwohner;
	std::map <int, std::string, std::greater<int>> mapEinwohnerProLand;
protected:
	std::string Stadt;
	std::string Einwohner;
	std::string Land;
	std::string Kontinent;
};

