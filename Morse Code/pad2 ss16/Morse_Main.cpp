// pad2 ss16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <functional>
#include <iomanip> 
#include "Morse.h"

using namespace std;

void weiter();
int main()
{
	Morse* mors = new Morse;
	char input = NULL;
	mors->readCode();
	while (input != '5')
	{
		system("cls");
		cout << "---------------------------" << endl;
		cout << "|			MORSE		 |" << endl;
		cout << "---------------------------" << endl;
		cout << "1. Zeichen-Code-Paare nach Codelaenge sortiert ausgeben " << endl;
		cout << "2. 'AT.txt' einlesen, codieren und Morsecode in Datei abspeichern" << endl;
		cout << "3. 'ATCoded.txt' einlesen, decodieren und Text ausgeben" << endl;
		cout << "4. Uebertragungsdauer berechnen" << endl;
		cout << "5. Programm beenden" << endl;
		cout << endl << "Eingabe: ";
		cin >> input;
		system("cls");

		switch (input)
		{
		case '1':
		{
			system("cls");
			mors->showSortedCode();
			
			weiter();
			break;
		}
		case '2':
		{
			system("cls");
			mors->convertTextToMorse();
			weiter();
			break;
		}
		case '3':
		{
			system("cls");
			//mors->convertMorseToText();
			cout << "SUSAH BANGSAT" << endl;
			weiter();
			break;
		}
		case '4':
		{
			system("cls");
			mors->calculateLengthMorse();
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