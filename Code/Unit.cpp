#pragma once
#include "Unit.hpp"
#include "2FloatVector.hpp"

void Unit::rotate(double rads)
{
	if (rads > 0)
	{
		if (this->rotationSpeed > rads)
			this->direction.rotate(rads);
		else
			this->direction.rotate(this->rotationSpeed);
	}
	else
	{
		if (this->rotationSpeed > abs(rads))
			this->direction.rotate(rads);
		else
			this->direction.rotate(-this->rotationSpeed);
	}
}


void Unit::setVelocity(Vector2D vel, bool ovr)
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

void Unit::setDestination(Vector2D des)
{
	this->destination = des;
}

void Unit::setDirection(Vector2D dir)
{
	
}

void Unit::setmaxVelocity(int maxVel)
{
	this->maxVelocity = maxVel;
}

void Unit::setRotationSpeed(double rSpeed)
{
	this->rotationSpeed = rSpeed;
}


Vector2D Unit::getVelocity()
{
	return this->velocity;
}

Vector2D Unit::getDestination()
{
	return this->destination;
}

Vector2D Unit::getDirection()
{
	return this->direction;
}

int Unit::getMaxVelocity()
{
	return this->maxVelocity;
}

double Unit::getRotationSpeed()
{
	return this->rotationSpeed;
}