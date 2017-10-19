#pragma once


#include <SFML/Audio.hpp>
#include <string>

class h_SFX : public sf::Sound
{

	//Increment when a new h_SFX object is created.
	static int IDCounter;
	//Used for when you want to play this
	int ID;

	//Used if you for some reason need a title instead
	std::string SFXName;

	//From where was this sound loaded?
	std::string fileName;

public:

	//Initialize the counter
	static void initIDCounter();

	//Constructor
	h_SFX(std::string nSFXName = "0", std::string nFileName = "0");

	std::string getfileName();
	void setFileName(std::string fName);
	int getID();
};
