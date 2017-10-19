#pragma once

#include "SoundManager.hpp"

bool SoundManager::Initialize(std::string MUSIC_FOLDER, std::string SFX_FOLDER, bool SFX_MUTE, bool MUSIC_MUTE)
{
	h_SFX::initIDCounter();
	h_Music::initIDCounter();

	SFX_F = SFX_FOLDER;
	MUS_F = MUSIC_FOLDER;
	effectMute = SFX_MUTE;
	musicMute = MUSIC_MUTE;
	musicVol = 5;
	SFXVol = 5;
	return true;
}

SoundManager* SoundManager::Instance()
{
	static SoundManager instance;
	return &instance;
}


bool SoundManager::playSFXByID(int id)
{
	for (std::vector<h_SFX>::iterator iter = SFX.begin(); iter != SFX.end(); iter++)
	{
		if (iter->getID() == id)
		{
			iter->play();
			return true;
		}
	}
	//ID not found, either faulty ID or something fucked up. Return false;
	return false;
}

bool SoundManager::playSongByID(int id, bool queue = false)
{
	for (std::vector<h_Music>::iterator iter = Music.begin(); iter != Music.end(); iter++)
	{
		if (iter->getID() == id)
		{
			if (queue)
				nextMusic = &*iter;
			else
			{
				curMusic->stop();
				curMusic = &*iter;
				curMusic->play();
			}
			//ID found, song switched. Return true.
			return true;
		}
	}
	//ID not found, either faulty ID or something fucked up. Return false;
	return false;
}

void SoundManager::pause()
{
	this->curMusic->pause();
}

void SoundManager::play()
{
	if (this->curMusic->getStatus() != sf::SoundSource::Status::Playing)
		this->curMusic->play();
}

void SoundManager::next()
{
	//Randomly selects next song
	if (shuffleMusic)
	{
		int uBound = this->Music.size();
		this->nextMusic = &Music[this->internalRand.iGenerateRandom(0, uBound)];
	}
	else
	{
		//Std:find is fucky, so I'll just use my own inefficient algorithm
		for (std::vector<h_Music>::iterator iter = Music.begin(); iter != Music.end(); iter++)
		{
			if (curMusic->getID() == iter->getID())
			{
				if (iter != Music.end())
					this->nextMusic = &*iter;
				else
					this->nextMusic = (Music.data() + (iter - Music.begin()));
			}
		}
	}
}

void SoundManager::restart()
{
	curMusic->stop();
	curMusic->play();
}

void SoundManager::setShuffle(bool nShuffle)
{
	this->shuffleMusic = nShuffle;
}

void SoundManager::muteMusic(bool val)
{
	this->musicMute = val;
}

void SoundManager::muteSFX(bool val)
{
	this->effectMute = val;
}

void SoundManager::muteAll(bool val)
{
	this->musicMute = val;
	this->effectMute = val;
}

void SoundManager::decreaseVolume(std::string identifier)
{
	if (identifier == "Music" && musicVol > 0)
		musicVol--;
	else if (identifier == "SFX" && SFXVol > 0)
		SFXVol--;

}

void SoundManager::increaseVolume(std::string identifier)
{
	if (identifier == "Music" && musicVol < 10)
		musicVol--;
	else if (identifier == "SFX" && SFXVol < 10)
		SFXVol--;
}