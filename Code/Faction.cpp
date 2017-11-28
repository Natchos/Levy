#pragma once

#include "Faction.hpp"


Faction::Faction(std::string name)
{
	this->factionName = name;
}


void Faction::createUnit(Basic_Unit* ptr)
{
	this->ownedUnits.push_back(ptr);
}

void Faction::createUnit(UnitType uType, Vector2D pos)
{

}

void Faction::select(std::vector<Basic_Unit*> selection)
{
	this->selectedUnits.clear();
	this->selectedUnits = selection;
}

void Faction::addToSelection(Basic_Unit* unit)
{
	if (!this->isSelected(unit))
	{
		if (unit->getFaction() == this->factionName)
			selectedUnits.push_back(unit);
	}
}

void Faction::addToSelection(int ID)
{
	if (!this->isSelected(ID))
	{
		Basic_Unit* ptr = this->isOwned(ID);
		if (!(ptr == nullptr))
			selectedUnits.push_back(ptr);
	}
}
void Faction::removeFromSelection(Basic_Unit * unit)
{
	this->removeFromSelection(unit->getID());
}

void Faction::removeFromSelection(int ID)
{
	if (this->isSelected(ID))
	{
		std::vector<Basic_Unit*>::iterator iter;
		for (iter = selectedUnits.begin(); iter != selectedUnits.end(); iter++)
		{
			if ((*iter)->getID() == ID)
			{
				selectedUnits.erase(iter);
				return;
			}
		}
	}
}

void Faction::unSelect()
{
	this->selectedUnits.clear();
}

void Faction::selectAll(UnitType uType)
{
	//TBI
}

Basic_Unit* Faction::isOwned(int ID)
{
	std::vector<Basic_Unit*>::iterator iter;
	for (iter = ownedUnits.begin(); iter != ownedUnits.end(); iter++)
	{
		if ((*iter)->getID() == ID)	//Match, is owned
			return (*iter);
	}
	return nullptr;
}

bool Faction::isOwned(Basic_Unit * unit)
{
	return (unit->getFaction() == this->factionName);
}

bool Faction::isSelected(Basic_Unit* unit)
{
	return this->isSelected(unit->getID());
}

bool Faction::isSelected(int ID)
{
	std::vector<Basic_Unit*>::iterator iter;
	for (iter = selectedUnits.begin(); iter != selectedUnits.end(); iter++)
	{
		if ((*iter)->getID() == ID)	//Match, is already selected.
			return true;
	}
}

Basic_Unit* Faction::getUnit(int ID)
{
	std::vector<Basic_Unit*>::iterator iter;
	for (iter = ownedUnits.begin(); iter != ownedUnits.end(); iter++)
	{
		if ((*iter)->getID() == ID)	
			return (*iter);
	}
}

