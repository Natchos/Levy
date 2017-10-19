#pragma once
#include "Game_Object.hpp"
//Constructor.
Game_Object::Game_Object( bool startAlive)
{
	Alive = startAlive;
}
//Default Destructor.
Game_Object::~Game_Object()
{
	delete this;
}
//Returns the OBJ_Type.
Object_Type Game_Object::getObjectType()
{
	return this->OBJ_Type;
}
//Sets the OBJ_Type variable. Should be used sparingly.
void Game_Object::setObjectType(Object_Type newValue)
{
	this->OBJ_Type = newValue;
}
//Gets whether the object is alive
bool Game_Object::getAlive()
{
	return this->Alive;
}
//Sets whether the object is alive
void Game_Object::setAlive(bool nVal)
{
	this->Alive = nVal;
}

//Returns deletion flag state
bool Game_Object::getDeleteFlag()
{
	return this->Delete;
}

//Mark for deletion
void Game_Object::setDeleteFlag(bool nVal)
{
	this->Delete = nVal;
}