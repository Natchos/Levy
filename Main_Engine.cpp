#pragma once
#include "Code/GraphicsManager.hpp"
#include "Code/ObjectManager.hpp"
#include "Code/Basic_Render_Entity.hpp"
#include "Code/Game_Object.hpp"
#include "Code/Console_Log.hpp"
#include "Code/ScreenLog.hpp"
#include "Code/InputManager.hpp"
#include "Code/SoundManager.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

//As little code as possible should be here. Optimally this .cpp file will contain the following: Main, Update, init and shutdown functions.


GameState Current_Gamestate;
GameState Previous_Gamestate;

#define OBJMGR ObjectManager::Instance()
#define CONLOG Console_Log::Instance()
#define SCRLOG ScreenLog::Instance()
#define GFXMGR GraphicsManager::Instance()
#define INPMGR InputManager::Instance()
#define SFXMGR SoundManager::Instance()

bool main_Initialization();
void main_Running_Loop();
bool main_Shutdown();

std::vector<Game_Object*> Objects;

void main()
{
	if(main_Initialization())
	{
		CONLOG->Log("Launching into main loop!",LogPriority::SysInformation);
		main_Running_Loop();
	}

	main_Shutdown();
	//Shutting down
	CONLOG->Log("Exiting and shutting down! Creating logfile!", LogPriority::SysInformation);
	//No need to create a logfile for a standard run. 
	//CONLOG->Write_Log_File();
	return;
}

bool main_Initialization()
{
	if(CONLOG->Initialize())
	{
		CONLOG->Log("Initializing Object Manager", LogPriority::SysInformation);
		CONLOG->Log("Initializing Screen Logger", LogPriority::SysInformation);
		if(SCRLOG->Initialize())
		{
			if(OBJMGR->Initialize())
			{
				CONLOG->Log("Object Manager Initialized");
				CONLOG->Log("Initializing Graphics Manager", LogPriority::SysInformation);
				if(GFXMGR->Initialize(SCRLOG, 600,840,60))
				{
					CONLOG->Log("Graphics Manager Initialized");
					SCRLOG->AddMessage("Graphics Manager Initialized");
					CONLOG->Log("Initializing Messaging Manager", LogPriority::SysInformation);
					GFXMGR->Homebrew_Render_PTR()->setPosition(sf::Mouse::getPosition());

					CONLOG->Log("Messaging Manager Initialized");
					CONLOG->Log("Initializing Sound Manager", LogPriority::SysInformation);
					if (SFXMGR->Initialize("/Music","/Effects"))
					{
						CONLOG->Log("Sound Manager initialized", LogPriority::SysInformation);

					}
					else
						CONLOG->Log("Sound Manager failed to initalize. Soundless mode initiated.", LogPriority::Severe);
				}
				else
					CONLOG->Log("Graphics Manager failed to initalize. Exiting.",LogPriority::Severe);
			}
			else
				CONLOG->Log("Object Manager failed to initalize. Exiting.", LogPriority::Severe);
		}
		else
			CONLOG->Log("Screen Logger failed to initalize. Exiting.", LogPriority::Severe);
	}
	CONLOG->Log("Initalization completed successfully!",LogPriority::SysInformation);
	return true;
}

void main_Running_Loop()
{
	bool Exit = false;
	while(Exit == false)
	{
		OBJMGR->Update();
		GFXMGR->Update();
		SCRLOG->Update();
		if (!(INPMGR->Update(GFXMGR->Homebrew_Render_PTR())))
			Exit = true;
	}
}

bool main_Shutdown()
{
	OBJMGR->Exit();
	CONLOG->Log("Object Manager succesfully shut down.");
	GFXMGR->Exit();
	CONLOG->Log("Graphics Manager succesfully shut down.");
	return true;
}

void change_GameState(GameState new_Gamestate)
{
	Previous_Gamestate = Current_Gamestate;
	Current_Gamestate = new_Gamestate;
}
