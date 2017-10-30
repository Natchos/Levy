#pragma once
#include "Unit_Functionality.hpp"
#include "Game_Object.hpp"
#include "Basic_Render_Entity.hpp"

/* Class for basic units. This class implements the following class functionalities: Object, Unit, Render_Entities.
It implements GFX_Update(), move() and OBJ_Update().

*/
class Basic_Unit : public Game_Object, public Unit_Functionality, public Basic_Render_Entity
{

	//Implementing inherited abstract functions
	void GFX_Update();
	void move();
	void OBJ_Update();

};