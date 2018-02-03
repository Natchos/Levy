#pragma once
#include "Basic_Unit.hpp"
#include "Military_Functionality.hpp"
#include "Engine_Enums.cpp"
#include "Levy_Enums.cpp"
#include <vector>

/* Contains functionality for a military unit. Combines military functionality and Basic_Unit.

*/
class Military_Unit : public Basic_Unit
{
public:
	//Creates a basic unit without any attacks
	Military_Unit(long lt, int sz, int mHealth, int cHealth, Vector2D vel, float maxVel, float maxAcc, Vector2D fac, double rotSpeed, std::string fName);
	//Simple constructor, same as above
	Military_Unit(int sz, int mHealth, float maxVel, float maxAcc, Vector2D fac, double rotSpeed, std::string fName);
	
	Military_Functionality* getPrimaryMeleeMA();
	Military_Functionality* getPrimaryRangedMA();
	void setPrimaryMeleeMA(int index);
	void setPrimaryRangedMA(int index);
	Military_Functionality* getMA(int index);
	//Automatically detects ranged/melee type
	void addMA(Military_Functionality newMA, bool primary = false);
	void addMA(Military_Functionality* newMA, bool primary = false);
	
private:
	std::vector<Military_Functionality*> ModesOfAttack;
};