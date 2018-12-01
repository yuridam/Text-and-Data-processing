// pad2 ss12 with verwaltung.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Episode.h"
#include "Verwaltung.h"

using namespace std;


void weiter();

int main()
{
	Episode* epi = new Episode;
	Verwaltung verwalt;
	char input = NULL;
	string inputEpsNummer;
	verwalt.readEpisodes();
	while (input != '5')
	{
		system("cls");
		cout << "---------------------------" << endl;
		cout << "|			NYASAR		 |" << endl;
		cout << "---------------------------" << endl;
		cout << "1. Englische Episodentitel und Inhalt einer beliebigen Episode ausgeben" << endl;
		cout << "2. Nur Rückblicke einer beliebigen Episode ausgeben" << endl;
		cout << "3. Die 15 häufigsten Wörter der Rückblicke einer Episode ausgeben" << endl;
		cout << "4. Hauptpersonen aller Episoden ausgeben" << endl;
		cout << "5. Programm beenden" << endl;
		cout << endl << "Eingabe: ";
		cin >> input;
		system("cls");

		switch (input)
		{
		case '1':
		{
			system("cls");

			//list episodes
			verwalt.listEpisodes();
			cout << "Which episode do you want to read the synopsis?" << endl;
			cout << "Enter the Episode Number :";
			cin >> inputEpsNummer;
			system("cls");
			verwalt.showInhalt(inputEpsNummer);
			weiter();
			break;
		}
		case '2':
		{
			system("cls");
			verwalt.listEpisodes();
			cout << "Which episode do you want to read the flashback?" << endl;
			cout << "Enter the Episode Number :";
			cin >> inputEpsNummer;
			verwalt.showEpisodeRueckblick(inputEpsNummer);
			weiter();
			break;
		}
		case '3':
		{
			system("cls");
			verwalt.listEpisodes();
			cout << "Which episode do you want to see the common words in flashback?" << endl;
			cout << "Enter the Episode Number :";
			cin >> inputEpsNummer;
			verwalt.showCommonWords(inputEpsNummer);
			weiter();
			break;
		}
		case '4':
		{
			system("cls");

			verwalt.showEpisodesWithMC();
			weiter();
			break;
		}
		case '5':
		{

			break;
		}
		}

	}
}

void weiter()
{
	string enter;
	cin.ignore();
	getline(cin, enter);
	system("cls");

}