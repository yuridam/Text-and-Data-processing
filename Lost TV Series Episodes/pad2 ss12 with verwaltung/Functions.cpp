#include "stdafx.h"
#include "Verwaltung.h"


Verwaltung::Verwaltung()
{
}


Verwaltung::~Verwaltung()
{
}


void Verwaltung::addEpisode(string newNummer, string titelDE, string titelEN, string inhalt, string flashback) {
	Episode* newEpisode = new Episode;
	newEpisode->setEpisodeNummer(newNummer);
	newEpisode->setEpisodeTitelDE(titelDE);
	newEpisode->setEpisodeTitelEN(titelEN);
	newEpisode->setEpisodeInhalt(inhalt);
	newEpisode->setEpisodeFlashback(flashback);
	myEpi.push_back(newEpisode);
}

void Verwaltung::readEpisodes() {
	Episode* epi = new Episode;

	ifstream fin;
	fin.open("text2.txt");


	if (fin.is_open())
		cout << "READ\n";
	else cout << "Not Found\n";
	bool titlefound = false;
	string epsNummer;
	string epsTitelDE;
	string epsTitelEN;
	string epsInhalt = "";
	string epsFlashback = "";

	do
	{
		// declare variable for current line
		string line;
		getline(fin, line);



		if (titlefound) {
			int titleBegin = line.find("(");
			int titleEnd = line.find(")");
			epsTitelEN = line.substr(titleBegin + 1, titleEnd - titleBegin - 1);
			epsTitelDE = line.substr(0, titleBegin - 1);
			epsInhalt = "";

			do {
				std::getline(fin, line);

				int dividerLocation = line.find("****");
				epsInhalt = epsInhalt + line.substr(0, dividerLocation);

				if (line.find("<FLASHBACK>") != std::string::npos) {
					int flashbackBegin = line.find("<FLASHBACK>");
					int flashbackEnd = line.find("</FLASHBACK>");
					epsFlashback = epsFlashback + "\n>" + line.substr(flashbackBegin + 12, flashbackEnd - flashbackBegin - 13);
				}


			} while (fin && line != "****");




			addEpisode(epsNummer, epsTitelDE, epsTitelEN, epsInhalt, epsFlashback);
			titlefound = false;
			epsFlashback = "";
		}


		if (line.find("EPISODE") != std::string::npos) {
			epsNummer = line.substr(line.find(" ") + 1);
			titlefound = true;
		}



	} while (fin); // stop when there are no lines left

}

void Verwaltung::listEpisodes() {
	system("CLS");
	if (myEpi.size() != 0)
	{
		for (unsigned int i = 0; i < myEpi.size(); i++)
		{
			cout
				<< myEpi[i]->getEpisodeNummer() << " " <<
				myEpi[i]->getEpisodeTitelEN() << endl;

		}
	}
	else
	{
		cout << "No Episodes found" << endl;
	}
}

void Verwaltung::showInhalt(string inputEpsNummer) {
	system("CLS");
	if (myEpi.size() != 0)
	{
		for (unsigned int i = 0; i < myEpi.size(); i++)
		{
			if (inputEpsNummer == myEpi[i]->getEpisodeNummer()) {
				cout
					<< ") Episode Nummer : " << myEpi[i]->getEpisodeNummer() << endl
					<< "   > Titel DE    : " << myEpi[i]->getEpisodeTitelDE() << endl
					<< "   > Titel EN	 : " << myEpi[i]->getEpisodeTitelEN() << endl
					<< "   > Inhalt		 : " << endl << myEpi[i]->getEpisodeInhalt() << endl;
			}

		}
	}
	else
	{
		cout << "No Episodes found" << endl;
	}
}

void Verwaltung::showEpisodeRueckblick(string inputEpsNummer) {
	system("cls");
	if (myEpi.size() != 0)
	{
		for (unsigned int i = 0; i < myEpi.size(); i++)
		{
			if (inputEpsNummer == myEpi[i]->getEpisodeNummer()) {
				cout << myEpi[i]->getEpisodeNummer() << endl;
				cout << myEpi[i]->getEpisodeFlashback() << endl;
			}

		}
	}
	else
	{
		cout << "No Episodes found" << endl;
	}

}

void Verwaltung::showCommonWords(string inputEpsNummer) {
	system("cls");
	if (myEpi.size() != 0)
	{
		for (unsigned int i = 0; i < myEpi.size(); i++)
		{
			if (inputEpsNummer == myEpi[i]->getEpisodeNummer()) {
				cout << myEpi[i]->getEpisodeNummer() << endl;



				map <string, int> wordsmap;
				map<int, vector<string>, greater<int>> invertedMap;
				vector<string> words;

				istringstream lines(myEpi[i]->getEpisodeFlashback());

				while (lines) {
					string line;
					lines >> line;
					words.push_back(line);

				}
				words.pop_back();
				sort(words.begin(), words.end());

				int vSize = words.size();
				int wordCount = 1;

				string sortWord = words[0];


				for (int i = 1; i < vSize; i++) {

					if (sortWord != words[i]) {
						wordsmap.insert(pair<string, int>(sortWord, wordCount));
						wordCount = 0;
						sortWord = words[i];
					}
					wordCount++;
				}


				wordsmap.insert(pair<string, int>(sortWord, wordCount));



				for (map<string, int>::iterator it = wordsmap.begin(); it != wordsmap.end(); ++it)
				{

					invertedMap[it->second].push_back(it->first);

				}

				int top15reached = 0;
				for (map<int, vector<string>>::iterator it = invertedMap.begin(); it != invertedMap.end(); ++it)
				{

					for (auto c : it->second)
					{
						if (top15reached > 14) {
							break;
						}
						std::cout << it->first << " - ";
						std::cout << c << std::endl;
						top15reached++;
					}

				}

			}

		}
	}
	else
	{
		cout << "No Episodes found" << endl;
	}
}

void Verwaltung::showHauptpersonen(string inputEpsNummer) {
	system("cls");
	if (myEpi.size() != 0)
	{
		for (unsigned int i = 0; i < myEpi.size(); i++)
		{
			if (inputEpsNummer == myEpi[i]->getEpisodeNummer()) {
				cout << myEpi[i]->getEpisodeNummer() << endl;

				ifstream readHauptpersonen;
				readHauptpersonen.open("hauptpersonen.txt");

				string hauptpersonen;
				while (readHauptpersonen) {
					string linePersonen;
					getline(readHauptpersonen, linePersonen);
					int appear = 0;
					istringstream linesFlashback(myEpi[i]->getEpisodeFlashback());
					while (linesFlashback) {
						string line;
						linesFlashback >> line;
						if (line.find(linePersonen) != std::string::npos) {
							appear++;
						}
					}
					if (appear > 5) {
						hauptpersonen = hauptpersonen + " " + linePersonen;
					}


				}
				if (hauptpersonen.size() == 1) {
					cout << "Hauptpersonen : keine" << endl;
				}
				else cout << "Hauptpersonen :" << hauptpersonen << endl;



			}

		}
	}
	else
	{
		cout << "No Episodes found" << endl;
	}
}

void Verwaltung::showEpisodesWithMC() {
	system("CLS");
	if (myEpi.size() != 0)
	{
		for (unsigned int i = 0; i < myEpi.size(); i++)
		{
			cout
				<< myEpi[i]->getEpisodeNummer() << " " <<
				myEpi[i]->getEpisodeTitelEN() << " ";

			ifstream readHauptpersonen;
			readHauptpersonen.open("hauptpersonen.txt");

			string hauptpersonen;
			while (readHauptpersonen) {
				string linePersonen;
				getline(readHauptpersonen, linePersonen);
				int appear = 0;
				istringstream linesFlashback(myEpi[i]->getEpisodeFlashback());
				while (linesFlashback) {
					string line;
					linesFlashback >> line;
					if (line.find(linePersonen) != std::string::npos) {
						appear++;
					}
				}
				if (appear > 5) {
					hauptpersonen = hauptpersonen + " " + linePersonen;
				}


			}
			if (hauptpersonen.size() == 1) {
				cout << "Keine Spezielle" << endl;
			}
			else cout << hauptpersonen << endl;

		}
	}
	else
	{
		cout << "No Episodes found" << endl;
	}
}