#include "Basic_Unit.hpp"


Basic_Unit::Basic_Unit(long lt, int sz, int mHealth, int cHealth, Vector2D vel, float maxVel, float maxAcc, Vector2D fac, double rotSpeed, std::string fName) : Game_Entity(lt, sz, mHealth, cHealth),
	Unit_Functionality(vel, maxVel, maxAcc, fac, rotSpeed)
{
	this->setDirection(fac);
	this->factionName = fName;
}

Basic_Unit::Basic_Unit(int sz, int mHealth, float maxVel, float maxAcc, Vector2D fac, double rotSpeed, std::string fName) : Game_Entity(sz, mHealth),
Unit_Functionality(maxVel, maxAcc, rotSpeed)
{
	this->setDirection(fac);
	this->factionName = fName;
}


void Basic_Unit::IntializeGraphics(sf::Texture texture, Vector2D scale, Vector2D position, Vector2D origin)
{
	this->setTexture(texture);
	this->setScale(scale.x,scale.y);
	this->setPosition(position);
	this->setOrigin(origin);
}


//Specifies how this entitys graphical charasteristics should be behave/update
void Basic_Unit::GFX_Update()
{
	int x = 0;
}

void Basic_Unit::setDeleteFlag(bool nVal)
{
	this->Basic_Render_Entity::setDeleteFlag(nVal);
	this->Game_Object::setDeleteFlag(nVal);
}

//Implements movement
void Basic_Unit::move()
{
	Basic_Render_Entity::move(this->velocity.x,this->velocity.y);
	Vector2D desiredFacing(Vector2D(this->destination - this->getPosition()).Normalize());
	this->rotateTowardsDestination();
	this->incrementVelocity(this->facing);
}


void Basic_Unit::rotateTowardsDestination()
{
	Vector2D desiredFacing(Vector2D(this->destination - this->getPosition()).Normalize());
	double angleToFace = Vector2D::angleBetween(this->facing, desiredFacing);
	this->rotateFacing(angleToFace); //Used for units
	this->rotate(angleToFace * atan(1) * 4); //Used for graphics
}

//Updates object parameters
void Basic_Unit::OBJ_Update()
{
	if (this->currentHealth < 0)
	{
		this->setAlive(false);
		this->setDeleteFlag(true);
	}
	if (this->lifetime > 0)
	{
		if (this->lifeClock.getElapsedTime().asMilliseconds() > this->lifetime)
		{
			this->setDeleteFlag(true);
			this->setAlive(false);
		}
	}
}

std::string Basic_Unit::getFaction()
{
	return this->factionName;
}

void Basic_Unit::setFaction(std::string nFaction)
{
	this->factionName = nFaction;
}
