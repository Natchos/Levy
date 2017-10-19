#pragma once


#include <list>
#include <string>
#include <SFML/Audio.hpp>
#include "Engine_Enums.cpp"



//A wrapper for sf::Music, to implement some new features.
class h_Music : public sf::Music
{
	//Increment when a new h_SFX object is created.
	static int IDCounter;
	//Used for when you want to play this specifically
	int ID;

	//In what situations should this be played?
	std::list<AudioEnvironment> AEnv;

	//Name/title of the music
	std::string musicName;

	//From what file was this music loaded from?
	std::string fileName;


public:

	//Initialize the counter
	static void initIDCounter();

	//Constructor
	h_Music(AudioEnvironment* Envs, int size, std::string iFileName = "0", std::string iMusicName = "0");

		//Default constructor
	h_Music();

	//Accessors
	std::string getMusicName();	

	void setMusicName(std::string mName);

	std::string getFileName();

	void setFileName(std::string fName);

	//Returns true if this object contains a matching environment
	bool environCheck(AudioEnvironment val);

	//Returns the list of current environs
	std::list<AudioEnvironment> getEnvirons();

	int getID();
};