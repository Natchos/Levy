#pragma once
#include "InputManager.hpp"

InputManager::InputManager()
{
	keyPressTimer.reset();
}

bool InputManager::Initialize(static ScreenLog* ptrScrLog)
{
	this->ScrLog = ptrScrLog;
	return true;
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
		{
			//Exit
			case sf::Event::Closed:
				return false;

			case sf::Event::MouseButtonPressed:
			{
				if (curEvent.mouseButton.button == sf::Mouse::Left && keyPressTimer.getElapsedTime().asMilliseconds() > 1000)
				{
					ScrLog->AddMessage("Here a unit would have been created! At position " + std::to_string(sf::Mouse::getPosition().x) + ", " + std::to_string(sf::Mouse::getPosition().y));
					keyPressTimer.reset();
				}
			}
		}
	}
	//Exit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		return false;
	}

	//Add more entries when needed. Don't forget to combine the timer and the memory to allow for combos.

	return true;
}	