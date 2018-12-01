#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <functional>
#include <iomanip> 
class Morse
{
public:
	Morse();
	~Morse();


	void readCode();
	void showSortedCode();
	void convertTextToMorse();
	void convertMorseToText();
	void calculateLengthMorse();

	std::map <std::string, std::string> codeMap;
	std::map <std::string, std::string> codeMap2; //inverted map
	std::map <std::string, int> mapCodeAndLength;
	std::map <int, std::map<std::string, std::string>, std::greater<int>> codeMapWithLength;
		

protected:
	std::string Zeichen;
	std::string Code;
	std::string Lange;



};

