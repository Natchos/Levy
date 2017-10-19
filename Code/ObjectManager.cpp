#pragma once
#include "ObjectManager.hpp"



bool ObjectManager::Initialize()
{
	this->DesiredFPS = 60;
	UpdateTimer.reset();
	//Init Message, send at Master Prio
	return true;
}

void ObjectManager::Exit()
{
	for(std::vector<Game_Object*>::iterator iter = Objects.begin(); iter != Objects.end(); iter++)
	{
		delete (*iter);
	}
	//Shutdown Message send at Master Prio
	this->~ObjectManager();
}

int ObjectManager::createNewObject(Object_Type type, Vector2D position, Vector2D size, GFXDrawPriority drawPrio, sf::Sprite copySprite)
{
	//Points to our new temporary object
	Game_Object* tempPTR;
	//To create a new object you MUST always specify the Object_Type, since this is used to create the game_object sub-class since no base-class object can be created
	switch(type)
	{
	/*
	*Pseudo-code prototype:
	*new Object_Type/Class temp_OBJ(ctr param);
	*tempPTR = &temp_OBJ
	*/
	case Actor:
	case Player:
	case Obstacle:
	//No type = return -1 for error.
	default:
		return -1;
	}
	Objects.push_back(tempPTR);
}

int ObjectManager::createNewObject(Object_Type type, Vector2D position, Vector2D size)
{
	return this->createNewObject(type, position, size, GFXDrawPriority::DoNotDraw, sf::Sprite());
}

int ObjectManager::createNewObject(Object_Type type)
{
	return this->createNewObject(type, Vector2D(0, 0), Vector2D(1, 1));
}

void ObjectManager::AddObject(Game_Object* nVal)
{
	this->Objects.push_back(nVal);
}

void ObjectManager::setFPS(int NewFPS)
{
	this->DesiredFPS = NewFPS;
}

void ObjectManager::Update()
{
	//Anything that you want done every frame and is pertaining to the Object Properties of an entity
	//should be placed under this function
	if(UpdateTimer.getElapsedTime().asMilliseconds() > 1000/DesiredFPS)
	{
		for(std::vector<Game_Object*>::iterator iter = Objects.begin(); iter != Objects.end(); iter++)
		{
			(*iter)->OBJ_Update();
			if ((*iter)->getDeleteFlag())
			{
				//Marked for deletion. Terminate, this will automatically call destructor. Pointer destruction must be handled in relevant managers
				delete *iter;
			}
		}
		UpdateTimer.reset();
	}
}


//Singleton design pattern.
ObjectManager* ObjectManager::Instance()
{
	static ObjectManager instance;
	return &instance;
}