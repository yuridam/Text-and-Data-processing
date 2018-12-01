// pad2 ss14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <iomanip> 
#include "Town.h"


using namespace std;
void weiter();
int main()
{
	Town* twn = new Town;
	twn->sortTownsAndLand();
	twn->readTowns();
	char input = NULL;

	while (input != '5')
	{
		system("cls");
		cout << "---------------------------" << endl;
		cout << "|			TOWN	 |" << endl;
		cout << "---------------------------" << endl;
		cout << "1. Alle Städte sortiert nach Land und Namen ausgeben   " << endl;
		cout << "2.	Alle Städte sortiert nach Land und Einwohnerzahl ausgeben " << endl;
		cout << "3. Länder und Gesamteinwohnerzahl in Millionenstädten ausgeben " << endl;
		cout << "4. Alle Städte sortiert nach Einwohnerzahl im Jahr 2050 ausgeben " << endl;
		cout << "5. Programm beenden" << endl;
		cout << endl << "Eingabe: ";
		cin >> input;
		system("cls");

		switch (input)
		{
		case '1':
		{
			system("cls");
			twn->showTowns();
			weiter();
			break;
		}
		case '2':
		{
			system("cls");
			twn->sortTownsByEinwohner();
			twn->showTowns3();
			weiter();
			break;
		}
		case '3':
		{
			system("cls");
			twn->sumEinwohnerProLand();
			for (std::map<int, std::string>::iterator it = twn->mapEinwohnerProLand.begin(); it != twn->mapEinwohnerProLand.end(); ++it) {

				std::cout << it->first << '\t' << it->second << std::endl;
			}
			weiter();
			break;
		}
		case '4':
		{
			system("cls");
			
				for (unsigned int i = 0; i < twn->myTown.size(); i++)
				{
					
					cout << twn->myTown[i]->getEinwohner().substr(1) << endl;
				}
			
			weiter();
			break;
		}
		case '5':
		{
			break;
		}
		}
	}

	return 0;
}

void weiter()
{
	string enter;
	cin.ignore();
	getline(cin, enter);
	system("cls");
}