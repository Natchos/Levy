#pragma once

#include "Basic_unit.hpp"

/*
* Capsules the most basic faction functionalities: An collection of units and buildings. 
* Diplomacy, economy and AI will all have their own classes.
*
*/
class Faction {
public:
	void createUnit(Basic_Unit* ptr);



private:
	std::vector<Basic_Unit*> ownedUnits;
	//std::vector<Basic_Buildings> ownedBuildings; Not yet implemented.


};