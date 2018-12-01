#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map> //std::map
#include <functional> //std::greater
#include <sstream> //std::istringstream
#include <algorithm> //std::sort

using namespace std;
class Episode
{
public:
	Episode();
	~Episode();

	void setEpisodeNummer(string);
	void setEpisodeTitelDE(string);
	void setEpisodeTitelEN(string);
	void setEpisodeInhalt(string);
	void setEpisodeFlashback(string);




	string getEpisodeNummer();
	string getEpisodeTitelDE();
	string getEpisodeTitelEN();
	string getEpisodeInhalt();
	string getEpisodeFlashback();

protected:
	string EpisodeNummer;
	string EpisodeTitelDE;
	string EpisodeTitelEN;
	string EpisodeInhalt;
	string EpisodeFlashback;
};

