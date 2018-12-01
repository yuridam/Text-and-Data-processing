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


class Store
{
public:
	Store();
	~Store();

	void setPLZ(std::string);
	void setOrt(std::string);
	void setAdresse(std::string);
	void setTelefonnummer(std::string);

	std::string getPLZ();
	std::string getOrt();
	std::string getAdresse();
	std::string getTelefonnummer();

	void addStore(std::string plz, std::string ort, std::string adresse, std::string telefonnumer);
	void readVorwahlen();
	void readStores();
	void showStores();
	void showStoresWithPrefix();
	void searchStores();
	std::vector <Store*> myStore;
	std::map<std::string, int> vorwahlen;

protected:
	std::string PLZ;
	std::string Ort;
	std::string Adresse;
	std::string Telefonnummer;


};

