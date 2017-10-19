#pragma once

#include "Homebrew_Music.hpp"

//Increment when a new h_SFX object is created.
int h_Music::IDCounter = 0;


//Initialize the counter
void h_Music::initIDCounter()
{
	h_Music::IDCounter = 0;
}

//Constructor
h_Music::h_Music(AudioEnvironment* Envs, int size, std::string iFileName, std::string iMusicName) : sf::Music()
{
	for (int i = 0; i < size; i++)
	{
		AEnv.push_back(Envs[i]);
	}
	//Prepend a default Audio folder?
	if (iFileName != "0")
	{
		fileName = iFileName;
	}
	if (iMusicName != "0")
	{
		musicName = iMusicName;
	}
	this->openFromFile(fileName);
}
//Default constructor
h_Music::h_Music()
{
	AEnv.push_back(AudioEnvironment::Normal);
	ID = h_Music::IDCounter;
	h_Music::IDCounter++;
}
//Accessors
std::string h_Music::getMusicName()
{
	return musicName;
}
void h_Music::setMusicName(std::string mName)
{
	musicName = mName;
}
std::string h_Music::getFileName()
{
	return fileName;
}
void h_Music::setFileName(std::string fName)
{
	fileName = fName;
}

//Returns true if this object contains a matching environment
bool h_Music::environCheck(AudioEnvironment val)
{
	for (std::list<AudioEnvironment>::const_iterator itr = AEnv.begin(), end = AEnv.end(); itr != end; itr++)
	{
		if (*itr == val)
			return true;
	}
	return false;
}

//Returns the list of current environs
std::list<AudioEnvironment> h_Music::getEnvirons()
{
	return AEnv;
}

int h_Music::getID()
{
	return ID;
};
