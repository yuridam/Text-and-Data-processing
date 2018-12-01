#include "stdafx.h"
#include "Town.h"


Town::Town()
{
}


Town::~Town()
{
}


void Town::setStadt(std::string stadt)
{
	this->Stadt = stadt;
}

void Town::setEinwohner(std::string einwohner)
{
	this->Einwohner= einwohner;
}

void Town::setLand(std::string land)
{
	this->Land = land;
}

void Town::setKontinent(std::string kontinent)
{
	this->Kontinent = kontinent;
}

std::string Town::getStadt()
{
	return Stadt;
}

std::string Town::getEinwohner()
{
	return Einwohner;
}

std::string Town::getLand()
{
	return Land;
}

std::string Town::getKontinent()
{
	return Kontinent;
}

void Town::addTown(std::string stadt, std::string einwohner, std::string land, std::string kontinent) {

	Town* newTown = new Town;
	newTown->setStadt(stadt);
	newTown->setEinwohner(einwohner);
	newTown->setLand(land);
	newTown->setKontinent(kontinent);
	myTown.push_back(newTown);

}

void Town::addTown2(std::string stadt2, std::string einwohner2, std::string land2, std::string kontinent2) {

	Town* newTown2 = new Town;
	newTown2->setStadt(stadt2);
	newTown2->setEinwohner(einwohner2);
	newTown2->setLand(land2);
	newTown2->setKontinent(kontinent2);
	myTownSorted.push_back(newTown2);

}

void Town::sortTownsAndLand() {
	std::ifstream fin;
	fin.open("towns.txt");


	if (fin.is_open())
		std::cout << "READ\n";
	else std::cout << "Not Found\n";

	std::string stadt;
	std::string land;
	std::string einwohner;

	std::string dummyLine;
	std::getline(fin, dummyLine);
	std::getline(fin, dummyLine);
	std::getline(fin, dummyLine);
	while (fin) {

		std::string word;
		getline(fin, word, ';');
		stadt = word;
		
		getline(fin, word, '.');
		einwohner += word;
		getline(fin, word, '.');
		einwohner += word;
		getline(fin, word, ';');
		einwohner += word;
		getline(fin, word, ';');
		land = word;
		getline(fin, word, '\n');
		


		sortedLand.insert(land);
		sortedStadt.insert(stadt);
		sortedEinwohner.push_back(atoi(einwohner.c_str()));
		//sortedEinwohner.push_back(std::stoi(einwohner));
		einwohner = "";
	}
	sortedLand.erase("");
	sortedStadt.erase("");
	sortedEinwohner.pop_back();
	sort(sortedEinwohner.begin(), sortedEinwohner.end(), std::greater<int>());
}
void Town::readTowns() {
	for (std::set<std::string>::iterator it = sortedStadt.begin(); it != sortedStadt.end(); ++it) {

	std::ifstream fin;
	fin.open("towns.txt");

	std::string stadt;
	std::string einwohner;
	std::string land;
	std::string kontinent;

	
	std::string dummyLine;
	std::getline(fin, dummyLine);
	std::getline(fin, dummyLine);
	std::getline(fin, dummyLine);


	
	while (fin && sortedStadt.size()) {

			//getline(fin, line);
			std::string word;
			getline(fin, word, ';');
			stadt = word;
			getline(fin, word, '.');
			einwohner += word;
			getline(fin, word, '.');
			einwohner += word;
			getline(fin, word, ';');
			einwohner += word;
			getline(fin, word, ';');
			land = word;
			getline(fin, word, '\n');
			kontinent = word;
		
	
			
			if(stadt == *it){
			addTown(stadt, einwohner, land, kontinent);
			}
	
			einwohner = "";
			}
	}
	//myTown.pop_back();
	
}


void Town::showTowns() {
	std::vector <std::string> stadtInLand;
	if (myTown.size() != 0)
	{
		for (std::set<std::string>::iterator it = sortedLand.begin(); it != sortedLand.end(); ++it) {
			
			for (unsigned int k = 0; k < myTown.size(); k++) {
				if (myTown[k]->getLand() == *it) {
			
					std::cout
						<< std::left << std::setw(15) << myTown[k]->getStadt() << std::setw(20)
						<< myTown[k]->getEinwohner() << std::setw(30)
						<< myTown[k]->getLand() << std::setw(30)
						<< myTown[k]->getKontinent() << std::right << std::setw(30)
						<< std::endl;
				}
			}	
		}
	}
	else
	{
		std::cout << "No Stores found" << std::endl;
	}

}

void Town::sumEinwohnerProLand() {
	for (std::set<std::string>::iterator it = sortedLand.begin(); it != sortedLand.end(); ++it) {
		int sumEinwohner = 0;
		for (unsigned int k = 0; k < myTown.size(); k++) {
			if (myTown[k]->getLand() == *it) {

				sumEinwohner += atoi(myTown[k]->getEinwohner().c_str());

			}

		}
		mapEinwohnerProLand[sumEinwohner] = *it;

	}

}



void Town::sortTownsByEinwohner() {
	std::string stadt2;
	std::string einwohner2;
	std::string land2;
	std::string kontinent2;

	for (unsigned int k = 0; k < sortedEinwohner.size(); k++) {
		std::string sortedEinwohnerAsString = std::to_string(sortedEinwohner[k]);
		for (unsigned int i = 0; i < myTown.size(); i++)
		{
			if (myTown[i]->getEinwohner().substr(1) == sortedEinwohnerAsString) {
				stadt2 = myTown[i]->getStadt();
				einwohner2 = myTown[i]->getEinwohner();
				land2 = myTown[i]->getLand();
				kontinent2 = myTown[i]->getKontinent();

				addTown2(stadt2, einwohner2, land2, kontinent2);
			}
		}
	}
}

void Town::showTowns3() {

	if (myTownSorted.size() != 0)
	{
		for (std::set<std::string>::iterator it = sortedLand.begin(); it != sortedLand.end(); ++it) {
			for (unsigned int i = 0; i < myTownSorted.size(); i++)
				if(myTownSorted[i]->getLand() == *it)
			{
				std::cout
					<< std::left << std::setw(15) << myTownSorted[i]->getStadt() << std::setw(20)
					<< myTownSorted[i]->getEinwohner() << std::setw(30)
					<< myTownSorted[i]->getLand() << std::setw(30)
					<< myTownSorted[i]->getKontinent() << std::right << std::setw(30)

					<< std::endl;

			}
		}
	}
	else
	{
		std::cout << "No Stores found" << std::endl;
	}
}

