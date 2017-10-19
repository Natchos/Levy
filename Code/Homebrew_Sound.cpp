#pragma once

#include "Homebrew_Sound.hpp"
//A wrapper for sf::Sound, mostly to implement IDs.

//Increment when a new h_SFX object is created.
int h_SFX::IDCounter = 0;

//Initialize the counter
void h_SFX::initIDCounter()
{
	h_SFX::IDCounter = 0;
}

	//Constructor
h_SFX::h_SFX(std::string nSFXName, std::string nFileName)
{
	ID = IDCounter;
	IDCounter++;
	if (nSFXName != "0")
	{
		SFXName = nSFXName;
	}
	if (nFileName != "0")
	{
		fileName = nFileName;
	}
}
	//Accessors
std::string h_SFX::getfileName()
	{
		return fileName;
	}
void h_SFX::setFileName(std::string fName)
{
	fileName = fName;
}
int h_SFX::getID()
{
	return ID;
}