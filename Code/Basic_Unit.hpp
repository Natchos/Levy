#pragma once
#include "Unit_Functionality.hpp"
#include "Game_Entity.hpp"
#include "Basic_Render_Entity.hpp"

/* Class for basic units. This class implements the following class functionalities: Entity, Unit, Render_Entities.
It implements GFX_Update(), move() and OBJ_Update().

*/
class Basic_Unit : public Game_Entity, public Unit_Functionality, public Basic_Render_Entity
{
protected:



public:

	//Graphical initializer
	void IntializeGraphics(sf::Texture texture, Vector2D scale, Vector2D position, Vector2D origin);
	//Full constructor
	Basic_Unit(long lt, int sz, int mHealth, int cHealth, Vector2D vel, float maxVel, float maxAcc, Vector2D fac, double rotSpeed);
	//Simple constructor
	Basic_Unit(int sz, int mHealth, float maxVel, float maxAcc, Vector2D fac, double rotSpeed);
	//Implementing inherited abstract functions
	void GFX_Update();
	void move();
	void OBJ_Update();

	virtual void setDeleteFlag(bool nVal = true);
protected:
	void rotateTowardsDestination();


};