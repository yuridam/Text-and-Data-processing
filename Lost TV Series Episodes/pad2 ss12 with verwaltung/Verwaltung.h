#pragma once
#include "Episode.h"

class Verwaltung
{
public:
	Verwaltung();
	~Verwaltung();


	void addEpisode(string newNummer, string titelDE, string titelEN, string inhalt, string flashback);
	void readEpisodes();
	void listEpisodes();
	void showInhalt(string);
	void showEpisodeRueckblick(string);
	void showCommonWords(string);
	void showHauptpersonen(string);
	void showEpisodesWithMC();

	std::vector <Episode*> myEpi;
};

