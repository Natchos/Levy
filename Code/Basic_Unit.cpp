#include "Basic_Unit.hpp"

//Specifies how this entitys graphical charasteristics should be behave/update
void Basic_Unit::GFX_Update()
{

}

//Implements movement
void Basic_Unit::move()
{
	this->position += this->velocity;
	Vector2D desiredFacing(Vector2D(this->destination - this->position).Normalize());
}

//Updates object parameters
void Basic_Unit::OBJ_Update()
{

}