#pragma once
#include "2FloatVector.hpp"

/*
Contains the basic functions for moving, rotateable functionality.
Abstract class so needs to be subclassed. The move function needs to be implemented
*/
class Unit_Functionality
{
protected:

	//Current position
	Vector2D position;

	// Velocity per frame
	Vector2D velocity;

	// Max Velocity per frame
	int maxVelocity;

	// Position vector of the destination
	Vector2D destination;

	// The direction this unit is facing, should be normalized
	Vector2D facing;

	// Max Rotation speed. Should be in radians
	double rotationSpeed;

public:

	//Full constructor
	Unit_Functionality(Vector2D pos, Vector2D vel, int maxVel, Vector2D dest, Vector2D fac, double rotSpeed);

	//Neccessary only constructor
	Unit_Functionality(Vector2D pos, int maxVel, double rotSpeed);

	//Empty destructor
	~Unit_Functionality();

	//Setters & getters
	void setPosition(Vector2D vel);
	void incrementPosition(Vector2D vel);
	void setVelocity(Vector2D vel, bool ovr = true); //If override is true, velocity will be set and then scaled to max Velocity
	void setDestination(Vector2D des);
	void setDirection(Vector2D dir);
	void setMaxVelocity(int maxVel);
	void setRotationSpeed(double rSpeed);

	Vector2D getPosition();
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