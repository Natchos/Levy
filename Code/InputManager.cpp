#pragma once
#include "InputManager.hpp"

InputManager::InputManager()
{
	keyPressTimer.reset();
}

//Singleton design pattern.
InputManager* InputManager::Instance()
{
	static InputManager instance;
	return &instance;
}

bool InputManager::Update(sf::RenderWindow* activeWindow)
{
	sf::Event curEvent;
	while (activeWindow->pollEvent(curEvent))
	{
		switch (curEvent.type)
			//Exit
			case sf::Event::Closed:
			return false;			
	}
	//Exit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return false;
	}
	//Add more entries when needed. Don't forget to combine the timer and the memory to allow for combos.

	return true;
}