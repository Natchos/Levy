#pragma once
#include "Engine_Enums.cpp"
#include "Basic_Render_Entity.hpp"
#include "2FloatVector.hpp"
#include "ScreenLog.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/* This class manages all the graphical objects in the program(atleast the ones that are descended from the Basic_Render_Entity)
* Its main function is the GFX_Update, but it also contains various functions for accessing and modifying a sprite, allowing
* search by ID */
class GraphicsManager
{
public:
	//Initializes the Graphics Manager. Creates a renderwindow and sets its dimensions, either according to parameters or failing that, through the desktop mode.
	//FPS is set to 60 as default value.
	bool Initialize(static ScreenLog* ScrLogPtr, int Height = -1, int Width = -1, int FPS = 60);

	//Graphical Update/Render
	void Update();

	//Allows you to set an visual FPS. Recommended values: 30-60
	void setGFPS(int newFPS);


	void Exit();

	void AddEntity(Basic_Render_Entity* nVal);


	//Singleton design pattern
	static GraphicsManager* Instance();

	//If direct access to the Render Window is needed.
	sf::RenderWindow* Homebrew_Render_PTR();
private:
	//Visual FPS
	int DesiredFPS;
	//Used to time every frame
	Watch UpdateTimer;
	//Contains all drawn entities(with the exception of UI elements).
	std::vector<Basic_Render_Entity*> RenderVector;

	std::vector<sf::Texture> TextureVector;


	//Pointer to the Render Window. The Render Window is allocated through new, and is deallocated and deleted through the Exit function, so please use
	//this to prevent memory leaks
	sf::RenderWindow* Homebrew_Render;

	Vector2D Screensize;
	
	//Screenlog pointer, for rendering purposes.
	ScreenLog* ScrLog;
};