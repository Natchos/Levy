#pragma once
#include "2FloatVector.hpp"

/*
Contains the basic functions for moving, rotateable functionality.
Abstract class so needs to be subclassed. The move function needs to be implemented
*/
class Unit
{
private:
	// Velocity per frame
	Vector2D velocity;

	// Max Velocity per frame
	int maxVelocity;

	// Position vector of the destination
	Vector2D destination;

	// The direction this unit is facing, should be normalized
	Vector2D direction;

	// Max Rotation speed. Should be in radians
	double rotationSpeed;

public:
	//Setters & getters
	void setVelocity(Vector2D vel, bool ovr = true); //If override is true, velocity will be set and then scaled to max Velocity
	void setDestination(Vector2D des);
	void setDirection(Vector2D dir);
	void setmaxVelocity(int maxVel);
	void setRotationSpeed(double rSpeed);

	Vector2D getVelocity();
	Vector2D getDestination();
	Vector2D getDirection();
	int getMaxVelocity();
	double getRotationSpeed();


	//Abstract class.
	virtual void move() = 0;

	//Rotates the facing either m_rads or the max allowed rotation
	void rotate(double rads);
};