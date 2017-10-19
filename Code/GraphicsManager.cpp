#pragma once
#include "GraphicsManager.hpp"

//Initialization
bool GraphicsManager::Initialize(static ScreenLog* ScrLogPtr, int Height, int Width, int FPS)
{
	this->ScrLog = ScrLogPtr;
	if(Height != -1 && Width != -1)
		Homebrew_Render = new sf::RenderWindow(sf::VideoMode::VideoMode(Width,Height), "Homebrew Pre-Omega");
	else
		Homebrew_Render = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Homebrew Pre-Omega");
	this->DesiredFPS = FPS;
	Homebrew_Render->setFramerateLimit(DesiredFPS);
	return true;
}
//Update function. Iterates through all objects and draws them in appropriate order, based on their draw priority enum value.
//Any graphical effect you would like to be applied every frame should be put here.
void GraphicsManager::Update()
{
	if(UpdateTimer.getElapsedTime().asMilliseconds() > 1000/DesiredFPS)
	{
		Homebrew_Render->clear(sf::Color(0,0,0,255));
		for(int DrawPrio_Count = 0; DrawPrio_Count < 4; DrawPrio_Count++)
		{
			for(std::vector<Basic_Render_Entity*>::iterator iter = RenderVector.begin(); iter != RenderVector.end(); iter++)
			{
				if (*iter != NULL)
				{
					if ((*iter)->getDrawPrio() == (GFXDrawPriority)DrawPrio_Count)
					{
						(*iter)->GFX_Update();
						Homebrew_Render->draw(**iter);
					}
				}
				else 
				{
					//Handles deleted objects, removes pointers to Null
					iter = RenderVector.erase(iter);
				}
			}
		}
		//std::vector<sf::Text*> RenderLog = ScrLog->SendListToRender();
		for(std::vector<TimedText>::iterator iter = ScrLog->Lines.begin(); iter != ScrLog->Lines.end(); iter++)
		{
			Homebrew_Render->draw(*iter);
		}
		if(ScrLog->Lines.size() != 0)
		{
			std::string ex(ScrLog->Lines[0].getBase()->getString());
			Homebrew_Render->draw(sf::Text(ScrLog->Lines[0]));
		}
		Homebrew_Render->display();
		UpdateTimer.reset();
	}
}

void GraphicsManager::AddEntity(Basic_Render_Entity* nVal)
{
	RenderVector.push_back(nVal);
}

//Singleton design pattern.
GraphicsManager* GraphicsManager::Instance()
{
	static GraphicsManager instance;
	return &instance;
}

sf::RenderWindow* GraphicsManager::Homebrew_Render_PTR()
{
	return Homebrew_Render;
}

//Shut it all down! Deallocates and deletes objects as well as the render window.
void GraphicsManager::Exit()
{
	RenderVector.clear();
	//Send message that GFX Manager is shutting down.
	//Deallocate memory and call destructor.
	delete Homebrew_Render;
	this->~GraphicsManager();
}

//Sets the GFPS to given value
void GraphicsManager::setGFPS(int NewFPS)
{
	this->DesiredFPS = NewFPS;
}
