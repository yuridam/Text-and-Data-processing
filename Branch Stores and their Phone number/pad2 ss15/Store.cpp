#include "stdafx.h"
#include "Store.h"


Store::Store()
{
}


Store::~Store()
{
}


void Store::setPLZ(std::string plz)
{
	this->PLZ = plz;
}

void Store::setOrt(std::string ort)
{
	this->Ort = ort;
}

void Store::setAdresse(std::string adresse)
{
	this->Adresse = adresse;
}

void Store::setTelefonnummer(std::string telefonnummer)
{
	this->Telefonnummer = telefonnummer;
}

std::string Store::getPLZ()
{
	return PLZ;
}

std::string Store::getOrt()
{
	return Ort;
}

std::string Store::getAdresse()
{
	return Adresse;
}

std::string Store::getTelefonnummer()
{
	return Telefonnummer;
}


void Store::addStore(std::string plz, std::string ort, std::string adresse, std::string telefonnumer) {
	Store* newStore = new Store;
	newStore->setPLZ(plz);
	newStore->setOrt(ort);
	newStore->setAdresse(adresse);
	newStore->setTelefonnummer(telefonnumer);
	myStore.push_back(newStore);
}


void Store::readVorwahlen() {

	std::ifstream input("vorwahlen.txt");
	std::string key;
	int value;
	while (input) {
		std::string line;

		getline(input, line, '\t');
		key = line;

		getline(input, line, '\n');
		value = atoi(line.c_str());

		//vorwahlen.insert(std::pair<std::string, int>(key, value));
		vorwahlen[key] = value;

	}

	vorwahlen.erase("");
}
void Store::readStores() {
	Store* sto = new Store;
	std::string plz;
	std::string ort;
	std::string adresse;
	std::string telefonnummer;
	std::ifstream input("test.txt");
	while (input) {
		std::string line;

		getline(input, line, ',');
		plz = line;
		getline(input, line, ',');
		ort = line;
		getline(input, line, ',');
		adresse = line;
		getline(input, line, '\n');
		telefonnummer = line;

		addStore(plz, ort, adresse, telefonnummer);

	}
	myStore.pop_back();
	//std::sort(myStore.begin(), myStore.end());
}

void Store::showStores() {
	if (myStore.size() != 0)
	{
		for (unsigned int i = 0; i < myStore.size(); i++)
		{
			std::cout 
				<< std::left << std::setw(15)<< myStore[i]->getPLZ() << std::setw(20)
				<< myStore[i]->getOrt() << std::setw(30)
				<< myStore[i]->getAdresse() << std::right << std::setw(30)
				<< myStore[i]->getTelefonnummer()
				<< std::endl;

		}
	}
	else
	{
		std::cout << "No Stores found" << std::endl;
	}

}

void Store::showStoresWithPrefix() {
	if (myStore.size() != 0)
	{
		for (unsigned int i = 0; i < myStore.size(); i++)
		{
			std::cout
				<< std::left << std::setw(15) << myStore[i]->getPLZ() << std::setw(20)
				<< myStore[i]->getOrt() << std::setw(30)
				<< myStore[i]->getAdresse() << std::right << std::setw(30)
				<< vorwahlen[myStore[i]->getOrt()]<< "-" 
				<< myStore[i]->getTelefonnummer()
				<< std::endl;

		}
	}
	else
	{
		std::cout << "No Stores found" << std::endl;
	}


}

void Store::searchStores() {
	std::cout << "Enter Ort" << std::endl;
	std::string searched;
	std::cin >> searched;
	std::set<std::string> searchedOrt;
	if (myStore.size() != 0)
	{
		for (unsigned int i = 0; i < myStore.size(); i++)
		{
			int sizeOfSearched = searched.size();
			
			if(myStore[i]->getOrt().substr(0, sizeOfSearched).find(searched) != std::string::npos){
				
				searchedOrt.insert(myStore[i]->getOrt());
				
				/*
				std::cout
				<< std::left << std::setw(15) << myStore[i]->getOrt() << std::setw(20)
				<< myStore[i]->getPLZ() << std::setw(30)
				<< myStore[i]->getAdresse() << std::right << std::setw(30)
				<< vorwahlen[myStore[i]->getOrt()] << "-"
				<< myStore[i]->getTelefonnummer()
				<< std::endl;
				*/
			}
		}
	}
	else
	{
		std::cout << "No Stores found" << std::endl;
	}


	//std::sort(searchedOrt.begin(), searchedOrt.end());

	for (std::set<std::string>::iterator it = searchedOrt.begin(); it != searchedOrt.end(); ++it) {
		//std::cout << searchedOrt[j] << std::endl;
		
		for (unsigned int k = 0; k < myStore.size(); k++) {
			if (myStore[k]->getOrt() == *it) {
				std::cout
					<< std::left << std::setw(15) << myStore[k]->getOrt() << std::setw(20)
					<< myStore[k]->getPLZ() << std::setw(30)
					<< myStore[k]->getAdresse() << std::right << std::setw(30)
					
					<< std::endl;
				
			}
			
		}
		
	}

}