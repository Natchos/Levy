#pragma once
#include "Watch.hpp"
#ifndef INCLUDED_BASE_OBJECT
#include "Game_Object.hpp"
#endif
#include "2FloatVector.hpp"
#include "Randomizer.cpp"
#include "Engine_Enums.cpp"
#include <vector>
#include <list>
#include <iostream>
#include <SFML/System.hpp>

//Defines the maximum amount of objects with unique IDs which can be represented in the game.
const int Max_Number_Of_Objects = 10000;
//The ObjectManager class contains all current GameObjects. These are all stored in a vector as pointers to Game_Object.
//All updating of course happens within the OBJ_Update, but the manager should be in charge of following functions:
//Deleting/Killing Objects, Adding new Objects, Timing the game updates, keeping track of the IDs used
class ObjectManager 
{
public:
	bool Initialize();

	//Returns the ID of the new object.
	//CREATES OBJECT WITH NEW KEYWORD. The engine automtically deallocates upon shutdown.
	int createNewObject(Object_Type type, Vector2D position, Vector2D size, GFXDrawPriority drawPrio, sf::Sprite copySprite);

	//Same as above
	int createNewObject(Object_Type type, Vector2D position, Vector2D size);
	
	//Most basic entity
	int createNewObject(Object_Type type);
	//Add a sent/completed object
	void AddObject(Game_Object* nVal);

	//Allows you to change FPS during runtime.
	void setFPS(int NewFPS);

	//Allmighty Update function, hallowed be thy name
	void Update();

	//Call upon shutdown. Deallocates any memory used up.
	void Exit();

	//Singleton, so this returns the only instance of the objectmanager
	static ObjectManager* Instance();

private:

	//What FPS should the engine strive for? Recommended value: >60
	int DesiredFPS;

	//Used to time every update
	Watch UpdateTimer;


	std::vector<Game_Object*> Objects;
};