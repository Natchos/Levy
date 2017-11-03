#pragma once
#include "Unit_Functionality.hpp"
#include "2FloatVector.hpp"

void Unit_Functionality::rotateFacing(double rads)
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

Unit_Functionality::Unit_Functionality(Vector2D vel, float maxVel, float maxAcc, Vector2D dest, Vector2D fac, double rotSpeed)
{
	this->velocity = vel;
	this->maxVelocity = maxVel;
	this->maxAcceleration = maxAcc;
	this->destination = dest;
	this->facing = fac;
	this->rotationSpeed = rotSpeed;
}

Unit_Functionality::Unit_Functionality(float maxVel, float maxAcc, double rotSpeed)
{
	this->maxVelocity = maxVel;
	this->maxAcceleration = maxAcc;
	this->rotationSpeed = rotSpeed;
	this->velocity = Vector2D(0, 0);
	this->destination = Vector2D(0, 0);
	this->facing = Vector2D(0, 0);
}

Unit_Functionality::~Unit_Functionality()
{}



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
	this->facing = dir.Normalize();
}

void Unit_Functionality::setMaxVelocity(float maxVel)
{
	this->maxVelocity = maxVel;
}

void Unit_Functionality::setMaxAcceleration(float maxAcc)
{
	this->maxAcceleration = maxAcc;
}

void Unit_Functionality::setRotationSpeed(double rSpeed)
{
	this->rotationSpeed = rSpeed;
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
	return this->facing;
}

float Unit_Functionality::getMaxVelocity()
{
	return this->maxVelocity;
}

float Unit_Functionality::getMaxAcceleration()
{
	return this->maxAcceleration;
}

double Unit_Functionality::getRotationSpeed()
{
	return this->rotationSpeed;
}

void Unit_Functionality::incrementVelocity(Vector2D acc)
{
	//Saves sqrt. 
	if (acc.LengthSq() > this->maxAcceleration*this->maxAcceleration)
	{
		this->velocity += Vector2D::Truncate(acc, maxAcceleration);
	}
	else
		this->velocity += (acc*maxAcceleration);
	this->restrainVelocity();
}

void Unit_Functionality::incrementVelocity(Vector2D facing, float scale)
{
	this->velocity += (facing *= (scale*maxAcceleration));
	this->restrainVelocity();
}

void Unit_Functionality::incrementVelocity()
{
	this->velocity += (facing *= maxAcceleration);
	this->restrainVelocity();
}

void Unit_Functionality::scaleVelocity(float percentage)
{
	this->velocity.Scale(percentage);
	this->restrainVelocity();
}

void Unit_Functionality::restrainVelocity()
{
	if (this->velocity.LengthSq() > this->maxVelocity*this->maxVelocity) //Save the sqrt
		this->velocity.Truncate(maxVelocity);
}
