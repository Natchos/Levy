#pragma once
#include "Unit_Functionality.hpp"
#include "2FloatVector.hpp"

void Unit_Functionality::rotate(double rads)
{
	if (rads > 0)
	{
		if (this->rotationSpeed > rads)
			this->facing.rotate(rads);
		else
			this->facing.rotate(this->rotationSpeed);
	}
	else
	{
		if (this->rotationSpeed > abs(rads))
			this->facing.rotate(rads);
		else
			this->facing.rotate(-this->rotationSpeed);
	}
}

Unit_Functionality::Unit_Functionality(Vector2D pos, Vector2D vel, int maxVel, Vector2D dest, Vector2D fac, double rotSpeed)
{
	this->position = pos;
	this->velocity = vel;
	this->maxVelocity = maxVel;
	this->destination = dest;
	this->facing = fac;
	this->rotationSpeed = rotSpeed;
}

Unit_Functionality::Unit_Functionality(Vector2D pos, int maxVel, double rotSpeed)
{
	this->position = pos;
	this->maxVelocity = maxVel;
	this->rotationSpeed = rotSpeed;
	this->velocity = Vector2D(0, 0);
	this->destination = Vector2D(0, 0);
	this->facing = Vector2D(0, 0);
}

Unit_Functionality::~Unit_Functionality()
{}

void Unit_Functionality::setPosition(Vector2D vel)
{
	this->position = vel;
}

void Unit_Functionality::incrementPosition(Vector2D vel)
{
	this->position += vel;
}

void Unit_Functionality::setVelocity(Vector2D vel, bool ovr)
{
	if (vel.LengthSq() > this->maxVelocity*this->maxVelocity)
	{
		if (ovr)
		{
			this->velocity = vel * ((double)maxVelocity / vel.Length());
		}
	}
	else
		this->velocity = vel;
}

void Unit_Functionality::setDestination(Vector2D des)
{
	this->destination = des;
}

void Unit_Functionality::setDirection(Vector2D dir)
{
	
}

void Unit_Functionality::setMaxVelocity(int maxVel)
{
	this->maxVelocity = maxVel;
}

void Unit_Functionality::setRotationSpeed(double rSpeed)
{
	this->rotationSpeed = rSpeed;
}

Vector2D Unit_Functionality::getPosition()
{
	return this->position;
}

Vector2D Unit_Functionality::getVelocity()
{
	return this->velocity;
}

Vector2D Unit_Functionality::getDestination()
{
	return this->destination;
}

Vector2D Unit_Functionality::getDirection()
{
	return this->direction;
}

int Unit_Functionality::getMaxVelocity()
{
	return this->maxVelocity;
}

double Unit_Functionality::getRotationSpeed()
{
	return this->rotationSpeed;
}