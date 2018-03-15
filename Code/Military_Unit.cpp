#pragma once
#include "Military_Unit.hpp"

Military_Unit::Military_Unit(long lt, int sz, int mHealth, int cHealth, Vector2D vel, float maxVel, float maxAcc, Vector2D fac, double rotSpeed, std::string fName) : Basic_Unit(lt, sz, mHealth, cHealth, vel, maxVel, maxAcc, fac, rotSpeed,fName)
{
	//Populate so that there is something.
	this->ModesOfAttack.push_back(new Military_Functionality);
}

Military_Unit::Military_Unit(int sz, int mHealth, float maxVel, float maxAcc, Vector2D fac, double rotSpeed, std::string fName) : Basic_Unit(sz, mHealth, maxVel, maxAcc, fac, rotSpeed, fName)
{
	//Populate so that there is something.
	this->ModesOfAttack.push_back(new Military_Functionality);
}


Military_Functionality * Military_Unit::getPrimaryMeleeMA()
{
	return nullptr;
}

Military_Functionality * Military_Unit::getPrimaryRangedMA()
{
	return nullptr;
}

void Military_Unit::setPrimaryRangedMA(int index)
{
}

Military_Functionality * Military_Unit::getMA(int index)
{
	return nullptr;
}

void Military_Unit::addMA(Military_Functionality newMA, bool primary)
{
}

void Military_Unit::addMA(Military_Functionality * newMA, bool primary)
{
}

void Military_Unit::setPrimaryMeleeMA(int index)
{
}
