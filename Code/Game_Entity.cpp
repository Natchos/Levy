#pragma once
#include "Game_Entity.hpp"

int Game_Entity::IDCounter = 0;

Game_Entity::Game_Entity(long lt, int sz, int mHealth, int cHealth)
{
	this->lifeClock = Watch();
	this->ID = createNewID();
	this->lifetime = lt;
	this->size = sz;
	this->maxHealth = mHealth;
	this->currentHealth = cHealth;
	this->lifeClock.restart();
}

Game_Entity::Game_Entity(int sz, int mHealth) : Game_Entity( -1, sz, mHealth, mHealth)
{

}

Game_Entity::Game_Entity(long lt, int sz, int mHealth) : Game_Entity(lt, sz, mHealth, mHealth)
{
}

int Game_Entity::createNewID()
{
	this->IDCounter++;
	return this->IDCounter;
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