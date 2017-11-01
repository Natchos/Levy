#pragma once
#include "Game_Entity.hpp"

int Game_Entity::IDCounter = 0;

Game_Entity::Game_Entity(Vector2D pos, long lt, int sz, int mHealth, int cHealth)
{
	this->lifeClock = Watch();
	this->ID = createNewID();
	this->position = pos;
	this->lifetime = lt;
	this->size = sz;
	this->maxHealth = mHealth;
	this->currentHealth = cHealth;
	this->lifeClock.restart();
}

Game_Entity::Game_Entity(Vector2D pos, int sz, int mHealth) : Game_Entity(Vector2D(0, 0), -1, sz, mHealth, mHealth)
{

}

Game_Entity::Game_Entity(long lt, int sz, int mHealth) : Game_Entity(Vector2D(0, 0), lt, sz, mHealth, mHealth)
{
}

int Game_Entity::createNewID()
{
	this->IDCounter++;
	return this->IDCounter;
}

Vector2D Game_Entity::getPosition()
{
	return this->position;
}

int Game_Entity::getID()
{
	return this->ID;
}

double Game_Entity::getToC()
{
	return this->ToC;
}

long Game_Entity::getLifetime()
{
	return lifetime;
}

long Game_Entity::getRemainingLife()
{
	return lifeClock.getElapsedTime().asMilliseconds() - lifetime;
}

int Game_Entity::getSize()
{
	return this->size;
}

int Game_Entity::getMaxHealth()
{
	return this->maxHealth;
}

int Game_Entity::getCurrentHealth()
{
	return this->currentHealth;
}

void Game_Entity::setPosition(Vector2D nPos)
{
	this->position = nPos;
}

void Game_Entity::incrementPosition(Vector2D nPos)
{
	this->position += nPos;
}

void Game_Entity::setLifetime(long nLifetime)
{
	this->lifetime = nLifetime;
}

void Game_Entity::setSize(int nSize)
{
	this->size = nSize;
}

void Game_Entity::setmaxHealth(int nHealthMax, bool ovr)
{
	this->maxHealth = nHealthMax;
}

void Game_Entity::setCurrentHealth(int nCurrentHealth)
{
	this->currentHealth = nCurrentHealth;
}

void Game_Entity::incrementCurrentHealth(int increment)
{
	this->currentHealth += increment;
}