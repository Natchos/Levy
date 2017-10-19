#pragma once
#ifndef INCLUDED_BASE_OBJECT
#define INCLUDED_BASE_OBJECT
#include "Engine_Enums.cpp"
#include "Randomizer.cpp"

//The basic class of an object. Contains an enum for its type, a bool value for whether it is "alive" for the engines purposes, and an exit function.
//This Class can not be "used" per se, since it is an abstract class.
//A game will always need to inherit from this and implement OBJ_Update.
class Game_Object
{
public:
	//In default the Game Object will be alive at start.
	Game_Object(bool startAlive = true);
	~Game_Object();

	Object_Type getObjectType();
	void setObjectType(Object_Type newValue);

	bool getAlive();
	void setAlive(bool newValue);

	bool getDeleteFlag();
	void setDeleteFlag(bool nVal = true);


	//Abstract class.
	virtual void OBJ_Update() = 0;
protected:
	//If alive is set to false, the game will not update or draw this entity at all.
	bool Alive;
	//Set to true when this entity should be deleted
	bool Delete;
private:
	//Can be used to identify an object. Can/should not be changed after the object is initialized.
	Object_Type OBJ_Type;
};
#endif