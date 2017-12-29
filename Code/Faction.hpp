#pragma once

#include "Basic_unit.hpp"
#include "Military_Unit.hpp"
#include "ScreenLog.hpp"
#include "Levy_Enums.cpp"

/*
* Capsules the most basic faction functionalities: An collection of units and buildings. 
* Diplomacy, economy and AI will all have their own classes.
*
*/
class Faction 
{
public:
	Faction(std::string name, ScreenLog* Writer);
	//Faction(std::string name, std::vector<Basic_Unit*> startingUnits, std::vector<Basic_Buildings*> startingBuildings)

	void createUnit(Basic_Unit* ptr);
	void createUnit(UnitType uType, Vector2D pos);

	void select(std::vector<Basic_Unit*> selection);
	//void select(std::vector<Basic_Buildings*> selection);
	void addToSelection(Basic_Unit* unit);
	void addToSelection(int ID);
	void removeFromSelection(Basic_Unit* unit);
	void removeFromSelection(int ID);
	void unSelect();
	void selectAll(UnitType uType);

	Basic_Unit* isOwned(int ID);
	bool isOwned(Basic_Unit* unit);
	bool isSelected(Basic_Unit* unit);
	bool isSelected(int ID);

	Basic_Unit* getUnit(int ID);



private:


	std::vector<Basic_Unit*> ownedUnits;
	//std::vector<Basic_Buildings> ownedBuildings; Not yet implemented.
	std::vector<Basic_Unit*> selectedUnits;

	std::string factionName;

	//All are going to point to same pointer anyway.
	static ScreenLog* scrPrt;
};