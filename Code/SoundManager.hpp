#pragma once

#include <SFML/Audio.hpp>
#include <list>
#include <vector>
#include "Randomizer.cpp"
#include "Engine_Enums.cpp"
#include "Homebrew_Music.hpp"
#include "Homebrew_Sound.hpp"

//The class that manages the playback of all audio. It is built upon SFMLs Audio package(so check out docs if you want change it).
//The manager primarily consists of 3 containers for sf:Music, sf:SoundBuffer and sf:Sound.
//The audio data that you want to use should always be loaded as early as possible. 
//Probably I will implement a fixed directory loading function, but there will also be some support for sending filenames.
class SoundManager {
public:

	//Singleton design
	static SoundManager* Instance();


	//Initializes the manager, h_SFX & h_Music classes
	bool Initialize(std::string MUSIC_FOLDER, std::string SFX_FOLDER,bool SFX_MUTE = false, bool MUSIC_MUTE = false);
	//Contains the sound data.
	std::vector<sf::Sound> Sounds;

	//Play SFX by ID
	bool playSFXByID(int id);

	//Play music by ID
	bool playSongByID(int id, bool queue);

	//Pauses the music currently playing
	void pause();
	//Play the music currently selected
	void play();
	//Skip to the next music in the queue
	void next();
	//Start over the music currently selected
	void restart();
	//Sets shuffle
	void setShuffle(bool nShuffle);

	void increaseVolume(std::string identifier);
	void decreaseVolume(std::string identifier);
	//Increase/Decrease volume by 1. Values are clamped between 0 and 10

	//Mutes Music
	void muteMusic(bool val = true);
	//Mutes SFX
	void muteSFX(bool val = true);
	//Mutes everything
	void muteAll(bool val = true);
private:
	//Contains source data for the Sounds
	std::vector<sf::SoundBuffer> srcData;
	//Contains the Music for playback
	std::vector<h_Music> Music;
	//Contains the SFX objects
	std::vector<h_SFX> SFX;

	//Pointer to the current music being played
	h_Music* curMusic;
	//Pointer to the next music
	h_Music* nextMusic;
	//Indicates whether music should be shuffled
	bool shuffleMusic;
	//True if music is off
	bool musicMute;
	//True if sound effects are off
	bool effectMute;

	int musicVol;
	//Volume for music
	int SFXVol;
	//Volume for SFX

	Randomizer internalRand;

	//Source folder for SFX
	std::string SFX_F;

	//Source folder for Music
	std::string MUS_F;

};