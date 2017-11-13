#pragma once
#include "2FloatVector.hpp"

/*
Contains the basic functions for moving, rotateable functionality.
Abstract class so needs to be subclassed. The move function needs to be implemented
*/
class Unit_Functionality
{
protected:
	// Velocity per frame
	Vector2D velocity;

	// Max Velocity per frame
	float maxVelocity;

	// Max Acceleration per frame
	float maxAcceleration;

	// Position vector of the destination
	Vector2D destination;

	// The direction this unit is facing, should be normalized
	Vector2D facing;

	// Max Rotation speed. Should be in radians
	double rotationSpeed;

public:

	//Full constructor
	Unit_Functionality(Vector2D vel, float maxVel, float maxAcc, Vector2D dest, Vector2D fac, double rotSpeed);

	//Full constructor w/o destination
	Unit_Functionality(Vector2D vel, float maxVel, float maxAcc, Vector2D fac, double rotSpeed);

	//Neccessary only constructor
	Unit_Functionality(float maxVel, float maxAcc, double rotSpeed);

	//Empty destructor
	~Unit_Functionality();

	//Setters & getters
	/*If override is true, velocity will be set and then scaled to max Velocity
	Ignores max acceleration!*/
	void setVelocity(Vector2D vel, bool ovr = true);
	void setDestination(Vector2D des);
	void setDirection(Vector2D dir);
	void setMaxVelocity(float maxVel);
	void setMaxAcceleration(float maxAcceleration);
	void setRotationSpeed(double rSpeed);

	Vector2D getVelocity();
	Vector2D getDestination();
	Vector2D getDirection();
	float getMaxVelocity();
	float getMaxAcceleration();
	double getRotationSpeed();


	//Abstract class.
	virtual void move() = 0;

	//Rotates the facing either m_rads or the max allowed rotation
	void rotateFacing(double rads);

	//Attempts to add the acc vector to velocity, then rescales velocity if need be.
	void incrementVelocity(Vector2D acc);
	//Increment velocity with a direction aswell as number between 0 and 1 which scales the accelerating force to maxAcceleration
	void incrementVelocity(Vector2D facing, float scale);
	//Increments by the maxAcceleration in the facing direction
	void incrementVelocity();
	//Scale velocity. The percentage should give the percentage after. So Vel = (1,0) and perc = 1.2 -> Velc(1.2,0). Will be moderated by accelerating force. 
	void scaleVelocity(float percentage);

private:
	void restrainVelocity();
};