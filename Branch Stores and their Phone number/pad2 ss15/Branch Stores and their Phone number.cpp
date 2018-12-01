// pad2 ss15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <iomanip> 
#include "Store.h"


using namespace std;
void weiter();
int main()
{
	Store* sto = new Store;
	sto->readVorwahlen();
	char input = NULL;
	sto->readStores();
	while (input != '5')
	{
		system("cls");
		cout << "---------------------------" << endl;
		cout << "|			FILIALE		 |" << endl;
		cout << "---------------------------" << endl;
		cout << "1. Vorwahlen nach Orten sortiert in Datei schreiben  " << endl;
		cout << "2.	Filialen einlesen " << endl;
		cout << "3. Vorwahlen fuer Filialen ergaenzen " << endl;
		cout << "4. Filialen ausgeben (fuer bestimmte Orts-Anfangsbuchstaben)" << endl;
		cout << "5. Programm beenden" << endl;
		cout << endl << "Eingabe: ";
		cin >> input;
		system("cls");

		switch (input)
		{
		case '1':
		{
			system("cls");
			
			
			string title;
			cout << "Geben Sie die Dateiname an!" << endl;
			cin >> title;
			ofstream output(title+".txt");
			for (std::map<std::string, int>::iterator it = sto->vorwahlen.begin(); it != sto->vorwahlen.end(); ++it)
			{

				
				output << left << setw(30) << setfill('.') << it->first << it->second << endl;

			}


			weiter();
			break;
		}
		case '2':
		{
			system("cls");
			sto->showStores();

			weiter();
			break;
		}
		case '3':
		{
			system("cls");
			sto->showStoresWithPrefix();
			weiter();
			break;
		}
		case '4':
		{
			system("cls");
			sto->searchStores();
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