#pragma once
#include <SFML/System/Clock.hpp>
#include <ctime>
#include <SFML/System/Time.hpp>
#include <SFML/System/sleep.hpp>
#include <SFML/System/Export.hpp>
#include "2FloatVector.hpp"


class Watch : public sf::Clock
{
protected:
	sf::Time stopwatch_start;
	bool paused;
public:
	Watch();
	sf::Time reset();
	void  Pause();
	void  UnPause();
	bool  stopwatch(int ms);
	bool  IsPaused();
};

