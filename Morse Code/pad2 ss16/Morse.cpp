#include "stdafx.h"
#include "Morse.h"


Morse::Morse()
{
}


Morse::~Morse()
{
}



void Morse::readCode() {
	std::ifstream input;
	input.open("input.txt");

	if (input.is_open())
		std::cout << "READ\n";
	else std::cout << "Not Found\n";
	std::string key;
	std::string value;
	while (input) {
		std::string line;

		getline(input, line, '\t');
		key = line;

		getline(input, line, '\n');
		value = line;
		std::istringstream split(line);
		int length = 0;
		int space = -2;
		int totalLength;
		while (split) {
			std::string singleCode;
			split >> singleCode;
			if (singleCode.find("-") != std::string::npos) {
				length += 3;
			}
			if (singleCode.find(".") != std::string::npos) {
				length += 1;
			}
			space++;
		}
		totalLength = length + space;
		codeMap.insert(std::pair<std::string, std::string>(key, value));
		codeMap.insert(std::pair<std::string, std::string>(" ", "    ")); //new key space with value of 4 spaces for req 2
		mapCodeAndLength.insert(std::pair<std::string, int>(key, totalLength)); //map with only characters and their length
		codeMap2.insert(std::pair<std::string, std::string>(value, key));
		codeMapWithLength[totalLength].insert(std::pair<std::string, std::string>(key, value));
	}
	codeMapWithLength.erase(-1);
}

void Morse::showSortedCode() {
	for (std::map <int, std::map<std::string, std::string>>::iterator it = codeMapWithLength.begin(); it != codeMapWithLength.end(); ++it)
	{
		for (std::map<std::string, std::string>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
			std::cout << std::left << std::setw(10) << it->first << std::right << std::setw(20) << it2->second << std::right << std::setw(15) << it2->first << std::endl;
		}
	}
}

void Morse::convertTextToMorse() {
	char ch;
	std::ifstream fin("AT.txt");
	std::string convertedText;
	std::string charAsString = "";
	while (fin >> std::noskipws >> ch) {
		charAsString += ch;
		convertedText += codeMap[charAsString] + "   ";
		charAsString = "";
		}
	std::cout << convertedText;

	std::ofstream fout("ATCoded.txt");
	fout << convertedText;

}

void Morse::convertMorseToText() {
	std::ifstream input;
	input.open("ATCoded.txt");

	while (input) {
		std::string line;

		getline(input, line, ' ');
		std::cout << line << std::endl;
	}
}

void Morse::calculateLengthMorse() {
	mapCodeAndLength[" "] = 7; //set the length of a single space as 7 long
	std::ifstream input;
	input.open("symbolCounts.txt");
	std::string key;
	int value;
	int lengthRoman = 0;
	while (input) {
		std::string line;

		getline(input, line, '\t');
		key = line;
		getline(input, line, '\n');
		value = atoi(line.c_str());
		
		lengthRoman += (value * (mapCodeAndLength[key]+3)); //plus 3 karena diantara karakter lamanya 3 ketuk
	}
	int lengthRomanInMinutes = lengthRoman / 100;
	int lengthRomanInHours = lengthRomanInMinutes / 60;
	int lengthRomanInDays = lengthRomanInHours / 24;
	std::cout << "Day : " << lengthRomanInDays << std::endl;
	std::cout << "Hour : " << lengthRomanInHours << std::endl;
	std::cout << "Minute : " << lengthRomanInMinutes << std::endl;
	std::cout << "Second : " << lengthRoman << std::endl;
}