#pragma once
#include "Game_Object.hpp"
#include "2FloatVector.hpp"
#include "Watch.hpp"

class Game_Entity : public Game_Object
{
protected:
	static int IDCounter;
	Watch lifeClock;
	int ID; //Permament and unique identifier
	double ToC;
	long lifetime;
	int size;
	int maxHealth;
	int currentHealth;

	int createNewID();

public:

	//Constructors
	Game_Entity(long lt, int sz, int mHealth, int cHealth);
	Game_Entity(int sz, int mHealth);
	Game_Entity(long lt, int sz, int mHealth);

	//Abstract
	virtual void OBJ_Update() = 0;

	//Gets&sets
	int getID();
	double getToC();
	long getLifetime();
	long getRemainingLife();
	int getSize();
	int getMaxHealth();
	int getCurrentHealth();
	
	void setLifetime(long nLifetime);
	void setSize(int nSize);
	void setmaxHealth(int nHealthMax, bool ovr = false);
	void setCurrentHealth(int nCurrentHealth);
	void incrementCurrentHealth(int increment); //Can also be used to decrement. #YOLO
};
