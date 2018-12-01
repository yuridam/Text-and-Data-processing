#include "stdafx.h"
#include "Episode.h"


Episode::Episode()
{
}


Episode::~Episode()
{
}


void Episode::setEpisodeNummer(string newNummer)
{
	this->EpisodeNummer = newNummer;
}


void Episode::setEpisodeTitelDE(string titelDE)
{
	this->EpisodeTitelDE = titelDE;
}

void Episode::setEpisodeTitelEN(string titelEN)
{
	this->EpisodeTitelEN = titelEN;
}

void Episode::setEpisodeInhalt(string inhalt)
{
	this->EpisodeInhalt = inhalt;
}

void Episode::setEpisodeFlashback(string flashback)
{
	this->EpisodeFlashback = flashback;
}




string Episode::getEpisodeNummer()
{
	return EpisodeNummer;
}

string Episode::getEpisodeTitelDE()
{
	return EpisodeTitelDE;
}

string Episode::getEpisodeTitelEN()
{
	return EpisodeTitelEN;
}

string Episode::getEpisodeInhalt()
{
	return EpisodeInhalt;
}

string Episode::getEpisodeFlashback()
{
	return EpisodeFlashback;
}