#pragma once

#include "ObjectManager.hpp"
#include "GraphicsManager.hpp"
#include "Watch.hpp"
#include "Engine_Enums.cpp"

class InputManager
{

	//Keeps track of how much time has elapsed since last input
	Watch keyPressTimer;

	//Keeps track of previous keypresses.
	std::vector<sf::Keyboard::Key> keyPresses;

public:
	
	InputManager();

	//Handles event looping and mouse events.
	bool Update(sf::RenderWindow* activeWindow);

	//Singleton design pattern
	static InputManager* Instance();
private:
};
