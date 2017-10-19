#pragma once
#include "Watch.hpp"


Watch::Watch()
{
	this->restart();
	stopwatch_start = this->getElapsedTime();
}
//Resets the watch.
sf::Time Watch::reset()
{
	paused = false;
	return stopwatch_start = this->restart();
}
//Pauses if unpause. Else does nothing.
void  Watch::Pause()
{
	// If not yet paused...
	if (!paused)
	{
		paused = true;
		stopwatch_start += this->getElapsedTime();
	}
}
//Unpauses(removes paused state) if paused. Else does nothing.
void  Watch::UnPause()
{
	if (paused)
	{
		paused = false;
	}
}
//Resumes after ms Milliseconds has gone by
bool  Watch::stopwatch(int ms)
{
	if (this->getElapsedTime() > stopwatch_start + sf::milliseconds(ms) ) 
	{
		stopwatch_start = this->getElapsedTime();
		if(paused) paused = false;
			return true;
	}
	else 
	{
		return false;			
	}
}
//Returns the current state
bool  Watch::IsPaused()
{
	return paused;
}

